#include "scene.h"

#include <random>

Scene::Scene(){
    camera = Camera();
}

Scene::~Scene(){}

Camera& Scene::getCamera(){
    return camera;
}

int generate_color()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0x000000, 0xFFFFFF);
    return dist(gen);
}

void Scene::add_object(Object* object){
    int color = generate_color();
    while(colors.count(color)) // makes sure color is unique
    {
        color = generate_color();
    }
    BoundingBox b = BoundingBox(object, color);
    colors[color] = b;
    bounding_boxes.push_back(b);
    objects.push_back(object);
}

std::vector<Object*> Scene::get_objects(){
    return objects;
}

std::vector<BoundingBox> Scene::get_bounding_boxes()
{
    return bounding_boxes;
}


void Scene::delete_scene(){
    for(unsigned int i = 0; i < objects.size(); i++){
        delete objects[i];
        objects[i] = nullptr;
    }
    objects.clear();
}