//
// Created by erickalanis on 12/7/24.
//

#ifndef GOLDEN_GATE_H
#define GOLDEN_GATE_H

#include "../object.h"

class GoldenGateBridge : public Object {


public:

    using Object::Object;

    GoldenGateBridge();

    void refresh() override;

    ~GoldenGateBridge();

};


#endif //GOLDEN_GATE_H
