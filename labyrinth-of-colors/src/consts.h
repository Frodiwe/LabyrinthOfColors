//
//  consts.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 14.12.21.
//

#ifndef consts_h
#define consts_h

#include <map>
#include <set>

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
    static constexpr auto inventory_item_width = 60;
    static constexpr auto inventory_item_height = inventory_item_width;
    
    static inline const auto exit_texture_path = base_path + "exit.png";
    static inline const auto color_factory_texture_path = base_path + "color_factory.png";

    static inline const auto color_map = std::map<std::string, CellColor>{
        {"0", CellColor::WALL},
        {"1", CellColor::YELLOW},
        {"2", CellColor::RED},
        {"3", CellColor::BLUE},
        {"4", CellColor::WHITE},
        {"5", CellColor::BLACK},
        {"7", CellColor::GREEN},
        {"10", CellColor::SAND},
        {"25", CellColor::RAINBOW}
    };
    static inline const auto category_map = std::map<std::string, Category>{
        {"paint", Category::Paint},
        {"bucket", Category::Bucket}
    };

    static inline const std::map<CellColor, std::string> cell_textures_map {
        {CellColor::RED, base_path + "cell_red.png"},
        {CellColor::YELLOW, base_path + "cell_yellow.png"},
        {CellColor::BLUE, base_path + "cell_blue.png"},
        {CellColor::WHITE, base_path + "cell_white.png"},
        {CellColor::BLACK, base_path + "cell_black.png"},
        {CellColor::GREEN, base_path + "cell_green.png"},
        {CellColor::SAND, base_path + "cell_sand.png"},
        {CellColor::RAINBOW, base_path + "cell_rainbow.png"},
        {CellColor::WALL, ""}
    };
    static inline const std::map<Category, std::map<CellColor, std::string>> item_textures_map {
        {Category::Bucket, {
            {CellColor::RED, base_path + "bucket_red.png"},
            {CellColor::YELLOW, base_path + "bucket_yellow.png"},
            {CellColor::BLUE, base_path + "bucket_blue.png"},
            {CellColor::WHITE, base_path + "bucket_white.png"},
            {CellColor::BLACK, base_path + "bucket_black.png"},
            {CellColor::GREEN, base_path + "bucket_green.png"},
            {CellColor::SAND, base_path + "bucket_sand.png"},
        }},
        {Category::Paint, {
            {CellColor::RED, base_path + "paint_red.png"},
            {CellColor::YELLOW, base_path + "paint_yellow.png"},
            {CellColor::BLUE, base_path + "paint_blue.png"},
            {CellColor::WHITE, base_path + "paint_white.png"},
            {CellColor::BLACK, base_path + "paint_black.png"},
            {CellColor::GREEN, base_path + "paint_green.png"},
            {CellColor::SAND, base_path + "paint_sand.png"},
            {CellColor::RAINBOW, base_path + "paint_rainbow.png"},
        }}
    };
    
    static inline const std::map<CellColor, std::set<CellColor>> color_mixes {
//        {CellColor::WHITE, {CellColor::RED, CellColor::YELLOW, CellColor::BLUE}},
        {CellColor::BLACK, {CellColor::RED, CellColor::YELLOW, CellColor::BLUE}},
        {CellColor::GREEN, {CellColor::YELLOW, CellColor::BLUE}},
        {CellColor::SAND, {CellColor::YELLOW, CellColor::BLACK}}
    };
};

#endif /* consts_h */
