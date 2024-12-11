#ifndef INTERSECTION_LIGHT_H
#define INTERSECTION_LIGHT_H

#include "../object.h"

#define RED_LIGHT 0xFF0000
#define YELLOW_LIGHT 0xFFFF00
#define GREEN_LIGHT 0x00FF00

class IntersectionLight : public Object
{

    Light* enabled_light;

public:
    using Object::Object;

    IntersectionLight();

    void refresh() override;

    ~IntersectionLight();

    void enable_light(int light_color, int light_id);

    Light* get_enabled_light();

    void add_existing_light(int light_color, Light* light);
};


#endif //INTERSECTION_LIGHT_H
