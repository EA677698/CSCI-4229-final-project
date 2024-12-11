//
// Created by erickalanis on 12/10/24.
//

#include "water.h"
#include "../texture.h"


Water::Water()
{
    width = 680;
    depth = 800;
    height = 0;
    name = "Water";

    Polygon polygon = Polygon(WATER_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);
    for (unsigned int i = 0; i < polygons.size(); i++)
    {
        polygons[i].generate_texture_vertices();
        polygons[i].set_texture_repeats({20, 20});
    }
}

void Water::refresh()
{
    polygons.clear();
    Polygon polygon = Polygon(WATER_TEXTURE, 0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);
    for (unsigned int i = 0; i < polygons.size(); i++)
    {
        polygons[i].generate_texture_vertices();
        polygons[i].set_texture_repeats({20, 20});
    }
}

Water::~Water()
{
}
