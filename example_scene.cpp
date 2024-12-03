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
#include "objects/generic/street_light.h"
#include "objects/generic/sidewalk.h"

ExampleScene::ExampleScene() {
    scene = Scene();
    scene.getCamera().change_viewing_mode(PERSPECTIVE);
    scene.getCamera().fov = 15;
    Skybox *skybox = new Skybox();
    scene.add_skybox(skybox);
    Terrain *terrain = new Terrain();
    terrain->set_position(0, -0.1, 0);
    terrain->disable_bounding_box();
    scene.add_object(terrain);

    Street *street1 = new Street();
    street1->set_rotation(0, 90, 0);
    scene.add_object(street1);
    Street *street2 = new Street();
    street2->set_rotation(0, 90, 0);
    street2->set_position(0, 0, 52);
    scene.add_object(street2);
    Street *street3 = new Street();
    street3->set_position(26, 0, 26);
    scene.add_object(street3);
    Street *street4 = new Street();
    street4->set_position(26, 0, -26);
    scene.add_object(street4);
    Street *street5 = new Street();
    street5->set_rotation(0, 90, 0);
    street5->set_position(0, 0, -40);
    scene.add_object(street5);
    Street *street6 = new Street();
    street6->set_rotation(0, 90, 0);
    street6->set_position(0, 0, -80);
    scene.add_object(street6);
    Street *street7 = new Street();
    street7->set_rotation(0, 90, 0);
    street7->set_position(0, 0, -120);
    scene.add_object(street7);
    Street *street8 = new Street();
    street8->set_position(-146, 0, 26);
    scene.add_object(street8);
    Street *street9 = new Street();
    street9->set_position(-146, 0, 66);
    scene.add_object(street9);
    Street *street10 = new Street();
    street10->set_position(-146, 0, -26);
    scene.add_object(street10);
    Street *street11 = new Street();
    street11->set_position(-146, 0, -66);
    scene.add_object(street11);
    Street *street12 = new Street();
    street12->set_rotation(0, 90, 0);
    street12->set_position(-92, 0, -172);
    scene.add_object(street12);
    Street *street13 = new Street();
    street13->set_rotation(0, 90, 0);
    street13->set_position(-92, 0, -212);
    scene.add_object(street13);
    Street *street14 = new Street();
    street14->set_rotation(0, 90, 0);
    street14->set_position(-92, 0, -252);
    scene.add_object(street14);
    Street *street15 = new Street();
    street15->set_rotation(0, 90, 0);
    street15->set_position(-92, 0, -292);
    scene.add_object(street15);
    Street *street16 = new Street();
    street16->set_rotation(0, 90, 0);
    street16->set_position(92, 0, -172);
    scene.add_object(street16);
    Street *street17 = new Street();
    street17->set_rotation(0, 90, 0);
    street17->set_position(92, 0, -212);
    scene.add_object(street17);
    Street *street18 = new Street();
    street18->set_rotation(0, 90, 0);
    street18->set_position(92, 0, -252);
    scene.add_object(street18);
    Street *street19 = new Street();
    street19->set_rotation(0, 90, 0);
    street19->set_position(92, 0, -292);
    scene.add_object(street19);
    Street *street20 = new Street();
    street20->set_position(-318, 0, -66);
    scene.add_object(street20);
    Street *street21 = new Street();
    street21->set_position(-318, 0, -26);
    scene.add_object(street21);
    Street *street22 = new Street();
    street22->set_position(-318, 0, 14);
    scene.add_object(street22);
    Street *street23 = new Street();
    street23->add_depth(12);
    street23->set_position(-318, 0, 60);
    street23->refresh();
    scene.add_object(street23);

    Sidewalk *sidewalk1 = new Sidewalk();
    sidewalk1->set_position(-7, 0, -60);
    sidewalk1->set_rotation(0, 90, 0);
    sidewalk1->add_depth(120);
    sidewalk1->refresh();
    scene.add_object(sidewalk1);

    Sidewalk *sidewalk2 = new Sidewalk();
    sidewalk2->set_position(7, 0, -60);
    sidewalk2->set_rotation(0, 90, 0);
    sidewalk2->add_depth(120);
    sidewalk2->refresh();
    scene.add_object(sidewalk2);

    Sidewalk *sidewalk3 = new Sidewalk();
    sidewalk3->set_position(19, 0, -27);
    sidewalk3->add_depth(-2);
    sidewalk3->refresh();
    scene.add_object(sidewalk3);

    Sidewalk *sidewalk4 = new Sidewalk();
    sidewalk4->set_position(33, 0, -27);
    sidewalk4->add_depth(-2);
    sidewalk4->refresh();
    scene.add_object(sidewalk4);

    Sidewalk *sidewalk5 = new Sidewalk();
    sidewalk5->set_position(-7, 0, 52);
    sidewalk5->set_rotation(0, 90, 0);
    sidewalk5->refresh();
    scene.add_object(sidewalk5);

    Sidewalk *sidewalk6 = new Sidewalk();
    sidewalk6->set_position(7, 0, 52);
    sidewalk6->set_rotation(0, 90, 0);
    sidewalk6->refresh();
    scene.add_object(sidewalk6);

    Sidewalk *sidewalk7 = new Sidewalk();
    sidewalk7->set_position(19, 0, 27);
    sidewalk7->add_depth(-2);
    sidewalk7->refresh();
    scene.add_object(sidewalk7);

    Sidewalk *sidewalk8 = new Sidewalk();
    sidewalk8->set_position(33, 0, 27);
    sidewalk8->add_depth(-2);
    sidewalk8->refresh();
    scene.add_object(sidewalk8);

    Sidewalk *sidewalk9 = new Sidewalk();
    sidewalk9->set_position(-139, 0, 53);
    sidewalk9->add_depth(50);
    sidewalk9->refresh();
    scene.add_object(sidewalk9);

    Sidewalk *sidewalk10 = new Sidewalk();
    sidewalk10->set_position(-139, 0, -53);
    sidewalk10->add_depth(50);
    sidewalk10->refresh();
    scene.add_object(sidewalk10);

    Sidewalk *sidewalk11 = new Sidewalk();
    sidewalk11->set_position(-99, 0, -231);
    sidewalk11->set_rotation(0, 90, 0);
    sidewalk11->add_depth(146);
    sidewalk11->refresh();
    scene.add_object(sidewalk11);

    Sidewalk *sidewalk12 = new Sidewalk();
    sidewalk12->set_position(99, 0, -231);
    sidewalk12->set_rotation(0, 90, 0);
    sidewalk12->add_depth(146);
    sidewalk12->refresh();
    scene.add_object(sidewalk12);

    Sidewalk *sidewalk13 = new Sidewalk();
    sidewalk13->set_position(-325, 0, 0);
    sidewalk13->add_depth(160);
    sidewalk13->refresh();
    scene.add_object(sidewalk13);

    Sidewalk *sidewalk14 = new Sidewalk();
    sidewalk14->set_position(-311, 0, 0);
    sidewalk14->add_depth(132);
    sidewalk14->refresh();
    scene.add_object(sidewalk14);

    Sidewalk *sidewalk15 = new Sidewalk();
    sidewalk15->set_position(-153, 0, 0);
    sidewalk15->add_depth(132);
    sidewalk15->refresh();
    scene.add_object(sidewalk15);

    Sidewalk *sidewalk16 = new Sidewalk();
    sidewalk16->set_position(-85, 0, -232);
    sidewalk16->set_rotation(0, 90, 0);
    sidewalk16->add_depth(116);
    sidewalk16->refresh();
    scene.add_object(sidewalk16);

    Sidewalk *sidewalk17 = new Sidewalk();
    sidewalk17->set_position(85, 0, -232);
    sidewalk17->set_rotation(0, 90, 0);
    sidewalk17->add_depth(116);
    sidewalk17->refresh();
    scene.add_object(sidewalk17);

    Intersection *intersection1 = new Intersection();
    intersection1->set_position(26, 0, 0);
    scene.add_object(intersection1);
    Intersection *intersection2 = new Intersection();
    intersection2->set_position(-146, 0, 0);
    scene.add_object(intersection2);
    Intersection *intersection3 = new Intersection();
    intersection3->set_position(-146, 0, -92);
    scene.add_object(intersection3);
    Intersection *intersection4 = new Intersection();
    intersection4->set_position(-146, 0, 92);
    scene.add_object(intersection4);
    Intersection *intersection5 = new Intersection();
    intersection5->set_position(-318, 0, 92);
    scene.add_object(intersection5);
    Intersection *intersection6 = new Intersection();
    intersection6->set_position(-318, 0, -92);
    scene.add_object(intersection6);


    StreetLight *street_light1 = new StreetLight();
    street_light1->set_position(16, 0, -10);
    scene.add_object(street_light1);

    StreetLight *street_light2 = new StreetLight();
    street_light2->set_rotation(-180, 0, -180);
    street_light2->set_position(-36, 0, -10);
    scene.add_object(street_light2);

    StreetLight *street_light3 = new StreetLight();
    street_light3->set_rotation(0, 90, 0);
    street_light3->set_position(-10, 0, 16);
    scene.add_object(street_light3);

    StreetLight *street_light4 = new StreetLight();
    street_light4->set_rotation(0, -90, 0);
    street_light4->set_position(-10, 0, -36);
    scene.add_object(street_light4);


    EiffelTower *eiffel_tower = new EiffelTower();
    eiffel_tower->set_position(-230, 0, 0);
    scene.add_object(eiffel_tower);




    Skyscraper *skyscraper1 = new Skyscraper();
    skyscraper1->set_position(-20, 0, -44);
    scene.add_object(skyscraper1);

    Skyscraper *skyscraper2 = new Skyscraper();
    skyscraper2->add_height(-30);
    skyscraper2->set_position(72, 0, -44);
    skyscraper2->refresh();
    scene.add_object(skyscraper2);

    Skyscraper *skyscraper3 = new Skyscraper();
    skyscraper3->add_height(50);
    skyscraper3->set_position(72, 0, 42);
    skyscraper3->refresh();
    scene.add_object(skyscraper3);

    Skyscraper *skyscraper4 = new Skyscraper();
    skyscraper4->add_height(-40);
    skyscraper4->set_position(-20, 0, 42);
    skyscraper4->refresh();
    scene.add_object(skyscraper4);


}

ExampleScene::~ExampleScene() {}

Scene ExampleScene::get_scene() {
    return scene;
}
