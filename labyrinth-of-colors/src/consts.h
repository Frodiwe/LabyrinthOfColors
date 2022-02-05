//
//  consts.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 14.12.21.
//

#ifndef consts_h
#define consts_h

#include <map>

#include "src/level/cell_color.h"

constexpr auto FPS = 60;
constexpr auto WIDTH = 800;
constexpr auto HEIGHT = 600;
constexpr auto INVENTORY_WIDTH = 80;
constexpr auto INVENTORY_ITEM_WIDTH = INVENTORY_WIDTH;
constexpr auto INVENTORY_ITEM_HEIGHT = INVENTORY_ITEM_WIDTH;

const std::string BASE_PATH = "/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/";
const auto EXIT_TEXTURE_PATH = BASE_PATH + "exit.png";

const std::map<std::string, CellColor> COLOR_DECODE_MAP {
    {"0", CellColor::WALL},
    {"1", CellColor::YELLOW},
    {"2", CellColor::RED}
};
const std::map<std::string, CellColor> ITEMS_COLOR_MAP {
    {"red_paint", CellColor::RED},
    {"red_paint_bucket", CellColor::RED}
};

const std::map<CellColor, std::string> CELL_TEXTURES_MAP {
    {CellColor::RED, BASE_PATH + "cell_red.png"},
    {CellColor::YELLOW, BASE_PATH + "cell_yellow.png"},
    {CellColor::WALL, ""}
};
const std::map<CellColor, std::string> ITEM_TEXTURES_MAP {
    {CellColor::RED, BASE_PATH + "bucket_red.png"},
    {CellColor::YELLOW, BASE_PATH + "bucket_red.png"}
};

#endif /* consts_h */
