//
//  move_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 5.12.21.
//

#ifndef move_listener_hpp
#define move_listener_hpp

#include "src/listeners/listener.h"

#include "third_party/entt/entity/registry.hpp"

class MovementSystem;
class InventorySystem;
class ItemsSystem;
class PlayerSystem;
class MoveEvent;
class EventsQueue;
struct MapPosition;

class MoveListener : public Listener
{
private:
    entt::registry& registry;
    
    MovementSystem* movement_system;
    
    InventorySystem* inventory_system;
    
    ItemsSystem* items_system;
    
    PlayerSystem* player_system;
    
    EventsQueue* events_queue;
    
    entt::entity get_cell(const MapPosition& at) const;
    
    MapPosition get_target_pos(MapPosition curr_pos, MapPosition abs_diff, bool backward);

    MapPosition get_abs_diff(int32_t i_diff, int32_t j_diff);
    
public:
    MoveListener(entt::registry& registry, EventsQueue* events_queue, PlayerSystem* player_system, MovementSystem* movement_system, InventorySystem* inventory_system, ItemsSystem* items_system)
    : registry{registry}, player_system{player_system}, movement_system{movement_system}, inventory_system{inventory_system}, items_system{items_system}, events_queue{events_queue}
    { }
    
    void operator()(Event* event);
};

#endif /* move_listener_hpp */
