#include "object.h"

float Object::get_width() const {
    return width;
}

float Object::get_height() const {
    return height;
}

float Object::get_depth() const {
    return depth;
}

void Object::set_position(const Vector3 &position) {
    this->position = position;
}

void Object::set_position(const float x, const float y, const float z) {
    this->position = Vector3(x, y, z);
}

void Object::translate(const Vector3 &translation) {
    this->position += translation;
    if(!polyhedrons.empty()){
        for(auto& polyhedron : polyhedrons){
            polyhedron->translate(translation);
        }
    }

}

void Object::translate(const float x, const float y, const float z) {
    this->position += Vector3(x, y, z);
    if(!polyhedrons.empty()){
        for(auto& polyhedron : polyhedrons){
            polyhedron->translate(Vector3(x, y, z));
        }
    }
}

void Object::disable_bounding_box() {
    bounding_box = false;
}

bool Object::has_bounding_box() const {
    return bounding_box;
}

Vector3 Object::get_position() const {
    return this->position;
}
