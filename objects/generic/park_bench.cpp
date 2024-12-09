//
// Created by erickalanis on 11/28/24.
//

#include "park_bench.h"
#include "../primitives/cuboid.h"
#include "../../texture.h"

ParkBench::ParkBench() {
    width = 4;
    height = 2;
    depth = 0.2;

    bounding_box = true;

    name = "Park Bench";


    auto* top_plank1 = new Cuboid(width, 0.5, depth);
    top_plank1->set_position(0, 0.2f, 0);
    top_plank1->refresh();
    polyhedrons.push_back(top_plank1);

    auto* top_plank2 = new Cuboid(width, 0.5, depth);
    top_plank2->set_position(0, top_plank1->get_position().y * 4, 0);
    top_plank2->refresh();
    polyhedrons.push_back(top_plank2);

    auto* top_plank3 = new Cuboid(width, 0.5, depth);
    top_plank3->set_position(0, top_plank1->get_position().y * 7, 0);
    top_plank3->refresh();
    polyhedrons.push_back(top_plank3);

    auto* bottom_plank1 = new Cuboid(width, depth, 0.5);
    bottom_plank1->set_position(0, 0, 0.2f);
    bottom_plank1->refresh();
    polyhedrons.push_back(bottom_plank1);

    auto* bottom_plank2 = new Cuboid(width, depth, 0.5);
    bottom_plank2->set_position(0, 0, bottom_plank1->get_position().z * 4);
    bottom_plank2->refresh();
    polyhedrons.push_back(bottom_plank2);

    auto* bottom_plank3 = new Cuboid(width, depth, 0.5);
    bottom_plank3->set_position(0, 0, bottom_plank1->get_position().z * 7);
    bottom_plank3->refresh();
    polyhedrons.push_back(bottom_plank3);

    for(auto& polygon1 : polygons){
        polygon1.generate_texture_vertices();
    }
}

ParkBench::~ParkBench() {}

void ParkBench::refresh() {

}
