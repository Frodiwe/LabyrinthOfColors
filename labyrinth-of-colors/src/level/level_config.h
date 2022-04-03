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
#include "src/components/map_position.h"
#include "src/category.h"

using LevelMap = std::vector<std::vector<CellColor>>;
using LevelItems = std::vector<std::tuple<std::string, Category, CellColor, MapPosition>>;
using LevelFactories = std::vector<MapPosition>;

struct LevelConfig
{
	LevelMap labyrinth;
    
    LevelItems items;
    
    MapPosition start;
    
    MapPosition exit;
    
    LevelFactories factories;
};

#endif /* level_config_h */
