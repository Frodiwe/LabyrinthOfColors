//
//  render_system.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 23.11.21.
//

#include "render_system.hpp"

#include <SDL2/SDL.h>

#include "src/components/position.h"
#include "src/components/size.h"
#include "src/tags/player.h"
#include "src/level/tags/cell.h"
#include "src/texture.h"
#include "src/coord.hpp"

void RenderSystem::render_map(SDL_Renderer* renderer)
{
    for (const auto [entity, texture, pos, size] : registry.view<Cell, Texture, Position, Size>().each())
    {
        texture.render(renderer, {Coord::start_x + pos.x, Coord::start_y + pos.y, size.width, size.height});
    }
}

void RenderSystem::render_player(SDL_Renderer* renderer)
{
    for (const auto [entity, texture, pos, size] : registry.view<Player, Texture, Position, Size>().each())
    {
        texture.render(renderer, {pos.x, pos.y, size.width, size.height});
    }
}
