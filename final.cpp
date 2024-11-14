#include "csci_lib/CSCIx229.h"
#include "scene.h"
#include "renderer.h"
#include "objects/terrain.h"
#include "objects/generic/skyscraper.h"
#include "texture.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
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

int move=1;       //  Move light
const char* text[] = {""};

int light     =   0;  // Lighting
int one       =   1;  // Unit value
int distance  =   5;  // Light distance
int inc       =  10;  // Ball increment
int smooth    =   1;  // Smooth/Flat shading
int local     =   0;  // Local Viewer Model
int emission  =   0;  // Emission intensity (%)
int ambient   =  10;  // Ambient intensity (%)
int diffuse   =  50;  // Diffuse intensity (%)
int specular  =   0;  // Specular intensity (%)
int shininess =   0;  // Shininess (power of two)
float shiny   =   1;  // Shininess (value)
int zh        =  90;  // Light azimuth
float ylight  =   0;  // Elevation of light

/*
 *  OpenGL (GLUT) calls this routine to display the scene
 */
void display()
{
   renderer.render(scene);
}

/*
 *  GLUT calls this routine when an arrow key is pressed
 */
void special(int key,int x,int y)
{
   Camera& camera = scene.getCamera();
   //  Right arrow key - increase angle by 5 degrees
   if (camera.get_viewing_mode() == FIRST_PERSON){
      double speed = 0.5;
      if (key == GLUT_KEY_LEFT){
         camera.x += scene.dir_z * speed;
         camera.z -= scene.dir_x * speed;
      }
      //  Left arrow key - decrease angle by 5 degrees
      else if (key == GLUT_KEY_RIGHT){
         camera.x -= scene.dir_z * speed;
         camera.z += scene.dir_x * speed;
      }
      //  Up arrow key - increase elevation by 5 degrees
      else if (key == GLUT_KEY_UP) {
         camera.x += scene.dir_x * speed;
         camera.z += scene.dir_z * speed;
      }
      //  Down arrow key - decrease elevation by 5 degrees
      else if (key == GLUT_KEY_DOWN){
         camera.x -= scene.dir_x * speed;
         camera.z -= scene.dir_z * speed;
      }
   } else{
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
      else if (key == GLUT_KEY_PAGE_DOWN && camera.dim>1)
         camera.dim -= 0.1;
      //  Keep angles to +/-360 degrees
      camera.th %= 360;
      camera.ph %= 360;
   }
   Project(camera.get_viewing_mode()?camera.fov:0,camera.asp,camera.dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when a key is pressed
 */
void key(unsigned char ch,int x,int y)
{
   Camera& camera = scene.getCamera();
   //  Exit on ESC
   if (ch == 27)
      exit(0);
   //  Reset view angle
   else if (ch == '0')
      camera.th = camera.ph = camera.pitch = camera.angle = 0;
   //  Toggle axes
   else if (ch == 'x' || ch == 'X')
      renderer.set_axis(1 - renderer.get_axis());
   else if (ch == 'l' || ch == 'L')
      light = 1-light;
   //  Switch display camera.get_viewing_mode()
   else if (ch == 'm' || ch == 'M')
      camera.change_viewing_mode(camera.get_viewing_mode() + 1);
   else if (ch == 'n' || ch == 'N')
      move = 1-move;
   //  Toggle lighting
   else if (ch == 'l' || ch == 'L')
      light = 1-light;
   else if (ch=='[')
      ylight -= 0.1;
   else if (ch==']')
      ylight += 0.1;
   //  Change field of view angle
   else if (ch == '-' && ch>1)
      camera.fov--;
   else if (ch == '+' && ch<179)
      camera.fov++;
   //  Move light
   else if (ch == '<')
      zh += 1;
   else if (ch == '>')
      zh -= 1;
   //  Ambient level
   else if (ch=='c' && ambient>0)
      ambient -= 5;
   else if (ch=='C' && ambient<100)
      ambient += 5;

   if (camera.get_viewing_mode() == FIRST_PERSON){
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
   Project(camera.get_viewing_mode()?camera.fov:0,camera.asp,camera.dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void reshape(int width,int height)
{
   Camera& camera = scene.getCamera();
   //  Ratio of the width to the height of the window
   camera.asp = (height>0) ? (double)width/height : 1;
   //  Set the viewport to the entire window
   glViewport(0,0, RES*width,RES*height);
   //  Set projection
   Project(camera.get_viewing_mode()?camera.fov:0,camera.asp,camera.dim);
}

/*
 *  GLUT calls this routine when there is nothing else to do
 */
void idle()
{
   glutPostRedisplay();
}

/*
 *  Start up GLUT and tell it what to do
 */
int main(int argc,char* argv[])
{
   //  Initialize GLUT and process user parameters
   glutInit(&argc,argv);
   //  Request double buffered, true color window with Z buffering at 600x600
   glutInitWindowSize(600,600);
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
   //  Tell GLUT to call "special" when an arrow key is pressed
   glutSpecialFunc(special);
   //  Tell GLUT to call "key" when a key is pressed
   glutKeyboardFunc(key);
   scene = Scene();
   //scene.add_object(Terrain());
   renderer = Renderer();
   renderer.set_axis(ENABLE_AXIS);
   renderer.set_debug(DEBUG_ON);
   Texture::get_instance();
   scene.add_object(Skyscraper());
   //  Pass control to GLUT so it can interact with the user
   glutMainLoop();


   return 0;
}
