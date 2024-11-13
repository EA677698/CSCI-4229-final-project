#include "vector2.h"
#include <math.h>

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2::~Vector2(){}

Vector2 Vector2::normalize()
{
    float magnitude = sqrt(x * x + y * y);
    float normalized_x = abs(x);
    float normalized_y = abs(y);
    if(x != 0){
        normalized_x /= magnitude;
    }
    if(y != 0){
        normalized_y /= magnitude;
    }
    return Vector2(normalized_x, normalized_y);
}