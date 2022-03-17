//
//  deactivate_factory_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef deactivate_factory_listener_hpp
#define deactivate_factory_listener_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/listeners/listener.h"

class ColorFactorySystem;

class DeactivateFactoryListener : public Listener
{
private:
    entt::registry& registry;
    
    ColorFactorySystem* color_factory_system;
    
public:
    DeactivateFactoryListener(entt::registry& registry, ColorFactorySystem* color_factory_system) : registry{registry}, color_factory_system{color_factory_system}
    { }
    
    void operator()(Event* event);
};

#endif /* deactivate_factory_listener_hpp */
