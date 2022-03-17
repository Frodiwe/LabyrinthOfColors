//
//  key_handler.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "key_handler.hpp"

#include <string>
#include "SDL2/SDL.h"

#include "events_queue.hpp"

#include "src/events/move_event.h"
#include "src/events/select_inventory_item_event.h"
#include "src/events/submit_event.h"


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
            
        case SDLK_1:
        case SDLK_2:
        case SDLK_3:
        case SDLK_4:
        case SDLK_5:
        case SDLK_6:
        case SDLK_7:
        case SDLK_8:
            events_queue->publish<SelectInventoryItemEvent>(static_cast<size_t>(key.keysym.sym - '0') - 1);
            
            return;
            
        case SDLK_RETURN:
            events_queue->publish<SubmitEvent>();
            
            return;
			
		default:
			return;
	}
}
