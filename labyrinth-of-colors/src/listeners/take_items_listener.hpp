//
//  take_items_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef take_items_listener_hpp
#define take_items_listener_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/listeners/listener.h"

class ItemsSystem;
class InventorySystem;
class PlayerSystem;
class EventsQueue;

class TakeItemsListener : public Listener
{
private:
    entt::registry& registry;
    
    ItemsSystem* items_system;
    
    InventorySystem* inventory_system;
    
    PlayerSystem* player_system;
    
    EventsQueue* events_queue;
    
public:
    TakeItemsListener(entt::registry& registry, EventsQueue* events_queue, PlayerSystem* player_system, ItemsSystem* items_system, InventorySystem* inventory_system)
    : registry{registry}, events_queue{events_queue}, player_system{player_system}, items_system{items_system}, inventory_system{inventory_system}
    { }
    
    void operator()(Event* event);
};

#endif /* take_items_listener_hpp */
