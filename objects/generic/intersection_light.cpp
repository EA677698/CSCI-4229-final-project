//
// Created by erickalanis on 12/2/24.
//

#include "intersection_light.h"
#include "../primitives/cylinder.h"
#include "../primitives/cuboid.h"
#include "../../texture.h"

IntersectionLight::IntersectionLight()
{
    width = 1;
    height = 15;
    depth = 1;

    name = "Intersection Light";

    bounding_box = true;
    light = nullptr;
    enabled_light = nullptr;

    auto* pole = new Cylinder(width, height, depth, 10);
    pole->set_position(0, 0, 0);
    pole->set_texture(SCRATCHED_METAL_TEXTURE);
    pole->set_color(0x696969);
    pole->set_texture_repeat({1.5, 0.5});
    polyhedrons.push_back(pole);

    auto* pole_arm = new Cylinder(width, height * 3 / 4, depth, 10);
    pole_arm->set_rotation(90, 0, 0);
    pole_arm->set_position(0, 0, -pole->get_height() * 14 / 16);
    pole_arm->set_texture(SCRATCHED_METAL_TEXTURE);
    pole_arm->set_color(0x696969);
    pole_arm->set_texture_repeat({1.5, 0.5});
    polyhedrons.push_back(pole_arm);

    auto* light_box = new Cuboid(width * 2, height / 3, depth * 2);
    light_box->set_position(0, pole_arm->get_height() * 0.95f, height * 0.45f);
    for (int i = 0; i < 6; i++)
    {
        light_box->set_texture(i, SCRATCHED_METAL_TEXTURE);
        light_box->set_color(i, 0x404040);
    }
    light_box->construct_cuboid();

    polyhedrons.push_back(light_box);

    auto* red_light = new Cylinder(width / 2, light_box->get_depth() / 4, depth / 2, 10);
    red_light->set_texture(RED_TEXTURE);
    red_light->set_rotation(0, 0, 90);
    red_light->set_position(light_box->get_position().y + light_box->get_height() * 0.8f,
                            -light_box->get_depth() - red_light->get_depth(),
                            light_box->get_position().z + light_box->get_width() / 2);
    red_light->set_color(0xFF0000);
    polyhedrons.push_back(red_light);

    auto* yellow_light = new Cylinder(width / 2, light_box->get_depth() / 4, depth / 2, 10);
    yellow_light->set_texture(YELLOW_TEXTURE);
    yellow_light->set_rotation(0, 0, 90);
    yellow_light->set_position(light_box->get_position().y + light_box->get_height() * 0.5f,
                               -light_box->get_depth() - yellow_light->get_depth(),
                               light_box->get_position().z + light_box->get_width() / 2);
    yellow_light->set_color(0xFFFF00);
    polyhedrons.push_back(yellow_light);

    auto* green_light = new Cylinder(width / 2, light_box->get_depth() / 4, depth / 2, 10);
    green_light->set_texture(GREEN_TEXTURE);
    green_light->set_rotation(0, 0, 90);
    green_light->set_position(light_box->get_position().y + light_box->get_height() * 0.2f,
                              -light_box->get_depth() - green_light->get_depth(),
                              light_box->get_position().z + light_box->get_width() / 2);
    green_light->set_color(0x00FF00);
    polyhedrons.push_back(green_light);

    for (auto& polygon1 : polygons)
    {
        polygon1.generate_texture_vertices();
    }
    depth = 10;
    height = 20;
}

void IntersectionLight::refresh()
{
}

IntersectionLight::~IntersectionLight()
{
}

void IntersectionLight::enable_light(int light_color, int light_id) {

    if(enabled_light != nullptr){
        delete enabled_light;
    }

    switch (light_color)
    {
    case YELLOW_LIGHT:
        polyhedrons[4]->init_light(light_id);
        enabled_light = polyhedrons[4]->get_light();
        enabled_light->position = {0,0,0, 1.0f};
        enabled_light->emission = {1.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->ambient = {1.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->diffuse = {1.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->specular = {1.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->shininess = 0.0f;
        enabled_light->attenuation_enabled = true;
        enabled_light->attenuation = {0.1f, 0.1f, 0.01f};
        break;
    case GREEN_LIGHT:
        polyhedrons[5]->init_light(light_id);
        enabled_light = polyhedrons[5]->get_light();
        enabled_light->position = {0,0,0, 1.0f};
        enabled_light->emission = {0.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->ambient = {0.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->diffuse = {0.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->specular = {0.0f, 1.0f, 0.0f, 1.0f};
        enabled_light->shininess = 0.0f;
        enabled_light->attenuation_enabled = true;
        enabled_light->attenuation = {0.1f, 0.1f, 0.01f};
        break;
    default:
        polyhedrons[3]->init_light(light_id);
        enabled_light = polyhedrons[3]->get_light();
        enabled_light->position = {0,0,0, 1.0f};
        enabled_light->emission = {1.0f, 0.0f, 0.0f, 1.0f};
        enabled_light->ambient = {1.0f, 0.0f, 0.0f, 1.0f};
        enabled_light->diffuse = {1.0f, 0.0f, 0.0f, 1.0f};
        enabled_light->specular = {1.0f, 0.0f, 0.0f, 1.0f};
        enabled_light->shininess = 0.0f;
        enabled_light->attenuation_enabled = true;
        enabled_light->attenuation = {0.1f, 0.1f, 0.01f};
        break;
    }

}

void IntersectionLight::add_existing_light(int light_color, Light *light) {

    switch (light_color)
    {
        case YELLOW_LIGHT:
            polyhedrons[4]->set_light(light);
            enabled_light = polyhedrons[4]->get_light();
            break;
        case GREEN_LIGHT:
            polyhedrons[5]->set_light(light);
            enabled_light = polyhedrons[5]->get_light();
            break;
        default:
            polyhedrons[3]->set_light(light);
            enabled_light = polyhedrons[3]->get_light();
            break;
    }
}

Light* IntersectionLight::get_enabled_light() {
    return enabled_light;
}

