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
struct Position;
enum class CellColor;

class ItemsKit
{
private:
    entt::registry& registry;
    
public:
    ItemsKit(entt::registry& r) : registry{r}
    { }
    
    entt::entity create_item(const std::string& item_name, const CellColor&, const MapPosition&, const Position&);
};

#endif /* items_kit_hpp */
