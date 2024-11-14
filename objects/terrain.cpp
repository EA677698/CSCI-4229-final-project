#include "terrain.h"

Terrain::Terrain()
{
        width = 1;
        height = 1;
        Polygon polygon = Polygon(0xFFFFFF);
        polygon.add_vertex(0, 0, 0);
        polygon.add_vertex(1, 0, 0);
        polygon.add_vertex(1, 0, 1);
        polygon.add_vertex(0, 0, 1);
        polygons.push_back(polygon);
        for(unsigned int i = 0; i < polygons.size(); i++){
            polygons[i].generate_texture_vertices();
        }

}

Terrain::~Terrain(){}