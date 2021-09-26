//
//  player.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#ifndef player_hpp
#define player_hpp

#include <set>
#include <memory>

#include "entity.h"
#include "src/rect.hpp"
#include "src/level/cell_color.h"

class RenderComponent;
class Bag;

using Color = CellColor;

class Player : public Entity
{
private:
	Rect target_rect;
	
	std::unique_ptr<RenderComponent> render_comp;
	
	std::set<Color> bag;
	
public:
	Player(std::unique_ptr<RenderComponent>&&, Rect);
	
	~Player() = default;
	
	void render();
	
	void move(int32_t, int32_t);
	
	bool has_color(Color color) const;
	
	void add_color(Color color);
};

#endif /* player_hpp */
