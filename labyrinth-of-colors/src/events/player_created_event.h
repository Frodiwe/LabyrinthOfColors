//
//  player_created_event.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 4.02.22.
//

#ifndef player_created_event_h
#define player_created_event_h

#include "src/events/event.h"

struct PlayerCreatedEvent : public Event
{
    PlayerCreatedEvent(entt::entity player) : player{player}
    { }
    
    entt::entity player;
    
    std::string get_name() const override
    {
        return "PLAYER_CREATED";
    }
};

#endif /* player_created_event_h */
