#include "skyscraper.h"
#include "../../texture.h"
#include "../primitives/cuboid.h"

Skyscraper::Skyscraper()
{
    width = 50;
    height = 200;
    depth = 50;

    bounding_box = true;

    name = "Skyscraper";

    auto* cuboid = new Cuboid(width, height, depth);
    cuboid->set_texture_to_all(OFFICE_TEXTURE);
    cuboid->set_texture(TOP_FACE, CONCRETE1_TEXTURE);
    cuboid->set_texture(BOTTOM_FACE, CONCRETE1_TEXTURE);
    cuboid->construct_cuboid();
    cuboid->set_texture_repeat_all({1, height / width});
    polyhedrons.push_back(cuboid);


    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}

Skyscraper::~Skyscraper()
{
}

void Skyscraper::refresh()
{
    polygons.clear();

    auto* cuboid = new Cuboid(width, height, depth);
    cuboid->set_texture_to_all(OFFICE_TEXTURE);
    cuboid->set_texture(TOP_FACE, CONCRETE1_TEXTURE);
    cuboid->set_texture(BOTTOM_FACE, CONCRETE1_TEXTURE);
    cuboid->construct_cuboid();
    cuboid->set_texture_repeat_all({1, height / width});
    polyhedrons.push_back(cuboid);


    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
}
