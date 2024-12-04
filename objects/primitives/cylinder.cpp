//
// Created by erickalanis on 11/28/24.
//

#include "cylinder.h"

#define Cos(th) cos(3.14159265/180*(th))
#define Sin(th) sin(3.14159265/180*(th))


Cylinder::Cylinder(float width, float height, float depth, int sides) {
    this->sides = sides;
    this->width = width;
    this->height = height * 1.5f;
    this->depth = depth;

    name = "Cylinder";

    Polygon polygon;
    float step = 360.0f / this->sides;

    for (int i = 0; i < this->sides; i++) {
        float angle = i * step;
        float next_angle = (i + 1) * step;

        float x = this->width * Cos(angle);
        float z = this->depth * Sin(angle);

        float next_x = this->width * Cos(next_angle);
        float next_z = this->depth * Sin(next_angle);

        polygon = Polygon(0xFFFFFF);
        polygon.add_vertex(x, 0, z);
        polygon.add_vertex(next_x, 0, next_z);
        polygon.add_vertex(next_x, this->height, next_z);
        polygon.add_vertex(x, this->height, z);
        polygons.push_back(polygon);
    }

    polygon = Polygon(0xFFFFFF);
    for (int i = 0; i < this->sides; i++) {
        float angle = i * step;
        float x = this->width * Cos(angle);
        float z = this->depth * Sin(angle);
        polygon.add_vertex(x, this->height, z);
    }
    polygons.push_back(polygon);

    polygon = Polygon(0xFFFFFF);
    for (int i = 0; i < this->sides; i++) {
        float angle = i * step;
        float x = this->width * Cos(angle);
        float z = this->depth * Sin(angle);
        polygon.add_vertex(x, 0, z);
    }
    polygons.push_back(polygon);

    for (auto& polygon1 : polygons) {
        polygon1.generate_texture_vertices();
    }
}


Cylinder::~Cylinder() {}

void Cylinder::refresh() {

    polygons.clear();
    Polygon polygon;
    float step = 360.0f / this->sides;

    for (int i = 0; i < this->sides; i++) {
        float angle = i * step;
        float next_angle = (i + 1) * step;

        float x = this->width * Cos(angle);
        float z = this->depth * Sin(angle);

        float next_x = this->width * Cos(next_angle);
        float next_z = this->depth * Sin(next_angle);

        polygon = Polygon(0xFFFFFF);
        polygon.add_vertex(x, 0, z);
        polygon.add_vertex(next_x, 0, next_z);
        polygon.add_vertex(next_x, this->height, next_z);
        polygon.add_vertex(x, this->height, z);
        polygons.push_back(polygon);
    }

    polygon = Polygon(0xFFFFFF);
    for (int i = 0; i < this->sides; i++) {
        float angle = i * step;
        float x = this->width * Cos(angle);
        float z = this->depth * Sin(angle);
        polygon.add_vertex(x, this->height, z);
    }
    polygons.push_back(polygon);

    polygon = Polygon(0xFFFFFF);
    for (int i = 0; i < this->sides; i++) {
        float angle = i * step;
        float x = this->width * Cos(angle);
        float z = this->depth * Sin(angle);
        polygon.add_vertex(x, 0, z);
    }
    polygons.push_back(polygon);

    for (auto& polygon1 : polygons) {
        polygon1.generate_texture_vertices();
    }
}

void Cylinder::set_texture_repeat(const Vector2& repeat) {

    for (auto& polygon : polygons) {
        polygon.set_texture_repeats(repeat);
    }

}

void Cylinder::set_texture(int texture) {

        for (auto& polygon : polygons) {
            polygon.set_texture(texture);
        }

}

void Cylinder::set_color(int color) {

    for (auto& polygon : polygons) {
        polygon.set_color(color);
    }

}
