//
// Created by erickalanis on 12/5/24.
//

#ifndef PYRAMID_H
#define PYRAMID_H
#include "../object.h"


class Pyramid : public Object{

private:

    int sides;

public:

    using Object::Object;

    Pyramid(float width = 1, float height = 1, float depth = 1, int sides = 3);

    void refresh() override;

    void set_texture_repeat(const Vector2& repeat);

    void set_texture(int texture);

    void set_color(int color);

    ~Pyramid();



};



#endif //PYRAMID_H
