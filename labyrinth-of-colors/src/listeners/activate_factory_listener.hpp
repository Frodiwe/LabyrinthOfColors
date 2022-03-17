//
//  activate_factory_listener.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 12.02.22.
//

#ifndef activate_factory_listener_hpp
#define activate_factory_listener_hpp

#include "third_party/entt/entity/registry.hpp"

#include "src/listeners/listener.h"

class ColorFactorySystem;

class ActivateFactoryListener : public Listener
{
private:
    entt::registry& registry;
    
    ColorFactorySystem* color_factory_system;
    
public:
    ActivateFactoryListener(entt::registry& registry, ColorFactorySystem* color_factory_system) : registry{registry}, color_factory_system{color_factory_system}
    { }
    
    void operator()(Event* event);
};

#endif /* activate_factory_listener_hpp */
