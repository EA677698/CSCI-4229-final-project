#ifndef STREET_LIGHT_H
#define STREET_LIGHT_H

#include "../object.h"

class StreetLight : public Object {


public:

    using Object::Object;

    StreetLight();

    void refresh() override;

    ~StreetLight();

};


#endif //STREET_LIGHT_H