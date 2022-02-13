//
//  blending_system.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.02.22.
//

#include "blending_system.hpp"

void BlendingSystem::activate()
{
    _is_active = true;
}

void BlendingSystem::deactivate()
{
    _is_active = false;
}

bool BlendingSystem::is_active()
{
    return _is_active;
}

CellColor BlendingSystem::blend(const std::vector<CellColor>& colors)
{
    return CellColor::WALL;
}
