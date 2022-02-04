//
//  give_base_inventory_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 4.02.22.
//

#include "give_base_inventory_listener.hpp"

#include "src/events/player_created_event.h"
#include "src/events/item_given_event.h"

#include "src/events_queue.hpp"

#include "src/systems/movement_system.hpp"
#include "src/systems/render_system.hpp"
#include "src/systems/items_system.hpp"
#include "src/systems/inventory_system.hpp"

#include "src/items_kit.hpp"

#include "src/level/cell_color.h"

void GiveBaseInventoryListener::operator()(Event *event)
{
    PlayerCreatedEvent* e = dynamic_cast<PlayerCreatedEvent*>(event);
    auto item = items_kit->create_item("yellow_paint", CellColor::YELLOW);
    
    inventory_system->give_item(e->player, item);
    
    events_queue->publish<ItemGivenEvent>(item);
    
    items_system->remove_item_from_map(item);
}
