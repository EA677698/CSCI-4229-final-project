#ifndef OBJECT_H
#define OBJECT_H

#include "../polygon.h"
#include "../light.h"
#include <vector>
#include <string>

class Object
{
protected:
    Vector3 scale;
    Vector3 position; // positions based on center of object
    Vector3 rotation;
    float width, height, depth;
    std::vector<Polygon> polygons;
    std::vector<Object*> polyhedrons;
    bool bounding_box;
    Light* light;
    bool night_light;
    std::string name; // identifier used for debugging

public:
    Object() : scale(Vector3(1, 1, 1)), position(Vector3(0, 0, 0)), rotation(Vector3(0, 0, 0)), width(1), height(1),
               depth(1), polygons(0), polyhedrons(0), bounding_box(true), light(nullptr), night_light(false), name("Generic Object")
    {
    };

    virtual ~Object()
    {
    };

    std::vector<Polygon> get_polygons()
    {
        return polygons;
    }

    std::vector<Object*> get_polyhedrons()
    {
        return polyhedrons;
    }

    float get_width() const;

    float get_height() const;

    float get_depth() const;

    void add_width(float width);

    void add_height(float height);

    void add_depth(float depth);

    void set_width(float width);

    void set_height(float height);

    void set_depth(float depth);

    // Used to recreate the object if attributes are changed
    virtual void refresh() = 0;

    void set_scale(const Vector3& scale);

    void set_scale(float x, float y, float z);

    Vector3 get_scale() const;

    void set_position(const Vector3& position);

    void set_position(float x, float y, float z);

    void add_position(const Vector3& position);

    void add_position(float x, float y, float z);

    void set_rotation(const Vector3& rotation);

    void set_rotation(float x, float y, float z);

    Vector3 get_rotation() const;

    void translate(const Vector3& translation);

    void translate(float x, float y, float z);

    void disable_bounding_box();

    bool has_bounding_box() const;

    Vector3 get_position() const;

    std::string get_name() const;

    void set_light(Light* light);

    void init_light(unsigned int light_num);

    Light* get_light() const;

    bool is_night_light() const;

    void set_night_light(bool night_light);
};

#endif
