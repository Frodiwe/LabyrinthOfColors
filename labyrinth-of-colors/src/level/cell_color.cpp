//
//  cell_color.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.12.21.
//

#include "cell_color.h"

const std::map<std::string, CellColor> COLOR_DECODE_MAP {
    {"0", CellColor::WALL},
    {"1", CellColor::YELLOW},
    {"2", CellColor::RED}
};

const std::map<std::string, CellColor> ITEMS_COLOR_MAP {
    {"red_paint", CellColor::RED},
};

const std::map<CellColor, std::string> CELL_TEXTURES_MAP {
    {CellColor::RED, "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/cell_red.png"},
    {CellColor::YELLOW, "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/cell_yellow.png"},
    {CellColor::WALL, ""}
};
const std::map<CellColor, std::string> ITEM_TEXTURES_MAP {
    {CellColor::RED, "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/bucket_red.png"},
};
