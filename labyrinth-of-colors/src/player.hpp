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
#include "src/render/renderable.h"
#include "src/rect.hpp"
#include "src/level/cell_color.h"

class RenderComponent;
class Bag;

using Color = CellColor;

class Player : public Entity, public Renderable
{
private:
	Rect target_rect;
	
	RenderComponent* render_comp;
	
	std::set<Color> bag;
	
public:
	Player(RenderComponent*, Rect);
	
	~Player() = default;
	
	void render();
	
	RenderableId r_id() const
	{
		return 666;
	}
	
	void move(int32_t, int32_t);
	
	bool has_color(Color color) const;
	
	void add_color(Color color);
};

#endif /* player_hpp */
