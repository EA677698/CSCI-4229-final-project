#include "skyscraper.h"
#include "../../texture.h"

Skyscraper::Skyscraper(){
    width = 1;
    height = 4;
    depth = 1;
    
    Polygon polygon;

    int side_texture = TEXTURE_SKYSCRAPER;

    // Floor
    polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(0, 0, depth);
    polygons.push_back(polygon);

    // Front Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(0, 0, depth);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);

    // Back Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(0, height, 0);
    polygons.push_back(polygon);

    // Left Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(0, 0, 0);
    polygon.add_vertex(0, 0, depth);
    polygon.add_vertex(0, height, depth);
    polygon.add_vertex(0, height, 0);
    polygons.push_back(polygon);

    // Right Side
    polygon = Polygon(side_texture, 0xFFFFFF);
    polygon.add_vertex(width, 0, 0);
    polygon.add_vertex(width, 0, depth);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(width, height, 0);
    polygons.push_back(polygon);

    // Roof
    polygon = Polygon(0xFFFFFF);
    polygon.add_vertex(0, height, 0);
    polygon.add_vertex(width, height, 0);
    polygon.add_vertex(width, height, depth);
    polygon.add_vertex(0, height, depth);
    polygons.push_back(polygon);


    for(unsigned int i = 0; i < polygons.size(); i++){
        polygons[i].generate_texture_vertices();
    }
}

Skyscraper::~Skyscraper(){}