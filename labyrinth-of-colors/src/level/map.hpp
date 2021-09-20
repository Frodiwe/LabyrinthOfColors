//
//  map.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef map_hpp
#define map_hpp

#include <vector>
#include <memory>

#include "src/events_queue.hpp"
#include "src/event.h"
#include "src/entity.h"

class RenderComponent;
class Cell;

class Map
{
private:
	std::vector<std::vector<Cell*>> cells;
	
public:
	Map(std::vector<std::vector<Cell*>>&&);
	
	void render();
	
	size_t col_count() const;
	
	size_t row_count() const;
	
	Cell* at(size_t i, size_t j);
};

#endif /* map_hpp */
