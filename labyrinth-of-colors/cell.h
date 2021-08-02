//
//  cell.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 2.08.21.
//

#ifndef cell_h
#define cell_h

enum class CellColor
{
	RED,
	YELLOW,
}

class Cell
{
public:
	bool is_wall();
	
	CellColor get_color();
}

#endif /* cell_h */
