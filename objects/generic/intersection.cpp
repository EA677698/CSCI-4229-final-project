//
// Created by erickalanis on 11/24/24.
//

#include "intersection.h"
#include "../../texture.h"

Intersection::Intersection() {

    width = 12;
    depth = 12;
    height = 0.2;

    name = "Intersection";

    auto polygon = Polygon(INTERSECTION_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }

}

Intersection::~Intersection() {}

void Intersection::refresh() {
    polygons.clear();
    auto polygon = Polygon(INTERSECTION_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }
}
