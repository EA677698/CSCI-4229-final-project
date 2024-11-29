//
// Created by erickalanis on 11/24/24.
//

#include "skybox.h"
#include "../texture.h"

Skybox::Skybox() {

    width = 1;
    depth = 1;
    height = 1;

    int side_texture = SKYBOX_SIDE_TEXTURE;

    bounding_box = false;

    // Skybox made clockwise fashion to have normals point inward

    // Bottom
    auto polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(0, 0, depth);
    polygons.push_back(polygon);

    // Front Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(0, 0, depth);
    polygons.push_back(polygon);

    // Back Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(width, 0, 0);
    polygons.push_back(polygon);

    // Left Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(0, 0, depth);
    polygons.push_back(polygon);

    // Right Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    // Top
    polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }

}

Skybox::~Skybox() {}