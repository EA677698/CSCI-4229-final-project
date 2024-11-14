#include "polygon.h"
#include "texture.h"
#include <algorithm>


Polygon::Polygon(int texture, int color)
{
    this->texture = Texture::get_instance()->get_texture(texture);
    this->color = color;
}

Polygon::Polygon(int color) : Polygon(TEXTURE_NULL, color) {}

Polygon::Polygon() : Polygon(TEXTURE_NULL, 0xFFFFFF) {}

Vector3 Polygon::calculate_normal(){
    Vector3 normal = {0.0, 0.0, 0.0};
   for (unsigned int i = 0; i < vertices.size(); i++) {
      Vector3 current = vertices[i];
      Vector3 next = vertices[(i + 1) % vertices.size()];
        
      normal.x += (current.y - next.y) * (current.z + next.z);
      normal.y += (current.z - next.z) * (current.x + next.x);
      normal.z += (current.x - next.x) * (current.y + next.y);
   }
   return normal;
}

void create_rotation_matrix(Vector3 axis, double theta, Vector3 rotation_matrix[3][3]) {
    axis.normalize();
    double ux = axis.x;
    double uy = axis.y;
    double uz = axis.z;

    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    double one_minus_cos = 1.0 - cos_theta;

    rotation_matrix[0][0] = Vector3(cos_theta + ux * ux * one_minus_cos, 0, 0);
    rotation_matrix[0][1] = Vector3(ux * uy * one_minus_cos - uz * sin_theta, 0, 0);
    rotation_matrix[0][2] = Vector3(ux * uz * one_minus_cos + uy * sin_theta, 0, 0);

    rotation_matrix[1][0] = Vector3(uy * ux * one_minus_cos + uz * sin_theta, 0, 0);
    rotation_matrix[1][1] = Vector3(cos_theta + uy * uy * one_minus_cos, 0, 0);
    rotation_matrix[1][2] = Vector3(uy * uz * one_minus_cos - ux * sin_theta, 0, 0);

    rotation_matrix[2][0] = Vector3(uz * ux * one_minus_cos - uy * sin_theta, 0, 0);
    rotation_matrix[2][1] = Vector3(uz * uy * one_minus_cos + ux * sin_theta, 0, 0);
    rotation_matrix[2][2] = Vector3(cos_theta + uz * uz * one_minus_cos, 0, 0);
}

Vector3 rotate_vector(Vector3 v, Vector3 matrix[3][3]) {
    return Vector3(
        v.x * matrix[0][0].x + v.y * matrix[0][1].x + v.z * matrix[0][2].x,
        v.x * matrix[1][0].x + v.y * matrix[1][1].x + v.z * matrix[1][2].x,
        v.x * matrix[2][0].x + v.y * matrix[2][1].x + v.z * matrix[2][2].x
    );
}

void Polygon::normalize_texture_vectors(){
    Vector2 min = texture_vertices[0];
    double x_min = min.x, x_max = min.x;
    double y_min = min.y, y_max = min.y;
    for(unsigned int i = 0; i< texture_vertices.size(); i++){
        Vector2 vertex = texture_vertices[i];
        if(vertex.x < x_min){
            x_min = vertex.x;
        }
        if(vertex.x > x_max){
            x_max = vertex.x;
        }
        if(vertex.y < y_min){
            y_min = vertex.y;
        }
        if(vertex.y > y_max){
            y_max = vertex.y;
        }
    }

    for(unsigned int i = 0; i < texture_vertices.size(); i++){
        Vector2 vertex = texture_vertices[i];
        vertex.x -= x_min;
        vertex.x /= (x_max - x_min);
        vertex.y -= y_min;
        vertex.y /= (y_max - y_min);
        texture_vertices[i] = vertex;
    }
}

void Polygon::generate_texture_vertices(){
    if(vertices.size() < 3){
        return;
    }
    Vector3 main_normal = Vector3(0,0,-1);
    Vector3 normal = Polygon::calculate_normal();
    Vector3 axis_of_rotation = Vector3::cross_product(main_normal, normal);
    if (axis_of_rotation.get_magnitude() != 0) {
        axis_of_rotation.normalize();
    }
    double dot_product = Vector3::dot_product(main_normal, normal);
    double cos_theta = dot_product / (normal.get_magnitude() * main_normal.get_magnitude());
    cos_theta = std::clamp(cos_theta, -1.0, 1.0);
    double angle = acos(cos_theta);
    Vector3 rotation_matrix[3][3];
    create_rotation_matrix(axis_of_rotation, angle, rotation_matrix);
    for(unsigned int i = 0; i < vertices.size(); i++){
        Vector3 flattened = rotate_vector(vertices[i], rotation_matrix);
        texture_vertices.push_back(Vector2(flattened.x, flattened.y));
    }
    normalize_texture_vectors();

}

void Polygon::add_vertex(Vector3 vertex)
{
    vertices.push_back(vertex);
}

void Polygon::add_vertex(float x, float y, float z)
{
    Polygon::add_vertex(Vector3(x, y, z));
}

void Polygon::set_texture(int texture)
{
    this->texture = Texture::get_instance()->get_texture(texture);
}

unsigned int Polygon::get_texture()
{
    return texture;
}

const std::vector<Vector2> Polygon::get_texture_vertices()
{
    return texture_vertices;
}

const std::vector<Vector3> Polygon::get_vertices()
{
    return vertices;
}

void Polygon::set_color(int color)
{
    this->color = color;
}

int Polygon::get_color()
{
    return color;
}

Polygon::~Polygon(){}