//
//  key_handler.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "key_handler.hpp"

#include <SDL2/SDL.h>

#include "events_queue.hpp"
#include "src/events/move_event.h"

void KeyHandler::process(const SDL_KeyboardEvent& key) const
{
	switch(key.keysym.sym)
	{
		case SDLK_LEFT:
			events_queue->publish<MoveEvent>(0, -1);
			
			return;
			
		case SDLK_RIGHT:
            events_queue->publish<MoveEvent>(0, 1);
			
			return;
			
		case SDLK_UP:
            events_queue->publish<MoveEvent>(-1, 0);
			
			return;
			
		case SDLK_DOWN:
            events_queue->publish<MoveEvent>(1, 0);
			
			return;
			
		default:
			return;
	}
}
