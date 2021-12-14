//
//  csv.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.12.21.
//

#ifndef csv_hpp
#define csv_hpp

#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <map>

#include "src/level/cell_color.h"

class CSV
{
    template<typename T>
    using CSVResult = std::vector<std::vector<T>>;
    
private:
    std::ifstream file;
    
public:
    CSV(const std::string& file_name) : file{file_name}
    { }
    
    template<typename TargetT>
    CSVResult<TargetT> read(const std::map<std::string, TargetT>& decode = {})
    {
        auto result = CSVResult<TargetT>{};
        
        for (std::string line; std::getline(file, line);)
        {
            result.emplace_back();
            
            auto reg = std::regex{","};
            auto splitted_line = std::vector<std::string>{
                std::sregex_token_iterator{line.begin(), line.end(), reg, -1},
                std::sregex_token_iterator{}
            };
            
            for (const auto& value : splitted_line)
            {
                result.back().emplace_back(decode.at(value));
            }
        }
        
        return result;
    }
};

#endif /* csv_h */
