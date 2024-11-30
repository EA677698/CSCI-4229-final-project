//
// Created by erickalanis on 11/24/24.
//

#ifndef SKYBOX_H
#define SKYBOX_H

#include "object.h"

class Skybox : public Object {


public:

    using Object::Object;

    Skybox();

    void refresh() override;

    ~Skybox();

};


#endif //SKYBOX_H
