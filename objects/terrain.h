#ifndef TERRAIN_H
#define TERRAIN_H

#include "object.h"

class Terrain : public Object
{
private:


public:
    using Object::Object;

    Terrain();

    void refresh() override;

    ~Terrain();
};


#endif
