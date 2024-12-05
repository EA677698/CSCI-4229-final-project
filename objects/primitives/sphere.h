//
// Created by erickalanis on 12/5/24.
//

#ifndef SPHERE_H
#define SPHERE_H

#include "../object.h"


class Sphere : public Object {

public:

    using Object::Object;

    Sphere(float radius = 1, int slices = 10, int stacks = 10);

    void refresh() override;

    void set_texture_repeat(const Vector2& repeat);

    void set_texture(int texture);

    void set_color(int color);

    ~Sphere();

};



#endif //SPHERE_H
