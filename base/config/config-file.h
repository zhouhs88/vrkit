
#ifndef _VRKIT_CONFIG_FILE_H_
#define _VRKIT_CONFIG_FILE_H_

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <stdexcept>

class ConfigFileException : public std::runtime_error {
    public:
            explicit ConfigFileException(const std::string& except):
                std::runtime_error(except) {}
};

class ConfigFile {
    public:
        ConfigFile(const std::string& file);
        ~ConfigFile();

        void getSections(std::vector<std::string>& sections);
        bool getKeys(const std::string& section, std::vector<std::string>& keys);
        bool get(const std::string& section,
                 const std::string& key,
                 std::string& val);
        bool gets(const std::string& section,
                 const std::string& key,
                 std::vector<std::string>& val);
        bool get(const std::string& section,
                 const std::string& key,
                 unsigned int& valInt);
        bool gets(const std::string& section,
                 const std::string& key,
                 std::vector<unsigned int>& val);
        bool get(const std::string& section,
                 const std::string& key,
                 bool& result);
    private:
        typedef std::map<std::string, std::string> Section;
        std::map<std::string, Section*> m_sections;
        std::string m_path;
        std::string m_file;
        std::ifstream m_ifile;
    private:
        void analyze();
        Section* getSection(char* buf, std::string& sectionName);
        bool getKeyAndValue(char* buf, std::string& key, std::string& val);
};

#endif // _VRKIT_CONFIG_FILE_H_
