//
// Created by erickalanis on 11/28/24.
//

#include "curve.h"
#include "cuboid.h"


Curve::Curve(int definition, float width, float height, float depth) {

    this->definition = definition;
    this->width = width;
    this->height = height;
    this->depth = depth;

    name = "Curve";
}

void Curve::add_point(const Vector3& point) {

    points.push_back(point);

}

void Curve::clear_points() {

    points.clear();

}

Vector3 Curve::calculate_point(float t) {

    if (points.size() < 2){
        return {0, 0, 0};
    }

    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    Vector3 p = points[0] * uuu;
    p += points[1] * 3 * uu * t;
    p += points[2] * 3 * u * tt;
    p += points[3] * ttt;

    return p;

}


void Curve::refresh() {

    if(points.size() < 2){
        return;
    }

    polygons.clear();

    for (int i = 0; i < definition; i++) {

        float t = (float)i / (definition - 1);
        float t2 = (float)(i + 1) / (definition - 1);

        Vector3 p1 = calculate_point(t);
        Vector3 p2 = calculate_point(t2);

        Vector3 p3 = calculate_point(t + 0.01);
        Vector3 p4 = calculate_point(t2 - 0.01);


        Polygon polygon = Polygon(0xFFFFFF);
        polygon.add_vertex(p1.x, p1.y, p1.z);
        polygon.add_vertex(p2.x, p2.y, p2.z);
        polygon.add_vertex(p4.x, p4.y, p4.z);
        polygon.add_vertex(p3.x, p3.y, p3.z);
        polygons.push_back(polygon);

    }

}

