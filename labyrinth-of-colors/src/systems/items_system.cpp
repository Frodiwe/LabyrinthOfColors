//
//  items_system.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 30.11.21.
//

#include "items_system.hpp"

#include "src/components/map_position.h"
#include "src/components/item.h"

#include <iostream>

entt::entity ItemsSystem::get_item(const MapPosition& position)
{
    std::cout << "Getting item at " << position.i << ", " << position.j << std::endl;
    
    for (const auto [e, item, pos] : registry.view<Item, MapPosition>().each())
    {
        if (pos != position)
        {
            continue;
        }
        
        return e;
    }
    
    return entt::null;
}

void ItemsSystem::remove_item(const entt::entity& item)
{
    registry.destroy(item);
}
