//
//  color_factory.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.02.22.
//

#ifndef color_factory_h
#define color_factory_h

#include <vector>

#include "src/level/cell_color.h"

struct ColorFactory
{
private:
    size_t factory_size;
    
    std::vector<CellColor> colors;
    
public:
    ColorFactory(size_t factory_size = 2) : factory_size{factory_size}
    { }
    
    void add_color(CellColor color)
    {
        if (colors.size() >= factory_size) {
            colors.clear();
        }
        
        colors.emplace_back(color);
    }
    
    const std::vector<CellColor>& get_colors() const
    {
        return colors;
    }
};

#endif /* color_factory_h */
