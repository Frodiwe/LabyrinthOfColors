//
//  inventory_system.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 1.12.21.
//

#include "inventory_system.hpp"

#include "src/level/cell_color.h"
#include "src/components/item.h"
#include "src/components/inventory.h"

#include <iostream>

void InventorySystem::give_item(const entt::entity& player, const entt::entity& item)
{
    std::cout << "Giving item \"" << registry.get<Item>(item).name << "\" to player" << std::endl;
    
    registry.emplace<Inventory>(item);
    
    return;
}

bool InventorySystem::has_color(const entt::entity& player, CellColor color)
{
    for (const auto [entity, item, c] : registry.view<Inventory, Item, CellColor>().each())
    {
        if (c == color)
        {
            return true;
        }
    }
    
    return false;
}
