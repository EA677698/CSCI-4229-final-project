#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

#include "vector4.h"

class Vector3
{
public:
    float x;
    float y;
    float z;

    bool operator==(const Vector3& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    Vector3 operator+(const Vector3& v) const
    {
        return {x + v.x, y + v.y, z + v.z};
    }

    Vector3& operator+=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3& operator*=(const Vector3& v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    Vector3& operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3 operator*(const float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vector3& operator-=(const Vector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3 operator-(const Vector3& v) const
    {
        return {x - v.x, y - v.y, z - v.z};
    }

    operator Vector4() const
    {
        return Vector4(x, y, z, 1.0f); // Default w = 1.0f
    }

    operator const float *() const {
        return &x;
    }

    Vector3();

    Vector3(float x, float y, float z);

    ~Vector3();

    Vector3 normalize() const;

    float get_magnitude() const;

    static float dot_product(const Vector3& a, const Vector3& b);

    static Vector3 cross_product(const Vector3& a, const Vector3& b);

    bool is_parallel(const Vector3& v) const;
};

#endif
