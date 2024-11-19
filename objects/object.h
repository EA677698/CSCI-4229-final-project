#ifndef OBJECT_H
#define OBJECT_H

#include "../polygon.h"
#include <vector>

class Object {

protected:

    Vector3 position; // positions based on center of object
    float width, height, depth;
    std::vector<Polygon> polygons;

public:

    Object() : position(Vector3(0,0,0)), width(1), height(1), depth(1) {};
    virtual ~Object() {};

    std::vector<Polygon> get_polygons(){
        return polygons;
    }

    float get_width() const;
    float get_height() const;
    float get_depth() const;

    void set_position(const Vector3& position);
    void set_position(float x, float y, float z);
    void translate(const Vector3& translation) const;
    void translate(float x, float y, float z) const;
    Vector3 get_position() const;

};

#endif