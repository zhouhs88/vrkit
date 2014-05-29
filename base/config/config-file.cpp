
#include "base/config/config-file.h"
#include <cstdlib>
#include <utility>
#include <string.h>
#include <stdlib.h>

#define STREAM_SIZE 255    

ConfigFile::ConfigFile(const std::string& file)
{
    m_file = file;
    analyze();
}

ConfigFile::~ConfigFile()
{
    std::map<std::string, Section*>::iterator ite = m_sections.begin();
    for (; ite != m_sections.end(); ite++)
        delete ite->second;
    m_sections.clear();

    m_ifile.close();
}

// path = /etc
// file = owl.conf
void ConfigFile::analyze()
{
    // open config file, throw exception if failed
    m_ifile.open(m_file.c_str());
    if (!m_ifile.good()) {
        throw ConfigFileException("Open file failed");
        return;
    }

    // get all sections 
    char buf[STREAM_SIZE];
    memset(buf, 0, sizeof(buf));
    Section* curSection = NULL;
    std::string curSectionName;
    while (m_ifile.getline(buf, STREAM_SIZE)) {
        // if new section is found, the last section should be checked
        if (*buf == '[') {
            // a new section is created
            curSection = getSection(buf, curSectionName);
            if (!curSection) {
                throw ConfigFileException("section error");
                return;
            }
            // if the last section exist, save it into sections
            // if there are two same sections, exception should be thrown
            if (m_sections.find(curSectionName) != m_sections.end()) {
                delete curSection;
                throw ConfigFileException("section error");
                return;
            }
            else
                m_sections.insert(std::make_pair(curSectionName, curSection));
        }
        else {
            // current section must not be null
            if (!curSection) {
                throw ConfigFileException("no section");
                return;
            }
            // get key and value from current section
            std::string key, val;
            if (!getKeyAndValue(buf, key, val)) {
                delete curSection;
                throw ConfigFileException("key and value error");
                return;
            }
            // check wheater there are two same keys
            if (curSection->find(key) == curSection->end())
                curSection->insert(std::make_pair(key, val));
            else {
                throw ConfigFileException("key and value error");
                return;
            }
        }
    } // while(file.getline...)
    memset(buf, 0, sizeof(buf));
}

static void strip(std::string& val, const std::string& patten)
{
    size_t start = val.find_first_not_of(patten);
    size_t end = val.find_last_not_of(patten);
    val = val.substr(start, end - start + 1);
}

static void split(std::string& val, 
                  const std::string& patten, 
                  std::vector<std::string>& result)
{
    char* subVal = strtok((char*)val.c_str(), patten.c_str());
    while (subVal)
    {
        result.push_back(subVal);
        subVal = strtok(NULL, patten.c_str());
    }
}

static void split(std::string& val, 
                  const std::string& patten, 
                  std::vector<unsigned int>& result)
{
    char* subVal = strtok((char*)val.c_str(), patten.c_str());
    while (subVal)
    {
        result.push_back(atoi(subVal));
        subVal = strtok(NULL, patten.c_str());
    }
}

ConfigFile::Section* ConfigFile::getSection(char* buf, std::string& sectionName)
{
    int length = strlen(buf); 
    if (buf[0] != '[' || buf[length- 1] != ']')
        return NULL;
    sectionName = std::string(buf, 1, length - 2);
    strip(sectionName, " ");
    if (sectionName.empty()) {
        throw ConfigFileException("section error");
        return NULL;
    }

    return new Section;
}

bool ConfigFile::getKeyAndValue(char* buf, std::string& key, std::string& val)
{
    std::string content = buf;
    size_t pos = content.find_first_of("=");
    if (pos == std::string::npos) {
        throw ConfigFileException("section error");
        return false;
    }
    key = content.substr(0, pos);
    val = content.substr(pos + 1, content.size() - pos - 1);
    strip(key, " ");
    strip(val, " ");

    return true;
}

void ConfigFile::getSections(std::vector<std::string>& sections)
{
    std::map<std::string, Section*>::iterator ite = m_sections.begin();
    for (; ite != m_sections.end(); ite++) 
        sections.push_back(ite->first);
}

bool ConfigFile::getKeys(const std::string& sectionName,
                      std::vector<std::string>& keys)
{
    if (m_sections.find(sectionName) == m_sections.end()) 
        return false;

    Section* section = m_sections[sectionName];
    std::map<std::string, std::string>::iterator ite = section->begin();
    for (; ite != section->end(); ite++)
        keys.push_back(ite->first);

    return true;
}

bool ConfigFile::get(const std::string& sectionName,
                     const std::string& key,
                     std::string& val)
{
    if (m_sections.find(sectionName) != m_sections.end()) {
        Section* section = m_sections[sectionName];
        if (section->find(key) != section->end()) {
            val = (*section)[key];
            return true;
        }
    }

    return false;
}

bool ConfigFile::gets(const std::string& section,
                      const std::string& key,
                      std::vector<std::string>& val)
{ 
    std::string content;
    if (!getString(section, key, content))
        return false;
    split(content, ";", val);

    return true;
}

bool ConfigFile::get(const std::string& section,
                     const std::string& key,
                     unsigned int& valInt )
{
    std::string val;
    if (!getString(section, key, val))
        return false;
    valInt = (unsigned int)atoi(val.c_str());

    return true;
}

bool ConfigFile::gets(const std::string& section,
                      const std::string& key,
                      std::vector<unsigned int>& val)
{
    std::string content;
    if (!getString(section, key, content))
        return false;
    split(content, ";", val);

    return true;
}

bool ConfigFile::get(const std::string& section,
                     const std::string& key,
                     bool& result)
{
    std::string val;
    if (!getString(section, key, val))
        return false;
    if (val == "true")
        result = true;
    else if (val == "false")
        result = false;
    else
        return false;

    return true;
}
