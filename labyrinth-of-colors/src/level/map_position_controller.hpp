//
//  map_position_controller.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.08.21.
//

#ifndef map_position_controller_hpp
#define map_position_controller_hpp

#include <memory>
#include <array>

#include "src/event.h"
#include "src/listener.hpp"

class Map;
class Player;
class Cell;

class MapPositionController
{
private:
	size_t current_i = 0;
	
	size_t current_j = 0;
	
	Player* player;
	
	Map* map;
	
	std::array<std::unique_ptr<Listener>, 4> listeners;
	
	bool can_move(size_t, size_t);
	
	void move(size_t, size_t);
	
	void move(const Cell*, const Cell*);
	
public:
	MapPositionController(Player*, Map*, size_t, size_t);
};

#endif /* map_position_controller_hpp */

