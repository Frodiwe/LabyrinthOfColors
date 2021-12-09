//
//  items_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 30.11.21.
//

#include "items_kit.hpp"

#include <string>

#include "src/components/map_position.h"
#include "src/components/item.h"
#include "src/level/cell_color.h"

entt::entity ItemsKit::create_item(const std::string& name, const CellColor& color, const MapPosition& position)
{
    const auto item = registry.create();
    
    registry.emplace<Item>(item, name);
    registry.emplace<MapPosition>(item, position);
    registry.emplace<CellColor>(item, color);
    
    return item;
}
