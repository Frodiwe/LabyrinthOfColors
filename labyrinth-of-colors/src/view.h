//
//  view.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 5.02.22.
//

#ifndef view_hpp
#define view_hpp

#include <stdlib.h>

#include "src/components/position.h"
#include "src/components/size.h"

class View
{
protected:
    Position position;
    
    Size size;
    
public:
    View(Position pos, Size size): position{pos}, size{size}
    { }
    
    bool is_inside(Position pos) const
    {
        return position.x + size.width >= pos.x and position.y + size.height >= pos.y;
    }
};

#endif /* view_hpp */
