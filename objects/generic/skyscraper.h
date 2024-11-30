#ifndef SKYSCRAPER_H
#define SKYSCRAPER_H

#include "../object.h"

class Skyscraper : public Object {

public:

    using Object::Object;

    Skyscraper();

    void refresh() override;

    ~Skyscraper();

};

#endif