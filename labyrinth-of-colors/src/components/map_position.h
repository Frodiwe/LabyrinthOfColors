//
//  map_position.h
//  labyrinth-of-colors
//
//  Created by Fiodar Navumenka on 14.11.21.
//

#ifndef map_position_h
#define map_position_h

struct MapPosition
{
	size_t i;
	
	size_t j;
    
    bool operator==(const MapPosition& v)
    {
        return i == v.i and j == v.j;
    }
    
    bool operator!=(const MapPosition& v)
    {
        return not (*this == v);
    }
    
    MapPosition operator+(const MapPosition& v)
    {
        return {i + v.i, j + v.j};
    }
    
    MapPosition operator-(const MapPosition& v)
    {
        return {
            v.i > i ? i : i - v.i,
            v.j > j ? j : j - v.j
        };
    }
};

#endif /* map_position_h */
