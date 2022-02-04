//
//  change_map_opacity.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 26.12.21.
//

#include "change_map_opacity.hpp"

#include "src/events/item_given_event.h"

#include "src/texture.h"
#include "src/level/tags/cell.h"
#include "src/level/cell_color.h"

void ChangeMapOpacity::operator()(Event* event)
{
    ItemGivenEvent* e = dynamic_cast<ItemGivenEvent*>(event);
    
    for (const auto [entity, texture, color] : registry.view<Cell, Texture, CellColor>().each())
    {
        if (color != registry.get<CellColor>(e->item)) {
            continue;
        }

        texture.set_alpha(255);
    }
}
