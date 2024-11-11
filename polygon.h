#ifndef POLYGON_H
#define POLYGON_H
#include "vector3.h"
#include <vector>

class Polygon
{
private:
    std::vector<Vector3> vertices;
    unsigned int texture;
public:
    Polygon(unsigned int);
    ~Polygon();
    void add_vertex(Vector3);
    void add_vertex(float, float, float);
    void set_texture(unsigned int);
    unsigned int get_texture();
    const std::vector<Vector3> get_vertices();
};




#endif