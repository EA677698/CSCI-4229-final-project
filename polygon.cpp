#include "polygon.h"
#include "texture.h"
#include <algorithm>


Polygon::Polygon(const int texture, const int color)
{
    if (texture == NO_TEXTURE)
    {
        has_texture = false;
    }
    else
    {
        this->texture = Texture::get_instance()->get_texture(texture);
        has_texture = true;
    }

    this->color = color;
    this->texture_repeats = 1;
}

Polygon::Polygon(const int color) : Polygon(NULL_TEXTURE, color)
{
}

Polygon::Polygon() : Polygon(NULL_TEXTURE, 0xFFFFFF)
{
}

Vector3 Polygon::calculate_normal() const
{
    Vector3 normal = {0.0, 0.0, 0.0};
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        const Vector3 current = vertices[i];
        const Vector3 next = vertices[(i + 1) % vertices.size()];

        normal.x += (current.y - next.y) * (current.z + next.z);
        normal.y += (current.z - next.z) * (current.x + next.x);
        normal.z += (current.x - next.x) * (current.y + next.y);
    }
    return normal;
}

void create_rotation_matrix(const Vector3& axis, const double theta, Vector3 rotation_matrix[3][3])
{
    axis.normalize();
    const double ux = axis.x;
    const double uy = axis.y;
    const double uz = axis.z;

    const double cos_theta = cos(theta);
    const double sin_theta = sin(theta);
    const double one_minus_cos = 1.0 - cos_theta;

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

Vector3 rotate_vector(const Vector3& v, Vector3 matrix[3][3])
{
    return {
        v.x * matrix[0][0].x + v.y * matrix[0][1].x + v.z * matrix[0][2].x,
        v.x * matrix[1][0].x + v.y * matrix[1][1].x + v.z * matrix[1][2].x,
        v.x * matrix[2][0].x + v.y * matrix[2][1].x + v.z * matrix[2][2].x
    };
}

void Polygon::normalize_texture_vectors()
{
    const Vector2 min = texture_vertices[0];
    double x_min = min.x, x_max = min.x;
    double y_min = min.y, y_max = min.y;
    for (const auto& vertex : texture_vertices)
    {
        if (vertex.x < x_min)
        {
            x_min = vertex.x;
        }
        if (vertex.x > x_max)
        {
            x_max = vertex.x;
        }
        if (vertex.y < y_min)
        {
            y_min = vertex.y;
        }
        if (vertex.y > y_max)
        {
            y_max = vertex.y;
        }
    }

    for (auto& texture_vertex : texture_vertices)
    {
        Vector2 vertex = texture_vertex;
        vertex.x -= x_min;
        vertex.x /= (x_max - x_min);
        vertex.y -= y_min;
        vertex.y /= (y_max - y_min);
        texture_vertex = vertex;
    }
}

bool Polygon::contains_texture() const
{
    return has_texture;
}

void Polygon::generate_texture_vertices()
{
    if (vertices.size() < 3)
    {
        return;
    }
    const Vector3 main_normal = Vector3(0, 0, -1);
    const Vector3 normal = Polygon::calculate_normal();
    const Vector3 axis_of_rotation = Vector3::cross_product(main_normal, normal);
    if (axis_of_rotation.get_magnitude() != 0)
    {
        axis_of_rotation.normalize();
    }
    const double dot_product = Vector3::dot_product(main_normal, normal);
    double cos_theta = dot_product / (normal.get_magnitude() * main_normal.get_magnitude());
    cos_theta = std::clamp(cos_theta, -1.0, 1.0);
    const double angle = acos(cos_theta);
    Vector3 rotation_matrix[3][3];
    create_rotation_matrix(axis_of_rotation, angle, rotation_matrix);
    for (const auto& vertex : vertices)
    {
        const Vector3 flattened = rotate_vector(vertex, rotation_matrix);
        texture_vertices.push_back(Vector2(flattened.x, flattened.y));
    }
    normalize_texture_vectors();
}

void Polygon::add_vertex(const Vector3& vertex)
{
    vertices.push_back(vertex);
}

void Polygon::add_vertex(const float x, const float y, const float z)
{
    add_vertex(Vector3(x, y, z));
}

void Polygon::set_texture(const int texture)
{
    if (texture == NO_TEXTURE)
    {
        has_texture = false;
        return;
    }
    this->texture = Texture::get_instance()->get_texture(texture);
    has_texture = true;
}

unsigned int Polygon::get_texture() const
{
    return texture;
}

std::vector<Vector2> Polygon::get_texture_vertices()
{
    return texture_vertices;
}

std::vector<Vector3> Polygon::get_vertices()
{
    return vertices;
}

void Polygon::set_color(int color)
{
    this->color = color;
}

int Polygon::get_color() const
{
    return color;
}

void Polygon::set_texture_repeats(const float repeats)
{
    this->texture_repeats = repeats;
}

float Polygon::get_texture_repeats() const
{
    return texture_repeats;
}

Polygon::~Polygon()
{
}
