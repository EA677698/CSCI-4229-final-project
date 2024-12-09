//
// Created by erickalanis on 11/27/24.
//

#ifndef CUBOID_H
#define CUBOID_H

#include "../object.h"

enum CuboidVertex {
    BACK_BOTTOM_LEFT,
    BACK_BOTTOM_RIGHT,
    BACK_TOP_LEFT,
    BACK_TOP_RIGHT,
    FRONT_BOTTOM_LEFT,
    FRONT_BOTTOM_RIGHT,
    FRONT_TOP_RIGHT,
    FRONT_TOP_LEFT
};

enum CuboidFace {
    BACK_FACE,
    RIGHT_FACE,
    FRONT_FACE,
    LEFT_FACE,
    TOP_FACE,
    BOTTOM_FACE
};

class Cuboid : public Object {

private:

    Vector3 vertices[8];
    int colors[6];
    int textures[6];



public:

    using Object::Object;

    Cuboid(float width = 1, float height = 1, float depth = 1);

    void refresh() override;

    ~Cuboid();

    void set_vector(int index, const Vector3& vector);

    void set_vector(int index, float x, float y, float z);

    void add_vector(int index, const Vector3& vector);

    void add_vector(int index, float x, float y, float z);

    void set_texture_to_all(int texture);

    void set_color(int index, int color);

    void set_texture(int index, int texture);

    void set_texture_repeat(int index, Vector2 repeat);

    void set_texture_repeat_all(const Vector2& repeat);

    void set_color_to_all(int color);

    void construct_cuboid();

};


#endif //CUBOID_H
