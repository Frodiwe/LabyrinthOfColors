//
//  blending_system.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.02.22.
//

#include "color_factory_system.hpp"

#include "src/consts.h"

#include "src/tags/color_factory.h"
#include "src/tags/active.h"

#include "src/components/map_position.h"
#include "src/components/color_blending.h"

void ColorFactorySystem::activate(entt::entity color_factory)
{
    registry.emplace<Active>(color_factory);
}

void ColorFactorySystem::deactivate(entt::entity color_factory)
{
    registry.remove<Active>(color_factory);
    
    registry.get<ColorBlending>(color_factory).clear();
}

entt::entity ColorFactorySystem::get_active_factory() const
{
    for (const auto [entity] : registry.view<ColorFactory, Active>().each())
    {
        return entity;
    }
    
    return entt::null;
}

entt::entity ColorFactorySystem::get_factory_at(MapPosition position)
{
    for (const auto [entity, map_position] : registry.view<ColorFactory, MapPosition>().each())
    {
        if (map_position == position)
        {
            return entity;
        }
    }
    
    return entt::null;
}

bool ColorFactorySystem::has_active_factory() const
{
    return get_active_factory() != entt::null;
}

CellColor ColorFactorySystem::blend(const std::set<CellColor>& colors)
{
    for (const auto& [color, components] : Consts::color_mixes)
    {
        if (components == colors)
        {
            return color;
        }
    }
    
    return CellColor::WALL;
}

