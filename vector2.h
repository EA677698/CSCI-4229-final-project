#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
    
public:
    float x;
    float y;

    Vector2();
    Vector2(float x, float y);
    ~Vector2();

    Vector2 normalize();
    float get_magnitude() const;
};

#endif