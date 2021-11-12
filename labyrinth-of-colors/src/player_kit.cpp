//
//  player_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.11.21.
//

#include "player_kit.hpp"

#include "src/player.hpp"
#include "src/texture.h"
#include "src/render_component.h"

Player PlayerKit::create_player(SDL_Renderer* renderer, int32_t start_x, int32_t start_y) const
{
	return Player{
		new Texture{
			renderer,
			"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/wizard-idle.png",
			{0, 0, 32, 32}
		},
		{
			start_x,
			start_y,
			100,
			100
		},
	};
}
