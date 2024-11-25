//
// Created by erickalanis on 11/14/24.
//

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "objects/object.h"
#include <vector>

class BoundingBox {

private:

    float width, height, depth;
    Object *object;
    int color;

    std::vector<Polygon> polygons;

public:

    BoundingBox();

    BoundingBox(Object *object, int color);

    ~BoundingBox();

    std::vector<Polygon> get_polygons() const;

    Object *get_object() const;

    int get_color() const;


};


#endif //BOUNDINGBOX_H
