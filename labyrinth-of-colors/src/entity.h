//
//  entity.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 9.08.21.
//

#ifndef entity_h
#define entity_h

#include <stdint.h>

class Entity
{
public:
	virtual void move(int32_t, int32_t) = 0;
	
	virtual ~Entity() = 0;
};

#endif /* entity_h */
