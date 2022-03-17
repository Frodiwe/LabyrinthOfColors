//
//  color_factory_kit.cpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.02.22.
//

#include "color_factory_kit.hpp"

#include "src/tags/color_factory.h"

#include "src/components/color_blending.h"
#include "src/components/map_position.h"

entt::entity ColorFactoryKit::create_factory(MapPosition map_position) const
{
    auto factory = registry.create();
    
    registry.emplace<ColorFactory>(factory);
    registry.emplace<ColorBlending>(factory);
    registry.emplace<MapPosition>(factory, std::move(map_position));
    
    return factory;
}
