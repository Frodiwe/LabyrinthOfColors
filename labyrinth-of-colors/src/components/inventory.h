//
//  inventory.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.12.21.
//

#ifndef inventory_h
#define inventory_h

#include <algorithm>
#include <vector>

#include "src/level/cell_color.h"

class Inventory
{
private:
    std::vector<CellColor> items;
    
public:
    Inventory(const std::vector<CellColor>& items) : items{items}
    { }
    
    void add(CellColor color)
    {
        items.emplace_back(color);
    }
    
    bool has(CellColor color) const
    {
        return std::find(items.begin(), items.end(), color) != items.end();
    }
};

#endif /* inventory_h */
