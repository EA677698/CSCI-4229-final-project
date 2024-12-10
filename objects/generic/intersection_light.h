#ifndef INTERSECTION_LIGHT_H
#define INTERSECTION_LIGHT_H

#include "../object.h"

class IntersectionLight : public Object
{
public:
    using Object::Object;

    IntersectionLight();

    void refresh() override;

    ~IntersectionLight();
};


#endif //INTERSECTION_LIGHT_H
