//
//  player.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#include "player.hpp"

#include "src/render_component.h"

Player::Player(std::unique_ptr<RenderComponent>&& render_comp, Rect target_rect):
	render_comp{std::move(render_comp)},
	target_rect{target_rect}
{ }

void Player::move(int32_t to_x, int32_t to_y)
{
	target_rect.x = to_x;
	target_rect.y = to_y;
}

void Player::render()
{
	render_comp->render(target_rect);
}
