//
//  blend_colors_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.02.22.
//

#include "blend_colors_listener.hpp"

#include "src/consts.h"

#include "src/systems/color_factory_system.hpp"
#include "src/systems/items_system.hpp"
#include "src/systems/inventory_system.hpp"
#include "src/systems/player_system.hpp"

#include "src/items_kit.hpp"
#include "src/category.h"

#include "src/components/color_blending.h"

#include "src/events/submit_event.h"

void BlendColorsListener::operator()(Event *event)
{
    SubmitEvent* e = dynamic_cast<SubmitEvent*>(event);
    
    auto get_blender = [&] {
        return registry.get<ColorBlending>(color_factory_system->get_active_factory());
    };
    
    if (not color_factory_system->has_active_factory())
    {
        return;
    }
    
    if (get_blender().get_colors().size() < 2)
    {
        return;
    }
    
    const auto blended_color = color_factory_system->blend(get_blender().get_colors());
    
    inventory_system->give_item(player_system->get_player(), items_kit->create_item("mixed_paint", Category::Paint, blended_color));
    inventory_system->give_item(player_system->get_player(), items_kit->create_item("mixed_paint_bucket", Category::Bucket, blended_color));
    
    for (const auto& color : get_blender().get_colors())
    {
        const auto bucket = inventory_system->get_bucket_by_color(color);
        
        inventory_system->remove_item(player_system->get_player(), bucket);
        items_system->destroy_item(bucket);
    }
    
    registry.replace<ColorBlending>(color_factory_system->get_active_factory());
}
