//
//  items_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 30.11.21.
//

#include "items_kit.hpp"

#include <string>

#include "src/consts.h"
#include "src/texture.h"
#include "src/category.h"

#include "src/components/map_position.h"
#include "src/components/item.h"
#include "src/components/size.h"
#include "src/components/position.h"
#include "src/level/cell_color.h"

entt::entity ItemsKit::create_item(const std::string& name, Category category, const CellColor& color)
{
    const auto item = registry.create();
    
    registry.emplace<Item>(item, name);
    registry.emplace<CellColor>(item, color);
    registry.emplace<Texture>(item, Texture(Consts::item_textures_map.at(color), {0, 0, 32, 32}));
    registry.emplace<Size>(item, 50ul, 50ul);
    registry.emplace<Category>(item, category);
    
    return item;
}

entt::entity ItemsKit::create_item(const std::string& name, Category category, const CellColor& color, const MapPosition& map_position, const Position& position)
{
    const auto item = create_item(name, category, color);
    
    registry.emplace<MapPosition>(item, map_position);
    registry.emplace<Position>(item, position);
    
    return item;
}
