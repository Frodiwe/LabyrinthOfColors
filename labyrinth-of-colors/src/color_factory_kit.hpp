//
//  color_factory_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 17.02.22.
//

#ifndef color_factory_kit_hpp
#define color_factory_kit_hpp

#include "third_party/entt/entity/registry.hpp"

struct MapPosition;

class ColorFactoryKit
{
private:
    entt::registry& registry;
    
public:
    ColorFactoryKit(entt::registry& registry) : registry{registry}
    { }
    
    entt::entity create_factory(MapPosition map_position) const;
};

#endif /* color_factory_kit_hpp */
