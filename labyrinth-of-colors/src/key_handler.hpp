//
//  key_handler.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef key_handler_hpp
#define key_handler_hpp

#include "src/events_queue.hpp"

class SDL_KeyboardEvent;

class KeyHandler
{
private:
    EventsQueue* events_queue;
    
public:
    KeyHandler(EventsQueue* eq) : events_queue{eq}
    { }
    
	void process(const SDL_KeyboardEvent& key) const;
};

#endif /* key_handler_hpp */
