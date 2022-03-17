//
//  select_inventory_item_event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.02.22.
//

#ifndef select_inventory_item_event_h
#define select_inventory_item_event_h

#include "src/events/event.h"

struct SelectInventoryItemEvent : public Event
{
    size_t inventory_index;
    
    SelectInventoryItemEvent(size_t i) : inventory_index{i}
    { }
    
    std::string get_name() const override
    {
        return "SELECT_INVENTORY_ITEM";
    }
};

#endif /* select_inventory_item_event_h */
