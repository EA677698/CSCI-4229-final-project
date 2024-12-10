//
// Created by erickalanis on 11/27/24.
//

#include "cuboid.h"
#include "../../texture.h"


Cuboid::Cuboid(float width, float height, float depth)
{
    this->width = width;
    this->height = height;
    this->depth = depth;
    bounding_box = true;

    name = "Cuboid";

    for (unsigned int i = 0; i < 6; i++)
    {
        colors[i] = 0xFFFFFF;
        textures[i] = NULL_TEXTURE;
    }

    vertices[BACK_BOTTOM_LEFT] = Vector3(0, 0, 0);
    vertices[BACK_BOTTOM_RIGHT] = Vector3(width, 0, 0);
    vertices[BACK_TOP_LEFT] = Vector3(width, height, 0);
    vertices[BACK_TOP_RIGHT] = Vector3(0, height, 0);

    vertices[FRONT_BOTTOM_LEFT] = Vector3(0, 0, depth);
    vertices[FRONT_BOTTOM_RIGHT] = Vector3(width, 0, depth);
    vertices[FRONT_TOP_RIGHT] = Vector3(width, height, depth);
    vertices[FRONT_TOP_LEFT] = Vector3(0, height, depth);

    auto polygon = Polygon(textures[0], colors[0]);
    polygon.add_vertex(vertices[0]);
    polygon.add_vertex(vertices[1]);
    polygon.add_vertex(vertices[2]);
    polygon.add_vertex(vertices[3]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[1], colors[1]);
    polygon.add_vertex(vertices[1]);
    polygon.add_vertex(vertices[5]);
    polygon.add_vertex(vertices[6]);
    polygon.add_vertex(vertices[2]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[2], colors[2]);
    polygon.add_vertex(vertices[5]);
    polygon.add_vertex(vertices[4]);
    polygon.add_vertex(vertices[7]);
    polygon.add_vertex(vertices[6]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[3], colors[3]);
    polygon.add_vertex(vertices[4]);
    polygon.add_vertex(vertices[0]);
    polygon.add_vertex(vertices[3]);
    polygon.add_vertex(vertices[7]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[4], colors[4]);
    polygon.add_vertex(vertices[3]);
    polygon.add_vertex(vertices[2]);
    polygon.add_vertex(vertices[6]);
    polygon.add_vertex(vertices[7]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[5], colors[5]);
    polygon.add_vertex(vertices[4]);
    polygon.add_vertex(vertices[5]);
    polygon.add_vertex(vertices[1]);
    polygon.add_vertex(vertices[0]);
    polygons.push_back(polygon);

    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}


void Cuboid::set_vector(int index, const Vector3& vector)
{
    vertices[index % 8] = vector;
}

void Cuboid::set_vector(int index, float x, float y, float z)
{
    vertices[index % 8] = Vector3(x, y, z);
}

void Cuboid::add_vector(int index, const Vector3& vector)
{
    vertices[index % 8] += vector;
}

void Cuboid::add_vector(int index, float x, float y, float z)
{
    vertices[index % 8] += Vector3(x, y, z);
}

void Cuboid::set_color(int index, int color)
{
    colors[index % 6] = color;
}

void Cuboid::set_texture(int index, int texture)
{
    textures[index % 6] = texture;
}

void Cuboid::construct_cuboid()
{
    polygons.clear();

    auto polygon = Polygon(textures[0], colors[0]);
    polygon.add_vertex(vertices[0]);
    polygon.add_vertex(vertices[1]);
    polygon.add_vertex(vertices[2]);
    polygon.add_vertex(vertices[3]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[1], colors[1]);
    polygon.add_vertex(vertices[1]);
    polygon.add_vertex(vertices[5]);
    polygon.add_vertex(vertices[6]);
    polygon.add_vertex(vertices[2]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[2], colors[2]);
    polygon.add_vertex(vertices[5]);
    polygon.add_vertex(vertices[4]);
    polygon.add_vertex(vertices[7]);
    polygon.add_vertex(vertices[6]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[3], colors[3]);
    polygon.add_vertex(vertices[4]);
    polygon.add_vertex(vertices[0]);
    polygon.add_vertex(vertices[3]);
    polygon.add_vertex(vertices[7]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[4], colors[4]);
    polygon.add_vertex(vertices[3]);
    polygon.add_vertex(vertices[2]);
    polygon.add_vertex(vertices[6]);
    polygon.add_vertex(vertices[7]);
    polygons.push_back(polygon);

    polygon = Polygon(textures[5], colors[5]);
    polygon.add_vertex(vertices[4]);
    polygon.add_vertex(vertices[5]);
    polygon.add_vertex(vertices[1]);
    polygon.add_vertex(vertices[0]);
    polygons.push_back(polygon);

    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}

Cuboid::~Cuboid()
{
}

void Cuboid::refresh()
{
    vertices[BACK_BOTTOM_LEFT] = Vector3(0, 0, 0);
    vertices[BACK_BOTTOM_RIGHT] = Vector3(width, 0, 0);
    vertices[BACK_TOP_LEFT] = Vector3(width, height, 0);
    vertices[BACK_TOP_RIGHT] = Vector3(0, height, 0);

    vertices[FRONT_BOTTOM_LEFT] = Vector3(0, 0, depth);
    vertices[FRONT_BOTTOM_RIGHT] = Vector3(width, 0, depth);
    vertices[FRONT_TOP_RIGHT] = Vector3(width, height, depth);
    vertices[FRONT_TOP_LEFT] = Vector3(0, height, depth);

    construct_cuboid();
}

void Cuboid::set_texture_repeat(int index, Vector2 repeat)
{
    polygons[index].set_texture_repeats(repeat);
}

void Cuboid::set_texture_to_all(int texture)
{
    for (unsigned int i = 0; i < 6; i++)
    {
        textures[i] = texture;
    }
}

void Cuboid::set_texture_repeat_all(const Vector2& repeat)
{
    for (unsigned int i = 0; i < 6; i++)
    {
        polygons[i].set_texture_repeats(repeat);
    }
}

void Cuboid::set_color_to_all(int color)
{
    for (unsigned int i = 0; i < 6; i++)
    {
        colors[i] = color;
    }
}
