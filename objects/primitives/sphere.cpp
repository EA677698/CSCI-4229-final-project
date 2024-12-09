//
// Created by erickalanis on 12/5/24.
//

#include "sphere.h"

#include "../texture.h"
#include <CSCIx229.h>

Sphere::Sphere(float radius, int slices, int stacks)
{
    width = radius * 2;
    height = radius * 2;
    depth = radius * 2;

    name = "Sphere";

    Polygon polygon;
    std::vector<float> vertices;
    float step = 360.0f / slices;
    float stack_step = 180.0f / stacks;

    for(int i = 0; i < stacks; i++)
    {
        for(int j = 0; j < slices; j++)
        {
            float theta = 360 * (j / slices);
            float phi = 90 - 180 * (i / stacks);
            float theta2 = 360 * ((j + 1) / slices);

            polygon = Polygon(NULL_TEXTURE, 0xFFFFFF);
        }
    }

}

void Sphere::set_texture_repeat(const Vector2 &repeat) {

}

void Sphere::set_texture(int texture) {

}

void Sphere::set_color(int color) {

}

void Sphere::refresh() {

}

Sphere::~Sphere() {}

