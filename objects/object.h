#ifndef OBJECT_H
#define OBJECT_H

#include "../polygon.h"
#include <vector>

class Object {

protected:

    int width, height, depth;
    std::vector<Polygon> polygons;

public:

    Object() : width(1), height(1), depth(1) {};
    virtual ~Object() {};

    std::vector<Polygon> get_polygons(){
        return polygons;
    }

};

#endif