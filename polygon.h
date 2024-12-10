#ifndef POLYGON_H
#define POLYGON_H

#include "vector3.h"
#include "vector2.h"
#include <vector>
#include <cstdio>

class Polygon
{
private:
    Vector2 texture_repeats;
    std::vector<Vector3> vertices;
    std::vector<Vector2> texture_vertices;
    int raw_texture;
    unsigned int texture;
    int color;
    bool has_texture;


    void normalize_texture_vectors();

public:
    Polygon();

    Polygon(int color);

    Polygon(int texture, int color);

    ~Polygon() = default;

    void add_vertex(const Vector3&);

    void add_vertex(float, float, float);

    Vector3 calculate_normal() const;

    void set_texture(int);

    void set_color(int);

    void flip_texture_vertically();

    void flip_texture_horizontally();

    int get_color() const;

    bool contains_texture() const;

    unsigned int get_texture() const;

    void generate_texture_vertices();

    const std::vector<Vector2>& get_texture_vertices() const;

    std::vector<Vector3> get_vertices();

    Vector2 get_texture_repeats() const;

    void set_texture_repeats(const Vector2& repeats);

    void set_texture_repeats(float repeat_x, float repeat_y);

    int get_raw_texture() const;

    void print_texture_vertices()
    {
        for (unsigned int i = 0; i < texture_vertices.size(); i++)
        {
            const Vector2& vertex = texture_vertices[i];
            printf("Texture Vertex %d: (%f, %f)\n", i, vertex.x, vertex.y);
        }
    }

    void print_vertices()
    {
        for (unsigned int i = 0; i < vertices.size(); i++)
        {
            const Vector3& vertex = vertices[i];
            printf("Vertex %d: (%f, %f, %f)\n", i, vertex.x, vertex.y, vertex.z);
        }
        printf("\n");
    }
};


#endif
