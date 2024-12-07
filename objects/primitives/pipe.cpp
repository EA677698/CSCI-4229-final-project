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
    this->name = "Pipe";
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
    this->sides = sides > 2 ? sides : 3;
}

void Pipe::generate_pipe(bool render_endcaps) {

    float step = 360.0f / this->sides;

    for (unsigned int i = 0; i < path.size() - 1; i++) {

        Vector3 v1 = path[i];
        Vector3 v2 = path[i + 1];

        generate_basis(v1, v2);

        Vector3 b1 = basis_transformation(v1);
        Vector3 b2 = basis_transformation(v2);

        Polygon polygon1 = Polygon(0xFF0000);
        Polygon polygon2 = Polygon(0x0000FF);

        for (int j = 0; j < sides; j++) {

            float angle = j * step;
            Vector3 v = Vector3(radius * Cos(angle), radius * Sin(angle), radius * Cos(angle));
            Vector3 p1 = normal_basis_transformation(b1 + v);
            Vector3 p2 = normal_basis_transformation(b2 + v);
            polygon1.add_vertex(p1);
            polygon2.add_vertex(p2);

            check_bounds(p1);
            check_bounds(p2);

        }

        Polygon polygon;
        for(int j = 0; j < sides; j++){
            polygon = Polygon(0xFFFFFF >> j);
            unsigned int next = (j + 1) % sides;
            polygon.add_vertex(polygon1.get_vertices()[j]);
            polygon.add_vertex(polygon2.get_vertices()[j]);
            polygon.add_vertex(polygon2.get_vertices()[next]);
            polygon.add_vertex(polygon1.get_vertices()[next]);
            polygons.push_back(polygon);
        }

        if (render_endcaps) {
            polygons.push_back(polygon1);
            polygons.push_back(polygon2);
        }

    }

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
        polygon1.print_vertices();
    }

    recompute_size();

}

Pipe::~Pipe() {}

void Pipe::generate_basis(const Vector3 &v1, const Vector3 &v2) {

    Vector3 direction_vector = (v2 - v1).normalize();
    basis[2] = direction_vector;
    basis[1] = Vector3(0, 1, 0);
    if (basis[1].is_parallel(basis[2])) {
        basis[1] = Vector3(1, 0, 0);
    }
    basis[0] = Vector3::cross_product(basis[1], basis[2]).normalize();
    basis[1] = Vector3::cross_product(basis[2], basis[0]).normalize();

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

void Pipe::check_bounds(const Vector3 &v) {

    bounds[0].x = fmin(bounds[0].x, v.x);
    bounds[0].y = fmin(bounds[0].y, v.y);
    bounds[0].z = fmin(bounds[0].z, v.z);
    bounds[1].x = fmax(bounds[1].x, v.x);
    bounds[1].y = fmax(bounds[1].y, v.y);
    bounds[1].z = fmax(bounds[1].z, v.z);

}

void Pipe::recompute_size() {

    width = bounds[1].x - bounds[0].x;
    height = bounds[1].y - bounds[0].y;
    depth = bounds[1].z - bounds[0].z;

}

void Pipe::set_radius(float radius) {
    this->radius = radius;
}
