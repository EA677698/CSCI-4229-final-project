#include "object.h"

float Object::get_width() const
{
    return width;
}

float Object::get_height() const
{
    return height;
}

float Object::get_depth() const
{
    return depth;
}

void Object::set_position(const Vector3& position)
{
    this->position = position;
}

void Object::set_position(const float x, const float y, const float z)
{
    this->position = Vector3(x, y, z);
}

void Object::translate(const Vector3& translation)
{
    this->position += translation;
    if (!polyhedrons.empty())
    {
        for (auto& polyhedron : polyhedrons)
        {
            polyhedron->translate(translation);
        }
    }
}

void Object::translate(const float x, const float y, const float z)
{
    this->position += Vector3(x, y, z);
    if (!polyhedrons.empty())
    {
        for (auto& polyhedron : polyhedrons)
        {
            polyhedron->translate(Vector3(x, y, z));
        }
    }
}

void Object::disable_bounding_box()
{
    bounding_box = false;
}

bool Object::has_bounding_box() const
{
    return bounding_box;
}

Vector3 Object::get_position() const
{
    return this->position;
}

void Object::set_rotation(const Vector3& rotation)
{
    this->rotation = rotation;
}

void Object::set_rotation(const float x, const float y, const float z)
{
    this->rotation = Vector3(x, y, z);
}

Vector3 Object::get_rotation() const
{
    return this->rotation;
}

std::string Object::get_name() const
{
    return name;
}

void Object::set_light(Light* light)
{
    this->light = light;
}

Light* Object::get_light() const
{
    return light;
}


void Object::init_light(const unsigned int light_num)
{
    light = new Light(light_num);
}

void Object::add_width(float width)
{
    this->width += width;
}

void Object::add_height(float height)
{
    this->height += height;
}

void Object::add_depth(float depth)
{
    this->depth += depth;
}

void Object::add_position(const Vector3& position)
{
    this->position += position;
}

void Object::add_position(float x, float y, float z)
{
    this->position += Vector3(x, y, z);
}

Vector3 Object::get_scale() const
{
    return scale;
}

void Object::set_scale(float x, float y, float z)
{
    this->scale = Vector3(x, y, z);
}

void Object::set_scale(const Vector3& scale)
{
    this->scale = scale;
}

void Object::set_width(float width)
{
    this->width = width;
}

void Object::set_height(float height)
{
    this->height = height;
}

void Object::set_depth(float depth)
{
    this->depth = depth;
}

bool Object::is_night_light() const {
    return night_light;
}

void Object::set_night_light(bool night_light) {
    this->night_light = night_light;
}
