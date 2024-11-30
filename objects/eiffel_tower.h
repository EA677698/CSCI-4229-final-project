//
// Created by erickalanis on 11/27/24.
//

#ifndef EIFFEL_TOWER_H
#define EIFFEL_TOWER_H

#include "object.h"


class EiffelTower : public Object {


public:

    using Object::Object;

    EiffelTower();

    void refresh() override;

    ~EiffelTower();

};


#endif //EIFFEL_TOWER_H
