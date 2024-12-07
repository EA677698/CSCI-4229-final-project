//
// Created by erickalanis on 12/5/24.
//

#include "pipe.h"

#define Cos(th) cos(3.14159265/180*(th))
#define Sin(th) sin(3.14159265/180*(th))


Pipe::Pipe(float radius, int sides) {
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

    for (unsigned int i = 0; i < path.size() - 1; i++) {

        Vector3 v1 = path[i];
        Vector3 v2 = path[i + 1];

        generate_basis(v1, v2);

        Vector3 b1 = basis_transformation(v1);
        Vector3 b2 = basis_transformation(v2);

        Vector3 diff = b2 - b1;
        diff.set_if_zero();

        printf("diff: %f, %f, %f\n", diff.x, diff.y, diff.z);

        Polygon polygon1 = Polygon(0xFF0000);
        Polygon polygon2 = Polygon(0x0000FF);

        for (int j = 0; j < sides; j++) {

            float angle = j * step;
            Vector3 v = Vector3(radius * Cos(angle), radius * Sin(angle), radius * Cos(angle));
            v *= diff;
            polygon1.add_vertex(normal_basis_transformation(b1 + v));
            polygon2.add_vertex(normal_basis_transformation(b2 + v));

        }

        polygons.push_back(polygon1);
        polygons.push_back(polygon2);

    }


        for (auto &polygon1: polygons) {
            polygon1.generate_texture_vertices();
            polygon1.print_vertices();
        }


}

Pipe::~Pipe() {}

void Pipe::generate_basis(const Vector3 &v1, const Vector3 &v2) {

    Vector3 direction_vector = v2 - v1;
    basis[0] = direction_vector.normalize();
    basis[1] = Vector3(0, 1, 0);
    basis[1] = direction_vector.is_parallel(basis[1]) ? Vector3(1, 0, 0) : basis[1];
    basis[1] = basis[1].normalize();
    basis[2] = Vector3::cross_product(basis[0], basis[1]).normalize();

}

Vector3 Pipe::basis_transformation(const Vector3 &v) {
    return {
            basis[0].x * v.x + basis[0].y * v.y + basis[0].z * v.z,
            basis[1].x * v.x + basis[1].y * v.y + basis[1].z * v.z,
            basis[2].x * v.x + basis[2].y * v.y + basis[2].z * v.z
    };
}

Vector3 Pipe::normal_basis_transformation(const Vector3 &v) {
    return {
            basis[0].x * v.x + basis[1].x * v.y + basis[2].x * v.z,
            basis[0].y * v.x + basis[1].y * v.y + basis[2].y * v.z,
            basis[0].z * v.x + basis[1].z * v.y + basis[2].z * v.z
    };
}
