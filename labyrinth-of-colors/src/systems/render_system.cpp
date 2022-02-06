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
#include "src/components/item.h"
#include "src/components/inventory.h"
#include "src/tags/player.h"

#include "src/level/tags/cell.h"
#include "src/level/components/exit.h"

#include "src/texture.h"
#include "src/coord.hpp"
#include "src/view.h"
#include "src/game.hpp"
#include "src/consts.h"
#include "src/category.h"

void RenderSystem::render_map(SDL_Renderer* renderer)
{
    for (const auto [entity, texture, pos, size] : registry.view<Cell, Texture, Position, Size>().each())
    {        
        texture.render(renderer, {Coord::start_x + pos.x, Coord::start_y + pos.y, size.width, size.height});
        
        if (registry.all_of<Exit>(entity))
        {
            registry.get<Exit>(entity).texture.render(renderer, {Coord::start_x + pos.x, Coord::start_y + pos.y, size.width, size.height});
        }
    }
}

void RenderSystem::render_player(SDL_Renderer* renderer)
{
    for (const auto [entity, texture, pos, size] : registry.view<Player, Texture, Position, Size>().each())
    {
        texture.render(renderer, {pos.x, pos.y, size.width, size.height});
    }
}

void RenderSystem::render_items(SDL_Renderer* renderer)
{
    for (const auto [entity, _, texture, pos, size] : registry.view<Item, Texture, Position, Size>().each())
    {
        texture.render(renderer, {Coord::start_x + pos.x, Coord::start_y + pos.y, size.width, size.height});
    }
}

void RenderSystem::render_inventory(SDL_Renderer* renderer)
{
    auto y = -INVENTORY_ITEM_HEIGHT;
    
    for (const auto [entity, _, category, texture] : registry.view<Inventory, Item, Category, Texture>().each())
    {
        if (category == Category::Bucket) {
            continue;
        }
        
        texture.render(renderer, {WIDTH - INVENTORY_ITEM_WIDTH, y += INVENTORY_ITEM_HEIGHT, INVENTORY_ITEM_WIDTH, INVENTORY_ITEM_HEIGHT});
    }
    
    auto x = -INVENTORY_ITEM_WIDTH;
    
    for (const auto [entity, _, category, texture] : registry.view<Inventory, Item, Category, Texture>().each())
    {
        if (category != Category::Bucket) {
            continue;
        }
        
        texture.render(renderer, {x += INVENTORY_ITEM_WIDTH, HEIGHT - INVENTORY_ITEM_HEIGHT, INVENTORY_ITEM_WIDTH, INVENTORY_ITEM_HEIGHT});
    }
}
