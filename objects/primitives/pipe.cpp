//
// Created by erickalanis on 12/5/24.
//

#include "pipe.h"

#define Cos(th) cos(3.14159265/180*(th))
#define Sin(th) sin(3.14159265/180*(th))

Vector3 Pipe::get_distance(const Vector3& a, const Vector3& b)
{
    return Vector3(b.x - a.x, b.y - a.y, b.z - a.z);
}

Pipe::Pipe(float radius, int sides)
{
    width = 1;
    height = 1;
    this->sides = sides;
    this->radius = radius;
}


void Pipe::refresh() {

}

void Pipe::set_texture_repeat(const Vector2 &repeat) {

}

void Pipe::set_texture(int texture) {

}

void Pipe::set_color(int color) {

}

void Pipe::add_point(const Vector3 &point) {

    path.push_back(point);

}

void Pipe::set_sides(int sides) {
    this->sides = sides;
}

void Pipe::generate_pipe() {

    float step = 360.0f / this->sides;
    Polygon polygon;

    for(unsigned int i = 0; i < path.size() - 1; i++){

        Vector3 a = path[i];
        Vector3 b = path[i + 1];

        for(int j = 0; j < this->sides; j++){

            float angle = j * step;
            float next_angle = (j + 1) * step;

            float z = this->width * Cos(angle);
            float y = this->depth * Sin(angle);

            float next_z = this->width * Cos(next_angle);
            float next_y = this->depth * Sin(next_angle);

            polygon = Polygon(0xFFFFFF);
            polygon.add_vertex(0, y, z);
            polygon.add_vertex(0, next_y, next_z);
            polygon.add_vertex(0, y, next_z);
            polygon.add_vertex(0, next_y, z);
            polygons.push_back(polygon);

        }

        for(auto& polygon1 : polygons){
            polygon1.generate_texture_vertices();
        }

    }


}

Pipe::~Pipe() {}

