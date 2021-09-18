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
class Entity;
class Cell;

class MapPositionController
{
private:
	size_t current_i = 0;
	
	size_t current_j = 0;
	
	Entity* entity;
	
	Map* map;
	
	std::array<std::unique_ptr<Listener>, 4> listeners;
	
	void move(size_t, size_t);
	
	void move_to_cell(Cell*);
	
public:
	MapPositionController(Entity*, Map*);
};

#endif /* map_position_controller_hpp */

