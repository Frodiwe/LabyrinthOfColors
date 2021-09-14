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
class Entity;
class MapPositionController;

class Level
{
private:
	std::shared_ptr<Map> map;
	
	std::shared_ptr<Entity> player;
	
	std::unique_ptr<MapPositionController> map_position_controller;
	
public:
	Level(std::shared_ptr<Entity>, std::shared_ptr<Map>, std::unique_ptr<MapPositionController>);
	
	void render();
};

#endif /* level_hpp */
