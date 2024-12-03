//
// Created by erickalanis on 12/3/24.
//

#include "sidewalk.h"
#include "../primitives/cuboid.h"

Sidewalk::Sidewalk() {
    name = "Sidewalk";
    bounding_box = true;
    width = 2;
    height = 1;
    depth = 40;

    auto *cuboid = new Cuboid(width, height, depth);
    cuboid->construct_cuboid();
    polyhedrons.push_back(cuboid);

    for(auto& polygon1 : polygons){
        polygon1.generate_texture_vertices();
    }


}

Sidewalk::~Sidewalk() {}

void Sidewalk::refresh() {

    delete polyhedrons.front();
    polyhedrons.clear();
    auto *cuboid = new Cuboid(width, height, depth);
    cuboid->construct_cuboid();
    polyhedrons.push_back(cuboid);

    for(auto& polygon1 : polygons){
        polygon1.generate_texture_vertices();
    }

}