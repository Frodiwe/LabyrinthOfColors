//
//  map.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef map_h
#define map_h

#include <vector>

struct Position
{
	size_t i;
	
	size_t j;
}

class Map
{
private:
	std::vector<std::vector<Cell>> cells;
	
	Position player_position;
}

#endif /* map_h */
