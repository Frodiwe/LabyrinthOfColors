//
//  config.hpp
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 19.09.21.
//

#ifndef config_hpp
#define config_hpp

#include <stdlib.h>

class LevelConfig;

class Config
{
public:
	static LevelConfig level(size_t);
};

#endif /* config_hpp */
