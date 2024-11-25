#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <vector>

#include "boundingbox.h"
#include "camera.h"
#include "objects/object.h"

class Scene {

private:

    Camera camera;
    Object *skybox;
    std::vector<Object *> objects;
    std::map<int, BoundingBox> colors;
    std::vector<BoundingBox> bounding_boxes;
    std::vector<Object *> selected_objects;

public:

    double dir_x = 0;
    double dir_y = 0;
    double dir_z = 0;

    Scene(/* args */);

    ~Scene();

    Camera &getCamera();

    void add_object(Object *object);

    std::vector<Object *> get_objects();

    std::vector<BoundingBox> get_bounding_boxes();

    void add_selected_object(Object *object);

    std::vector<Object *> get_selected_objects();

    void add_skybox(Object *skybox);

    Object* get_skybox();

    Object *get_object_by_color(int color);

    void delete_scene();
};


#endif