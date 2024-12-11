#ifndef STREET_LIGHT_H
#define STREET_LIGHT_H

#include "../object.h"

class StreetLight : public Object
{

    Light* enabled_light;

public:
    using Object::Object;

    StreetLight();

    void enable_light(int light_id);

    void refresh() override;

    ~StreetLight();

    void add_existing_light(Light* light);

    Light* get_enabled_light();
};


#endif //STREET_LIGHT_H
