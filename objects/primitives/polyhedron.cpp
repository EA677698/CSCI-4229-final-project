//
// Created by erickalanis on 11/28/24.
//

#include "polyhedron.h"

#define Cos(th) cos(3.14159265/180*(th))
#define Sin(th) sin(3.14159265/180*(th))


Polyhedron::Polyhedron(float width, float height, float depth, int definition) {
    this->sides = definition;
    this->width = width;
    this->height = height;
    this->depth = depth;

    Polygon polygon = Polygon(0xFFFFFF);
    float step = 360.0f / definition;

    for (int i = 0; i < definition; i++) {
        float angle = i * step;
        float next_angle = (i + 1) * step;

        float x = Cos(angle);
        float z = Sin(angle);

        float next_x = Cos(next_angle);
        float next_z = Sin(next_angle);

        polygon = Polygon(0xFFFFFF);
        polygon.add_vertex(x, 0, z);
        polygon.add_vertex(next_x, 0, next_z);
        polygon.add_vertex(next_x, height, next_z);
        polygon.add_vertex(x, height, z);
        polygons.push_back(polygon);
    }

    // Top
    polygon = Polygon(0xFFFFFF);
    for (int i = 0; i < definition; i++) {
        float angle = i * step;
        float x = Cos(angle);
        float z = Sin(angle);
        polygon.add_vertex(x, height, z);
    }
    polygons.push_back(polygon);

    // Bottom
    polygon = Polygon(0xFFFFFF);
    for (int i = 0; i < definition; i++) {
        float angle = i * step;
        float x = Cos(angle);
        float z = Sin(angle);
        polygon.add_vertex(x, 0, z);
    }
    polygons.push_back(polygon);

    for(auto& polygon1 : polygons){
        polygon1.generate_texture_vertices();
    }

}

Polyhedron::~Polyhedron() {}
