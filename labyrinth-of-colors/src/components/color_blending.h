//
//  color_blending.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.02.22.
//

#ifndef color_blending_h
#define color_blending_h

#include <vector>

#include "src/level/cell_color.h"

struct ColorBlending
{
private:
    size_t factory_size;
    
    std::vector<CellColor> colors;
    
public:
    ColorBlending(size_t factory_size = 2) : factory_size{factory_size}
    { }
    
    void add_color(CellColor color)
    {
        if (colors.size() >= factory_size) {
            colors.clear();
        }
        
        colors.emplace_back(color);
    }
    
    std::vector<CellColor> get_colors() const
    {
        return colors;
    }
    
    void clear()
    {
        colors.clear();
    }
};

#endif /* color_blending_h */
