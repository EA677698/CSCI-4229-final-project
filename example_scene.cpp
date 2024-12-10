//
// Created by erickalanis on 11/29/24.
//

#include "example_scene.h"

#include "objects/skybox.h"
#include "objects/terrain.h"
#include "objects/generic/skyscraper.h"
#include "objects/generic/street.h"
#include "objects/generic/eiffel_tower.h"
#include "objects/generic/intersection.h"
#include "objects/generic/intersection_light.h"
#include "objects/generic/sidewalk.h"
#include "objects/generic/street_light.h"
#include "objects/generic/golden_gate.h"
#include "objects/primitives/sphere.h"

ExampleScene::ExampleScene()
{
    scene = Scene();
    scene.getCamera().change_viewing_mode(PERSPECTIVE);
    scene.getCamera().fov = 15;
    // scene.disable_lighting();
    // scene.disable_sun();
    auto* skybox = new Skybox();
    scene.add_skybox(skybox);
    auto* sun = new Sphere(10);
    scene.set_sun_object(sun);
    sun->init_light(GL_LIGHT0);
    auto* terrain = new Terrain();
    terrain->set_width(600);
    terrain->set_position(-100, -0.1, 0);
    terrain->refresh();
    terrain->disable_bounding_box();
    scene.add_object(terrain);

    auto* street1 = new Street();
    street1->set_rotation(0, 90, 0);
    scene.add_object(street1);
    auto* street2 = new Street();
    street2->set_rotation(0, 90, 0);
    street2->set_position(0, 0, 52);
    scene.add_object(street2);
    auto* street3 = new Street();
    street3->set_position(26, 0, 26);
    scene.add_object(street3);
    auto* street4 = new Street();
    street4->set_position(26, 0, -26);
    scene.add_object(street4);
    auto* street5 = new Street();
    street5->set_rotation(0, 90, 0);
    street5->set_position(0, 0, -40);
    scene.add_object(street5);
    auto* street6 = new Street();
    street6->set_rotation(0, 90, 0);
    street6->set_position(0, 0, -80);
    scene.add_object(street6);
    auto* street7 = new Street();
    street7->set_rotation(0, 90, 0);
    street7->set_position(0, 0, -120);
    scene.add_object(street7);
    auto* street8 = new Street();
    street8->set_position(-146, 0, 26);
    scene.add_object(street8);
    auto* street9 = new Street();
    street9->set_position(-146, 0, 66);
    scene.add_object(street9);
    auto* street10 = new Street();
    street10->set_position(-146, 0, -26);
    scene.add_object(street10);
    auto* street11 = new Street();
    street11->set_position(-146, 0, -66);
    scene.add_object(street11);
    auto* street12 = new Street();
    street12->set_rotation(0, 90, 0);
    street12->set_position(-92, 0, -172);
    scene.add_object(street12);
    auto* street13 = new Street();
    street13->set_rotation(0, 90, 0);
    street13->set_position(-92, 0, -212);
    scene.add_object(street13);
    auto* street14 = new Street();
    street14->set_rotation(0, 90, 0);
    street14->set_position(-92, 0, -252);
    scene.add_object(street14);
    auto* street15 = new Street();
    street15->set_rotation(0, 90, 0);
    street15->set_position(-92, 0, -292);
    scene.add_object(street15);
    auto* street16 = new Street();
    street16->set_rotation(0, 90, 0);
    street16->set_position(92, 0, -172);
    scene.add_object(street16);
    auto* street17 = new Street();
    street17->set_rotation(0, 90, 0);
    street17->set_position(92, 0, -212);
    scene.add_object(street17);
    auto* street18 = new Street();
    street18->set_rotation(0, 90, 0);
    street18->set_position(92, 0, -252);
    scene.add_object(street18);
    auto* street19 = new Street();
    street19->set_rotation(0, 90, 0);
    street19->set_position(92, 0, -292);
    scene.add_object(street19);
    auto* street20 = new Street();
    street20->set_position(-318, 0, -66);
    scene.add_object(street20);
    auto* street21 = new Street();
    street21->set_position(-318, 0, -26);
    scene.add_object(street21);
    auto* street22 = new Street();
    street22->set_position(-318, 0, 14);
    scene.add_object(street22);
    auto* street23 = new Street();
    street23->add_depth(12);
    street23->set_position(-318, 0, 60);
    street23->refresh();
    scene.add_object(street23);

    auto* sidewalk1 = new Sidewalk();
    sidewalk1->set_position(-7, 0, -60);
    sidewalk1->set_rotation(0, 90, 0);
    sidewalk1->add_depth(120);
    sidewalk1->refresh();
    scene.add_object(sidewalk1);

    auto* sidewalk2 = new Sidewalk();
    sidewalk2->set_position(7, 0, -60);
    sidewalk2->set_rotation(0, 90, 0);
    sidewalk2->add_depth(120);
    sidewalk2->refresh();
    scene.add_object(sidewalk2);

    auto* sidewalk3 = new Sidewalk();
    sidewalk3->set_position(19, 0, -27);
    sidewalk3->add_depth(-2);
    sidewalk3->refresh();
    scene.add_object(sidewalk3);

    auto* sidewalk4 = new Sidewalk();
    sidewalk4->set_position(33, 0, -27);
    sidewalk4->add_depth(-2);
    sidewalk4->refresh();
    scene.add_object(sidewalk4);

    auto* sidewalk5 = new Sidewalk();
    sidewalk5->set_position(-7, 0, 52);
    sidewalk5->set_rotation(0, 90, 0);
    sidewalk5->refresh();
    scene.add_object(sidewalk5);

    auto* sidewalk6 = new Sidewalk();
    sidewalk6->set_position(7, 0, 52);
    sidewalk6->set_rotation(0, 90, 0);
    sidewalk6->refresh();
    scene.add_object(sidewalk6);

    auto* sidewalk7 = new Sidewalk();
    sidewalk7->set_position(19, 0, 27);
    sidewalk7->add_depth(-2);
    sidewalk7->refresh();
    scene.add_object(sidewalk7);

    auto* sidewalk8 = new Sidewalk();
    sidewalk8->set_position(33, 0, 27);
    sidewalk8->add_depth(-2);
    sidewalk8->refresh();
    scene.add_object(sidewalk8);

    auto* sidewalk9 = new Sidewalk();
    sidewalk9->set_position(-139, 0, 53);
    sidewalk9->add_depth(50);
    sidewalk9->refresh();
    scene.add_object(sidewalk9);

    auto* sidewalk10 = new Sidewalk();
    sidewalk10->set_position(-139, 0, -53);
    sidewalk10->add_depth(50);
    sidewalk10->refresh();
    scene.add_object(sidewalk10);

    auto* sidewalk11 = new Sidewalk();
    sidewalk11->set_position(-99, 0, -231);
    sidewalk11->set_rotation(0, 90, 0);
    sidewalk11->add_depth(146);
    sidewalk11->refresh();
    scene.add_object(sidewalk11);

    auto* sidewalk12 = new Sidewalk();
    sidewalk12->set_position(99, 0, -231);
    sidewalk12->set_rotation(0, 90, 0);
    sidewalk12->add_depth(146);
    sidewalk12->refresh();
    scene.add_object(sidewalk12);

    auto* sidewalk13 = new Sidewalk();
    sidewalk13->set_position(-325, 0, 0);
    sidewalk13->add_depth(160);
    sidewalk13->refresh();
    scene.add_object(sidewalk13);

    auto* sidewalk14 = new Sidewalk();
    sidewalk14->set_position(-311, 0, 0);
    sidewalk14->add_depth(132);
    sidewalk14->refresh();
    scene.add_object(sidewalk14);

    auto* sidewalk15 = new Sidewalk();
    sidewalk15->set_position(-153, 0, 0);
    sidewalk15->add_depth(132);
    sidewalk15->refresh();
    scene.add_object(sidewalk15);

    auto* sidewalk16 = new Sidewalk();
    sidewalk16->set_position(-85, 0, -232);
    sidewalk16->set_rotation(0, 90, 0);
    sidewalk16->add_depth(116);
    sidewalk16->refresh();
    scene.add_object(sidewalk16);

    auto* sidewalk17 = new Sidewalk();
    sidewalk17->set_position(85, 0, -232);
    sidewalk17->set_rotation(0, 90, 0);
    sidewalk17->add_depth(116);
    sidewalk17->refresh();
    scene.add_object(sidewalk17);

    auto* intersection1 = new Intersection();
    intersection1->set_position(26, 0, 0);
    scene.add_object(intersection1);
    auto* intersection2 = new Intersection();
    intersection2->set_position(-146, 0, 0);
    scene.add_object(intersection2);
    auto* intersection3 = new Intersection();
    intersection3->set_position(-146, 0, -92);
    scene.add_object(intersection3);
    auto* intersection4 = new Intersection();
    intersection4->set_position(-146, 0, 92);
    scene.add_object(intersection4);
    auto* intersection5 = new Intersection();
    intersection5->set_position(-318, 0, 92);
    scene.add_object(intersection5);
    auto* intersection6 = new Intersection();
    intersection6->set_position(-318, 0, -92);
    scene.add_object(intersection6);


    auto* intersection_light1 = new IntersectionLight();
    intersection_light1->set_position(16, 0, -10);
    scene.add_object(intersection_light1);

    auto* intersection_light2 = new IntersectionLight();
    intersection_light2->set_rotation(-180, 0, -180);
    intersection_light2->set_position(-36, 0, -10);
    scene.add_object(intersection_light2);

    auto* intersection_light3 = new IntersectionLight();
    intersection_light3->set_rotation(0, 90, 0);
    intersection_light3->set_position(-10, 0, 16);
    scene.add_object(intersection_light3);

    auto* intersection_light4 = new IntersectionLight();
    intersection_light4->set_rotation(0, -90, 0);
    intersection_light4->set_position(-10, 0, -36);
    scene.add_object(intersection_light4);

    float distance_apart = -50;

    auto* street_light1 = new StreetLight();
    street_light1->set_position(intersection_light1->get_position().x + distance_apart, 0, -10);
    scene.add_object(street_light1);

    auto* street_light4 = new StreetLight();
    street_light4->set_rotation(0, 180, 0);
    street_light4->set_position(-15 + -distance_apart / 2, 0, -10);
    scene.add_object(street_light4);

    auto* street_light2 = new StreetLight();
    street_light2->set_position(street_light1->get_position().x + distance_apart, 0, -10);
    scene.add_object(street_light2);

    auto* street_light5 = new StreetLight();
    street_light5->set_rotation(0, 180, 0);
    street_light5->set_position(street_light4->get_position().x - distance_apart, 0, -10);
    scene.add_object(street_light5);

    auto* street_light3 = new StreetLight();
    street_light3->set_position(street_light2->get_position().x + distance_apart, 0, -10);
    scene.add_object(street_light3);

    auto* street_light6 = new StreetLight();
    street_light6->set_rotation(0, 180, 0);
    street_light6->set_position(street_light5->get_position().x - distance_apart, 0, -10);
    scene.add_object(street_light6);

    auto* eiffel_tower = new EiffelTower();
    eiffel_tower->set_position(-230, 0, 0);
    scene.add_object(eiffel_tower);

    auto* street24 = new Street();
    street24->set_rotation(0, 90, 0);
    street24->set_position(0, 0, 92);
    scene.add_object(street24);

    auto* street25 = new Street();
    street25->set_rotation(0, 90, 0);
    street25->set_position(0, 0, 132);
    scene.add_object(street25);

    auto* street26 = new Street();
    street26->set_depth(32);
    street26->refresh();
    street26->set_rotation(0, 90, 0);
    street26->set_position(0, 0, 168);
    scene.add_object(street26);

    Terrain* terrain2 = new Terrain();
    terrain2->disable_bounding_box();
    terrain2->set_position(1280, -0.1, 0);
    scene.add_object(terrain2);


    auto* golden_gate = new GoldenGateBridge();
    golden_gate->set_rotation(0, -90, 0);
    golden_gate->set_position(44, 0, -546);
    scene.add_object(golden_gate);


    auto* skyscraper1 = new Skyscraper();
    skyscraper1->set_position(-20, 0, -44);
    scene.add_object(skyscraper1);

    auto* skyscraper2 = new Skyscraper();
    skyscraper2->add_height(-30);
    skyscraper2->set_position(72, 0, -44);
    skyscraper2->refresh();
    scene.add_object(skyscraper2);

    auto* skyscraper3 = new Skyscraper();
    skyscraper3->add_height(50);
    skyscraper3->set_position(72, 0, 42);
    skyscraper3->refresh();
    scene.add_object(skyscraper3);

    auto* skyscraper4 = new Skyscraper();
    skyscraper4->add_height(-40);
    skyscraper4->set_position(-20, 0, 42);
    skyscraper4->refresh();
    scene.add_object(skyscraper4);
}

ExampleScene::~ExampleScene() = default;

Scene ExampleScene::get_scene()
{
    return scene;
}
