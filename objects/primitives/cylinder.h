//
// Created by erickalanis on 11/28/24.
//

#ifndef CYLINDER_H
#define CYLINDER_H

#include "../object.h"

class Cylinder : public Object {

private:

    int sides;

public:

    using Object::Object;

    Cylinder(float width = 1, float height = 1, float depth = 1, int sides = 3);

    void refresh() override;

    void set_texture_repeat(const Vector2& repeat);

    void set_texture(int texture);

    void set_color(int color);

    ~Cylinder();

};


#endif //CYLINDER_H
