#ifndef STREET_H
#define STREET_H

#include "../object.h"

class Street : public Object {

public:

    using Object::Object;

    Street();

    void refresh() override;

    ~Street();

};

#endif