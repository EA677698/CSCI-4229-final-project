//
// Created by erickalanis on 12/3/24.
//

#include "sidewalk.h"
#include "../primitives/cuboid.h"
#include "../../texture.h"

Sidewalk::Sidewalk() {
    name = "Sidewalk";
    bounding_box = true;
    width = 2;
    height = 1;
    depth = 40;

    auto *cuboid = new Cuboid(width, height, depth);
    for(int i = 0; i < 6; i++){
        cuboid->set_texture(i, SIDEWALK_TEXTURE);
    }
    cuboid->construct_cuboid();
    cuboid->set_texture_repeat(TOP_FACE, {0.1, 1});
    cuboid->set_texture_repeat(BOTTOM_FACE, {0.1, 1});
    cuboid->set_texture_repeat(LEFT_FACE, {1, 0.1});
    cuboid->set_texture_repeat(RIGHT_FACE, {1, 0.1});
    cuboid->set_texture_repeat(FRONT_FACE, {0.1, 0.1});
    cuboid->set_texture_repeat(BACK_FACE, {0.1, 0.1});
    polyhedrons.push_back(cuboid);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }


}

Sidewalk::~Sidewalk() {}

void Sidewalk::refresh() {

    delete polyhedrons.front();
    polyhedrons.clear();
    auto *cuboid = new Cuboid(width, height, depth);
    for (int i = 0; i < 6; i++) {
        cuboid->set_texture(i, SIDEWALK_TEXTURE);
    }
    cuboid->construct_cuboid();
    cuboid->set_texture_repeat(TOP_FACE, {0.1, 1});
    cuboid->set_texture_repeat(BOTTOM_FACE, {0.1, 1});
    cuboid->set_texture_repeat(LEFT_FACE, {1, 0.1});
    cuboid->set_texture_repeat(RIGHT_FACE, {1, 0.1});
    cuboid->set_texture_repeat(FRONT_FACE, {0.1, 0.1});
    cuboid->set_texture_repeat(BACK_FACE, {0.1, 0.1});
    polyhedrons.push_back(cuboid);

    for (auto &polygon1: polygons) {
        polygon1.generate_texture_vertices();
    }

}