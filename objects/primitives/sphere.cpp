//
// Created by erickalanis on 12/5/24.
//

#include "sphere.h"

#include "../texture.h"
#include <CSCIx229.h>

Sphere::Sphere(float radius, int lat, int lon)
{
    this->radius = radius;
    this->lat = lat;
    this->lon = lon;
    texture = NULL_TEXTURE;
    texture_repeat = {1.0f / lat, 1.0f / lon};
    color = 0xFFFFFF;

    width = radius * 2;
    height = radius * 2;
    depth = radius * 2;

    name = "Sphere";

    Polygon polygon;

    for (int i = 0; i < lat; ++i)
    {
        float theta1 = i * 180 / lat;
        float theta2 = (i + 1) * 180 / lat;

        for (int j = 0; j < lon; ++j)
        {
            float phi1 = j * 360 / lon;
            float phi2 = (j + 1) * 360 / lon;

            Vector3 v1(radius * Sin(theta1) * Cos(phi1), radius * Cos(theta1), radius * Sin(theta1) * Sin(phi1));
            Vector3 v2(radius * Sin(theta2) * Cos(phi1), radius * Cos(theta2), radius * Sin(theta2) * Sin(phi1));
            Vector3 v3(radius * Sin(theta2) * Cos(phi2), radius * Cos(theta2), radius * Sin(theta2) * Sin(phi2));
            Vector3 v4(radius * Sin(theta1) * Cos(phi2), radius * Cos(theta1), radius * Sin(theta1) * Sin(phi2));

            polygon = Polygon(0xFFFFFF);
            polygon.add_vertex(v1);
            polygon.add_vertex(v2);
            polygon.add_vertex(v3);
            polygons.push_back(polygon);

            polygon = Polygon(0xFFFFFF);
            polygon.add_vertex(v1);
            polygon.add_vertex(v3);
            polygon.add_vertex(v4);
            polygons.push_back(polygon);
        }
    }

    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}

void Sphere::set_texture_repeat(const Vector2& repeat)
{
    texture_repeat = repeat;
}

void Sphere::set_texture(int texture)
{
    this->texture = texture;
}

void Sphere::set_color(int color)
{
    this->color = color;
}

void Sphere::refresh()
{
    polygons.clear();
    width = radius * 2;
    height = radius * 2;
    depth = radius * 2;

    name = "Sphere";

    Polygon polygon;

    for (int i = 0; i < lat; ++i)
    {
        float theta1 = i * 180 / lat;
        float theta2 = (i + 1) * 180 / lat;

        for (int j = 0; j < lon; ++j)
        {
            float phi1 = j * 360 / lon;
            float phi2 = (j + 1) * 360 / lon;

            Vector3 v1(radius * Sin(theta1) * Cos(phi1), radius * Cos(theta1), radius * Sin(theta1) * Sin(phi1));
            Vector3 v2(radius * Sin(theta2) * Cos(phi1), radius * Cos(theta2), radius * Sin(theta2) * Sin(phi1));
            Vector3 v3(radius * Sin(theta2) * Cos(phi2), radius * Cos(theta2), radius * Sin(theta2) * Sin(phi2));
            Vector3 v4(radius * Sin(theta1) * Cos(phi2), radius * Cos(theta1), radius * Sin(theta1) * Sin(phi2));

            polygon = Polygon(texture, 0xFFFFFF);
            polygon.set_texture_repeats(texture_repeat);
            polygon.add_vertex(v1);
            polygon.add_vertex(v2);
            polygon.add_vertex(v3);
            polygons.push_back(polygon);

            polygon = Polygon(texture, 0xFFFFFF);
            polygon.set_texture_repeats(texture_repeat);
            polygon.add_vertex(v1);
            polygon.add_vertex(v3);
            polygon.add_vertex(v4);
            polygons.push_back(polygon);
        }
    }

    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}

Sphere::~Sphere()
{
}
