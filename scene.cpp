#include "scene.h"

#include <random>

Scene::Scene() {
    camera = Camera();
    skybox = nullptr;
}

Scene::~Scene() {}

Camera &Scene::getCamera() {
    return camera;
}

int generate_color() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0x000000, 0xFFFFFF);
    return dist(gen);
}

void Scene::add_object(Object *object) {
    if(object->has_bounding_box()) {
        int color = generate_color();
        while (colors.count(color)) // makes sure color is unique
        {
            color = generate_color();
        }
        const auto b = BoundingBox(object, color);
        colors[color] = b;
        bounding_boxes.push_back(b);
    }
    objects.push_back(object);
}

std::vector<Object *> Scene::get_objects() {
    return objects;
}

std::vector<BoundingBox> Scene::get_bounding_boxes() {
    return bounding_boxes;
}

void Scene::add_selected_object(Object *object) {
    selected_objects.push_back(object);
}

std::vector<Object *> Scene::get_selected_objects() {
    return selected_objects;
}

Object *Scene::get_object_by_color(int color) {
    return colors[color].get_object();
}


void Scene::delete_scene() {
    for (auto &object: objects) {
        delete object;
        object = nullptr;
    }
    objects.clear();
}

void Scene::add_skybox(Object *skybox) {
    this->skybox = skybox;
}

Object *Scene::get_skybox() {
    return skybox;
}
