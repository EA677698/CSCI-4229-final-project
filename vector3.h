#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector3
{
    
public:

    float x;
    float y;
    float z;

    Vector3();
    Vector3(float x, float y, float z);
    ~Vector3();
    Vector3 normalize();
    float get_magnitude();
    static float dot_product(Vector3 a, Vector3 b);
    static Vector3 cross_product(Vector3 a, Vector3 b);
};

#endif