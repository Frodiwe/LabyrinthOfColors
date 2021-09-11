//
//  level.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 10.08.21.
//

#ifndef level_hpp
#define level_hpp

#include <memory>

class Map;
class Player;
class MapPositionController;

class Level
{
private:
	std::unique_ptr<Map> map;
	
	std::unique_ptr<Player> player;
	
	std::unique_ptr<MapPositionController> map_position_controller;
	
public:
	Level(std::unique_ptr<Player>, std::unique_ptr<Map>, std::unique_ptr<MapPositionController>);
	
	void render();
};

#endif /* level_hpp */
