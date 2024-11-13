#include "vector3.h"

Vector3::Vector3(){
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::~Vector3(){}

float Vector3::get_magnitude(){
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize(){
    float magnitude = sqrt(x * x + y * y + z * z);
    return Vector3(x / magnitude, y / magnitude, z / magnitude);
}

float Vector3::dot_product(Vector3 a, Vector3 b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::cross_product(Vector3 a, Vector3 b){
    return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}


