#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

class Scene {

private:

    Camera camera;
    
public:

    double dir_x = 0;
    double dir_y = 0;
    double dir_z = 0;

    Scene(/* args */);
    ~Scene();
    Camera& getCamera();
};


#endif