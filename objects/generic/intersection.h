//
// Created by erickalanis on 11/24/24.
//

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "../object.h"

class Intersection : public Object {


public:

    using Object::Object;

    Intersection();

    void refresh() override;

    ~Intersection();
};


#endif //INTERSECTION_H
