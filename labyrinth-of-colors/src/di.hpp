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
class ItemsKit;
class ColorFactoryKit;
class MovementSystem;
class RenderSystem;
class ItemsSystem;
class InventorySystem;
class PlayerSystem;
class ColorFactorySystem;
class EventsQueue;
class CellKit;

class DI
{
private:
	static CellKit* cell_kit;
	
	static MapKit* map_kit;
	
	static PlayerKit* player_kit;
    
    static ItemsKit* items_kit;
    
    static ColorFactoryKit* color_factory_kit;
	
	static MovementSystem* movement_system;
    
    static RenderSystem* render_system;
    
    static ItemsSystem* items_system;
    
    static InventorySystem* inventory_system;
    
    static PlayerSystem* player_system;
    
    static ColorFactorySystem* color_factory_system;
    
    static EventsQueue* events_queue;
	
	static entt::registry registry;
	
public:
	static MapKit* get_map_kit();
	
	static PlayerKit* get_player_kit();
    
    static ItemsKit* get_items_kit();
    
    static ColorFactoryKit* get_color_factory_kit();
	
	static entt::registry& get_registry();
	
	static MovementSystem* get_movement_system();
    
    static RenderSystem* get_render_system();
    
    static ItemsSystem* get_items_system();
    
    static InventorySystem* get_inventory_system();
    
    static PlayerSystem* get_player_system();
    
    static ColorFactorySystem* get_color_factory_system();
    
    static EventsQueue* get_events_queue();
};

#endif /* di_hpp */
