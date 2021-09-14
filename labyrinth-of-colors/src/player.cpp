//
//  player.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#include "player.hpp"

Player::Player(int32_t x, int32_t y):
	x{x},
	y{y}
{ }

void Player::move(int32_t to_x, int32_t to_y)
{
	x = to_x;
	y = to_y;
}

void Player::render()
{
	
}
