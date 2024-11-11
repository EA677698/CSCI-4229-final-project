#include "scene.h"

Scene::Scene(){
    camera = Camera();
}

Scene::~Scene(){}

Camera& Scene::getCamera(){
    return camera;
}

void Scene::add_object(Object object){
    objects.push_back(object);
}

std::vector<Object> Scene::get_objects(){
    return objects;
}