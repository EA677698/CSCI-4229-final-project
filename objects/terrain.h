#ifndef TERRAIN_H
#define TERRAIN_H

#include "object.h"

class Terrain: public Object {

private:


public:

    Terrain()
    {
        width = 1;
        height = 1;
        Polygon polygon = Polygon(0x00FF00);
        polygon.add_vertex(0, 0, 0);
        polygon.add_vertex(1, 0, 0);
        polygon.add_vertex(1, 0, 1);
        polygon.add_vertex(0, 0, 1);
        polygons.push_back(polygon);
    }


    ~Terrain(){};

};


#endif