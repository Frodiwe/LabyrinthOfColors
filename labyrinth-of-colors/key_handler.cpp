//
//  key_handler.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "key_handler.hpp"

#include <SDL2/SDL.h>

#include "events_queue.hpp"

void KeyHandler::process(const SDL_KeyboardEvent& key) const
{
	switch(key.keysym.sym)
	{
		case SDLK_LEFT:
			EventsQueue::publish(Event::K_LEFT_KEYDOWN);
			
			return;
			
		case SDLK_RIGHT:
			EventsQueue::publish(Event::K_RIGHT_KEYDOWN);
			
			return;
			
		case SDLK_UP:
			EventsQueue::publish(Event::K_UP_KEYDOWN);
			
			return;
			
		case SDLK_DOWN:
			EventsQueue::publish(Event::K_DOWN_KEYDOWN);
			
			return;
			
		default:
			return;
	}
}
