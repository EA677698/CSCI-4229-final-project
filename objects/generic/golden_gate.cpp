//
// Created by erickalanis on 12/7/24.
//

#include "golden_gate.h"
#include "street.h"
#include "sidewalk.h"
#include "../primitives/cuboid.h"
#include "../primitives/pipe.h"
#include "../../texture.h"

GoldenGateBridge::GoldenGateBridge() {

    // 9 to 25 ratio scale

    Street *street1 = new Street();
    street1->set_position(0,0,0);
    street1->refresh();
    polyhedrons.push_back(street1);

    float total_depth = street1->get_depth();

    while(total_depth < 461){
        Street *street = new Street();
        street->set_position(0,0,total_depth);
        street->refresh();
        polyhedrons.push_back(street);
        total_depth += street->get_depth();
    }

    Street *street2 = new Street();
    street2->set_position(0,0,-40);
    street2->refresh();
    polyhedrons.push_back(street2);

    Street *street3 = new Street();
    street3->set_position(0,0,-80);
    street3->refresh();
    polyhedrons.push_back(street3);

    Street *street4 = new Street();
    street4->set_position(0,0,-120);
    street4->refresh();
    polyhedrons.push_back(street4);

    Street *street5 = new Street();
    street5->set_position(0,0,total_depth);
    street5->refresh();
    polyhedrons.push_back(street5);

    Street *street6 = new Street();
    street6->set_position(0,0,total_depth + 40);
    street6->refresh();
    polyhedrons.push_back(street6);

    Street *street7 = new Street();
    street7->set_position(0,0,total_depth + 80);
    street7->refresh();
    polyhedrons.push_back(street7);

    Sidewalk *sidewalk1 = new Sidewalk();
    sidewalk1->add_width(6);
    sidewalk1->set_position(street1->get_width(),0,0);
    sidewalk1->refresh();
    polyhedrons.push_back(sidewalk1);

    Sidewalk *sidewalk2 = new Sidewalk();
    sidewalk2->add_width(6);
    sidewalk2->set_position(-8,0,0);
    sidewalk2->refresh();
    polyhedrons.push_back(sidewalk2);

    Sidewalk *sidewalk3 = new Sidewalk();
    sidewalk3->add_width(6);
    sidewalk3->set_position(street1->get_width(),0,-40);
    sidewalk3->refresh();
    polyhedrons.push_back(sidewalk3);

    Sidewalk *sidewalk4 = new Sidewalk();
    sidewalk4->add_width(6);
    sidewalk4->set_position(-8,0,-40);
    sidewalk4->refresh();
    polyhedrons.push_back(sidewalk4);

    Sidewalk *sidewalk5 = new Sidewalk();
    sidewalk5->add_width(6);
    sidewalk5->set_position(street1->get_width(),0,-80);
    sidewalk5->refresh();
    polyhedrons.push_back(sidewalk5);

    Sidewalk *sidewalk6 = new Sidewalk();
    sidewalk6->add_width(6);
    sidewalk6->set_position(-8,0,-80);
    sidewalk6->refresh();
    polyhedrons.push_back(sidewalk6);

    Sidewalk *sidewalk7 = new Sidewalk();
    sidewalk7->add_width(6);
    sidewalk7->set_position(street1->get_width(),0,-120);
    sidewalk7->refresh();
    polyhedrons.push_back(sidewalk7);

    Sidewalk *sidewalk8 = new Sidewalk();
    sidewalk8->add_width(6);
    sidewalk8->set_position(-8,0,-120);
    sidewalk8->refresh();
    polyhedrons.push_back(sidewalk8);

    Sidewalk *sidewalk9 = new Sidewalk();
    sidewalk9->add_width(6);
    sidewalk9->set_position(street1->get_width(),0,total_depth);
    sidewalk9->refresh();
    polyhedrons.push_back(sidewalk9);

    Sidewalk *sidewalk10 = new Sidewalk();
    sidewalk10->add_width(6);
    sidewalk10->set_position(-8,0,total_depth);
    sidewalk10->refresh();
    polyhedrons.push_back(sidewalk10);

    Sidewalk *sidewalk11 = new Sidewalk();
    sidewalk11->add_width(6);
    sidewalk11->set_position(street1->get_width(),0,total_depth + 40);
    sidewalk11->refresh();
    polyhedrons.push_back(sidewalk11);

    Sidewalk *sidewalk12 = new Sidewalk();
    sidewalk12->add_width(6);
    sidewalk12->set_position(-8,0,total_depth + 40);
    sidewalk12->refresh();
    polyhedrons.push_back(sidewalk12);

    Sidewalk *sidewalk13 = new Sidewalk();
    sidewalk13->add_width(6);
    sidewalk13->set_position(street1->get_width(),0,total_depth + 80);
    sidewalk13->refresh();
    polyhedrons.push_back(sidewalk13);

    Sidewalk *sidewalk14 = new Sidewalk();
    sidewalk14->add_width(6);
    sidewalk14->set_position(-8,0,total_depth + 80);
    sidewalk14->refresh();
    polyhedrons.push_back(sidewalk14);


    total_depth = sidewalk1->get_depth();
    while(total_depth < 461){
        Sidewalk *sidewalka = new Sidewalk();
        sidewalka->add_width(2);
        sidewalka->set_position(street1->get_width(),0,total_depth);
        sidewalka->refresh();
        polyhedrons.push_back(sidewalka);

        Sidewalk *sidewalkb = new Sidewalk();
        sidewalkb->add_width(2);
        sidewalkb->set_position(-4,0,total_depth);
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
    tower1_l->set_texture_repeat_all({1,14});
    tower1_l->set_position(-tower1_l->get_width(),-25,0);
    polyhedrons.push_back(tower1_l);

    Cuboid* tower1_r = new Cuboid();
    tower1_r->add_width(4);
    tower1_r->add_depth(4);
    tower1_r->add_height(84);
    tower1_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_r->refresh();
    tower1_r->set_texture_repeat_all({1,14});
    tower1_r->set_position(street1->get_width(),-25,0);
    polyhedrons.push_back(tower1_r);

    float section_heights = tower1_r->get_height() * (0.5f / 13.0f);

    Cuboid* tower1_first_section = new Cuboid();
    tower1_first_section->add_width(street1->get_width() - 1);
    tower1_first_section->add_depth(2);
    tower1_first_section->add_height(section_heights);
    tower1_first_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_first_section->refresh();
    tower1_first_section->set_texture_repeat_all({1,1});
    tower1_first_section->set_position(0,tower1_first_section->get_height() * 2.5,1);
    polyhedrons.push_back(tower1_first_section);

    Cuboid* tower1_second_section = new Cuboid();
    tower1_second_section->add_width(street1->get_width() - 1);
    tower1_second_section->add_depth(2);
    tower1_second_section->add_height(section_heights);
    tower1_second_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_second_section->refresh();
    tower1_second_section->set_texture_repeat_all({1,1});
    tower1_second_section->set_position(0,tower1_first_section->get_height() * 6.5,1);
    polyhedrons.push_back(tower1_second_section);

    Cuboid* tower1_third_section = new Cuboid();
    tower1_third_section->add_width(street1->get_width() - 1);
    tower1_third_section->add_depth(2);
    tower1_third_section->add_height(section_heights);
    tower1_third_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_third_section->refresh();
    tower1_third_section->set_texture_repeat_all({1,1});
    tower1_third_section->set_position(0,tower1_first_section->get_height() * 9.5,1);
    polyhedrons.push_back(tower1_third_section);

    Cuboid* tower1_fourth_section = new Cuboid();
    tower1_fourth_section->add_width(street1->get_width() - 1);
    tower1_fourth_section->add_depth(2);
    tower1_fourth_section->add_height(section_heights);
    tower1_fourth_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower1_fourth_section->refresh();
    tower1_fourth_section->set_texture_repeat_all({1,1});
    tower1_fourth_section->set_position(0,tower1_first_section->get_height() * 12.5,1);
    polyhedrons.push_back(tower1_fourth_section);

    Cuboid* bottom_first_x_1 = new Cuboid(street1->get_width(), 1,3);
    bottom_first_x_1->set_position(0,-bottom_first_x_1->get_height() * 10,1);
    bottom_first_x_1->add_vector(FRONT_TOP_LEFT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->add_vector(BACK_TOP_RIGHT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->add_vector(BACK_BOTTOM_LEFT, 0, bottom_first_x_1->get_height() * 9, 0);
    bottom_first_x_1->construct_cuboid();
    polyhedrons.push_back(bottom_first_x_1);

    Cuboid* bottom_first_x_2 = new Cuboid(street1->get_width(), 1,3);
    bottom_first_x_2->set_position(0,-bottom_first_x_1->get_height() * 10,1);
    bottom_first_x_2->add_vector(FRONT_TOP_RIGHT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->add_vector(BACK_TOP_LEFT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, bottom_first_x_2->get_height() * 9, 0);
    bottom_first_x_2->construct_cuboid();
    polyhedrons.push_back(bottom_first_x_2);

    Cuboid* bottom_first_x_bar = new Cuboid(street1->get_width(), 1,3);
    bottom_first_x_bar->set_position(0,-bottom_first_x_bar->get_height() * 10 - (bottom_first_x_bar->get_height() / 2),1);
    bottom_first_x_bar->construct_cuboid();
    polyhedrons.push_back(bottom_first_x_bar);

    Cuboid* bottom_second_x_1 = new Cuboid(street1->get_width(), 1,3);
    bottom_second_x_1->set_position(0,-bottom_second_x_1->get_height() * 20,1);
    bottom_second_x_1->add_vector(FRONT_TOP_LEFT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->add_vector(BACK_TOP_RIGHT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->add_vector(BACK_BOTTOM_LEFT, 0, bottom_second_x_1->get_height() * 9, 0);
    bottom_second_x_1->construct_cuboid();
    polyhedrons.push_back(bottom_second_x_1);

    Cuboid* bottom_second_x_2 = new Cuboid(street1->get_width(), 1,3);
    bottom_second_x_2->set_position(0,-bottom_second_x_2->get_height() * 20,1);
    bottom_second_x_2->add_vector(FRONT_TOP_RIGHT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->add_vector(BACK_TOP_LEFT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, bottom_second_x_2->get_height() * 9, 0);
    bottom_second_x_2->construct_cuboid();
    polyhedrons.push_back(bottom_second_x_2);

    Cuboid* bottom_second_x_bar = new Cuboid(street1->get_width(), 1,3);
    bottom_second_x_bar->set_position(0,-bottom_second_x_bar->get_height() * 20 - (bottom_second_x_bar->get_height() / 2),1);
    bottom_second_x_bar->construct_cuboid();
    polyhedrons.push_back(bottom_second_x_bar);




    // 58 top height


    Cuboid* tower2_l = new Cuboid();
    tower2_l->add_width(4);
    tower2_l->add_depth(4);
    tower2_l->add_height(84);
    total_depth -= tower2_l->get_depth();
    tower2_l->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_l->refresh();
    tower2_l->set_texture_repeat_all({1,14});
    tower2_l->set_position(-tower2_l->get_width(),-25,total_depth);
    polyhedrons.push_back(tower2_l);

    Cuboid* tower2_r = new Cuboid();
    tower2_r->add_width(4);
    tower2_r->add_depth(4);
    tower2_r->add_height(84);
    tower2_r->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_r->refresh();
    tower2_r->set_texture_repeat_all({1,14});
    tower2_r->set_position(street1->get_width(),-25,total_depth);
    polyhedrons.push_back(tower2_r);

    Cuboid* tower2_first_section = new Cuboid();
    tower2_first_section->add_width(street1->get_width() - 1);
    tower2_first_section->add_depth(2);
    tower2_first_section->add_height(section_heights);
    tower2_first_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_first_section->refresh();
    tower2_first_section->set_texture_repeat_all({1,1});
    tower2_first_section->set_position(0,tower2_first_section->get_height() * 2.5,total_depth + 1);
    polyhedrons.push_back(tower2_first_section);

    Cuboid* tower2_second_section = new Cuboid();
    tower2_second_section->add_width(street1->get_width() - 1);
    tower2_second_section->add_depth(2);
    tower2_second_section->add_height(section_heights);
    tower2_second_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_second_section->refresh();
    tower2_second_section->set_texture_repeat_all({1,1});
    tower2_second_section->set_position(0,tower2_first_section->get_height() * 6.5,total_depth + 1);
    polyhedrons.push_back(tower2_second_section);

    Cuboid* tower2_third_section = new Cuboid();
    tower2_third_section->add_width(street1->get_width() - 1);
    tower2_third_section->add_depth(2);
    tower2_third_section->add_height(section_heights);
    tower2_third_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_third_section->refresh();
    tower2_third_section->set_texture_repeat_all({1,1});
    tower2_third_section->set_position(0,tower2_first_section->get_height() * 9.5,total_depth + 1);
    polyhedrons.push_back(tower2_third_section);

    Cuboid* tower2_fourth_section = new Cuboid();
    tower2_fourth_section->add_width(street1->get_width() - 1);
    tower2_fourth_section->add_depth(2);
    tower2_fourth_section->add_height(section_heights);
    tower2_fourth_section->set_texture_to_all(GOLDEN_GATE_TEXTURE);
    tower2_fourth_section->refresh();
    tower2_fourth_section->set_texture_repeat_all({1,1});
    tower2_fourth_section->set_position(0,tower2_first_section->get_height() * 12.5,total_depth + 1);
    polyhedrons.push_back(tower2_fourth_section);

    Cuboid* t2_bottom_first_x_1 = new Cuboid(street1->get_width(), 1,3);
    t2_bottom_first_x_1->set_position(0,-t2_bottom_first_x_1->get_height() * 10,total_depth + 1);
    t2_bottom_first_x_1->add_vector(FRONT_TOP_LEFT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->add_vector(BACK_TOP_RIGHT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->add_vector(BACK_BOTTOM_LEFT, 0, t2_bottom_first_x_1->get_height() * 9, 0);
    t2_bottom_first_x_1->construct_cuboid();
    polyhedrons.push_back(t2_bottom_first_x_1);

    Cuboid* t2_bottom_first_x_2 = new Cuboid(street1->get_width(), 1,3);
    t2_bottom_first_x_2->set_position(0,-t2_bottom_first_x_1->get_height() * 10,total_depth + 1);
    t2_bottom_first_x_2->add_vector(FRONT_TOP_RIGHT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->add_vector(BACK_TOP_LEFT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, t2_bottom_first_x_2->get_height() * 9, 0);
    t2_bottom_first_x_2->construct_cuboid();
    polyhedrons.push_back(t2_bottom_first_x_2);

    Cuboid* t2_bottom_first_x_bar = new Cuboid(street1->get_width(), 1,3);
    t2_bottom_first_x_bar->set_position(0,-t2_bottom_first_x_bar->get_height() * 10 - (t2_bottom_first_x_bar->get_height() / 2),total_depth + 1);
    t2_bottom_first_x_bar->construct_cuboid();
    polyhedrons.push_back(t2_bottom_first_x_bar);

    Cuboid* t2_bottom_second_x_1 = new Cuboid(street1->get_width(), 1,3);
    t2_bottom_second_x_1->set_position(0,-t2_bottom_second_x_1->get_height() * 20,total_depth + 1);
    t2_bottom_second_x_1->add_vector(FRONT_TOP_LEFT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->add_vector(BACK_TOP_RIGHT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->add_vector(FRONT_BOTTOM_LEFT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->add_vector(BACK_BOTTOM_LEFT, 0, t2_bottom_second_x_1->get_height() * 9, 0);
    t2_bottom_second_x_1->construct_cuboid();
    polyhedrons.push_back(t2_bottom_second_x_1);

    Cuboid* t2_bottom_second_x_2 = new Cuboid(street1->get_width(), 1,3);
    t2_bottom_second_x_2->set_position(0,-t2_bottom_second_x_2->get_height() * 20,total_depth + 1);
    t2_bottom_second_x_2->add_vector(FRONT_TOP_RIGHT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->add_vector(BACK_TOP_LEFT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->add_vector(FRONT_BOTTOM_RIGHT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->add_vector(BACK_BOTTOM_RIGHT, 0, t2_bottom_second_x_2->get_height() * 9, 0);
    t2_bottom_second_x_2->construct_cuboid();
    polyhedrons.push_back(t2_bottom_second_x_2);

    Cuboid* t2_bottom_second_x_bar = new Cuboid(street1->get_width(), 1,3);
    t2_bottom_second_x_bar->set_position(0,-t2_bottom_second_x_bar->get_height() * 20 - (t2_bottom_second_x_bar->get_height() / 2),total_depth + 1);
    t2_bottom_second_x_bar->construct_cuboid();
    polyhedrons.push_back(t2_bottom_second_x_bar);


    Pipe *main_cable1 = new Pipe();
    main_cable1->set_sides(16);

    Pipe *main_cable2 = new Pipe();
    main_cable2->set_sides(16);
    for(float i = 0; i<475; i += 2){
        main_cable1->add_point({-tower1_l->get_width() / 2.0f, (232.0f/225625.0f) * pow(i - 237.5f, 2.0f) + 2, i});
        main_cable2->add_point({tower1_r->get_position().x + tower1_r->get_width() / 2.0f, (232.0f/225625.0f) * pow(i - 237.5f, 2.0f) + 2, i});
    }
    main_cable1->generate_pipe();
    main_cable2->generate_pipe();
    main_cable1->set_texture(GOLDEN_GATE_TEXTURE);
    main_cable2->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(main_cable1);
    polyhedrons.push_back(main_cable2);

    Pipe* start_cable1 = new Pipe();
    start_cable1->set_sides(16);
    Pipe* start_cable2 = new Pipe();
    start_cable2->set_sides(16);
    for(float i = 120; i > 0; i -= 2){
        start_cable1->add_point({-tower1_l->get_width() / 2.0f, (29.0f / 7200.0f) * pow(i - 120, 2.0f) + 2, -i + 2});
        start_cable2->add_point({tower1_r->get_position().x + tower1_r->get_width() / 2.0f, (29.0f / 7200.0f) * pow(i - 120, 2.0f) + 2, -i + 2});
    }
    start_cable1->generate_pipe();
    start_cable2->generate_pipe();
    start_cable1->set_texture(GOLDEN_GATE_TEXTURE);
    start_cable2->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(start_cable1);
    polyhedrons.push_back(start_cable2);

    Pipe* end_cable1 = new Pipe();
    end_cable1->set_sides(16);
    Pipe* end_cable2 = new Pipe();
    end_cable2->set_sides(16);
    for(float i = 120; i > 0; i -= 2){
        end_cable1->add_point({-tower1_l->get_width() / 2.0f, (29.0f / 7200.0f) * pow(i - 120, 2.0f) + 2, total_depth + i});
        end_cable2->add_point({tower1_r->get_position().x + tower1_r->get_width() / 2.0f, (29.0f / 7200.0f) * pow(i - 120, 2.0f) + 2, total_depth + i});
    }
    end_cable1->generate_pipe();
    end_cable2->generate_pipe();
    end_cable1->set_texture(GOLDEN_GATE_TEXTURE);
    end_cable2->set_texture(GOLDEN_GATE_TEXTURE);
    polyhedrons.push_back(end_cable1);
    polyhedrons.push_back(end_cable2);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }

}

void GoldenGateBridge::refresh() {}

GoldenGateBridge::~GoldenGateBridge() {}