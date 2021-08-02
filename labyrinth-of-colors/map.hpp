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

class RenderComponent;
class Cell;

struct MapPosition
{
	size_t i;
	
	size_t j;
};

class Map
{
private:
	std::vector<std::vector<Cell>> cells;
	
	MapPosition player_position;
	
public:
	Map();
	
	void render();
};

#endif /* map_hpp */
