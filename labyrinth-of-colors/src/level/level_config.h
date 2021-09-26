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

#include "src/level/cell_color.h"
#include "src/level/cell_action.h"

using LevelMap = std::vector<std::vector<CellColor>>;
using LevelActions = std::vector<std::tuple<CellAction, size_t, size_t>>;

struct LevelConfig
{
	LevelMap labyrinth;
	
	LevelActions actions;
	
	size_t start_i;
	
	size_t start_j;
};

#endif /* level_config_h */
