//
//  map_position.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 14.11.21.
//

#ifndef map_position_h
#define map_position_h

#include <stdlib.h>
#include <regex>
#include <string>

struct MapPosition
{
	size_t i;
	
	size_t j;
    
    bool operator==(const MapPosition& v)
    {
        return i == v.i and j == v.j;
    }
    
    bool operator!=(const MapPosition& v)
    {
        return not (*this == v);
    }
    
    MapPosition operator+(const MapPosition& v)
    {
        return {i + v.i, j + v.j};
    }
    
    MapPosition operator-(const MapPosition& v)
    {
        return {
            v.i > i ? i : i - v.i,
            v.j > j ? j : j - v.j
        };
    }
    
    MapPosition(size_t i, size_t j) : i{i}, j{j}
    { }
    
    MapPosition(const std::string& value)
    {
        auto reg = std::regex{","};
        auto splitted_line = std::vector<std::string>{
            std::sregex_token_iterator{value.begin(), value.end(), reg, -1},
            std::sregex_token_iterator{}
        };
        
        i = std::stoul(splitted_line[0]);
        j = std::stoul(splitted_line[1]);
    }
};

#endif /* map_position_h */
