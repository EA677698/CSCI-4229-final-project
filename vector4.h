//
// Created by erickalanis on 12/10/24.
//

#ifndef VECTOR4_H
#define VECTOR4_H

class Vector4 {
public:
    float x;
    float y;
    float z;
    float w;

    bool operator==(const Vector4 &v) const {
        return x == v.x && y == v.y && z == v.z && w == v.w;
    }

    Vector4 operator+(const Vector4 &v) const {
        return {x + v.x, y + v.y, z + v.z, w + v.w};
    }

    Vector4 &operator+=(const Vector4 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }

    Vector4 &operator*=(const Vector4 &v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        w *= v.w;
        return *this;
    }

    Vector4 &operator*=(const float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vector4 operator*(const float scalar) const {
        return {x * scalar, y * scalar, z * scalar, w * scalar};
    }

    Vector4 &operator-=(const Vector4 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }

    Vector4 operator-(const Vector4 &v) const {
        return {x - v.x, y - v.y, z - v.z, w - v.w};
    }

    operator const float *() const {
        return &x;
    }

    Vector4();

    Vector4(float x, float y, float z, float w);

    float get_magnitude() const;

    ~Vector4();
};


#endif //VECTOR4_H
