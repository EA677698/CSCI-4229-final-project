//
// Created by erickalanis on 11/28/24.
//

#ifndef PARK_BENCH_H
#define PARK_BENCH_H


#include "../object.h"

class ParkBench : public Object {

public:

    using Object::Object;

    ParkBench();
    ~ParkBench();

    void refresh() override;

};


#endif //PARK_BENCH_H
