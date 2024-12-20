#ifndef CAMERA_H
#define CAMERA_H

#include "csci_lib/CSCIx229.h"

#ifdef USEGLEW
#include <GL/glew.h>
#endif
//  OpenGL with prototypes for glext
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
// Tell Xcode IDE to not gripe about OpenGL deprecation
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else

#include <GL/glut.h>

#endif
//  Default resolution
//  For Retina displays compile with -DRES=2
#ifndef RES
#define RES 1
#endif

#define ORTHOGONAL 0
#define PERSPECTIVE 1
#define FIRST_PERSON 2

class Camera
{
private:
    int mode;

public:
    bool is_dragging;
    bool pan_dragging;
    bool object_dragging;
    int object_x;
    int object_y;
    int mouse_x;
    int mouse_y;
    float pan_speed;

    // stupid fix for rotating camera before panning camera
    bool camera_flag;


    int prev_pan_x;
    int prev_pan_y;
    int pan_x;
    int pan_y;

    int th; // Azimuth of view angle
    int ph; // Elevation of view angle
    float fov; // Field of view (for perspective)
    double asp; // Aspect ratio
    double dim; // Size of the world

    bool camera_locked;

    double angle;
    double pitch;

    double x;
    double y;
    double z;

    Camera();

    ~Camera();

    void change_viewing_mode(int mode);

    void view(double dir_x, double dir_y, double dir_z);

    int get_viewing_mode() const;
};


#endif
