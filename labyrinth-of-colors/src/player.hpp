//
//  player.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#ifndef player_hpp
#define player_hpp

#include <array>

#include "entity.h"

class Player : public Entity
{
private:
	int32_t x;
	
	int32_t y;
	
public:
	Player(int32_t, int32_t);
	
	~Player() = default;
	
	void render();
	
	void move(int32_t, int32_t);
};

#endif /* player_hpp */
