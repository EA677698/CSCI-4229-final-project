#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    float x;
    float y;

    bool operator==(const Vector2& v) const
    {
        return x == v.x && y == v.y;
    }

    Vector2 operator+(const Vector2& v) const
    {
        return {x + v.x, y + v.y};
    }

    Vector2& operator+=(const Vector2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2& operator*=(const Vector2& v)
    {
        x *= v.x;
        y *= v.y;
        return *this;
    }

    Vector2& operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2 operator*(const float scalar) const
    {
        return {x * scalar, y * scalar};
    }

    Vector2& operator-=(const Vector2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2 operator-(const Vector2& v) const
    {
        return {x - v.x, y - v.y};
    }

    Vector2();

    Vector2(float x, float y);

    ~Vector2();

    Vector2 normalize();

    float get_magnitude() const;
};

#endif
