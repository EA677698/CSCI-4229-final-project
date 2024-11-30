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

    using Object::Object;

    Arc(float radius, float startAngle, float endAngle, int definition, float width, float height, float depth);

    void refresh() override;


};


#endif //ARC_H
