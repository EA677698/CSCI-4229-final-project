//
// Created by erickalanis on 12/5/24.
//

#include "street_light.h"
#include "../texture.h"
#include "../primitives/cylinder.h"
#include "../primitives/pyramid.h"

StreetLight::StreetLight()
{
    width = 1;
    height = 15;
    depth = 1;

    name = "Street Light";

    bounding_box = true;

    auto* pole = new Cylinder(width, height, depth, 10);
    pole->set_position(0, 0, 0);
    pole->set_texture(GALVANIZED_METAL_TEXTURE);
    pole->set_color(0x696969);
    pole->set_texture_repeat({1.5, 0.5});
    polyhedrons.push_back(pole);

    auto* pole_arm = new Cylinder(width, height * 3 / 4, depth, 10);
    pole_arm->set_rotation(90, 0, 0);
    pole_arm->set_position(0, 0, -pole->get_height() * 14 / 16);
    pole_arm->set_texture(GALVANIZED_METAL_TEXTURE);
    pole_arm->set_color(0x696969);
    pole_arm->set_texture_repeat({1.5, 0.5});
    polyhedrons.push_back(pole_arm);

    auto* lamp_case = new Pyramid(width * 2, 2, depth * 2, 10);
    lamp_case->set_position(pole_arm->get_position().x, -pole_arm->get_position().z - pole_arm->get_depth() - lamp_case->get_height() * 0.8f, pole_arm->get_height() - lamp_case->get_depth() / 4);
    lamp_case->set_color(0xFF0000);
    polyhedrons.push_back(lamp_case);
}



void StreetLight::refresh() {

}

StreetLight::~StreetLight() {}
