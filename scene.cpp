#include "scene.h"

Scene::Scene(){
    camera = Camera();
}

Scene::~Scene(){}

Camera& Scene::getCamera(){
    return camera;
}