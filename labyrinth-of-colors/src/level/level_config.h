//
//  level_config.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 19.09.21.
//

#ifndef level_config_h
#define level_config_h

#include <stdlib.h>

#include <vector>
#include <tuple>
#include <string>

#include "src/level/cell_color.h"
#include "src/components/item.h"

using LevelMap = std::vector<std::vector<CellColor>>;
using LevelItems = std::vector<std::tuple<std::string, CellColor, size_t, size_t>>;

struct LevelConfig
{
	LevelMap labyrinth;
    
    LevelItems items;
	
	size_t start_i;
	
	size_t start_j;
};

#endif /* level_config_h */
