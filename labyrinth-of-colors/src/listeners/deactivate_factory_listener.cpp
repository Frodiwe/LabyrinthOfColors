//
//  deactivate_factory_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#include "deactivate_factory_listener.hpp"

#include "src/events/move_out_event.h"
#include "src/systems/blending_system.hpp"
#include "src/components/color_factory.h"

void DeactivateFactoryListener::operator()(Event *event)
{
    MoveOutEvent* e = dynamic_cast<MoveOutEvent*>(event);
    
    if (registry.all_of<ColorFactory>(e->from_cell))
    {
        blending_system->deactivate();
    }
}
