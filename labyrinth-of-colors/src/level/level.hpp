//
//  level.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#ifndef level_hpp
#define level_hpp

#include <memory>

#include "src/render/renderable.h"

class Map;
class Player;
class MapPositionController;

class Level : public Renderable
{
private:
	Map* map;
	
	Player* player;
	
	MapPositionController* map_position_controller;
	
public:
	Level(Player*, Map*, MapPositionController*);
	
	void render();
	
	RenderableId r_id() const;
};

#endif /* level_hpp */
