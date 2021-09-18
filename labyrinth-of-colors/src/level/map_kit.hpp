//
//  map_kit.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 16.09.21.
//

#ifndef map_kit_hpp
#define map_kit_hpp

class SDL_Renderer;
class Map;
class CellKit;

class MapKit
{
private:
	CellKit* cell_kit;
	
public:
	MapKit(CellKit*);
	
	Map* create_map(SDL_Renderer*);
};

#endif /* map_kit_hpp */
