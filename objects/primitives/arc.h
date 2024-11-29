//
// Created by erickalanis on 11/28/24.
//

#ifndef ARC_H
#define ARC_H

#include "../object.h"

class Arc : public Object {

    int definition;
    float radius;

public:

    Arc(float radius, float startAngle, float endAngle, int definition, float width, float height, float depth);


};


#endif //ARC_H
