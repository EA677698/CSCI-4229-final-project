//
// Created by erickalanis on 11/28/24.
//

#include "park_bench.h"

#include <random>

#include "../primitives/cuboid.h"
#include "../../texture.h"
#include "../primitives/pipe.h"

ParkBench::ParkBench()
{
    width = 4;
    height = 2;
    depth = 2;

    float plank_height = 0.5;
    float plank_depth = 0.2;

    bounding_box = true;

    name = "Park Bench";

    position = {0, 0, height / 2.0f};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 8);


    auto* top_plank1 = new Cuboid(width, plank_height, plank_depth);
    top_plank1->set_position(0, 0.2f, 0);
    top_plank1->set_texture_to_all(OLD_WOOD_TEXTURE);
    top_plank1->refresh();
    top_plank1->set_texture_repeat_all({width, distrib(gen) / 8.0f});
    polyhedrons.push_back(top_plank1);

    auto* top_plank2 = new Cuboid(width, plank_height, plank_depth);
    top_plank2->set_position(0, top_plank1->get_position().y * 4, 0);
    top_plank2->set_texture_to_all(OLD_WOOD_TEXTURE);
    top_plank2->refresh();
    top_plank2->set_texture_repeat_all({width, distrib(gen) / 8.0f});
    polyhedrons.push_back(top_plank2);

    auto* top_plank3 = new Cuboid(width, plank_height, plank_depth);
    top_plank3->set_position(0, top_plank1->get_position().y * 7, 0);
    top_plank3->set_texture_to_all(OLD_WOOD_TEXTURE);
    top_plank3->refresh();
    top_plank3->set_texture_repeat_all({width, distrib(gen) / 8.0f});
    polyhedrons.push_back(top_plank3);

    auto* bottom_plank1 = new Cuboid(width, plank_depth, plank_height);
    bottom_plank1->set_position(0, 0, 0.2f);
    bottom_plank1->set_texture_to_all(OLD_WOOD_TEXTURE);
    bottom_plank1->refresh();
    bottom_plank1->set_texture_repeat_all({width, distrib(gen) / 8.0f});
    polyhedrons.push_back(bottom_plank1);

    auto* bottom_plank2 = new Cuboid(width, plank_depth, plank_height);
    bottom_plank2->set_position(0, 0, bottom_plank1->get_position().z * 4);
    bottom_plank2->set_texture_to_all(OLD_WOOD_TEXTURE);
    bottom_plank2->refresh();
    bottom_plank2->set_texture_repeat_all({width, distrib(gen) / 8.0f});
    polyhedrons.push_back(bottom_plank2);

    auto* bottom_plank3 = new Cuboid(width, plank_depth, plank_height);
    bottom_plank3->set_position(0, 0, bottom_plank1->get_position().z * 7);
    bottom_plank3->set_texture_to_all(OLD_WOOD_TEXTURE);
    bottom_plank3->refresh();
    bottom_plank3->set_texture_repeat_all({width, distrib(gen) / 8.0f});
    polyhedrons.push_back(bottom_plank3);

    auto structure_pipe = new Pipe();
    structure_pipe->set_radius(0.1);
    structure_pipe->set_sides(8);
    float x1 = width / 10;
    float x2 = width * 9 / 10;
    float z_start = bottom_plank3->get_position().z + bottom_plank3->get_depth() - 0.2f;
    float z_end = bottom_plank1->get_position().z;
    structure_pipe->add_point({x1, top_plank3->get_position().y + plank_height, -0.1f});
    structure_pipe->add_point({x1, top_plank1->get_position().y, -0.1f});
    structure_pipe->add_point({x1, -0.1, z_end});
    structure_pipe->add_point({x1, -0.1, z_start});
    structure_pipe->add_point({x1, -0.2, z_start + 0.1f});
    structure_pipe->add_point({x1, -height / 2.0f, z_start + 0.1f});
    structure_pipe->add_point({x1, -height / 2.0f, z_end - 0.1f});
    structure_pipe->add_point({x2, -height / 2.0f, z_end - 0.1f});
    structure_pipe->add_point({x2, -height / 2.0f, z_start + 0.1f});
    structure_pipe->add_point({x2, -0.2, z_start + 0.1f});
    structure_pipe->add_point({x2, -0.1, z_start});
    structure_pipe->add_point({x2, -0.1, z_end});
    structure_pipe->add_point({x2, top_plank1->get_position().y, -0.1f});
    structure_pipe->add_point({x2, top_plank3->get_position().y + plank_height, -0.1f});
    structure_pipe->generate_pipe(true);
    structure_pipe->set_color(0xFFFFFF);
    structure_pipe->set_texture(SCRATCHED_METAL_TEXTURE);
    polyhedrons.push_back(structure_pipe);

    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}

ParkBench::~ParkBench()
{
}

void ParkBench::refresh()
{
}
