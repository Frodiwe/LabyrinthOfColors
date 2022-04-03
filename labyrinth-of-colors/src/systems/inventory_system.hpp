//
//  inventory_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 1.12.21.
//

#ifndef inventory_system_hpp
#define inventory_system_hpp

#include "third_party/entt/entity/registry.hpp"

enum class CellColor;
class EventsQueue;

class InventorySystem
{
private:
    entt::registry& registry;
    
    EventsQueue* events_queue;
    
public:
    InventorySystem(entt::registry& r, EventsQueue* events_queue) : registry{r}, events_queue{events_queue}
    { }
    
    void give_item(const entt::entity player, const entt::entity item);
    
    entt::entity remove_item(const entt::entity player, const entt::entity item);
    
    entt::entity get_nth_bucket(size_t n);
    
    bool has_color(const entt::entity player, CellColor color);
    
    entt::entity get_bucket_by_color(CellColor color);
    
    size_t buckets_count() const;
};
#endif /* inventory_system_hpp */
