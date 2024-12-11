//
// Created by erickalanis on 11/27/24.
//

#include "eiffel_tower.h"
#include "../primitives/cuboid.h"
#include "../../texture.h"

EiffelTower::EiffelTower()
{
    width = 125;
    height = 300;
    depth = 125;

    name = "Eiffel Tower";

    bounding_box = true;

    // layer 1

    float leg1_proportion = 0.192307f;
    float first_layer_height = height * 0.19f * (5.0f / 6.5f);

    // base
    auto* platform1 = new Cuboid(width * (8.0f / 13.0f), height * 0.19f * (1.5f / 6.5f), depth * (8.0f / 13.0f));
    platform1->set_position(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    platform1->set_texture_to_all(BRASS_TEXTURE);
    platform1->construct_cuboid();
    polyhedrons.push_back(platform1);

    // Back left leg
    auto* bl_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    bl_leg->set_position(0, 0, 0);
    bl_leg->add_vector(BACK_TOP_RIGHT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(BACK_TOP_LEFT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(FRONT_TOP_RIGHT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(FRONT_TOP_LEFT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->set_texture_to_all(BRASS_TEXTURE);
    bl_leg->construct_cuboid();
    polyhedrons.push_back(bl_leg);

    // Back right leg
    auto* br_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    br_leg->set_position(width - br_leg->get_width(), 0, 0);
    br_leg->add_vector(BACK_TOP_RIGHT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(BACK_TOP_LEFT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(FRONT_TOP_RIGHT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(FRONT_TOP_LEFT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->set_texture_to_all(BRASS_TEXTURE);
    br_leg->construct_cuboid();
    polyhedrons.push_back(br_leg);

    // Front left leg
    auto* fl_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    fl_leg->set_position(0, 0, depth - fl_leg->get_depth());
    fl_leg->add_vector(BACK_TOP_RIGHT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(BACK_TOP_LEFT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(FRONT_TOP_RIGHT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(FRONT_TOP_LEFT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->set_texture_to_all(BRASS_TEXTURE);
    fl_leg->construct_cuboid();
    polyhedrons.push_back(fl_leg);

    // Front right leg
    auto* fr_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    fr_leg->set_position(width - fr_leg->get_width(), 0, depth - fr_leg->get_depth());
    fr_leg->add_vector(BACK_TOP_RIGHT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(BACK_TOP_LEFT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(FRONT_TOP_RIGHT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(FRONT_TOP_LEFT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->set_texture_to_all(BRASS_TEXTURE);
    fr_leg->construct_cuboid();
    polyhedrons.push_back(fr_leg);

    // layer 2
    float leg2_proportion = 0.142857f;
    float second_layer_height = height * 0.19f * (2.0f / 3.0f);

    auto platform2 = new Cuboid(platform1->get_width() * (2.3f / 4.0f), height * 0.19f * (1.0f / 3.0f),
                                platform1->get_depth() * (2.3f / 4.0f));
    platform2->set_position(leg2_proportion * width + platform2->get_width() / 2,
                            (height * 0.19f) + second_layer_height,
                            leg2_proportion * depth + platform2->get_depth() / 2);
    platform2->set_texture_to_all(BRASS_TEXTURE);
    platform2->construct_cuboid();
    polyhedrons.push_back(platform2);

    // Back left leg
    auto* bl_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    bl_leg2->set_position(leg1_proportion * width, height * 0.19f, leg1_proportion * depth);
    bl_leg2->add_vector(BACK_TOP_RIGHT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(BACK_TOP_LEFT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(FRONT_TOP_RIGHT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(FRONT_TOP_LEFT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->set_texture_to_all(BRASS_TEXTURE);
    bl_leg2->construct_cuboid();
    polyhedrons.push_back(bl_leg2);

    // Back right leg
    auto* br_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    br_leg2->set_position(width - (leg1_proportion * width) - (width * leg2_proportion), height * 0.19f,
                          leg1_proportion * depth);
    br_leg2->add_vector(BACK_TOP_RIGHT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(BACK_TOP_LEFT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(FRONT_TOP_RIGHT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(FRONT_TOP_LEFT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->set_texture_to_all(BRASS_TEXTURE);
    br_leg2->construct_cuboid();
    polyhedrons.push_back(br_leg2);

    // Front left leg
    auto* fl_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    fl_leg2->set_position(leg1_proportion * width, height * 0.19f, depth - fl_leg->get_depth() - fl_leg2->get_depth());
    fl_leg2->add_vector(BACK_TOP_RIGHT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(BACK_TOP_LEFT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(FRONT_TOP_RIGHT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(FRONT_TOP_LEFT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->set_texture_to_all(BRASS_TEXTURE);
    fl_leg2->construct_cuboid();
    polyhedrons.push_back(fl_leg2);

    // Front right leg
    auto* fr_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    fr_leg2->set_position(width - (leg1_proportion * width) - (width * leg2_proportion), height * 0.19f,
                          depth - fl_leg->get_depth() - fl_leg2->get_depth());
    fr_leg2->add_vector(BACK_TOP_RIGHT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(BACK_TOP_LEFT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(FRONT_TOP_RIGHT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(FRONT_TOP_LEFT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->set_texture_to_all(BRASS_TEXTURE);
    fr_leg2->construct_cuboid();
    polyhedrons.push_back(fr_leg2);

    // layer 3

    float leg3_proportion = 0.0714;
    float third_layer_height = height * 0.54f * (7.0f / 8.5f);

    auto* platform3 = new Cuboid(platform2->get_width() * (1.3f / 2.3f), height * 0.54f * (0.5f / 8.5f),
                                 platform2->get_width() * (1.3f / 2.3f));
    platform3->set_position(leg1_proportion * width + leg2_proportion * width + leg3_proportion * width,
                            height * 0.38f + third_layer_height,
                            leg2_proportion * depth + platform2->get_depth() / 2 + platform3->get_width() / 3);
    platform3->set_texture_to_all(BRASS_TEXTURE);
    platform3->construct_cuboid();
    polyhedrons.push_back(platform3);

    // Back left leg
    auto* bl_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    bl_leg3->set_position(leg1_proportion * width + leg2_proportion * width, height * 0.38f,
                          leg2_proportion * depth + platform2->get_depth() / 2);
    bl_leg3->add_vector(BACK_TOP_RIGHT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->add_vector(BACK_TOP_LEFT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->add_vector(FRONT_TOP_RIGHT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->add_vector(FRONT_TOP_LEFT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->set_texture_to_all(BRASS_TEXTURE);
    bl_leg3->construct_cuboid();
    polyhedrons.push_back(bl_leg3);

    // Back right leg
    auto* br_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    br_leg3->set_position(width - (leg1_proportion * width) - (width * leg2_proportion) - (width * leg3_proportion),
                          height * 0.38f, leg2_proportion * depth + platform2->get_depth() / 2);
    br_leg3->add_vector(BACK_TOP_RIGHT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->add_vector(BACK_TOP_LEFT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->add_vector(FRONT_TOP_RIGHT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->add_vector(FRONT_TOP_LEFT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->set_texture_to_all(BRASS_TEXTURE);
    br_leg3->construct_cuboid();
    polyhedrons.push_back(br_leg3);

    // Front left leg
    auto* fl_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    fl_leg3->set_position(leg1_proportion * width + leg2_proportion * width, height * 0.38f,
                          depth - fl_leg->get_depth() - fl_leg3->get_depth() * 3);
    fl_leg3->add_vector(BACK_TOP_RIGHT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->add_vector(BACK_TOP_LEFT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->add_vector(FRONT_TOP_RIGHT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->add_vector(FRONT_TOP_LEFT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->set_texture_to_all(BRASS_TEXTURE);
    fl_leg3->construct_cuboid();
    polyhedrons.push_back(fl_leg3);

    // Front right leg
    auto* fr_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    fr_leg3->set_position(width - (leg1_proportion * width) - (width * leg2_proportion) - (width * leg3_proportion),
                          height * 0.38f, depth - fl_leg->get_depth() - fl_leg3->get_depth() * 3);
    fr_leg3->add_vector(BACK_TOP_RIGHT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->add_vector(BACK_TOP_LEFT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->add_vector(FRONT_TOP_RIGHT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->add_vector(FRONT_TOP_LEFT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->set_texture_to_all(BRASS_TEXTURE);
    fr_leg3->construct_cuboid();
    polyhedrons.push_back(fr_leg3);

    auto* antenna = new Cuboid(5, height * 0.17f, 5);
    antenna->set_position(width / 2 - antenna->get_width() / 2, height * 0.38f + third_layer_height,
                          depth / 2 - antenna->get_depth() / 2);
    antenna->set_texture_to_all(BRASS_TEXTURE);
    antenna->construct_cuboid();
    polyhedrons.push_back(antenna);


    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}

EiffelTower::~EiffelTower()
{
}

void EiffelTower::refresh()
{
    polygons.clear();
    polyhedrons.clear();

    float leg1_proportion = 0.192307f;
    float first_layer_height = height * 0.19f * (5.0f / 6.5f);

    // base
    auto* platform1 = new Cuboid(width * (8.0f / 13.0f), height * 0.19f * (1.5f / 6.5f), depth * (8.0f / 13.0f));
    platform1->set_position(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    platform1->set_texture_to_all(BRASS_TEXTURE);
    platform1->construct_cuboid();
    polyhedrons.push_back(platform1);

    // Back left leg
    auto* bl_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    bl_leg->set_position(0, 0, 0);
    bl_leg->add_vector(BACK_TOP_RIGHT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(BACK_TOP_LEFT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(FRONT_TOP_RIGHT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->add_vector(FRONT_TOP_LEFT, leg1_proportion * width, 0, leg1_proportion * depth);
    bl_leg->set_texture_to_all(BRASS_TEXTURE);
    bl_leg->construct_cuboid();
    polyhedrons.push_back(bl_leg);

    // Back right leg
    auto* br_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    br_leg->set_position(width - br_leg->get_width(), 0, 0);
    br_leg->add_vector(BACK_TOP_RIGHT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(BACK_TOP_LEFT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(FRONT_TOP_RIGHT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->add_vector(FRONT_TOP_LEFT, -leg1_proportion * width, 0, leg1_proportion * depth);
    br_leg->set_texture_to_all(BRASS_TEXTURE);
    br_leg->construct_cuboid();
    polyhedrons.push_back(br_leg);

    // Front left leg
    auto* fl_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    fl_leg->set_position(0, 0, depth - fl_leg->get_depth());
    fl_leg->add_vector(BACK_TOP_RIGHT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(BACK_TOP_LEFT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(FRONT_TOP_RIGHT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->add_vector(FRONT_TOP_LEFT, leg1_proportion * width, 0, -leg1_proportion * depth);
    fl_leg->set_texture_to_all(BRASS_TEXTURE);
    fl_leg->construct_cuboid();
    polyhedrons.push_back(fl_leg);

    // Front right leg
    auto* fr_leg = new Cuboid(leg1_proportion * width, first_layer_height, leg1_proportion * depth);
    fr_leg->set_position(width - fr_leg->get_width(), 0, depth - fr_leg->get_depth());
    fr_leg->add_vector(BACK_TOP_RIGHT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(BACK_TOP_LEFT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(FRONT_TOP_RIGHT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->add_vector(FRONT_TOP_LEFT, -leg1_proportion * width, 0, -leg1_proportion * depth);
    fr_leg->set_texture_to_all(BRASS_TEXTURE);
    fr_leg->construct_cuboid();
    polyhedrons.push_back(fr_leg);

    // layer 2
    float leg2_proportion = 0.142857f;
    float second_layer_height = height * 0.19f * (2.0f / 3.0f);

    auto platform2 = new Cuboid(platform1->get_width() * (2.3f / 4.0f), height * 0.19f * (1.0f / 3.0f),
                                platform1->get_depth() * (2.3f / 4.0f));
    platform2->set_position(leg2_proportion * width + platform2->get_width() / 2,
                            (height * 0.19f) + second_layer_height,
                            leg2_proportion * depth + platform2->get_depth() / 2);
    platform2->set_texture_to_all(BRASS_TEXTURE);
    platform2->construct_cuboid();
    polyhedrons.push_back(platform2);

    // Back left leg
    auto* bl_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    bl_leg2->set_position(leg1_proportion * width, height * 0.19f, leg1_proportion * depth);
    bl_leg2->add_vector(BACK_TOP_RIGHT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(BACK_TOP_LEFT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(FRONT_TOP_RIGHT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->add_vector(FRONT_TOP_LEFT, leg2_proportion * width, 0, leg2_proportion * depth);
    bl_leg2->set_texture_to_all(BRASS_TEXTURE);
    bl_leg2->construct_cuboid();
    polyhedrons.push_back(bl_leg2);

    // Back right leg
    auto* br_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    br_leg2->set_position(width - (leg1_proportion * width) - (width * leg2_proportion), height * 0.19f,
                          leg1_proportion * depth);
    br_leg2->add_vector(BACK_TOP_RIGHT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(BACK_TOP_LEFT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(FRONT_TOP_RIGHT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->add_vector(FRONT_TOP_LEFT, -leg2_proportion * width, 0, leg2_proportion * depth);
    br_leg2->set_texture_to_all(BRASS_TEXTURE);
    br_leg2->construct_cuboid();
    polyhedrons.push_back(br_leg2);

    // Front left leg
    auto* fl_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    fl_leg2->set_position(leg1_proportion * width, height * 0.19f, depth - fl_leg->get_depth() - fl_leg2->get_depth());
    fl_leg2->add_vector(BACK_TOP_RIGHT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(BACK_TOP_LEFT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(FRONT_TOP_RIGHT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->add_vector(FRONT_TOP_LEFT, leg2_proportion * width, 0, -leg2_proportion * depth);
    fl_leg2->set_texture_to_all(BRASS_TEXTURE);
    fl_leg2->construct_cuboid();
    polyhedrons.push_back(fl_leg2);

    // Front right leg
    auto* fr_leg2 = new Cuboid(leg2_proportion * width, second_layer_height, leg2_proportion * depth);
    fr_leg2->set_position(width - (leg1_proportion * width) - (width * leg2_proportion), height * 0.19f,
                          depth - fl_leg->get_depth() - fl_leg2->get_depth());
    fr_leg2->add_vector(BACK_TOP_RIGHT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(BACK_TOP_LEFT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(FRONT_TOP_RIGHT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->add_vector(FRONT_TOP_LEFT, -leg2_proportion * width, 0, -leg2_proportion * depth);
    fr_leg2->set_texture_to_all(BRASS_TEXTURE);
    fr_leg2->construct_cuboid();
    polyhedrons.push_back(fr_leg2);

    // layer 3

    float leg3_proportion = 0.0714;
    float third_layer_height = height * 0.54f * (7.0f / 8.5f);

    auto* platform3 = new Cuboid(platform2->get_width() * (1.3f / 2.3f), height * 0.54f * (0.5f / 8.5f),
                                 platform2->get_width() * (1.3f / 2.3f));
    platform3->set_position(leg1_proportion * width + leg2_proportion * width + leg3_proportion * width,
                            height * 0.38f + third_layer_height,
                            leg2_proportion * depth + platform2->get_depth() / 2 + platform3->get_width() / 3);
    platform3->set_texture_to_all(BRASS_TEXTURE);
    platform3->construct_cuboid();
    polyhedrons.push_back(platform3);

    // Back left leg
    auto* bl_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    bl_leg3->set_position(leg1_proportion * width + leg2_proportion * width, height * 0.38f,
                          leg2_proportion * depth + platform2->get_depth() / 2);
    bl_leg3->add_vector(BACK_TOP_RIGHT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->add_vector(BACK_TOP_LEFT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->add_vector(FRONT_TOP_RIGHT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->add_vector(FRONT_TOP_LEFT, leg3_proportion * width, 0, leg3_proportion * depth);
    bl_leg3->set_texture_to_all(BRASS_TEXTURE);
    bl_leg3->construct_cuboid();
    polyhedrons.push_back(bl_leg3);

    // Back right leg
    auto* br_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    br_leg3->set_position(width - (leg1_proportion * width) - (width * leg2_proportion) - (width * leg3_proportion),
                          height * 0.38f, leg2_proportion * depth + platform2->get_depth() / 2);
    br_leg3->add_vector(BACK_TOP_RIGHT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->add_vector(BACK_TOP_LEFT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->add_vector(FRONT_TOP_RIGHT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->add_vector(FRONT_TOP_LEFT, -leg3_proportion * width, 0, leg3_proportion * depth);
    br_leg3->set_texture_to_all(BRASS_TEXTURE);
    br_leg3->construct_cuboid();
    polyhedrons.push_back(br_leg3);

    // Front left leg
    auto* fl_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    fl_leg3->set_position(leg1_proportion * width + leg2_proportion * width, height * 0.38f,
                          depth - fl_leg->get_depth() - fl_leg3->get_depth() * 3);
    fl_leg3->add_vector(BACK_TOP_RIGHT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->add_vector(BACK_TOP_LEFT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->add_vector(FRONT_TOP_RIGHT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->add_vector(FRONT_TOP_LEFT, leg3_proportion * width, 0, -leg3_proportion * depth);
    fl_leg3->set_texture_to_all(BRASS_TEXTURE);
    fl_leg3->construct_cuboid();
    polyhedrons.push_back(fl_leg3);

    // Front right leg
    auto* fr_leg3 = new Cuboid(leg3_proportion * width, third_layer_height, leg3_proportion * depth);
    fr_leg3->set_position(width - (leg1_proportion * width) - (width * leg2_proportion) - (width * leg3_proportion),
                          height * 0.38f, depth - fl_leg->get_depth() - fl_leg3->get_depth() * 3);
    fr_leg3->add_vector(BACK_TOP_RIGHT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->add_vector(BACK_TOP_LEFT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->add_vector(FRONT_TOP_RIGHT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->add_vector(FRONT_TOP_LEFT, -leg3_proportion * width, 0, -leg3_proportion * depth);
    fr_leg3->set_texture_to_all(BRASS_TEXTURE);
    fr_leg3->construct_cuboid();
    polyhedrons.push_back(fr_leg3);

    auto* antenna = new Cuboid(5, height * 0.17f, 5);
    antenna->set_position(width / 2 - antenna->get_width() / 2, height * 0.38f + third_layer_height,
                          depth / 2 - antenna->get_depth() / 2);
    antenna->set_texture_to_all(BRASS_TEXTURE);
    antenna->construct_cuboid();
    polyhedrons.push_back(antenna);


    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}
