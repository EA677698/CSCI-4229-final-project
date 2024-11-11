#include "renderer.h"

Renderer::Renderer(){
    axis = 1;
    debug = DEBUG_OFF;
}

Renderer::~Renderer(){}

void Renderer::render(Scene scene){
    
    Camera& camera = scene.getCamera();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //  Enable Z-buffering in OpenGL
    glEnable(GL_DEPTH_TEST);
    //  Undo previous transformations
    glLoadIdentity();
    scene.getCamera().view(scene.dir_x, scene.dir_y, scene.dir_z);

    std::vector<Object> objects = scene.get_objects();

    for(int i = 0; i < objects.size(); i++){
        Object object = objects[i];
        std::vector<Polygon> polygons = object.get_polygons();
        for(int j = 0; j < polygons.size(); j++){
            Polygon polygon = polygons[j];
            std::vector<Vector3> vertices = polygon.get_vertices();
            int color = polygon.get_color();
            unsigned int texture = polygon.get_texture();
            if (texture != TEXTURE_NULL){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, texture);
            }
            else{
                glDisable(GL_TEXTURE_2D);
            }
            glColor3ub((color>>16)&0xFF,(color>>8)&0xFF,color&0xFF);
            glBegin(GL_POLYGON);
            for(int k = 0; k < vertices.size(); k++){
                Vector3 vertex = vertices[k];
                glVertex3f(vertex.x, vertex.y, vertex.z);
            }
            glEnd();
        }
    }
    
    if (axis){
        render_axis();
    }

    if(debug){
        //  Five pixels from the lower left corner of the window
        glWindowPos2i(5,5);
        //  Print the text string
        char* mode_str = "";
        if (camera.get_viewing_mode() == ORTHOGONAL)
           mode_str = "Orthogonal";
        else if (camera.get_viewing_mode() == 1)
           mode_str = "Perspective";
        else
           mode_str = "First Person";
        Print("Angle=%d,%d  Dim=%.1f FOV=%d Projection=%s",camera.th,camera.ph,camera.dim,camera.fov,mode_str);
        //  Render the scene
        ErrCheck("display");
    }

    glFlush();
    glutSwapBuffers();
}

void Renderer::render_axis(){
    glColor3f(1,1,1);
    const double len=1.5;  //  Length of axes
    glBegin(GL_LINES);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(len,0.0,0.0);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(0.0,len,0.0);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(0.0,0.0,len);
    glEnd();
    //  Label axes
    glRasterPos3d(len,0.0,0.0);
    Print("X");
    glRasterPos3d(0.0,len,0.0);
    Print("Y");
    glRasterPos3d(0.0,0.0,len);
    Print("Z");
}

void Renderer::set_axis(int mode){
    axis = mode;
}

int Renderer::get_axis(){
    return axis;
}

void Renderer::set_debug(int mode){
    debug = mode;
}