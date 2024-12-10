//
// Created by erickalanis on 12/10/24.
//

#include "vector4.h"

#include <math.h>

Vector4::Vector4()
{
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

Vector4::Vector4(const float x, const float y, const float z, const float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float Vector4::get_magnitude() const
{
    return sqrt(x * x + y * y + z * z + w * w);
}

Vector4::~Vector4()
{
}
