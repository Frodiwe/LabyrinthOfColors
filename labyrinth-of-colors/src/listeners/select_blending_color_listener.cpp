//
//  select_blending_color_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.02.22.
//

#include "select_blending_color_listener.hpp"

#include "src/events/select_inventory_item_event.h"

#include "src/systems/color_factory_system.hpp"
#include "src/systems/inventory_system.hpp"

#include "src/components/color_blending.h"

void SelectBlendingColorListener::operator()(Event *event)
{
    SelectInventoryItemEvent* e = dynamic_cast<SelectInventoryItemEvent*>(event);
    
    if (not color_factory_system->has_active_factory())
    {
        return;
    }
    
    if (inventory_system->buckets_count() <= e->inventory_index)
    {
        return;
    }
    
    registry.get<ColorBlending>(color_factory_system->get_active_factory())
        .add_color(registry.get<CellColor>(inventory_system->get_nth_bucket(e->inventory_index)));
    
    std::cout << "Color selected (inventory index is " << e->inventory_index << "). Factory size is " << registry.get<ColorBlending>(color_factory_system->get_active_factory()).get_colors().size() << std::endl;
}
