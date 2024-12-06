#include "csci_lib/CSCIx229.h"
#include "scene.h"
#include "renderer.h"
#include "texture.h"
#include "example_scene.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "objects/skybox.h"
#include "objects/generic/street_light.h"
#include "objects/primitives/pyramid.h"
#include "objects/primitives/sphere.h"
#include "objects/primitives/pipe.h"

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

Scene scene;
Renderer renderer;

int move = 1;       //  Move light
const char *text[] = {""};

// Light code is not used yet. Will implement soon.

int light = 0;  // Lighting
int one = 1;  // Unit value
int distance = 5;  // Light distance
int inc = 10;  // Ball increment
int smooth = 1;  // Smooth/Flat shading
int local = 0;  // Local Viewer Model
int emission = 0;  // Emission intensity (%)
int ambient = 10;  // Ambient intensity (%)
int diffuse = 50;  // Diffuse intensity (%)
int specular = 0;  // Specular intensity (%)
int shininess = 0;  // Shininess (power of two)
float shiny = 1;  // Shininess (value)
int zh = 90;  // Light azimuth
float ylight = 0;  // Elevation of light

/*
 *  OpenGL (GLUT) calls this routine to display the scene
 */
void display() {
    renderer.render(scene);
}

void mouse_click(int button, int state, int x, int y) {
    int glY = renderer.get_display_height() - y;
    Camera &camera = scene.getCamera();

    if (button == GLUT_MIDDLE_BUTTON){
        camera.is_dragging = state == GLUT_DOWN;
        camera.mouse_x = x;
        camera.mouse_y = y;
    }

    if (button == GLUT_LEFT_BUTTON) {
        renderer.set_mouse_position(Vector2(x, glY));
        if(!renderer.read_color() && state == GLUT_DOWN){
            scene.clear_selected_objects();
        } else {
            Object* object = scene.get_object_by_color(renderer.read_color());
            if(object){
                scene.add_selected_object(object);
            }
        }
        camera.object_dragging = state == GLUT_DOWN;
    }

    if (button == GLUT_RIGHT_BUTTON) {
        camera.pan_dragging = state == GLUT_DOWN;
        camera.prev_pan_x = x;
        camera.prev_pan_y = y;
    }

    if (button == 4) { // Scroll down
        camera.fov += camera.fov > 0 ? -0.1 : 0;
    } else if (button == 3) { // Scroll up
        camera.fov += camera.fov < 180 ? 0.1 : 0;
    }
    Project(camera.get_viewing_mode() ? camera.fov : 0, camera.asp, camera.dim);
    glutPostRedisplay();
}

void mouse_move(int x, int y) {
    Camera &camera = scene.getCamera();
    if(camera.is_dragging){
        int dx = x - camera.mouse_x;
        int dy = y - camera.mouse_y;
        if (camera.get_viewing_mode() == FIRST_PERSON) {
            camera.x -= dx * camera.pan_speed * scene.dir_z;
            camera.z += dx * camera.pan_speed * scene.dir_x;

            camera.x += dy * camera.pan_speed * scene.dir_x;
            camera.z += dy * camera.pan_speed * scene.dir_z;

        } else {
            camera.th += dx * camera.pan_speed * 100.0f;
            camera.ph += dy * camera.pan_speed * 100.0f;
        }

        camera.mouse_x = x;
        camera.mouse_y = y;

    }

    if(camera.pan_dragging){
        int dx = x - camera.prev_pan_x;
        int dy = y - camera.prev_pan_y;
        camera.pan_x += dx;
        camera.pan_y += dy;
        camera.prev_pan_x = x;
        camera.prev_pan_y = y;
    }

    if(camera.object_dragging)
    {
        float dir_x = (x - camera.object_x);
        float dir_y = (y - camera.object_y);
        scene.update_selected_objects(Vector3(dir_x, 0, dir_y));
        camera.object_x = x;
        camera.object_y = y;
    }
    // Redisplay the scene
    Project(camera.get_viewing_mode() ? camera.fov : 0, camera.asp, camera.dim);
    glutPostRedisplay();
}

/*
 *  GLUT calls this routine when an arrow key is pressed
 */
void special(int key, int x, int y) {
    Camera &camera = scene.getCamera();
    //  Right arrow key - increase angle by 5 degrees
    if (camera.get_viewing_mode() == FIRST_PERSON) {
        double speed = 0.5;
        if (key == GLUT_KEY_LEFT) {
            camera.x += scene.dir_z * speed;
            camera.z -= scene.dir_x * speed;
        }
            //  Left arrow key - decrease angle by 5 degrees
        else if (key == GLUT_KEY_RIGHT) {
            camera.x -= scene.dir_z * speed;
            camera.z += scene.dir_x * speed;
        }
            //  Up arrow key - increase elevation by 5 degrees
        else if (key == GLUT_KEY_UP) {
            camera.x += scene.dir_x * speed;
            camera.z += scene.dir_z * speed;
        }
            //  Down arrow key - decrease elevation by 5 degrees
        else if (key == GLUT_KEY_DOWN) {
            camera.x -= scene.dir_x * speed;
            camera.z -= scene.dir_z * speed;
        }
    } else if(!camera.camera_locked) {
        if (key == GLUT_KEY_RIGHT)
            camera.th += 5;
            //  Left arrow key - decrease angle by 5 degrees
        else if (key == GLUT_KEY_LEFT)
            camera.th -= 5;
            //  Up arrow key - increase elevation by 5 degrees
        else if (key == GLUT_KEY_UP)
            camera.ph += 5;
            //  Down arrow key - decrease elevation by 5 degrees
        else if (key == GLUT_KEY_DOWN)
            camera.ph -= 5;
            //  PageUp key - increase dim
        else if (key == GLUT_KEY_PAGE_UP)
            camera.dim += 0.1;
            //  PageDown key - decrease dim
        else if (key == GLUT_KEY_PAGE_DOWN && camera.dim > 1)
            camera.dim -= 0.1;
        //  Keep angles to +/-360 degrees
        camera.th %= 360;
        camera.ph %= 360;
    } else{
        int modifiers = glutGetModifiers();
        if (key == GLUT_KEY_RIGHT)
            scene.update_selected_objects(Vector3(1, 0, 0));
            //  Left arrow key - decrease angle by 5 degrees
        else if (key == GLUT_KEY_LEFT)
            scene.update_selected_objects(Vector3(-1, 0, 0));
            //  Up arrow key - increase elevation by 5 degrees
        else if (key == GLUT_KEY_UP) {
            if (modifiers == GLUT_ACTIVE_SHIFT) {
                scene.update_selected_objects(Vector3(0, 1, 0));
            } else {
                scene.update_selected_objects(Vector3(0, 0, -1));
            }
        }
        //  Down arrow key - decrease elevation by 5 degrees
        else if (key == GLUT_KEY_DOWN) {
            if (modifiers == GLUT_ACTIVE_SHIFT) {
                scene.update_selected_objects(Vector3(0, -1, 0));
            } else {
                scene.update_selected_objects(Vector3(0, 0, 1));
            }
        }
    }
    Project(camera.get_viewing_mode() ? camera.fov : 0, camera.asp, camera.dim);
    //  Tell GLUT it is necessary to redisplay the scene
    glutPostRedisplay();
}

/*
 *  GLUT calls this routine when a key is pressed
 */
void key(unsigned char ch, int x, int y) {
    Camera &camera = scene.getCamera();
    //  Exit on ESC
    if (ch == 27) {
        scene.delete_scene();
        exit(0);
    }
    //  Reset view angle
    if (ch == '0')
        camera.th = camera.ph = camera.pitch = camera.angle = camera.pan_x = camera.pan_y = camera.prev_pan_x = camera.prev_pan_y = 0;
        //  Toggle debug
    else if (ch == 'x' || ch == 'X') {
        renderer.set_axis(1 - renderer.get_axis());
        renderer.set_debug(1 - renderer.get_debug());
    } else if (ch == 'l' || ch == 'L')
        light = 1 - light;
        //  Switch display camera.get_viewing_mode()
    else if (ch == 'm' || ch == 'M')
        camera.change_viewing_mode(camera.get_viewing_mode() + 1);
    else if (ch == 'n' || ch == 'N')
        move = 1 - move;
        //  Toggle lighting
    else if (ch == 'l' || ch == 'L')
        light = 1 - light;
    else if (ch == '[')
        ylight -= 0.1;
    else if (ch == ']')
        ylight += 0.1;
        //  Change field of view angle
    else if (ch == '-' && ch > 1)
        camera.fov += camera.fov > 0 ? -1 : 0;
    else if (ch == '+' && ch < 179)
        camera.fov += camera.fov < 180 ? 1 : 0;
        //  Move light
    else if (ch == '<')
        zh += 1;
    else if (ch == '>')
        zh -= 1;
        //  Ambient level
    else if (ch == 'c' && ambient > 0)
        ambient -= 5;
    else if (ch == 'C' && ambient < 100)
        ambient += 5;
    else if (ch == 't'){
        camera.camera_locked = true;
        scene.set_object_op(TRANSLATE);
    } else if (ch == 'r'){
        camera.camera_locked = true;
        scene.set_object_op(ROTATE);
    } else if (ch == 'y'){
        camera.camera_locked = true;
        scene.set_object_op(SCALE);
    } else if (ch == 'u'){
        camera.camera_locked = false;
    }

    if (camera.get_viewing_mode() == FIRST_PERSON) {
        if (ch == 'a')
            camera.angle -= 5;
        else if (ch == 'd')
            camera.angle += 5;
        else if (ch == 'w')
            camera.pitch += 5;
        else if (ch == 's')
            camera.pitch -= 5;
        fmod(camera.angle, 360);
        fmod(camera.pitch, 360);
        scene.dir_x = Cos(camera.angle);
        scene.dir_y = Sin(camera.pitch);
        scene.dir_z = Sin(camera.angle);
    }
    //  Reproject
    Project(camera.get_viewing_mode() ? camera.fov : 0, camera.asp, camera.dim);
    //  Tell GLUT it is necessary to redisplay the scene
    glutPostRedisplay();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void reshape(int width, int height) {
    Camera &camera = scene.getCamera();
    renderer.set_display_width(width);
    renderer.set_display_height(height);
    //  Ratio of the width to the height of the window
    camera.asp = (height > 0) ? (double) width / height : 1;
    //  Set the viewport to the entire window
    glViewport(0, 0, RES * width, RES * height);
    renderer.resize();
    //  Set projection
    Project(camera.get_viewing_mode() ? camera.fov : 0, camera.asp, camera.dim);
}

/*
 *  GLUT calls this routine when there is nothing else to do
 */
void idle() {
    Camera &camera = scene.getCamera();
    renderer.sun_xy.x = fmod(renderer.sun_xy.x + 1, 360.0f);
    renderer.sun_xy.y = fmod(renderer.sun_xy.y + 1, 360.0f);
//    renderer.add_sun_position({ 1, 0});
    glutPostRedisplay();
}

/*
 *  Start up GLUT and tell it what to do
 */
int main(int argc, char *argv[]) {
    //  Initialize GLUT and process user parameters
    glutInit(&argc, argv);
    //  Request double buffered, true colors window with Z buffering at 600x600
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    //  Create the window
    glutCreateWindow("Erick Alanis");
#ifdef USEGLEW
    //  Initialize GLEW
    if (glewInit()!=GLEW_OK) Fatal("Error initializing GLEW\n");
#endif
    //  Tell GLUT to call "idle" when there is nothing else to do
    glutIdleFunc(idle);
    //  Tell GLUT to call "display" when the scene should be drawn
    glutDisplayFunc(display);
    //  Tell GLUT to call "reshape" when the window is resized
    glutReshapeFunc(reshape);
    //  Tell GLUT to call "mouse" when the mouse_click is used
    glutMouseFunc(mouse_click);
    //  Tell GLUT to call "mouse" when the mouse_move is used
    glutMotionFunc(mouse_move);
    //  Tell GLUT to call "special" when an arrow key is pressed
    glutSpecialFunc(special);
    //  Tell GLUT to call "key" when a key is pressed
    glutKeyboardFunc(key);
    renderer = Renderer();
    Texture::get_instance(); // To initialize textures

     ExampleScene exampleScene = ExampleScene();
     scene = exampleScene.get_scene();

//    scene = Scene();
//    scene.getCamera().fov = 2;
//    scene.getCamera().change_viewing_mode(PERSPECTIVE);
//    scene.add_skybox(new Skybox());
//    Pipe* pipe = new Pipe();
//    pipe->add_point(Vector3(0, 0, 0));
//    pipe->add_point(Vector3(0, 0, 10));
//    pipe->add_point(Vector3(10, 0, 10));
//    pipe->generate_pipe();
//    scene.add_object(pipe);

    //  Pass control to GLUT so it can interact with the user
    glutMainLoop();


    return 0;
}
