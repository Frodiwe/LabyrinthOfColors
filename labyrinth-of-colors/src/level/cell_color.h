//
//  cell_color.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 19.09.21.
//

#ifndef cell_color_h
#define cell_color_h

#include <map>
#include <string>

enum class CellColor
{
	YELLOW,
	RED,
	WALL,
};

extern const std::map<std::string, CellColor> COLOR_DECODE_MAP;

extern const std::map<std::string, CellColor> ITEMS_COLOR_MAP;

#endif /* cell_color_h */
