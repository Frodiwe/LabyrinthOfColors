//
//  blending_system.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.02.22.
//

#ifndef blending_system_hpp
#define blending_system_hpp

#include <vector>

#include "third_party/entt/entity/registry.hpp"

#include "src/level/cell_color.h"

struct MapPosition;

class ColorFactorySystem
{
private:
    entt::registry& registry;
    
public:
    ColorFactorySystem(entt::registry& registry) : registry{registry}
    { }
    
    void activate(entt::entity color_factory);
    
    void deactivate(entt::entity color_factory);
    
    bool has_active_factory() const;
    
    entt::entity get_active_factory() const;
    
    entt::entity get_factory_at(MapPosition position);
    
    CellColor blend(const std::vector<CellColor>& colors);
};

#endif /* blending_system_hpp */
