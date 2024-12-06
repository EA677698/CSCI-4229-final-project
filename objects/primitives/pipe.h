//
// Created by erickalanis on 12/5/24.
//

#ifndef PIPE_H
#define PIPE_H

#include "../object.h"

class Pipe : public Object {

private:

    int sides;

    float radius;

    std::vector<Vector3> path;

    Vector3 get_distance(const Vector3& a, const Vector3& b);

public:

    Pipe(float radius = 1, int sides = 3);

    void refresh() override;

    void set_texture_repeat(const Vector2& repeat);

    void set_texture(int texture);

    void set_color(int color);

    void add_point(const Vector3& point);

    void generate_pipe();

    void set_sides(int sides);



    ~Pipe();

};



#endif //PIPE_H
