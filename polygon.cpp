#include "polygon.h"

Polygon::Polygon(unsigned int texture, int color)
{
    this->texture = texture;
    this->color = color;
}

Polygon::Polygon(int color)
{
    Polygon(TEXTURE_NULL, color);
}

Polygon::Polygon()
{
    Polygon(TEXTURE_NULL, 0xFFFFFF);   
}

void Polygon::add_vertex(Vector3 vertex)
{
    vertices.push_back(vertex);
}

void Polygon::add_vertex(float x, float y, float z)
{
    Polygon::add_vertex(Vector3(x, y, z));
}

void Polygon::set_texture(unsigned int texture)
{
    this->texture = texture;
}

unsigned int Polygon::get_texture()
{
    return texture;
}

const std::vector<Vector3> Polygon::get_vertices()
{
    return vertices;
}

void Polygon::set_color(int color)
{
    this->color = color;
}

int Polygon::get_color()
{
    return color;
}

Polygon::~Polygon(){}