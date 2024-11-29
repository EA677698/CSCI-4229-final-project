#ifndef OBJECT_H
#define OBJECT_H

#include "../polygon.h"
#include <vector>

class Object {

protected:

    Vector3 position; // positions based on center of object
    float width, height, depth;
    std::vector<Polygon> polygons;
    std::vector<Object*> polyhedrons;
    bool bounding_box;

public:

    Object() : position(Vector3(0, 0, 0)), width(1), height(1), depth(1), bounding_box(true) {
        polyhedrons = {};
    };

    virtual ~Object() {};

    std::vector<Polygon> get_polygons() {
        return polygons;
    }

    std::vector<Object*> get_polyhedrons() {
        return polyhedrons;
    }

    float get_width() const;

    float get_height() const;

    float get_depth() const;

    void set_position(const Vector3 &position);

    void set_position(float x, float y, float z);

    void translate(const Vector3 &translation);

    void translate(float x, float y, float z);

    void disable_bounding_box();

    bool has_bounding_box() const;

    Vector3 get_position() const;

};

#endif