#include "vector2.h"
#include <math.h>

Vector2::Vector2(){
    x = 0;
    y = 0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2::~Vector2(){}

float Vector2::get_magnitude()
{
    return sqrt(x * x + y * y);
}

Vector2 Vector2::normalize()
{
    float magnitude = get_magnitude();
    float normalized_x = x;
    float normalized_y = y;
    if(x != 0){
        normalized_x /= magnitude;
    }
    if(y != 0){
        normalized_y /= magnitude;
    }
    return Vector2(normalized_x, normalized_y);
}