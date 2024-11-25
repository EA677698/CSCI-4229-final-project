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

class Camera {

private:

    int mode;

public:
    int th;       // Azimuth of view angle
    int ph;       // Elevation of view angle
    int fov;     // Field of view (for perspective)
    double asp;   // Aspect ratio
    double dim; // Size of the world

    double angle;
    double pitch;

    double x;
    double y;
    double z;

    Camera();

    ~Camera();

    void update_View_angle(int deltaTh, int deltaPh);

    void change_viewing_mode(int mode);

    void view(double dir_x, double dir_y, double dir_z);

    int get_viewing_mode() const;
};


#endif