#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <vector>

#include "boundingbox.h"
#include "objects/object.h"
#include "camera.h"

class Scene {

private:

    Camera camera;
    std::vector<Object*> objects;
    std::map<int, BoundingBox> colors;
    std::vector<BoundingBox> bounding_boxes;
    
public:

    double dir_x = 0;
    double dir_y = 0;
    double dir_z = 0;

    Scene(/* args */);
    ~Scene();
    Camera& getCamera();
    void add_object(Object* object);
    std::vector<Object*> get_objects();
    std::vector<BoundingBox> get_bounding_boxes();
    void delete_scene();
};


#endif