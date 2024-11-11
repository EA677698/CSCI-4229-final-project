#ifndef POLYGON_H
#define POLYGON_H
#include "vector3.h"
#include <vector>

#define TEXTURE_NULL -1

class Polygon
{
private:

    std::vector<Vector3> vertices;
    unsigned int texture;
    int color;

public:

    Polygon();
    Polygon(int color);
    Polygon(unsigned int texture, int color);
    ~Polygon();
    void add_vertex(Vector3);
    void add_vertex(float, float, float);
    void set_texture(unsigned int);
    void set_color(int);
    int get_color();
    unsigned int get_texture();
    const std::vector<Vector3> get_vertices();
};




#endif