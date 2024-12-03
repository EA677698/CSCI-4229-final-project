#ifndef OBJECT_H
#define OBJECT_H

#include "../polygon.h"
#include <vector>
#include <string>

class Object {

protected:

    Vector3 position; // positions based on center of object
    Vector3 rotation;
    float width, height, depth;
    std::vector<Polygon> polygons;
    std::vector<Object*> polyhedrons;
    bool bounding_box;
    std::string name; // identifier used for debugging

public:

    Object() : position(Vector3(0, 0, 0)), rotation(Vector3(0,0,0)), width(1), height(1), depth(1), polygons(0), polyhedrons(0), bounding_box(true), name("Generic Object") {};

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

    void add_width(float width);

    void add_height(float height);

    void add_depth(float depth);

    // Used to recreate the object if attributes are changed
    virtual void refresh() = 0;

    void set_position(const Vector3 &position);

    void set_position(float x, float y, float z);

    void add_position(const Vector3 &position);

    void add_position(float x, float y, float z);

    void set_rotation(const Vector3 &rotation);

    void set_rotation(float x, float y, float z);

    Vector3 get_rotation() const;

    void translate(const Vector3 &translation);

    void translate(float x, float y, float z);

    void disable_bounding_box();

    bool has_bounding_box() const;

    Vector3 get_position() const;

    std::string get_name() const;

};

#endif