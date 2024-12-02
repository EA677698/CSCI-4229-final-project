#include "renderer.h"
#include "texture.h"
#include <string>

Renderer::Renderer() {
    axis = 0;
    debug = DEBUG_OFF;
    width = 600;
    height = 600;

    // Generate frame buffer
    glGenFramebuffers(1, &frame_buffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer);

    glGenTextures(1, &texture_color_buffer);
    glBindTexture(GL_TEXTURE_2D, texture_color_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_color_buffer, 0);

    glGenRenderbuffers(1, &render_buffer);
    glBindRenderbuffer(GL_RENDERBUFFER, render_buffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, render_buffer);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    ErrCheck("Renderer constructor");

}

Renderer::~Renderer() {}

int Renderer::read_color() {

    glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer);
    glReadBuffer(GL_COLOR_ATTACHMENT0);
    unsigned char pixel[3];
    glReadPixels(mouse_position.x, mouse_position.y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    int ret = (pixel[0] << 16) | (pixel[1] << 8) | pixel[2];

    ErrCheck("Renderer color read");
    return ret;
}

void Renderer::render_bounding_boxes(Scene scene) {


    if (debug) {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
    }

    const std::vector<BoundingBox> bounding_boxes = scene.get_bounding_boxes();
    for (const auto &bounding_box: bounding_boxes) {
        Object* object = bounding_box.get_object();
        glPushMatrix();
        constexpr float scale = 1.01;
        glScalef(scale, scale, scale);
        const float difference = ((scale * object->get_height()) - object->get_height()) / 2;
        glRotatef(object->get_rotation().x, 1, 0, 0);
        glRotatef(object->get_rotation().y, 0, 1, 0);
        glRotatef(object->get_rotation().z, 0, 0, 1);
        glTranslatef(-(object->get_width() / 2), -difference, -(object->get_depth() / 2));
        glTranslatef(object->get_position().x, object->get_position().y, object->get_position().z);
        std::vector<Polygon> polygons = bounding_box.get_polygons();
        for (auto polygon: polygons) {
            std::vector<Vector3> vertices = polygon.get_vertices();
            const int color = bounding_box.get_color();
            glBegin(GL_POLYGON);
            glColor4ub((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF, 0xA0);
            for (const auto &vertex: vertices) {
                glVertex3f(vertex.x, vertex.y, vertex.z);
            }
            glEnd();
        }
        glPopMatrix();
    }

    if (debug) {
        glDisable(GL_BLEND);
    }

    ErrCheck("Renderer bounding boxes");

}

void Renderer::render_picking_pass(Scene scene) {

    glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    bool prev_debug = debug;
    debug = DEBUG_OFF;
    render_bounding_boxes(scene);
    debug = prev_debug;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    ErrCheck("Renderer picking pass");

}

void Renderer::render_debug(Scene scene) {
    render_bounding_boxes(scene);

    Camera &camera = scene.getCamera();

    //  Five pixels from the lower left corner of the window
    glColor3ub(0xFF, 0xFF, 0xFF);
    glWindowPos2i(5, 5);
    //  Print the text string
    std::string mode_str;
    if (camera.get_viewing_mode() == ORTHOGONAL)
        mode_str = "Orthogonal";
    else if (camera.get_viewing_mode() == PERSPECTIVE)
        mode_str = "Perspective";
    else
        mode_str = "First Person";
    Print("Angle=%d,%d  Dim=%.1f FOV=%f Projection=%s", camera.th, camera.ph, camera.dim, camera.fov, mode_str.c_str());
    glWindowPos2i(5, 25);
    if(!scene.get_selected_objects().empty()) {
        Object *selected = scene.get_selected_objects().front();
        if (selected) {
            Print("Object selected: %s Pos:(%f, %f, %f), Rot:(%f, %f, %f)", selected->get_name().c_str(),
                  selected->get_position().x, selected->get_position().y, selected->get_position().z,
                  selected->get_rotation().x, selected->get_rotation().y, selected->get_rotation().z);
        }
    }

    ErrCheck("Renderer debug");
}


void Renderer::render_object(Object *object, const bool object_selected) {
    const std::vector<Polygon> polygons = object->get_polygons();
    for (auto polygon: polygons) {
        std::vector<Vector3> vertices = polygon.get_vertices();
        std::vector<Vector2> texture_vertices = polygon.get_texture_vertices();
        const int color = polygon.get_color();

        const unsigned int texture = polygon.get_texture();
        const float repeats = polygon.get_texture_repeats();
        const Vector3 normal = polygon.calculate_normal();
        if (polygon.contains_texture()) {
            glEnable(GL_TEXTURE_2D);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            glBindTexture(GL_TEXTURE_2D, texture);
        }
        glBegin(GL_POLYGON);
        if(object_selected){
            glColor3ub(0x0, 0xFF, 0x0);
        } else {
            glColor3ub((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
        }
        glNormal3f(normal.x, normal.y, normal.z);
        for (unsigned int k = 0; k < vertices.size(); k++) {
            glTexCoord2f(texture_vertices[k].x * repeats, texture_vertices[k].y * repeats);
            glVertex3f(vertices[k].x, vertices[k].y, vertices[k].z);
        }
        glEnd();
        if (polygon.contains_texture()) {
            glDisable(GL_TEXTURE_2D);
        }
    }
    if(!object->get_polyhedrons().empty()) {
        for (auto *polyhedron: object->get_polyhedrons()) {
            glPushMatrix();
            glTranslatef(polyhedron->get_position().x, polyhedron->get_position().y, polyhedron->get_position().z);
            render_object(polyhedron, object_selected);
            glPopMatrix();
        }
    }
    ErrCheck("Renderer object");
}

void Renderer::resize() {
    glDeleteTextures(1, &texture_color_buffer);
    glDeleteRenderbuffers(1, &render_buffer);

    // color texture
    glGenTextures(1, &texture_color_buffer);
    glBindTexture(GL_TEXTURE_2D, texture_color_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // renderbuffer
    glGenRenderbuffers(1, &render_buffer);
    glBindRenderbuffer(GL_RENDERBUFFER, render_buffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);

    glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_color_buffer, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, render_buffer);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}


int Renderer::get_display_width() const
{
    return width;
}

void Renderer::set_display_width(int width)
{
    this->width = width;
}

int Renderer::get_display_height() const
{
    return height;
}

void Renderer::set_display_height(int height)
{
    this->height = height;
}


void Renderer::render(Scene scene) {

    render_picking_pass(scene);

    Camera camera = scene.getCamera();


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //  Enable Z-buffering in OpenGL
    glEnable(GL_DEPTH_TEST);
    //  Undo previous transformations
    glLoadIdentity();
    glEnable(GL_NORMALIZE);
    camera.view(scene.dir_x, scene.dir_y, scene.dir_z);

    Object *skybox = scene.get_skybox();

    if (skybox) {
        glDisable(GL_DEPTH_TEST);
//        glDisable(GL_LIGHTING);
        glPushMatrix();
        float scalar = 4.0;
        glScaled(scalar * camera.dim, scalar * camera.dim, scalar * camera.dim);
        glTranslatef(-(skybox->get_width() / 2), -(skybox->get_height() / 2), -(skybox->get_depth() / 2));
        render_object(skybox);
        glPopMatrix();
//        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
    }

    const std::vector<Object *> objects = scene.get_objects();

    for (auto &i: objects) {
        Object* object = i;
        std::vector<Polygon> polygons = object->get_polygons();
        glPushMatrix();
        // Translate object to its position
        Vector3 rotation = object->get_rotation();
        glRotatef(rotation.x, 1, 0, 0);
        glRotatef(rotation.y, 0, 1, 0);
        glRotatef(rotation.z, 0, 0, 1);
        glTranslatef(object->get_position().x, object->get_position().y, object->get_position().z);
        // Position based on center of object
        glTranslatef(-(object->get_width() / 2), 0, -(object->get_depth() / 2));
        render_object(object, scene.is_selected(object));
        glPopMatrix();
    }
    ErrCheck("Renderer display");

    if (axis) {
        render_axis();
        ErrCheck("Renderer axis display");
    }

    if (debug) {
        render_debug(scene);
        ErrCheck("Renderer debug display");
    }

    glFlush();
    glutSwapBuffers();
}

void Renderer::render_axis() {
    glColor3f(1, 1, 1);
    constexpr double len = 1.5;  //  Length of axes
    glBegin(GL_LINES);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(len, 0.0, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, len, 0.0);
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(0.0, 0.0, len);
    glEnd();
    //  Label axes
    glRasterPos3d(len, 0.0, 0.0);
    Print("X");
    glRasterPos3d(0.0, len, 0.0);
    Print("Y");
    glRasterPos3d(0.0, 0.0, len);
    Print("Z");
}

void Renderer::set_mouse_position(const Vector2 &position) {
    mouse_position = position;
}

void Renderer::set_axis(const int mode) {
    axis = mode;
}

int Renderer::get_axis() const {
    return axis;
}

void Renderer::set_debug(const int mode) {
    debug = mode;
}

int Renderer::get_debug() const {
    return debug;
}
