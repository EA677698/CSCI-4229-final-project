//
// Created by erickalanis on 11/28/24.
//

#ifndef ARC_H
#define ARC_H

#include "../object.h"


class Curve : public Object {

    int definition;
    std::vector<Vector3> points;

public:

    using Object::Object;

    Vector3 calculate_point(float t);

    Curve(int definition, float width, float height, float depth);

    void refresh() override;

    void add_point(const Vector3& point);

    void clear_points();


};


#endif //ARC_H
