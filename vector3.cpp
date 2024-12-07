#include "vector3.h"

Vector3::Vector3() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(const float x, const float y, const float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::~Vector3() {}

float Vector3::get_magnitude() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize() const {
    float magnitude = get_magnitude();
    return {x / magnitude, y / magnitude, z / magnitude};
}

float Vector3::dot_product(const Vector3 &a, const Vector3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::cross_product(const Vector3 &a, const Vector3 &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

bool Vector3::is_parallel(const Vector3 &v) const {
    return cross_product(*this, v) == Vector3(0, 0, 0);
}

void Vector3::set_if_zero() {
    int sum = x + y + z;

    if(sum == 1){
        x = x == 0;
        y = y == 0;
        z = z == 0;
    } else {
        x = x != 0;
        y = y != 0;
        z = z != 0;
    }


}




