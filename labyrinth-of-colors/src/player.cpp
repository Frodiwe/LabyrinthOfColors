//
//  player.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#include "player.hpp"

#include "src/render_component.h"

Player::Player(RenderComponent* render_comp, Rect target_rect):
	render_comp{render_comp},
	target_rect{target_rect},
	bag{CellColor::YELLOW}
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

bool Player::has_color(Color color) const
{
	return bag.find(color) != bag.end();
}

void Player::add_color(Color color)
{
	bag.emplace(color);
}
