#include "scene.h"
#include <random>
#include <algorithm>

#define LIGHT_START 0x4000

Scene::Scene()
{
    camera = Camera();
    skybox = nullptr;
    object_op = TRANSLATE;
    bounding_boxes = {};
    selected_objects = {};
    sun = true;
    sun_object = nullptr;
    lighting = true;
}

Scene::~Scene()
{
}

Camera& Scene::getCamera()
{
    return camera;
}

int generate_color()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0x000000, 0xFFFFFF);
    return dist(gen);
}

// automatically adds bounding box to parent object (not to any of the children it may have)
void Scene::add_object(Object* object, bool light)
{
    if (object->has_bounding_box())
    {
        int color = generate_color();
        while (colors.count(color)) // makes sure colors is unique
        {
            color = generate_color();
        }
        const auto b = BoundingBox(object, color);
        colors[color] = b;
        bounding_boxes.push_back(b);
    }
    objects.push_back(object);
}

std::vector<Object*> Scene::get_objects()
{
    return objects;
}

std::vector<BoundingBox> Scene::get_bounding_boxes()
{
    return bounding_boxes;
}

void Scene::add_selected_object(Object* object)
{
    selected_objects.push_back(object);
}

std::vector<Object*> Scene::get_selected_objects()
{
    return selected_objects;
}

Object* Scene::get_object_by_color(int color)
{
    return colors[color].get_object();
}


void Scene::delete_scene()
{
    for (auto& object : objects)
    {
        delete object;
        object = nullptr;
    }
    objects.clear();
}

void Scene::add_skybox(Object* skybox)
{
    this->skybox = skybox;
}

Object* Scene::get_skybox()
{
    return skybox;
}

void Scene::clear_selected_objects()
{
    selected_objects.clear();
    camera.camera_locked = false;
}

bool Scene::is_selected(Object* object)
{
    return std::find(selected_objects.begin(), selected_objects.end(), object) != selected_objects.end();
}

// Reacts to inputs from user
void Scene::update_selected_objects(const Vector3& operation)
{
    if (!camera.camera_locked)
    {
        return;
    }
    switch (object_op)
    {
    case TRANSLATE:
        for (auto& object : selected_objects)
        {
            object->add_position(operation);
        }
        break;
    case ROTATE:
        for (auto& object : selected_objects)
        {
            object->set_rotation(object->get_rotation() + operation);
        }
        break;
    case SCALE:
        for (auto& object : selected_objects)
        {
            object->add_width(operation.x);
            object->add_height(operation.y);
            object->add_depth(operation.z);
        }
        break;
    }
}

void Scene::set_object_op(int object_op)
{
    this->object_op = object_op;
}

bool Scene::is_sun_enabled() const
{
    return sun;
}

bool Scene::is_lighting_enabled() const
{
    return lighting;
}

void Scene::enable_sun()
{
    sun = true;
}

void Scene::enable_lighting()
{
    lighting = true;
}

void Scene::disable_sun()
{
    sun = false;
}

void Scene::disable_lighting()
{
    lighting = false;
}

void Scene::set_sun_object(Object* sun_object)
{
    this->sun_object = sun_object;
    add_object(sun_object, true);
}

Object* Scene::get_sun_object()
{
    return sun_object;
}
