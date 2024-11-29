//
// Created by erickalanis on 11/27/24.
//

#include "eiffel_tower.h"
#include "primitives/cuboid.h"

EiffelTower::EiffelTower() {

    width = 125;
    height = 300;
    depth = 125;

    bounding_box = true;

    // layer 1

    float leg1_proportion = 0.192307f;
    float first_layer_height = height * 0.19f * (5.0f / 6.5f);

    // base
    auto* platform1 = new Cuboid(width * (8.0f / 13.0f), height * 0.19f * (1.5f / 6.5f), depth * (8.0f / 13.0f));
    platform1->set_position(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    platform1->construct_cuboid();
    polyhedrons.push_back(platform1);

    // Back left leg
    auto* bl_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    bl_leg->set_position(0, 0, 0);
    bl_leg->add_vector(BACK_TOP_RIGHT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(BACK_TOP_LEFT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(FRONT_TOP_RIGHT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(FRONT_TOP_LEFT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->construct_cuboid();
    polyhedrons.push_back(bl_leg);

    // Back right leg
    auto* br_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    br_leg->set_position(width - br_leg->get_width(), 0, 0);
    br_leg->add_vector(BACK_TOP_RIGHT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(BACK_TOP_LEFT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(FRONT_TOP_RIGHT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(FRONT_TOP_LEFT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->construct_cuboid();
    polyhedrons.push_back(br_leg);

    // Front left leg
    auto* fl_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    fl_leg->set_position(0, 0, depth - fl_leg->get_depth());
    fl_leg->add_vector(BACK_TOP_RIGHT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(BACK_TOP_LEFT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(FRONT_TOP_RIGHT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(FRONT_TOP_LEFT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->construct_cuboid();
    polyhedrons.push_back(fl_leg);

    // Front right leg
    auto* fr_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    fr_leg->set_position(width - fr_leg->get_width(), 0, depth - fr_leg->get_depth());
    fr_leg->add_vector(BACK_TOP_RIGHT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(BACK_TOP_LEFT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(FRONT_TOP_RIGHT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(FRONT_TOP_LEFT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->construct_cuboid();
    polyhedrons.push_back(fr_leg);

    // layer 2
    float leg2_proportion = 0.142857f;
    float second_layer_height = height * 0.19f * (2.0f / 3.0f);

    auto platform2 = new Cuboid(platform1->get_width() * (2.3f / 4.0f), height * 0.19f * (1.0f / 3.0f), platform1->get_depth() * (2.3f / 4.0f));
    platform2->set_position(leg2_proportion * width + platform2->get_width() / 2, (height * 0.19f) + second_layer_height , leg2_proportion * depth + platform2->get_depth() / 2);
    platform2->construct_cuboid();
    polyhedrons.push_back(platform2);

    // Back left leg
    auto* bl_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    bl_leg2->set_position(leg1_proportion * width, height * 0.19f, leg1_proportion * depth);
    bl_leg2->add_vector(BACK_TOP_RIGHT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(BACK_TOP_LEFT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(FRONT_TOP_RIGHT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(FRONT_TOP_LEFT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->construct_cuboid();
    polyhedrons.push_back(bl_leg2);

    // Back right leg
    auto* br_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    br_leg2->set_position(width - (leg1_proportion * width) - (width * leg2_proportion), height * 0.19f, leg1_proportion * depth);
    br_leg2->add_vector(BACK_TOP_RIGHT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(BACK_TOP_LEFT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(FRONT_TOP_RIGHT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(FRONT_TOP_LEFT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->construct_cuboid();
    polyhedrons.push_back(br_leg2);

    // Front left leg
    auto* fl_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    fl_leg2->set_position(leg1_proportion * width, height * 0.19f, depth - fl_leg->get_depth() - fl_leg2->get_depth());
    fl_leg2->add_vector(BACK_TOP_RIGHT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(BACK_TOP_LEFT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(FRONT_TOP_RIGHT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(FRONT_TOP_LEFT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->construct_cuboid();
    polyhedrons.push_back(fl_leg2);

    // Front right leg
    auto* fr_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    fr_leg2->set_position(width - (leg1_proportion * width) - (width * leg2_proportion), height * 0.19f, depth - fl_leg->get_depth() - fl_leg2->get_depth());
    fr_leg2->add_vector(BACK_TOP_RIGHT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(BACK_TOP_LEFT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(FRONT_TOP_RIGHT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(FRONT_TOP_LEFT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->construct_cuboid();
    polyhedrons.push_back(fr_leg2);

    // layer 3


    for(auto& polygon1 : polygons){
        polygon1.generate_texture_vertices();
    }
}

EiffelTower::~EiffelTower() {}
