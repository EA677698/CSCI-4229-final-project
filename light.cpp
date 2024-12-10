//
// Created by erickalanis on 12/10/24.
//

#include "light.h"

Light::Light(const unsigned int light)
{
    // position = object->get_position();
    ambient = Vector4(0.1, 0.1, 0.1, 1);
    diffuse = Vector4(1, 1, 1, 1);
    specular = Vector4(1, 1, 1, 1);
    shininess = 16;
    emission = Vector4(0, 0, 0, 1);
    this->light = light;
    attenuation_enabled = false;
}

Light::Light(const Vector4& position, const Vector4& ambient, const Vector4& diffuse, const Vector4& specular,
             const float shininess, const Vector4& emission, const unsigned int light)
{
    this->position = position;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
    this->emission = emission;
    this->light = light;
    attenuation_enabled = false;
}

unsigned int Light::get_light() const
{
    return light;
}
