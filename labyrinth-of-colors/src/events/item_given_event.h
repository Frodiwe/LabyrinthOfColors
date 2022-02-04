//
//  item_given_event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 26.12.21.
//

#ifndef item_given_event_h
#define item_given_event_h

#include "src/events/event.h"

struct ItemGivenEvent : public Event
{
    ItemGivenEvent(entt::entity item) : item{item}
    { }
    
    entt::entity item;
    
    std::string get_name() const override
    {
        return "ITEM_GIVEN";
    }
};

#endif /* item_given_event_h */
