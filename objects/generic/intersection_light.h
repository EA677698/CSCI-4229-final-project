#ifndef INTERSECTION_LIGHT_H
#define INTERSECTION_LIGHT_H

#include "../object.h"

#define RED_LIGHT 0xFF0000
#define YELLOW_LIGHT 0xFFFF00
#define GREEN_LIGHT 0x00FF00

class IntersectionLight : public Object
{
public:
    using Object::Object;

    IntersectionLight();

    void refresh() override;

    ~IntersectionLight();

    Vector3 get_light_position(int light_color) const;
};


#endif //INTERSECTION_LIGHT_H
