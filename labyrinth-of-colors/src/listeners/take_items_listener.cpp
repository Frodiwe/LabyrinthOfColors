//
//  take_items_listener.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#include "src/listeners/take_items_listener.hpp"

#include "src/events/move_in_event.h"
#include "src/events/item_given_event.h"

#include "src/systems/items_system.hpp"
#include "src/systems/inventory_system.hpp"
#include "src/systems/player_system.hpp"

#include "src/components/map_position.h"
#include "src/events_queue.hpp"

void TakeItemsListener::operator()(Event *event)
{
    MoveInEvent* e = dynamic_cast<MoveInEvent*>(event);
    
    for (const auto& item : items_system->get_items_at(registry.get<MapPosition>(e->to_cell)))
    {
        inventory_system->give_item(player_system->get_player(), item);
        events_queue->publish<ItemGivenEvent>(item);
        items_system->remove_item_from_map(item);
    }
}
