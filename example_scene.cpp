//
// Created by erickalanis on 11/29/24.
//

#include "example_scene.h"

#include "objects/skybox.h"
#include "objects/terrain.h"
#include "objects/generic/skyscraper.h"
#include "objects/generic/street.h"
#include "objects/generic/park_bench.h"
#include "objects/primitives/cylinder.h"
#include "objects/primitives/curve.h"
#include "objects/eiffel_tower.h"
#include "objects/generic/intersection.h"

ExampleScene::ExampleScene() {
    scene = Scene();
    scene.getCamera().change_viewing_mode(PERSPECTIVE);
    scene.getCamera().fov = 20;
    Skybox *skybox = new Skybox();
    scene.add_skybox(skybox);
    Terrain *terrain = new Terrain();
    terrain->set_position(0, -0.1, 0);
    terrain->disable_bounding_box();
    scene.add_object(terrain);

    Street *street = new Street();
    street->set_rotation(0, 90, 0);
    scene.add_object(street);
    Intersection *intersection = new Intersection();
    intersection->set_position(0, 0, -street->get_depth());
    scene.add_object(intersection);




//    Skyscraper *skyscraper = new Skyscraper();
//    skyscraper->set_position(0, 0, -skyscraper->get_depth() * .75f);
//    scene.add_object(skyscraper);

}

ExampleScene::~ExampleScene() {}

Scene ExampleScene::get_scene() {
    return scene;
}
