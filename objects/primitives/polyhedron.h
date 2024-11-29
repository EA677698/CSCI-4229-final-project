//
// Created by erickalanis on 11/28/24.
//

#ifndef CYLINDER_H
#define CYLINDER_H

#include "../object.h"

class Polyhedron : public Object {

private:

    int sides;

public:

    Polyhedron(float width = 1, float height = 1, float depth = 1, int sides = 3);

    ~Polyhedron();

};


#endif //CYLINDER_H
