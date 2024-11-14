#ifndef OBJECT_H
#define OBJECT_H

#include "../polygon.h"
#include <vector>

class Object {

protected:

    float width, height, depth;
    std::vector<Polygon> polygons;

public:

    Object() : width(1), height(1), depth(1) {};
    virtual ~Object() {};

    std::vector<Polygon> get_polygons(){
        return polygons;
    }

    float get_width() const;
    float get_height() const;
    float get_depth() const;

};

#endif