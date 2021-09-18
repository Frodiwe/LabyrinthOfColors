//
//  player.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#ifndef player_hpp
#define player_hpp

#include <array>
#include <memory>

#include "entity.h"
#include "src/rect.hpp"

class RenderComponent;

class Player : public Entity
{
private:
	Rect target_rect;
	
	std::unique_ptr<RenderComponent> render_comp;
	
public:
	Player(std::unique_ptr<RenderComponent>&&, Rect);
	
	~Player() = default;
	
	void render();
	
	void move(int32_t, int32_t);
};

#endif /* player_hpp */
