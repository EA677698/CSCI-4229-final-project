//
// Created by erickalanis on 12/10/24.
//

#ifndef WATER_H
#define WATER_H

#include "object.h"

class Water : public Object
{

public:

    using Object::Object;

    Water();

    void refresh() override;

    ~Water();

};


#endif //WATER_H
