#include "object.h"

float Object::get_width() const{
    return width;
}

float Object::get_height() const{
    return height;
}

float Object::get_depth() const {
    return depth;
}

void Object::set_position(const Vector3& position) {
    this->position = position;
}

void Object::set_position(const float x, const float y, const float z) {
    this->position = Vector3(x, y, z);
}

void Object::translate(const Vector3& translation) const
{
    this->position += translation;
}

void Object::translate(const float x, const float y, const float z) const
{
    this->position += Vector3(x, y, z);
}

Vector3 Object::get_position() const {
    return this->position;
}
