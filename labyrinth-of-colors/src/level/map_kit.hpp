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

class SDL_Renderer;
class Map;
class CellKit;

class MapKit
{
private:
	CellKit* cell_kit;
	
public:
	MapKit(CellKit*);
	
	Map* create_map(SDL_Renderer*, const std::vector<std::vector<CellColor>>&);
};

#endif /* map_kit_hpp */
