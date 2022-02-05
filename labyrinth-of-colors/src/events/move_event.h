//
//  move_event.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 4.12.21.
//

#ifndef move_event_hpp
#define move_event_hpp

#include <stdlib.h>

#include "src/events/event.h"

struct MoveEvent : public Event
{
    int32_t i_diff;
    
    int32_t j_diff;
    
    MoveEvent(int32_t i, int32_t j) : i_diff{i}, j_diff{j}
    { }
    
    std::string get_name() const override
    {
        return "MOVE";
    }
};


#endif /* move_event_hpp */
