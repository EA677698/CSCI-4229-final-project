#include "terrain.h"
#include "../texture.h"

Terrain::Terrain() {
    width = 800;
    depth = 800;
    height = 0;

    Polygon polygon = Polygon(GRASS_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);
    for (unsigned int i = 0; i < polygons.size(); i++) {
        polygons[i].generate_texture_vertices();
        polygons[i].set_texture_repeats(20);
    }

}

Terrain::~Terrain() {}