//
//  items_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 30.11.21.
//

#ifndef items_system_hpp
#define items_system_hpp

#include "third_party/entt/entity/registry.hpp"

struct MapPosition;

class ItemsSystem
{
private:
    entt::registry& registry;
    
public:
    ItemsSystem(entt::registry& r) : registry{r}
    { }
    
    entt::entity get_item(const MapPosition& position);
    
    void remove_item(const entt::entity& item);
};

#endif /* items_system_hpp */
