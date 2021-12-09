//
//  items_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 30.11.21.
//

#ifndef items_kit_hpp
#define items_kit_hpp

#include "third_party/entt/entity/registry.hpp"

struct MapPosition;

class ItemsKit
{
private:
    entt::registry& registry;
    
public:
    ItemsKit(entt::registry& r) : registry{r}
    { }
    
    entt::entity create_item(const std::string& item_name, const MapPosition&);
};

#endif /* items_kit_hpp */
