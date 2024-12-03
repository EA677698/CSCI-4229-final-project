//
// Created by erickalanis on 12/2/24.
//

#ifndef LIGHT_INTERSECTION_H
#define LIGHT_INTERSECTION_H

#include "../object.h"

// an intersection with streetlights
class LightIntersection : public Object {

public:

    using Object::Object;

    LightIntersection();

    void refresh() override;

    ~LightIntersection();

};


#endif //LIGHT_INTERSECTION_H
