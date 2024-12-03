//
// Created by erickalanis on 12/2/24.
//

#include "street_light.h"
#include "../primitives/cylinder.h"
#include "../primitives/cuboid.h"

StreetLight::StreetLight() {

    width = 1;
    height = 15;
    depth = 1;

    name = "Street Light";

    bounding_box = true;

    auto* pole = new Cylinder(width, height, depth, 10);
    pole->set_position(0, 0, 0);
    polyhedrons.push_back(pole);

    auto* pole_arm = new Cylinder(width, height * 3 / 4, depth, 10);
    pole_arm->set_rotation(90, 0, 0);
    pole_arm->set_position(0, 0, -pole->get_height() * 14 / 16);
    polyhedrons.push_back(pole_arm);

    auto* light_box = new Cuboid(width * 2, height / 4, depth * 2);
    light_box->set_position(0, pole_arm->get_height(), height / 2);
    light_box->construct_cuboid();
    polyhedrons.push_back(light_box);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }


}

void StreetLight::refresh() {

}

StreetLight::~StreetLight() {}
