//
//  map_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#ifndef map_kit_hpp
#define map_kit_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/level/cell_color.h"
#include "src/level/level_config.h"

class SDL_Renderer;
class Map;
class CellKit;

class MapKit
{
private:
	entt::registry& registry;
	
	CellKit* cell_kit;
	
public:
	MapKit(entt::registry&, CellKit*);
	
	void create_map(const LevelMap& labyrinth);
};

#endif /* map_kit_hpp */
