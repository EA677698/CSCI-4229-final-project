//
// Created by erickalanis on 12/7/24.
//

#include "golden_gate.h"
#include "street.h"
#include "sidewalk.h"
#include "../primitives/cuboid.h"
#include "../primitives/pipe.h"
#include "../../texture.h"
#include "../primitives/cylinder.h"

GoldenGateBridge::GoldenGateBridge()
{
    // 9 to 25 ratio scale
    depth = 475;
    width = 100;
    height = 75;

    int cable_sides = 8;

    Street* street1 = new Street();
    street1->set_position(0, 0, 0);
    street1->refresh();
    polyhedrons.push_back(street1);

    float total_depth = street1->get_depth();

    while (total_depth < 461)
    {
        Street* street = new Street();
        street->set_position(0, 0, total_depth);
        street->refresh();
        polyhedrons.push_back(street);
        total_depth += street->get_depth();
    }

    Street* street2 = new Street();
    street2->set_position(0, 0, -40);
    street2->refresh();
    polyhedrons.push_back(street2);

    Street* street3 = new Street();
    street3->set_position(0, 0, -80);
    street3->refresh();
    polyhedrons.push_back(street3);

    Street* street4 = new Street();
    street4->set_position(0, 0, -120);
    street4->refresh();
    polyhedrons.push_back(street4);

    Street* street5 = new Street();
    street5->set_position(0, 0, total_depth);
    street5->refresh();
    polyhedrons.push_back(street5);

    Street* street6 = new Street();
    street6->set_position(0, 0, total_depth + 40);
    street6->refresh();
    polyhedrons.push_back(street6);

    Street* street7 = new Street();
    street7->set_position(0, 0, total_depth + 80);
    street7->refresh();
    polyhedrons.push_back(street7);

    Sidewalk* sidewalk1 = new Sidewalk();
    sidewalk1->add_width(1);
    sidewalk1->set_position(street1->get_width(), 0, 0);
    sidewalk1->refresh();
    polyhedrons.push_back(sidewalk1);

    Sidewalk* sidewalk2 = new Sidewalk();
    sidewalk2->add_width(1);
    sidewalk2->set_position(-3, 0, 0);
    sidewalk2->refresh();
    polyhedrons.push_back(sidewalk2);

    Sidewalk* sidewalk3 = new Sidewalk();
    sidewalk3->add_width(1);
    sidewalk3->set_position(street1->get_width(), 0, -40);
    sidewalk3->refresh();
    polyhedrons.push_back(sidewalk3);

    Sidewalk* sidewalk4 = new Sidewalk();
    sidewalk4->add_width(1);
    sidewalk4->set_position(-3, 0, -40);
    sidewalk4->refresh();
    polyhedrons.push_back(sidewalk4);

    Sidewalk* sidewalk5 = new Sidewalk();
    sidewalk5->add_width(1);
    sidewalk5->set_position(street1->get_width(), 0, -80);
    sidewalk5->refresh();
    polyhedrons.push_back(sidewalk5);

    Sidewalk* sidewalk6 = new Sidewalk();
    sidewalk6->add_width(1);
    sidewalk6->set_position(-3, 0, -80);
    sidewalk6->refresh();
    polyhedrons.push_back(sidewalk6);

    Sidewalk* sidewalk7 = new Sidewalk();
    sidewalk7->add_width(1);
    sidewalk7->set_position(street1->get_width(), 0, -120);
    sidewalk7->refresh();
    polyhedrons.push_back(sidewalk7);

    Sidewalk* sidewalk8 = new Sidewalk();
    sidewalk8->add_width(1);
    sidewalk8->set_position(-3, 0, -120);
    sidewalk8->refresh();
    polyhedrons.push_back(sidewalk8);

    Sidewalk* sidewalk9 = new Sidewalk();
    sidewalk9->add_width(1);
    sidewalk9->set_position(street1->get_width(), 0, total_depth);
    sidewalk9->refresh();
    polyhedrons.push_back(sidewalk9);

    Sidewalk* sidewalk10 = new Sidewalk();
    sidewalk10->add_width(1);
    sidewalk10->set_position(-3, 0, total_depth);
    sidewalk10->refresh();
    polyhedrons.push_back(sidewalk10);

    Sidewalk* sidewalk11 = new Sidewalk();
    sidewalk11->add_width(1);
    sidewalk11->set_position(street1->get_width(), 0, total_depth + 40);
    sidewalk11->refresh();
    polyhedrons.push_back(sidewalk11);

    Sidewalk* sidewalk12 = new Sidewalk();
    sidewalk12->add_width(1);
    sidewalk12->set_position(-3, 0, total_depth + 40);
    sidewalk12->refresh();
    polyhedrons.push_back(sidewalk12);

    Sidewalk* sidewalk13 = new Sidewalk();
    sidewalk13->add_width(1);
    sidewalk13->set_position(street1->get_width(), 0, total_depth + 80);
    sidewalk13->refresh();
    polyhedrons.push_back(sidewalk13);

    Sidewalk* sidewalk14 = new Sidewalk();
    sidewalk14->add_width(1);
    sidewalk14->set_position(-3, 0, total_depth + 80);
    sidewalk14->refresh();
    polyhedrons.push_back(sidewalk14);


    total_depth = sidewalk1->get_depth();
    while (total_depth < 461)
    {
        Sidewalk* sidewalka = new Sidewalk();
        sidewalka->add_width(1);
        sidewalka->set_position(street1->get_width(), 0, total_depth);
        sidewalka->refresh();
        polyhedrons.push_back(sidewalka);

        Sidewalk* sidewalkb = new Sidewalk();
        sidewalkb->add_width(1);
        sidewalkb->set_position(-3, 0, total_depth);
        sidewalkb->refresh();
        polyhedrons.push_back(sidewalkb);

        total_depth += sidewalka->get_depth();
    }

    // 58 top height


    Cuboid* tower1_l = new Cuboid();
    tower1_l->add_width(4);
    tower1_l->add_depth(4);
    tower1_l->add_height(84);
    tower1_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_l->refresh();
    tower1_l->set_texture_repeat_all({1, 14});
    tower1_l->set_position(-tower1_l->get_width(), -25, 0);
    polyhedrons.push_back(tower1_l);

    Cuboid* tower1_r = new Cuboid();
    tower1_r->add_width(4);
    tower1_r->add_depth(4);
    tower1_r->add_height(84);
    tower1_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_r->refresh();
    tower1_r->set_texture_repeat_all({1, 14});
    tower1_r->set_position(street1->get_width(), -25, 0);
    polyhedrons.push_back(tower1_r);

    Sidewalk* tower1_l_sidewalk = new Sidewalk();
    tower1_l_sidewalk->set_depth(15);
    tower1_l_sidewalk->add_width(2);
    tower1_l_sidewalk->set_position(-tower1_l->get_width() - 2, 0, -5);
    tower1_l_sidewalk->refresh();
    polyhedrons.push_back(tower1_l_sidewalk);

    Sidewalk* tower1_r_sidewalk = new Sidewalk();
    tower1_r_sidewalk->set_depth(15);
    tower1_r_sidewalk->add_width(2);
    tower1_r_sidewalk->set_position(tower1_r->get_position().x + 0.5 + tower1_r->get_width() / 2, 0, -5);
    tower1_r_sidewalk->refresh();
    polyhedrons.push_back(tower1_r_sidewalk);

    Sidewalk* tower2_l_sidewalk = new Sidewalk();
    tower2_l_sidewalk->set_depth(15);
    tower2_l_sidewalk->add_width(2);
    tower2_l_sidewalk->set_position(-tower1_l->get_width() - 2, 0, total_depth - 10);
    tower2_l_sidewalk->refresh();
    polyhedrons.push_back(tower2_l_sidewalk);

    Sidewalk* tower2_r_sidewalk = new Sidewalk();
    tower2_r_sidewalk->set_depth(15);
    tower2_r_sidewalk->add_width(2);
    tower2_r_sidewalk->set_position(tower1_r->get_position().x + 0.5 + tower1_r->get_width() / 2, 0, total_depth - 10);
    tower2_r_sidewalk->refresh();
    polyhedrons.push_back(tower2_r_sidewalk);

    // Side beams
    Cuboid* back_top_beam_l = new Cuboid(1, 1, 115);
    back_top_beam_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    back_top_beam_l->construct_cuboid();
    back_top_beam_l->set_texture_repeat_all({30, 0.4});
    back_top_beam_l->set_position(-tower1_l->get_width() / 2 - 1, sidewalk1->get_height(), -120);
    polyhedrons.push_back(back_top_beam_l);

    Cuboid* back_bottom_beam_l = new Cuboid(1, 1, 115);
    back_bottom_beam_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    back_bottom_beam_l->construct_cuboid();
    back_bottom_beam_l->set_texture_repeat_all({30, 0.4});
    back_bottom_beam_l->set_position(-tower1_l->get_width() / 2 - 1, -back_top_beam_l->get_height() * 2, -120);
    polyhedrons.push_back(back_bottom_beam_l);

    Pipe* back_cross_beam_l = new Pipe();
    back_cross_beam_l->set_sides(4);
    back_cross_beam_l->set_radius(0.5);
    bool flip_flop = true;
    float beam_depth = 3;
    float beam_end = back_bottom_beam_l->get_position().z + back_bottom_beam_l->get_depth();
    for (int i = 0; back_bottom_beam_l->get_position().z + i * beam_depth < beam_end; i++)
    {
        flip_flop = !flip_flop;
        float beam_y = flip_flop
                           ? back_top_beam_l->get_position().y
                           : back_bottom_beam_l->get_position().y + back_bottom_beam_l->get_height() / 2;
        back_cross_beam_l->add_point({
            back_bottom_beam_l->get_position().x + back_bottom_beam_l->get_width() / 2, beam_y,
            back_bottom_beam_l->get_position().z + i * beam_depth
        });
    }
    back_cross_beam_l->generate_pipe();
    back_cross_beam_l->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(back_cross_beam_l);

    Cuboid* back_top_beam_r = new Cuboid(1, 1, 115);
    back_top_beam_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    back_top_beam_r->construct_cuboid();
    back_top_beam_r->set_texture_repeat_all({30, 0.4});
    back_top_beam_r->set_position(tower1_r->get_width() / 2 + 1 + (street1->get_width()), sidewalk1->get_height(),
                                  -120);
    polyhedrons.push_back(back_top_beam_r);

    Cuboid* back_bottom_beam_r = new Cuboid(1, 1, 115);
    back_bottom_beam_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    back_bottom_beam_r->construct_cuboid();
    back_bottom_beam_r->set_texture_repeat_all({30, 0.4});
    back_bottom_beam_r->set_position(tower1_r->get_width() / 2 + 1 + (street1->get_width()),
                                     -back_top_beam_r->get_height() * 2, -120);
    polyhedrons.push_back(back_bottom_beam_r);

    Pipe* back_cross_beam_r = new Pipe();
    back_cross_beam_r->set_sides(4);
    back_cross_beam_r->set_radius(0.5);
    flip_flop = true;
    for (int i = 0; back_bottom_beam_r->get_position().z + i * beam_depth < beam_end; i++)
    {
        flip_flop = !flip_flop;
        float beam_y = flip_flop
                           ? back_top_beam_r->get_position().y
                           : back_bottom_beam_r->get_position().y + back_bottom_beam_r->get_height() / 2;
        back_cross_beam_r->add_point({
            back_bottom_beam_r->get_position().x + back_bottom_beam_r->get_width() / 2, beam_y,
            back_bottom_beam_r->get_position().z + i * beam_depth
        });
    }
    back_cross_beam_r->generate_pipe();
    back_cross_beam_r->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(back_cross_beam_r);

    Cuboid* top_beam_l = new Cuboid(1, 1, total_depth - (sidewalk1->get_depth() / 2));
    top_beam_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    top_beam_l->construct_cuboid();
    top_beam_l->set_texture_repeat_all({30, 0.4});
    top_beam_l->set_position(-tower1_r->get_width() / 2 - 1, sidewalk1->get_height(), sidewalk1->get_depth() / 4);
    polyhedrons.push_back(top_beam_l);

    Cuboid* bottom_beam_l = new Cuboid(1, 1, total_depth - (sidewalk1->get_depth() / 2));
    bottom_beam_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_beam_l->construct_cuboid();
    bottom_beam_l->set_texture_repeat_all({30, 0.4});
    bottom_beam_l->set_position(-tower1_r->get_width() / 2 - 1, -top_beam_l->get_height() * 2,
                                sidewalk1->get_depth() / 4);
    polyhedrons.push_back(bottom_beam_l);

    // Cross-beams that zigzag between top and bottom beams
    Pipe* cross_beam_l = new Pipe();
    cross_beam_l->set_sides(4);
    cross_beam_l->set_radius(0.5);
    flip_flop = true;
    beam_depth = 3;
    beam_end = bottom_beam_l->get_position().z + bottom_beam_l->get_depth();
    for (int i = 0; bottom_beam_l->get_position().z + i * beam_depth < beam_end; i++)
    {
        flip_flop = !flip_flop;
        float beam_y = flip_flop
                           ? top_beam_l->get_position().y
                           : bottom_beam_l->get_position().y + bottom_beam_l->get_height() / 2;
        cross_beam_l->add_point({
            bottom_beam_l->get_position().x + bottom_beam_l->get_width() / 2, beam_y,
            bottom_beam_l->get_position().z + i * beam_depth
        });
    }
    cross_beam_l->generate_pipe();
    cross_beam_l->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(cross_beam_l);

    Cuboid* top_beam_r = new Cuboid(1, 1, total_depth - (sidewalk1->get_depth() / 2));
    top_beam_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    top_beam_r->construct_cuboid();
    top_beam_r->set_texture_repeat_all({30, 0.4});
    top_beam_r->set_position(tower1_r->get_width() / 2 + 1 + (street1->get_width()), sidewalk1->get_height(),
                             sidewalk1->get_depth() / 4);
    polyhedrons.push_back(top_beam_r);

    Cuboid* bottom_beam_r = new Cuboid(1, 1, total_depth - (sidewalk1->get_depth() / 2));
    bottom_beam_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_beam_r->construct_cuboid();
    bottom_beam_r->set_texture_repeat_all({30, 0.4});
    bottom_beam_r->set_position(tower1_r->get_width() / 2 + 1 + (street1->get_width()), -top_beam_r->get_height() * 2,
                                sidewalk1->get_depth() / 4);
    polyhedrons.push_back(bottom_beam_r);

    Pipe* cross_beam_r = new Pipe();
    cross_beam_r->set_sides(4);
    cross_beam_r->set_radius(0.5);
    flip_flop = true;
    for (int i = 0; bottom_beam_r->get_position().z + i * beam_depth < beam_end; i++)
    {
        flip_flop = !flip_flop;
        float beam_y = flip_flop
                           ? top_beam_r->get_position().y
                           : bottom_beam_r->get_position().y + bottom_beam_r->get_height() / 2;
        cross_beam_r->add_point({
            bottom_beam_r->get_position().x + bottom_beam_r->get_width() / 2, beam_y,
            bottom_beam_r->get_position().z + i * beam_depth
        });
    }
    cross_beam_r->generate_pipe();
    cross_beam_r->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(cross_beam_r);

    Cylinder* base1 = new Cylinder(15, 4, 15, 7);
    base1->set_texture(CONCRETE1_TEXTURE);
    base1->set_position(street1->get_width() / 2, -25, tower1_l->get_depth() / 2);
    polyhedrons.push_back(base1);


    float section_heights = tower1_r->get_height() * (0.5f / 13.0f);

    Cuboid* tower1_first_section = new Cuboid();
    tower1_first_section->add_width(street1->get_width() - 1);
    tower1_first_section->add_depth(2);
    tower1_first_section->add_height(section_heights);
    tower1_first_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_first_section->refresh();
    tower1_first_section->set_texture_repeat_all({1, 1});
    tower1_first_section->set_position(0, tower1_first_section->get_height() * 2.5, 1);
    polyhedrons.push_back(tower1_first_section);

    Cuboid* tower1_second_section = new Cuboid();
    tower1_second_section->add_width(street1->get_width() - 1);
    tower1_second_section->add_depth(2);
    tower1_second_section->add_height(section_heights);
    tower1_second_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_second_section->refresh();
    tower1_second_section->set_texture_repeat_all({1, 1});
    tower1_second_section->set_position(0, tower1_first_section->get_height() * 6.5, 1);
    polyhedrons.push_back(tower1_second_section);

    Cuboid* tower1_third_section = new Cuboid();
    tower1_third_section->add_width(street1->get_width() - 1);
    tower1_third_section->add_depth(2);
    tower1_third_section->add_height(section_heights);
    tower1_third_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_third_section->refresh();
    tower1_third_section->set_texture_repeat_all({1, 1});
    tower1_third_section->set_position(0, tower1_first_section->get_height() * 9.5, 1);
    polyhedrons.push_back(tower1_third_section);

    Cuboid* tower1_fourth_section = new Cuboid();
    tower1_fourth_section->add_width(street1->get_width() - 1);
    tower1_fourth_section->add_depth(2);
    tower1_fourth_section->add_height(section_heights);
    tower1_fourth_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_fourth_section->refresh();
    tower1_fourth_section->set_texture_repeat_all({1, 1});
    tower1_fourth_section->set_position(0, tower1_first_section->get_height() * 12.5, 1);
    polyhedrons.push_back(tower1_fourth_section);

    Cuboid* bottom_first_x_1 = new Cuboid(street1->get_width(), 1, 3);
    bottom_first_x_1->set_position(0, -bottom_first_x_1->get_height() * 10, 1);
    bottom_first_x_1->add_vector(FRONT_TOP_LEFT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->add_vector(BACK_TOP_RIGHT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->add_vector(BACK_BOTTOM_LEFT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_first_x_1->construct_cuboid();
    bottom_first_x_1->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(bottom_first_x_1);

    Cuboid* bottom_first_x_2 = new Cuboid(street1->get_width(), 1, 3);
    bottom_first_x_2->set_position(0, -bottom_first_x_1->get_height() * 10, 1);
    bottom_first_x_2->add_vector(FRONT_TOP_RIGHT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->add_vector(BACK_TOP_LEFT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_first_x_2->construct_cuboid();
    bottom_first_x_2->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(bottom_first_x_2);

    Cuboid* bottom_first_x_bar = new Cuboid(street1->get_width(), 1, 3);
    bottom_first_x_bar->set_position(0, -bottom_first_x_bar->get_height() * 10 - (bottom_first_x_bar->get_height() / 2),
                                     1);
    bottom_first_x_bar->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_first_x_bar->construct_cuboid();
    bottom_first_x_bar->set_texture_repeat_all({3, 1});
    polyhedrons.push_back(bottom_first_x_bar);

    Cuboid* bottom_second_x_1 = new Cuboid(street1->get_width(), 1, 3);
    bottom_second_x_1->set_position(0, -bottom_second_x_1->get_height() * 20, 1);
    bottom_second_x_1->add_vector(FRONT_TOP_LEFT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->add_vector(BACK_TOP_RIGHT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->add_vector(BACK_BOTTOM_LEFT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_second_x_1->construct_cuboid();
    bottom_second_x_1->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(bottom_second_x_1);

    Cuboid* bottom_second_x_2 = new Cuboid(street1->get_width(), 1, 3);
    bottom_second_x_2->set_position(0, -bottom_second_x_2->get_height() * 20, 1);
    bottom_second_x_2->add_vector(FRONT_TOP_RIGHT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->add_vector(BACK_TOP_LEFT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_second_x_2->construct_cuboid();
    bottom_second_x_2->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(bottom_second_x_2);

    Cuboid* bottom_second_x_bar = new Cuboid(street1->get_width(), 1, 3);
    bottom_second_x_bar->set_position(
        0, -bottom_second_x_bar->get_height() * 20 - (bottom_second_x_bar->get_height() / 2), 1);
    bottom_second_x_bar->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    bottom_second_x_bar->construct_cuboid();
    bottom_second_x_bar->set_texture_repeat_all({3, 1});
    polyhedrons.push_back(bottom_second_x_bar);


    // 58 top height


    Cuboid* tower2_l = new Cuboid();
    tower2_l->add_width(4);
    tower2_l->add_depth(4);
    tower2_l->add_height(84);
    total_depth -= tower2_l->get_depth();
    tower2_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_l->refresh();
    tower2_l->set_texture_repeat_all({1, 14});
    tower2_l->set_position(-tower2_l->get_width(), -25, total_depth);
    polyhedrons.push_back(tower2_l);

    Cuboid* tower2_r = new Cuboid();
    tower2_r->add_width(4);
    tower2_r->add_depth(4);
    tower2_r->add_height(84);
    tower2_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_r->refresh();
    tower2_r->set_texture_repeat_all({1, 14});
    tower2_r->set_position(street1->get_width(), -25, total_depth);
    polyhedrons.push_back(tower2_r);

    Cylinder* base2 = new Cylinder(15, 4, 15, 7);
    base2->set_texture(CONCRETE1_TEXTURE);
    base2->set_position(street1->get_width() / 2, -25, total_depth + tower1_l->get_depth() / 2);
    polyhedrons.push_back(base2);

    Cuboid* tower2_first_section = new Cuboid();
    tower2_first_section->add_width(street1->get_width() - 1);
    tower2_first_section->add_depth(2);
    tower2_first_section->add_height(section_heights);
    tower2_first_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_first_section->refresh();
    tower2_first_section->set_texture_repeat_all({1, 1});
    tower2_first_section->set_position(0, tower2_first_section->get_height() * 2.5, total_depth + 1);
    polyhedrons.push_back(tower2_first_section);

    Cuboid* tower2_second_section = new Cuboid();
    tower2_second_section->add_width(street1->get_width() - 1);
    tower2_second_section->add_depth(2);
    tower2_second_section->add_height(section_heights);
    tower2_second_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_second_section->refresh();
    tower2_second_section->set_texture_repeat_all({1, 1});
    tower2_second_section->set_position(0, tower2_first_section->get_height() * 6.5, total_depth + 1);
    polyhedrons.push_back(tower2_second_section);

    Cuboid* tower2_third_section = new Cuboid();
    tower2_third_section->add_width(street1->get_width() - 1);
    tower2_third_section->add_depth(2);
    tower2_third_section->add_height(section_heights);
    tower2_third_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_third_section->refresh();
    tower2_third_section->set_texture_repeat_all({1, 1});
    tower2_third_section->set_position(0, tower2_first_section->get_height() * 9.5, total_depth + 1);
    polyhedrons.push_back(tower2_third_section);

    Cuboid* tower2_fourth_section = new Cuboid();
    tower2_fourth_section->add_width(street1->get_width() - 1);
    tower2_fourth_section->add_depth(2);
    tower2_fourth_section->add_height(section_heights);
    tower2_fourth_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_fourth_section->refresh();
    tower2_fourth_section->set_texture_repeat_all({1, 1});
    tower2_fourth_section->set_position(0, tower2_first_section->get_height() * 12.5, total_depth + 1);
    polyhedrons.push_back(tower2_fourth_section);

    Cuboid* t2_bottom_first_x_1 = new Cuboid(street1->get_width(), 1, 3);
    t2_bottom_first_x_1->set_position(0, -t2_bottom_first_x_1->get_height() * 10, total_depth + 1);
    t2_bottom_first_x_1->add_vector(FRONT_TOP_LEFT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->add_vector(BACK_TOP_RIGHT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->add_vector(BACK_BOTTOM_LEFT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    t2_bottom_first_x_1->construct_cuboid();
    t2_bottom_first_x_1->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(t2_bottom_first_x_1);

    Cuboid* t2_bottom_first_x_2 = new Cuboid(street1->get_width(), 1, 3);
    t2_bottom_first_x_2->set_position(0, -t2_bottom_first_x_1->get_height() * 10, total_depth + 1);
    t2_bottom_first_x_2->add_vector(FRONT_TOP_RIGHT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->add_vector(BACK_TOP_LEFT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    t2_bottom_first_x_2->construct_cuboid();
    t2_bottom_first_x_2->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(t2_bottom_first_x_2);

    Cuboid* t2_bottom_first_x_bar = new Cuboid(street1->get_width(), 1, 3);
    t2_bottom_first_x_bar->set_position(
        0, -t2_bottom_first_x_bar->get_height() * 10 - (t2_bottom_first_x_bar->get_height() / 2), total_depth + 1);
    t2_bottom_first_x_bar->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    t2_bottom_first_x_bar->construct_cuboid();
    t2_bottom_first_x_bar->set_texture_repeat_all({3, 1});
    polyhedrons.push_back(t2_bottom_first_x_bar);

    Cuboid* t2_bottom_second_x_1 = new Cuboid(street1->get_width(), 1, 3);
    t2_bottom_second_x_1->set_position(0, -t2_bottom_second_x_1->get_height() * 20, total_depth + 1);
    t2_bottom_second_x_1->add_vector(FRONT_TOP_LEFT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->add_vector(BACK_TOP_RIGHT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->add_vector(BACK_BOTTOM_LEFT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    t2_bottom_second_x_1->construct_cuboid();
    t2_bottom_second_x_1->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(t2_bottom_second_x_1);

    Cuboid* t2_bottom_second_x_2 = new Cuboid(street1->get_width(), 1, 3);
    t2_bottom_second_x_2->set_position(0, -t2_bottom_second_x_2->get_height() * 20, total_depth + 1);
    t2_bottom_second_x_2->add_vector(FRONT_TOP_RIGHT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->add_vector(BACK_TOP_LEFT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    t2_bottom_second_x_2->construct_cuboid();
    t2_bottom_second_x_2->set_texture_repeat_all({3, 3});
    polyhedrons.push_back(t2_bottom_second_x_2);

    Cuboid* t2_bottom_second_x_bar = new Cuboid(street1->get_width(), 1, 3);
    t2_bottom_second_x_bar->set_position(
        0, -t2_bottom_second_x_bar->get_height() * 20 - (t2_bottom_second_x_bar->get_height() / 2), total_depth + 1);
    t2_bottom_second_x_bar->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    t2_bottom_second_x_bar->construct_cuboid();
    t2_bottom_second_x_bar->set_texture_repeat_all({3, 1});
    polyhedrons.push_back(t2_bottom_second_x_bar);

    Cuboid* front_top_beam_l = new Cuboid(1, 1, 115);
    front_top_beam_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    front_top_beam_l->construct_cuboid();
    front_top_beam_l->set_texture_repeat_all({30, 0.4});
    front_top_beam_l->set_position(-tower1_l->get_width() / 2 - 1, sidewalk1->get_height(),
                                   tower2_l_sidewalk->get_position().z + tower2_l_sidewalk->get_depth());
    polyhedrons.push_back(front_top_beam_l);

    Cuboid* front_bottom_beam_l = new Cuboid(1, 1, 115);
    front_bottom_beam_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    front_bottom_beam_l->construct_cuboid();
    front_bottom_beam_l->set_texture_repeat_all({30, 0.4});
    front_bottom_beam_l->set_position(-tower1_l->get_width() / 2 - 1, -front_top_beam_l->get_height() * 2,
                                      tower2_l_sidewalk->get_position().z + tower2_l_sidewalk->get_depth());
    polyhedrons.push_back(front_bottom_beam_l);

    Pipe* front_cross_beam_l = new Pipe();
    front_cross_beam_l->set_sides(4);
    front_cross_beam_l->set_radius(0.5);
    flip_flop = true;
    beam_depth = 3;
    beam_end = front_bottom_beam_l->get_position().z + front_bottom_beam_l->get_depth();
    for (int i = 0; front_bottom_beam_l->get_position().z + i * beam_depth < beam_end; i++)
    {
        flip_flop = !flip_flop;
        float beam_y = flip_flop
                           ? front_top_beam_l->get_position().y
                           : front_bottom_beam_l->get_position().y + front_bottom_beam_l->get_height() / 2;
        front_cross_beam_l->add_point({
            front_bottom_beam_l->get_position().x + front_bottom_beam_l->get_width() / 2, beam_y,
            front_bottom_beam_l->get_position().z + i * beam_depth
        });
    }
    front_cross_beam_l->generate_pipe();
    front_cross_beam_l->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(front_cross_beam_l);

    Cuboid* front_top_beam_r = new Cuboid(1, 1, 115);
    front_top_beam_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    front_top_beam_r->construct_cuboid();
    front_top_beam_r->set_texture_repeat_all({30, 0.4});
    front_top_beam_r->set_position(tower1_r->get_width() / 2 + 1 + (street1->get_width()), sidewalk1->get_height(),
                                   tower2_r_sidewalk->get_position().z + tower2_r_sidewalk->get_depth());
    polyhedrons.push_back(front_top_beam_r);

    Cuboid* front_bottom_beam_r = new Cuboid(1, 1, 115);
    front_bottom_beam_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    front_bottom_beam_r->construct_cuboid();
    front_bottom_beam_r->set_texture_repeat_all({30, 0.4});
    front_bottom_beam_r->set_position(tower1_r->get_width() / 2 + 1 + (street1->get_width()),
                                      -front_top_beam_r->get_height() * 2,
                                      tower2_r_sidewalk->get_position().z + tower2_r_sidewalk->get_depth());
    polyhedrons.push_back(front_bottom_beam_r);

    Pipe* front_cross_beam_r = new Pipe();
    front_cross_beam_r->set_sides(4);
    front_cross_beam_r->set_radius(0.5);
    flip_flop = true;
    for (int i = 0; front_bottom_beam_r->get_position().z + i * beam_depth < beam_end; i++)
    {
        flip_flop = !flip_flop;
        float beam_y = flip_flop
                           ? front_top_beam_r->get_position().y
                           : front_bottom_beam_r->get_position().y + front_bottom_beam_r->get_height() / 2;
        front_cross_beam_r->add_point({
            front_bottom_beam_r->get_position().x + front_bottom_beam_r->get_width() / 2, beam_y,
            front_bottom_beam_r->get_position().z + i * beam_depth
        });
    }
    front_cross_beam_r->generate_pipe();
    front_cross_beam_r->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(front_cross_beam_r);


    float offset = 0;
    Pipe* main_cable1 = new Pipe();
    main_cable1->set_sides(cable_sides);

    Pipe* main_cable2 = new Pipe();
    main_cable2->set_sides(cable_sides);
    for (float i = 0; i < 475; i += 10)
    {
        float y_value = (232.0f / 225625.0f) * pow(i - 237.5f, 2.0f) + 2;
        main_cable1->add_point({-tower1_l->get_width() / 2.0f, y_value, i + tower1_l->get_depth()});
        main_cable2->add_point({
            tower1_r->get_position().x + tower1_r->get_width() / 2.0f, y_value, i + tower1_l->get_depth()
        });

        if (fmod(i + offset, 5) == 0)
        {
            Pipe* middle_cable_l = new Pipe();
            middle_cable_l->set_sides(cable_sides);
            middle_cable_l->set_radius(0.5);
            middle_cable_l->add_point({-tower1_l->get_width() / 2.0f, y_value, i + tower1_l->get_depth()});
            middle_cable_l->add_point({
                -tower1_l->get_width() / 2.0f, top_beam_l->get_position().y, i + tower1_l->get_depth()
            });
            middle_cable_l->generate_pipe();
            middle_cable_l->set_texture(GOLDEN_GATE_TEXTURE);
            middle_cable_l->set_texture_repeat({0.1, 10});
            polyhedrons.push_back(middle_cable_l);

            Pipe* middle_cable_r = new Pipe();
            middle_cable_r->set_sides(cable_sides);
            middle_cable_r->set_radius(0.5);
            middle_cable_r->add_point({
                tower1_r->get_position().x + tower1_r->get_width() / 2.0f, y_value, i + tower1_l->get_depth()
            });
            middle_cable_r->add_point({
                tower1_r->get_position().x + tower1_r->get_width() / 2.0f, top_beam_r->get_position().y,
                i + tower1_l->get_depth()
            });
            middle_cable_r->generate_pipe();
            middle_cable_r->set_texture(GOLDEN_GATE_TEXTURE);
            middle_cable_r->set_texture_repeat({0.1, 10});
            polyhedrons.push_back(middle_cable_r);
        }
    }
    main_cable1->generate_pipe();
    main_cable2->generate_pipe();
    main_cable1->set_texture(GOLDEN_GATE_TEXTURE);
    main_cable2->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(main_cable1);
    polyhedrons.push_back(main_cable2);

    Pipe* start_cable1 = new Pipe();
    start_cable1->set_sides(cable_sides);
    Pipe* start_cable2 = new Pipe();
    start_cable2->set_sides(cable_sides);
    for (float i = 120; i > 0; i -= 2)
    {
        float y_value = (29.0f / 7200.0f) * pow(i - 120, 2.0f) + 2;
        start_cable1->add_point({-tower1_l->get_width() / 2.0f, y_value, -i + 2});
        start_cable2->add_point({tower1_r->get_position().x + tower1_r->get_width() / 2.0f, y_value, -i + 2});

        if (fmod(i + offset, 5) == 0)
        {
            Pipe* start_middle_cable_l = new Pipe();
            start_middle_cable_l->set_sides(16);
            start_middle_cable_l->set_radius(0.5);
            start_middle_cable_l->add_point({-tower1_l->get_width() / 2.0f, y_value, -i + 2});
            start_middle_cable_l->add_point({-tower1_l->get_width() / 2.0f, top_beam_l->get_position().y, -i + 2});
            start_middle_cable_l->generate_pipe();
            start_middle_cable_l->set_texture(GOLDEN_GATE_TEXTURE);
            start_middle_cable_l->set_texture_repeat({0.1, 10});
            polyhedrons.push_back(start_middle_cable_l);

            Pipe* start_middle_cable_r = new Pipe();
            start_middle_cable_r->set_sides(cable_sides);
            start_middle_cable_r->set_radius(0.5);
            start_middle_cable_r->add_point(
                {tower1_r->get_position().x + tower1_r->get_width() / 2.0f, y_value, -i + 2});
            start_middle_cable_r->add_point(
                {tower1_r->get_position().x + tower1_r->get_width() / 2.0f, top_beam_r->get_position().y, -i + 2});
            start_middle_cable_r->generate_pipe();
            start_middle_cable_r->set_texture(GOLDEN_GATE_TEXTURE);
            start_middle_cable_r->set_texture_repeat({0.1, 10});
            polyhedrons.push_back(start_middle_cable_r);
        }
    }
    start_cable1->generate_pipe();
    start_cable2->generate_pipe();
    start_cable1->set_texture(GOLDEN_GATE_TEXTURE);
    start_cable2->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(start_cable1);
    polyhedrons.push_back(start_cable2);

    Pipe* end_cable1 = new Pipe();
    end_cable1->set_sides(cable_sides);
    Pipe* end_cable2 = new Pipe();
    end_cable2->set_sides(cable_sides);
    for (float i = 120; i > 0; i -= 2)
    {
        float y_value = (29.0f / 7200.0f) * pow(i - 120, 2.0f) + 2;
        end_cable1->add_point({-tower1_l->get_width() / 2.0f, y_value, total_depth + i});
        end_cable2->add_point({tower1_r->get_position().x + tower1_r->get_width() / 2.0f, y_value, total_depth + i});

        if (fmod(i + offset, 5) == 0)
        {
            Pipe* end_middle_cable_l = new Pipe();
            end_middle_cable_l->set_sides(cable_sides);
            end_middle_cable_l->set_radius(0.5);
            end_middle_cable_l->add_point({-tower1_l->get_width() / 2.0f, y_value, total_depth + i});
            end_middle_cable_l->add_point(
                {-tower1_l->get_width() / 2.0f, top_beam_l->get_position().y, total_depth + i});
            end_middle_cable_l->generate_pipe();
            end_middle_cable_l->set_texture(GOLDEN_GATE_TEXTURE);
            end_middle_cable_l->set_texture_repeat({0.1, 10});
            polyhedrons.push_back(end_middle_cable_l);

            Pipe* end_middle_cable_r = new Pipe();
            end_middle_cable_r->set_sides(cable_sides);
            end_middle_cable_r->set_radius(0.5);
            end_middle_cable_r->add_point(
                {tower1_r->get_position().x + tower1_r->get_width() / 2.0f, y_value, total_depth + i});
            end_middle_cable_r->add_point(
                {
                    tower1_r->get_position().x + tower1_r->get_width() / 2.0f, top_beam_r->get_position().y,
                    total_depth + i
                });
            end_middle_cable_r->generate_pipe();
            end_middle_cable_r->set_texture(GOLDEN_GATE_TEXTURE);
            end_middle_cable_r->set_texture_repeat({0.1, 10});
            polyhedrons.push_back(end_middle_cable_r);
        }
    }
    end_cable1->generate_pipe();
    end_cable2->generate_pipe();
    end_cable1->set_texture(GOLDEN_GATE_TEXTURE);
    end_cable2->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(end_cable1);
    polyhedrons.push_back(end_cable2);


    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}

void GoldenGateBridge::refresh()
{
}

GoldenGateBridge::~GoldenGateBridge()
{
}
