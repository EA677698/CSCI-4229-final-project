//
// Created by erickalanis on 12/10/24.
//

#include "light.h"

Light::Light(const unsigned int light_id)
{
    // position = object->get_position();
    ambient = Vector4(0.1, 0.1, 0.1, 1);
    diffuse = Vector4(1, 1, 1, 1);
    specular = Vector4(1, 1, 1, 1);
    shininess = 16;
    emission = Vector4(0, 0, 0, 1);
    this->light_id = light_id;
    attenuation_enabled = false;

    spot_light = false;
    direction = Vector3(0, 0, 0);
    cutoff = 180;
    exponent = 0;
}

Light::Light(const Vector4& position, const Vector4& ambient, const Vector4& diffuse, const Vector4& specular,
             const float shininess, const Vector4& emission, const unsigned int light_id)
{
    this->position = position;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
    this->emission = emission;
    this->light_id = light_id;
    attenuation_enabled = false;

    spot_light = false;
    // spotlight parameters
    direction = Vector3(0, 0, 0);
    cutoff = 180;
    exponent = 0;
}

unsigned int Light::get_light_id() const
{
    return light_id;
}

Light::~Light() {

}

bool Light::is_spot_light() const {
    return spot_light;
}

void Light::set_spot_light(bool spot_light) {
    this->spot_light = spot_light;
}
