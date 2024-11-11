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

#define PERSPECTIVE 0
#define ORTHOGONAL 1
#define FIRST_PERSON 2

class Camera {

private:

    int mode;

public:
    int th = 0;       // Azimuth of view angle
    int ph = 0;       // Elevation of view angle
    int fov = 55;     // Field of view (for perspective)
    double asp = 1;   // Aspect ratio
    double dim = 10.0; // Size of the world

    double angle = 0;
    double pitch = 0;

    double x = 0;
    double y = 1;
    double z = 5;

    Camera();
    ~Camera();

    void update_View_angle(int deltaTh, int deltaPh);
    void change_viewing_mode(int mode);
    void view(double dir_x, double dir_y, double dir_z);
    int get_viewing_mode();
};


#endif