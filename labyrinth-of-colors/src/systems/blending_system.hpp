//
//  blending_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.02.22.
//

#ifndef blending_system_hpp
#define blending_system_hpp

#include <vector>

#include "src/level/cell_color.h"

class BlendingSystem
{
private:
    bool _is_active = false;
    
public:
    void activate();
    
    void deactivate();
    
    bool is_active();
    
    CellColor blend(const std::vector<CellColor>& colors);
};

#endif /* blending_system_hpp */
