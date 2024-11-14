#include "terrain.h"
#include "../texture.h"

Terrain::Terrain()
{
        width = 800;
        depth = 800;
        Polygon polygon = Polygon(ROAD_TEXTURE, 0x00FF00);
        polygon.add_vertex(0, 0, 0);
        polygon.add_vertex(width, 0, 0);
        polygon.add_vertex(width, 0, depth);
        polygon.add_vertex(0, 0, depth);
        polygons.push_back(polygon);
        for(unsigned int i = 0; i < polygons.size(); i++){
            polygons[i].generate_texture_vertices();
            //polygons[i].set_texture_repeats(10);
        }

}

Terrain::~Terrain(){}