//
//  give_base_inventory_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 4.02.22.
//

#ifndef give_base_inventory_listener_hpp
#define give_base_inventory_listener_hpp

#include "src/listeners/listener.h"

#include "third_party/entt/entity/registry.hpp"

class InventorySystem;
class ItemsSystem;
class EventsQueue;
class ItemsKit;

class GiveBaseInventoryListener : public Listener
{
private:
    entt::registry& registry;
    
    InventorySystem* inventory_system;
    
    ItemsSystem* items_system;
    
    ItemsKit* items_kit;
    
    EventsQueue* events_queue;
    
public:
    GiveBaseInventoryListener(entt::registry& registry, EventsQueue* events_queue, InventorySystem* inventory_system, ItemsSystem* items_system, ItemsKit* items_kit)
    : registry{registry}, inventory_system{inventory_system}, items_system{items_system}, events_queue{events_queue}, items_kit{items_kit}
    { }
    
    void operator()(Event* event);
};

#endif /* give_base_inventory_listener_hpp */
