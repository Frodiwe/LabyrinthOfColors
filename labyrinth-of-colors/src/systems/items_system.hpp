//
//  items_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 30.11.21.
//

#ifndef items_system_hpp
#define items_system_hpp

#include <vector>

#include "third_party/entt/entity/registry.hpp"

struct MapPosition;

class ItemsSystem
{
private:
    entt::registry& registry;
    
public:
    ItemsSystem(entt::registry& r) : registry{r}
    { }
    
    std::vector<entt::entity> get_items_at(const MapPosition& position);
    
    void destroy_item(const entt::entity item);
    
    void remove_item_from_map(const entt::entity& item);
};

#endif /* items_system_hpp */
