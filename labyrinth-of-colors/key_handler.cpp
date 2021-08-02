//
//  key_handler.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#include "key_handler.hpp"

#include <SDL2/SDL.h>

void KeyHandler::process(const SDL_KeyboardEvent& key) const
{
	switch(key.keysym.sym)
	{
		case SDLK_LEFT:
			return;
			
		case SDLK_RIGHT:
			return;
			
		case SDLK_UP:
			return;
			
		case SDLK_DOWN:
			return;
			
		default:
			return;
	}
}
