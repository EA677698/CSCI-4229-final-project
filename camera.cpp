#include "camera.h"

Camera::Camera()
{
    is_dragging = false;
    camera_locked = false;
    object_dragging = false;
    th = 0;
    ph = 0;
    fov = 55;
    asp = 1;
    dim = 1000.0;

    pan_speed = 0.01f;

    camera_flag = false;
    prev_pan_x = -1;
    prev_pan_y = -1;

    object_x = 0;
    object_y = 0;

    pan_x = 0;
    pan_y = 0;

    mouse_x = 0;
    mouse_y = 0;

    angle = 0;
    pitch = 0;

    x = 0;
    y = 100;
    z = 0;

    mode = PERSPECTIVE;
}

Camera::~Camera()
{
}

void Camera::change_viewing_mode(int mode)
{
    this->mode = mode % 3;
}

void Camera::view(double dir_x, double dir_y, double dir_z)
{
    if (mode == FIRST_PERSON) // first person
        gluLookAt(x, y, z, x + dir_x, y + dir_y, z + dir_z, 0, 1, 0);
    else if (mode == PERSPECTIVE)
    {
        double Ex = -2 * dim * Sin(th) * Cos(ph);
        double Ey = (+2 * dim * Sin(ph)) + 500;
        double Ez = +2 * dim * Cos(th) * Cos(ph);
        gluLookAt(Ex, Ey, Ez, pan_x, 0, pan_y, 0, Cos(ph), 0);
    }
    //  Orthogonal - set world orientation
    else
    {
        glRotatef(ph, 1, 0, 0);
        glRotatef(th, 0, 1, 0);
    }
}

int Camera::get_viewing_mode() const
{
    return mode;
}

