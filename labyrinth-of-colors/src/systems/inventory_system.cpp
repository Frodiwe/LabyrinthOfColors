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
#include "src/category.h"

#include <iostream>
#include <algorithm>
#include <tuple>

void InventorySystem::give_item(const entt::entity player, const entt::entity item)
{
    std::cout << "Giving item \"" << registry.get<Item>(item).name << "\" to player" << std::endl;
    
    registry.emplace<Inventory>(item);
    
    return;
}

entt::entity InventorySystem::remove_item(entt::entity player, entt::entity item)
{
    std::cout << "Removing item \"" << registry.get<Item>(item).name << "\" from player" << std::endl;
    
    registry.remove<Inventory>(item);
    
    return item;
}

bool InventorySystem::has_color(const entt::entity player, CellColor color)
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

entt::entity InventorySystem::get_nth_bucket(size_t n)
{
    auto current_i = 0;
    
    for (const auto [entity, item, category] : registry.view<Inventory, Item, Category>().each())
    {
        if (category == Category::Bucket and current_i++ == n)
        {
            return entity;
        }
    }
    
    return entt::null;
}

entt::entity InventorySystem::get_bucket_by_color(CellColor c)
{
    for (const auto [entity, item, category, color] : registry.view<Inventory, Item, Category, CellColor>().each())
    {
        if (category == Category::Bucket and c == color)
        {
            return entity;
        }
    }
    
    return entt::null;
}

size_t InventorySystem::buckets_count() const
{
    return std::count_if(registry.view<Inventory, Item, Category>().begin(), registry.view<Inventory, Item, Category>().end(), [this](const auto e) {
        return registry.get<Category>(e) == Category::Bucket;
    });
}
