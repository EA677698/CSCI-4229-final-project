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

    Vector3 basis[3];

    std::vector<Vector3> path;

public:

    Pipe(float radius = 1, int sides = 3);

    void refresh() override;

    void set_texture_repeat(const Vector2& repeat);

    void set_texture(int texture);

    void set_color(int color);

    void add_point(const Vector3& point);

    void generate_pipe();

    void set_sides(int sides);

    void generate_basis(const Vector3& v1, const Vector3& v2);

    Vector3 basis_transformation(const Vector3& v);

    Vector3 normal_basis_transformation(const Vector3& v);



    ~Pipe();

};



#endif //PIPE_H
