//
//  di.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#ifndef di_hpp
#define di_hpp

#include <memory>
#include <optional>

#include "third_party/entt/entity/registry.hpp"

class RenderList;
class RenderController;
class MapKit;
class PlayerKit;
class MovementSystem;
class RenderSystem;
class CellKit;

class DI
{
private:
	static CellKit* cell_kit;
	
	static MapKit* map_kit;
	
	static PlayerKit* player_kit;
	
	static MovementSystem* movement_system;
    
    static RenderSystem* render_system;
	
	static entt::registry registry;
	
public:
	static MapKit* get_map_kit();
	
	static PlayerKit* get_player_kit();
	
	static entt::registry& get_registry();
	
	static MovementSystem* get_movement_system();
    
    static RenderSystem* get_render_system();
};

#endif /* di_hpp */
