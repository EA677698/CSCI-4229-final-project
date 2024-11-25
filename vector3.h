#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector3 {

public:

    float x;
    float y;
    float z;

    Vector3 operator+(const Vector3 &v) const {
        return {x + v.x, y + v.y, z + v.z};
    }

    Vector3 operator+=(const Vector3 &v) const {
        return {x + v.x, y + v.y, z + v.z};
    }

    Vector3();

    Vector3(float x, float y, float z);

    ~Vector3();

    Vector3 normalize() const;

    float get_magnitude() const;

    static float dot_product(const Vector3 &a, const Vector3 &b);

    static Vector3 cross_product(const Vector3 &a, const Vector3 &b);
};

#endif