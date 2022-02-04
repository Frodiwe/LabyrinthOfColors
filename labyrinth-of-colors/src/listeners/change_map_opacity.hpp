//
//  change_map_opacity.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 26.12.21.
//

#ifndef change_map_opacity_hpp
#define change_map_opacity_hpp

#include "src/listeners/listener.h"

#include "third_party/entt/entity/registry.hpp"

class ChangeMapOpacity : public Listener
{
public:
    void operator()(Event* event);
};

#endif /* change_map_opacity_hpp */
