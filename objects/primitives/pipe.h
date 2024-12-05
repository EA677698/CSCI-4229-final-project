//
// Created by erickalanis on 12/5/24.
//

#ifndef PIPE_H
#define PIPE_H

#include "../object.h"

class Pipe : public Object {

private:

    int sides;

    Vector3 get_distance(const Vector3& a, const Vector3& b);

public:

    Pipe(int sides = 3, Vector3... path);

    void refresh() override;

    void set_texture_repeat(const Vector2& repeat);

    void set_texture(int texture);

    void set_color(int color);

    ~Pipe();

};



#endif //PIPE_H
