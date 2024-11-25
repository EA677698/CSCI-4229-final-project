//
// Created by erickalanis on 11/14/24.
//

#include "boundingbox.h"

#include "texture.h"


BoundingBox::BoundingBox() : width(0), height(0), depth(0), object(nullptr), color(0) {}

BoundingBox::BoundingBox(Object *object, const int color) {
    this->object = object;
    this->width = object->get_width();
    this->height = object->get_height();
    this->depth = object->get_depth();
    this->color = color;

    auto polygon = Polygon(NO_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(0, 0, depth);
    polygons.push_back(polygon);

    // Front Side
    polygon = Polygon(NO_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, 0, depth);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);

    // Back Side
    polygon = Polygon(NO_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(0, height, 0);
    polygons.push_back(polygon);

    // Left Side
    polygon = Polygon(NO_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(0, 0, depth);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(0, height, 0);
    polygons.push_back(polygon);

    // Right Side
    polygon = Polygon(NO_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    // Roof
    polygon = Polygon(NO_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);

}

Object *BoundingBox::get_object() const {
    return object;
}

int BoundingBox::get_color() const {
    return color;
}

std::vector<Polygon> BoundingBox::get_polygons() const {
    return polygons;
}

BoundingBox::~BoundingBox() {}
