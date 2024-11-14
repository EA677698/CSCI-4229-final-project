#ifndef POLYGON_H
#define POLYGON_H
#include "vector3.h"
#include "vector2.h"
#include <vector>
#include <cstdio>


class Polygon
{
private:

    std::vector<Vector3> vertices;
    std::vector<Vector2> texture_vertices;
    void normalize_texture_vectors();
    unsigned int texture;
    int color;

public:

    Polygon();
    Polygon(int color);
    Polygon(int texture, int color);
    ~Polygon();
    void add_vertex(Vector3);
    void add_vertex(float, float, float);
    Vector3 calculate_normal();
    void set_texture(int);
    void set_color(int);
    int get_color();
    unsigned int get_texture();
    void generate_texture_vertices();
    const std::vector<Vector2> get_texture_vertices();
    const std::vector<Vector3> get_vertices();

    void print_texture_vertices(){
        for(unsigned int i = 0; i < texture_vertices.size(); i++){
            Vector2 vertex = texture_vertices[i];
            printf("Texture Vertex %d: (%f, %f)\n", i, vertex.x, vertex.y);
        }
    }
};




#endif