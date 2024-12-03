//
// Created by erickalanis on 12/2/24.
//

#include "light_intersection.h"

#include "../generic/street_light.h"
#include "../generic/intersection.h"


LightIntersection::LightIntersection() {

    width = 62;
    height = 15;
    depth = 52;

    name = "Light Intersection";

    Intersection *intersection = new Intersection();
    intersection->set_position(0, 0, 0);
    polyhedrons.push_back(intersection);

    // left
    StreetLight *street_light1 = new StreetLight();
    street_light1->set_position(-4, 0, -4);
    polyhedrons.push_back(street_light1);

    // right
    StreetLight *street_light2 = new StreetLight();
    street_light2->set_rotation(-180, 0, -180);
    street_light2->set_position(-16, 0, -16);
    polyhedrons.push_back(street_light2);

    // bottom
    StreetLight *street_light3 = new StreetLight();
    street_light3->set_rotation(0, 90, 0);
    street_light3->set_position(-16, 0, -4);
    polyhedrons.push_back(street_light3);

    // top
    StreetLight *street_light4 = new StreetLight();
    street_light4->set_rotation(0, -90, 0);
    street_light4->set_position(-4, 0, -16);
    polyhedrons.push_back(street_light4);

}

void LightIntersection::refresh() {

}

LightIntersection::~LightIntersection() {}
