//
//  level_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.09.21.
//

#include "level_kit.hpp"

#include <memory>

#include "src/level/level.hpp"
#include "src/level/map.hpp"
#include "src/level/cell.hpp"
#include "src/level/map_position_controller.hpp"
#include "src/player.hpp"
#include "src/entity.h"
#include "src/texture.h"
#include "src/render_component.h"

Level LevelKit::create_test_level(SDL_Renderer* renderer, std::string_view cell_texture_path) const
{
	auto map = std::shared_ptr<Map>{new Map{
		{
		   {
			   Cell{std::unique_ptr<RenderComponent>{new Texture(renderer, cell_texture_path)}},
		   },
		},
		0, 0
	}};
	auto player = std::shared_ptr<Entity>{new Player{0, 0}};
	
	return Level{player, map, std::unique_ptr<MapPositionController>{new MapPositionController{player, map}}};
}
