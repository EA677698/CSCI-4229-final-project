#ifndef RENDERER_H
#define RENDERER_H

#include "csci_lib/CSCIx229.h"
#include "scene.h"

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

#define ENABLE_AXIS 1
#define DISABLE_AXIS 0
#define DEBUG_ON 1
#define DEBUG_OFF 0

class Renderer{

private:

    int axis;
    int debug;

    void render_debug(Scene scene);

public:

    Renderer();
    ~Renderer();
    
    void render(Scene scene);

    void render_axis();

    void set_axis(int mode);

    int get_axis();

    void set_debug(int mode);
};


#endif