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

#include "event.h"

class Map;
class Entity;
class Cell;
struct Listener;

class MapPositionController
{
private:
	size_t i;
	
	size_t j;
	
	std::unique_ptr<Entity> entity;
	
	std::unique_ptr<Map> map;
	
	std::array<std::unique_ptr<Listener>, 4> listeners {
		std::make_unique<Listener>(Event::K_UP_KEYDOWN, [this] { move(i + 1, j); }),
		std::make_unique<Listener>(Event::K_DOWN_KEYDOWN, [this] { move(i - 1, j); }),
		std::make_unique<Listener>(Event::K_LEFT_KEYDOWN, [this] { move(i, j - 1); }),
		std::make_unique<Listener>(Event::K_RIGHT_KEYDOWN, [this] { move(i, j + 1); })
	};
	
	void move(size_t, size_t);
	
	void move_to_cell(const Cell&);
	
public:
	MapPositionController(std::unique_ptr<Entity>, std::unique_ptr<Map>);
};

#endif /* map_position_controller_hpp */

