//
//  color_blending.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.02.22.
//

#ifndef color_blending_h
#define color_blending_h

#include <set>

#include "src/level/cell_color.h"

struct ColorBlending
{
private:
    size_t max_factory_size;
    
    std::set<CellColor> colors;
    
public:
    ColorBlending(size_t max_factory_size = 3) : max_factory_size{max_factory_size}
    { }
    
    void add_color(CellColor color)
    {
        if (colors.size() >= max_factory_size) {
            colors.clear();
        }
        
        colors.emplace(color);
    }
    
    std::set<CellColor> get_colors() const
    {
        return colors;
    }
    
    void clear()
    {
        colors.clear();
    }
};

#endif /* color_blending_h */
