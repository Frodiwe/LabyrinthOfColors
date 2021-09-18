//
//  level_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 13.09.21.
//

#ifndef level_kit_hpp
#define level_kit_hpp

#include <string_view>

class Level;
class SDL_Renderer;
class MapKit;

class LevelKit
{
private:
	MapKit* map_kit;
	
public:
	LevelKit(MapKit*);
	
	Level create_level(SDL_Renderer*) const;
};

#endif /* level_kit_hpp */
