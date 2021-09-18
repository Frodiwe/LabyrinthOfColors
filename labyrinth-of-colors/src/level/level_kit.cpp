//
//  level_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.09.21.
//

#include "level_kit.hpp"

#include <SDL2/SDL.h>

#include <memory>

#include "src/level/level.hpp"
#include "src/level/map.hpp"
#include "src/level/cell.hpp"
#include "src/level/map_position_controller.hpp"
#include "src/player.hpp"
#include "src/entity.h"
#include "src/texture.h"
#include "src/render_component.h"
#include "src/level/map_kit.hpp"

LevelKit::LevelKit(MapKit* map_kit):
	map_kit{map_kit}
{ }

Level LevelKit::create_level(SDL_Renderer* renderer) const
{
	auto map = map_kit->create_map(renderer);
	auto player = new Player{
		std::unique_ptr<RenderComponent>{
			new Texture{
				renderer,
				"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/wizard-idle.png",
				{0, 0, 32, 32}
			}
		},
		{0, 0, 32, 32}
	};
	
	return Level{player, map, new MapPositionController{player, map}};
}
