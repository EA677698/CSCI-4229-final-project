//
// Created by erickalanis on 12/10/24.
//

#ifndef LIGHT_H
#define LIGHT_H
#include "vector3.h"
#include "vector4.h"


class Light
{
    unsigned int light;

public:
    Vector4 position;
    Vector4 ambient;
    Vector4 diffuse;
    Vector4 specular;
    float shininess;
    Vector4 emission;
    Vector3 attenuation;

    bool attenuation_enabled;

    Light(unsigned int light);

    Light(const Vector4& position, const Vector4& ambient, const Vector4& diffuse, const Vector4& specular,
          float shininess, const Vector4& emission, unsigned int light);

    unsigned int get_light() const;


    ~Light();
};


#endif //LIGHT_H
