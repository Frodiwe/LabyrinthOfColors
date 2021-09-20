//
//  level_config.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 19.09.21.
//

#ifndef level_config_h
#define level_config_h

#include <vector>

#include "src/level/cell_color.h"

struct LevelConfig
{
	std::vector<std::vector<CellColor>> labyrinth;
};

#endif /* level_config_h */
