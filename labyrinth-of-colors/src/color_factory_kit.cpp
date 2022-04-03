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
#include "src/components/position.h"
#include "src/components/size.h"

#include "src/texture.h"
#include "src/consts.h"

entt::entity ColorFactoryKit::create_factory(MapPosition map_position, Position position) const
{
    auto factory = registry.create();
    
    registry.emplace<ColorFactory>(factory);
    registry.emplace<ColorBlending>(factory);
    registry.emplace<Texture>(factory, Texture(Consts::color_factory_texture_path, {0, 0, 32, 32}));
    registry.emplace<MapPosition>(factory, std::move(map_position));
    registry.emplace<Size>(factory, 50ul, 50ul);
    registry.emplace<Position>(factory, std::move(position));
    
    return factory;
}
