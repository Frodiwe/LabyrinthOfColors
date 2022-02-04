//
//  change_map_opacity.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 26.12.21.
//

#include "change_map_opacity.hpp"

#include "src/events/item_given_event.h"

void ChangeMapOpacity::operator()(Event* event)
{
    ItemGivenEvent* e = dynamic_cast<ItemGivenEvent*>(event);
}
