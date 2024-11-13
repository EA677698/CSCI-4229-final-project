#include "camera.h"

Camera::Camera(){
    th = 0;
    ph = 0;
    fov = 55;
    asp = 1;
    dim = 10.0;

    angle = 0;
    pitch = 0;
    
    x = 0;
    y = 1;
    z = 5;

    mode = PERSPECTIVE;
}

Camera::~Camera(){}

void Camera::change_viewing_mode(int mode){
    this->mode = mode % 3;
}

void Camera::view(double dir_x, double dir_y, double dir_z){
    if (mode == FIRST_PERSON) // first person
      gluLookAt(x, y, z, x + dir_x, y + dir_y, z + dir_z, 0, 1, 0);
   else if (mode == PERSPECTIVE)
   {
      double Ex = -2*dim*Sin(th)*Cos(ph);
      double Ey = +2*dim        *Sin(ph);
      double Ez = +2*dim*Cos(th)*Cos(ph);
      gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ph),0);
   }
   //  Orthogonal - set world orientation
   else
   {
      glRotatef(ph,1,0,0);
      glRotatef(th,0,1,0);
   }
}

int Camera::get_viewing_mode(){
    return mode;
}