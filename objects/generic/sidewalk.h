//
// Created by erickalanis on 12/3/24.
//

#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "../object.h"

class Sidewalk : public Object {

public:

    using Object::Object;

    Sidewalk();

    void refresh() override;

    ~Sidewalk();

};


#endif //SIDEWALK_H
