//
// Created by erickalanis on 12/10/24.
//

#ifndef LIGHT_H
#define LIGHT_H
#include "vector3.h"
#include "vector4.h"


class Light
{
    unsigned int light_id;
    bool spot_light;

public:
    Vector4 position;
    Vector4 ambient;
    Vector4 diffuse;
    Vector4 specular;
    float shininess;
    Vector4 emission;
    Vector3 attenuation;

    bool attenuation_enabled;

    // spotlight parameters
    Vector3 direction;
    float cutoff;
    float exponent;

    Light(unsigned int light_id);

    Light(const Vector4& position, const Vector4& ambient, const Vector4& diffuse, const Vector4& specular,
          float shininess, const Vector4& emission, unsigned int light_id);

    unsigned int get_light_id() const;

    void set_spot_light(bool spot_light);

    bool is_spot_light() const;


    ~Light();
};


#endif //LIGHT_H
