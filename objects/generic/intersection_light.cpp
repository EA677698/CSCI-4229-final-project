//
// Created by erickalanis on 12/2/24.
//

#include "intersection_light.h"
#include "../primitives/cylinder.h"
#include "../primitives/cuboid.h"
#include "../../texture.h"

IntersectionLight::IntersectionLight() {

    width = 1;
    height = 15;
    depth = 1;

    name = "Intersection Light";

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

    auto* light_box = new Cuboid(width * 2, height / 3, depth * 2);
    light_box->set_position(0, pole_arm->get_height() * 0.95f, height * 0.45f);
    for(int i = 0; i < 6; i++){
        light_box->set_texture(i, GALVANIZED_METAL_TEXTURE);
        light_box->set_color(i, 0x404040);
    }
    light_box->construct_cuboid();

    polyhedrons.push_back(light_box);

    auto* red_light = new Cylinder(width / 2, light_box->get_depth() / 4, depth / 2, 10);
    red_light->set_texture(NO_TEXTURE);
    red_light->set_rotation(0, 0, 90);
    red_light->set_position(light_box->get_position().y + light_box->get_height() * 0.8f, -light_box->get_depth() - red_light->get_depth(), light_box->get_position().z + light_box->get_width() / 2);
    red_light->set_color(0xFF0000);
    polyhedrons.push_back(red_light);

    auto* yellow_light = new Cylinder(width / 2, light_box->get_depth() / 4, depth / 2, 10);
    yellow_light->set_texture(NO_TEXTURE);
    yellow_light->set_rotation(0, 0, 90);
    yellow_light->set_position(light_box->get_position().y + light_box->get_height() * 0.5f, -light_box->get_depth() - yellow_light->get_depth(), light_box->get_position().z + light_box->get_width() / 2);
    yellow_light->set_color(0xFFFF00);
    polyhedrons.push_back(yellow_light);

    auto* green_light = new Cylinder(width / 2, light_box->get_depth() / 4, depth / 2, 10);
    green_light->set_texture(NO_TEXTURE);
    green_light->set_rotation(0, 0, 90);
    green_light->set_position(light_box->get_position().y + light_box->get_height() * 0.2f, -light_box->get_depth() - green_light->get_depth(), light_box->get_position().z + light_box->get_width() / 2);
    green_light->set_color(0x00FF00);
    polyhedrons.push_back(green_light);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }


}

void IntersectionLight::refresh() {

}

IntersectionLight::~IntersectionLight() {}
