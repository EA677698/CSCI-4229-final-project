//
// Created by erickalanis on 12/5/24.
//

#include "sphere.h"

Sphere::Sphere(float radius, int slices, int stacks)
{
    width = radius * 2;
    height = radius * 2;
    depth = radius * 2;

    name = "Sphere";

    Polygon polygon;
    float step = 360.0f / slices;
    float stack_step = 180.0f / stacks;


}
