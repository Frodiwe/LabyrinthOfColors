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
#include "src/category.h"

class Consts
{
private:
    static inline const auto base_path = std::string{"/Volumes/Development/gamedev/projects/labyrinth-of-colors/labyrinth-of-colors/assets/"};
    
public:
    static constexpr auto fps = 60;
    static constexpr auto window_width = 800;
    static constexpr auto window_height = 600;
    static constexpr auto inventory_item_width = 80;
    static constexpr auto inventory_item_height = inventory_item_width;
    
    static inline const auto exit_texture_path = base_path + "exit.png";

    static inline const auto color_map = std::map<std::string, CellColor>{
        {"0", CellColor::WALL},
        {"1", CellColor::YELLOW},
        {"2", CellColor::RED}
    };
    static inline const auto category_map = std::map<std::string, Category>{
        {"paint", Category::Paint},
        {"bucket", Category::Bucket}
    };

    static inline const std::map<CellColor, std::string> cell_textures_map {
        {CellColor::RED, base_path + "cell_red.png"},
        {CellColor::YELLOW, base_path + "cell_yellow.png"},
        {CellColor::WALL, ""}
    };
    static inline const std::map<CellColor, std::string> item_textures_map {
        {CellColor::RED, base_path + "bucket_red.png"},
        {CellColor::YELLOW, base_path + "bucket_yellow.png"}
    };
};

#endif /* consts_h */
