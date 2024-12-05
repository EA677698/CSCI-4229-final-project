//
// Created by erickalanis on 12/5/24.
//

#include "pipe.h"


Vector3 Pipe::get_distance(const Vector3& a, const Vector3& b)
{
    return Vector3(b.x - a.x, b.y - a.y, b.z - a.z);
}

Pipe::Pipe(int sides, Vector3... path)
{
    width = 1;
    height = 1;
    this->sides = sides;

    float step = 360.0f / this->sides;

}
