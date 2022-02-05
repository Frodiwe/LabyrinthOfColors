//
//  key_value_file.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.12.21.
//

#ifndef key_value_file_h
#define key_value_file_h

#include <fstream>
#include <string>
#include <regex>

class KeyValueFile
{
    using ParserResult = std::map<std::string, std::string>;
    
private:
    std::ifstream file;
    
public:
    KeyValueFile(const std::string& file_name) : file{file_name}
    { }
    
    ParserResult read()
    {
        auto result = ParserResult{};
        
        for (std::string line; std::getline(file, line);)
        {
            std::regex reg{R"((\w+):\s(.+))"};
            std::smatch match;
            
            if (std::regex_search(line, match, reg))
            {
                result[match[1].str()] = match[2].str();
            }
        }
        
        return result;
    }
};

#endif /* key_value_file_h */
