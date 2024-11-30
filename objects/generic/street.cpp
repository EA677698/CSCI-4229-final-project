#include "street.h"
#include "../../texture.h"

Street::Street() {
    width = 12;
    depth = 40;
    height = 0.2;

    name = "Street";

    auto polygon = Polygon(ROAD_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }
}

Street::~Street() {}

void Street::refresh() {
    polygons.clear();
    auto polygon = Polygon(ROAD_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }
}
