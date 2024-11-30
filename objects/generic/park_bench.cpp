//
// Created by erickalanis on 11/28/24.
//

#include "park_bench.h"

ParkBench::ParkBench() {
    width = 25;
    height = 10;
    depth = 10;

    bounding_box = true;

    name = "Park Bench";

    // Seat
    auto polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(0, 0, depth);
    polygons.push_back(polygon);

    // Back
    polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(0, height, 0);
    polygons.push_back(polygon);

    // Left
    polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(0, 0, depth);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(0, height, 0);
    polygons.push_back(polygon);

    // Right
    polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    // Front
    polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, 0, depth);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);


    for(auto& polygon1 : polygons){
        polygon1.generate_texture_vertices();
    }
}

ParkBench::~ParkBench() {}