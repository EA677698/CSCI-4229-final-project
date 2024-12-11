//
// Created by erickalanis on 12/5/24.
//

#include "street_light.h"
#include "../texture.h"
#include "../primitives/cylinder.h"
#include "../primitives/pyramid.h"
#include "../primitives/pipe.h"
#include "../primitives/sphere.h"

StreetLight::StreetLight()
{
    width = 1;
    height = 15;
    depth = 1;

    name = "Street Light";

    bounding_box = true;
    light = nullptr;
    enabled_light = nullptr;

    auto* pole = new Cylinder(width, height, depth, 10);
    pole->set_position(0, 0, 0);
    pole->set_texture(SCRATCHED_METAL_TEXTURE);
    pole->set_color(0x696969);
    pole->set_texture_repeat({1.5, 0.5});
    polyhedrons.push_back(pole);

    auto* pole_arm = new Pipe();
    Vector3 initial_position = {0, height * 1.20f, 0};
    pole_arm->add_point(initial_position);
    float peak = 1;
    float length = 3;
    for (int i = 0; i < length; i++)
    {
        pole_arm->add_point(initial_position + Vector3(0, -(peak / 2.25f) * pow(i - 1.5f, 2) + peak,
                                                       (height * 1.25f) * (i / length)));
    }
    pole_arm->set_sides(10);
    pole_arm->generate_pipe(true);
    pole_arm->set_texture(SCRATCHED_METAL_TEXTURE);
    pole_arm->set_color(0x696969);
    pole_arm->set_texture_repeat({1.5, 0.5});
    polyhedrons.push_back(pole_arm);


    auto* lamp_case = new Pyramid(width * 2, 2, depth * 2, 10);
    lamp_case->set_position(pole_arm->get_position().x, (height * 1.20f) - lamp_case->get_height(),
                            pole_arm->get_depth() - lamp_case->get_depth() / 2);
    lamp_case->set_texture(SCRATCHED_METAL_TEXTURE);
    lamp_case->set_color(0x696969);
    polyhedrons.push_back(lamp_case);

    auto* bulb = new Sphere();
    bulb->set_position(lamp_case->get_position().x, lamp_case->get_position().y - lamp_case->get_height() / 6,
                       lamp_case->get_position().z);
    bulb->set_texture(NO_TEXTURE);
    bulb->set_color(0xFFFFFF);
    bulb->set_night_light(true);
    bulb->refresh();
    polyhedrons.push_back(bulb);
}


void StreetLight::refresh()
{
}

StreetLight::~StreetLight()
{
}

void StreetLight::enable_light(int light_id) {
    polyhedrons.back()->init_light(light_id);
    enabled_light = polyhedrons.back()->get_light();
    enabled_light->position = {0.0f, 0.0f, 0.0f, 1.0f};
    enabled_light->ambient = {1.0f, 1.0f, 0.0f, 1.0f};
    enabled_light->diffuse = {1.0f, 1.0f, 0.5f, 1.0f};
    enabled_light->specular = {1.0f, 1.0f, 0.4f, 1.0f};
    enabled_light->emission = {1.0f, 1.0f, 0.0f, 1.0f};
    enabled_light->shininess = 32.0f;
    enabled_light->attenuation_enabled = true;
    enabled_light->attenuation = {0.1f, 0.1f, 0.01f};
    enabled_light->direction = {0.0f, 1.0f, 0.0f};
    enabled_light->cutoff = 30.0f;
    enabled_light->exponent = 5.0f;

}

void StreetLight::add_existing_light(Light *light) {
    polyhedrons.back()->set_light(light);
    enabled_light = light;
}

Light *StreetLight::get_enabled_light() {
    return enabled_light;
}
