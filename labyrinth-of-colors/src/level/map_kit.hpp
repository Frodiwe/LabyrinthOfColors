//
//  map_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#ifndef map_kit_hpp
#define map_kit_hpp

#include <vector>

#include "src/level/cell_color.h"
#include "src/level/level_config.h"

class SDL_Renderer;
class Map;
class CellKit;

class MapKit
{
private:
	CellKit* cell_kit;
	
	CellAction get_cell_action(LevelActions, size_t, size_t) const;
	
public:
	MapKit(CellKit*);
	
	Map create_map(SDL_Renderer* renderer, const LevelMap& labyrinth, const LevelActions& actions);
};

#endif /* map_kit_hpp */
