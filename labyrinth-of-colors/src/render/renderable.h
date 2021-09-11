//
//  renderable.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 11.09.21.
//

#ifndef renderable_h
#define renderable_h

using RenderableId = int;

class Renderable
{
public:
	virtual void render() = 0;
	
	virtual RenderableId r_id() const = 0;
};

#endif /* renderable_h */
