#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <vector>

#include "boundingbox.h"
#include "camera.h"
#include "objects/object.h"

enum Object_OP {
    TRANSLATE,
    ROTATE,
    SCALE
};

class Scene {

private:

    Camera camera;
    Object *skybox;
    std::vector<Object *> objects;
    std::map<int, BoundingBox> colors;
    std::vector<BoundingBox> bounding_boxes;
    std::vector<Object *> selected_objects;
    int object_op;



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

    void clear_selected_objects();

    bool is_selected(Object *object);

    void set_object_op(int object_op);

    void update_selected_objects(const Vector3& operation);



    void delete_scene();
};


#endif