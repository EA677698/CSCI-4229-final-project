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

class Renderer {

private:

    Vector2 mouse_position;
    int axis;
    int debug;

    int width;
    int height;

    Vector3 sun_position;
    int ambient;
    int diffuse;
    int specular;
    int shininess;
    float shiny;

    void render_picking_pass(Scene scene);

    void render_bounding_boxes(Scene scene);

    void render_debug(Scene scene);

    void render_axis();

    void render_object(Object* object, bool object_selected = false);

    GLuint frame_buffer;
    GLuint texture_color_buffer;
    GLuint render_buffer;

public:

    Vector2 sun_xy;

    void resize();

    void set_sun_position(const Vector3 &position);

    void add_sun_position(const Vector3 &position);

    Vector3 get_sun_position() const;

    int get_display_width() const;

    void set_display_width(int width);

    int get_display_height() const;

    void set_display_height(int height);

    int read_color();

    Renderer();

    ~Renderer();

    void render(Scene scene);

    void set_axis(int mode);

    int get_axis() const;

    void set_debug(int mode);

    int get_debug() const;

    void set_mouse_position(const Vector2 &position);

};


#endif