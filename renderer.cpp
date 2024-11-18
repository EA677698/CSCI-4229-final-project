#include "renderer.h"
#include "texture.h"
#include <string>

Renderer::Renderer(){
    axis = 0;
    debug = DEBUG_OFF;
}

Renderer::~Renderer(){}

void Renderer::render_debug(Scene scene)
{
    Camera& camera = scene.getCamera();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    std::vector<BoundingBox> bounding_boxes = scene.get_bounding_boxes();
    for(unsigned int i = 0; i < bounding_boxes.size(); i++)
    {
        Object object = *bounding_boxes[i].get_object();
        glPushMatrix();
        glScalef(1.01f, 1.01f, 1.01f);
        glTranslatef(-(object.get_width()/2), 0, -(object.get_depth()/2));
        std::vector<Polygon> polygons = bounding_boxes[i].get_polygons();
        for(unsigned int j = 0; j < polygons.size(); j++)
        {
            Polygon polygon = polygons[j];
            std::vector<Vector3> vertices = polygon.get_vertices();
            int color = bounding_boxes[i].get_color();
            glBegin(GL_POLYGON);
            glColor4ub((color >> 16) & 0xFF,( color >> 8) & 0xFF,color & 0xFF, 0xA0);
            for(unsigned int k = 0; k < vertices.size(); k++)
            {
                glVertex3f(vertices[k].x, vertices[k].y, vertices[k].z);
            }
            glEnd();
        }
        glPopMatrix();


    }

    glDisable(GL_BLEND);


    //  Five pixels from the lower left corner of the window
    glColor3ub(0xFF,0xFF,0xFF);
    glWindowPos2i(5,5);
    //  Print the text string
    std::string mode_str = "";
    if (camera.get_viewing_mode() == ORTHOGONAL)
        mode_str = "Orthogonal";
    else if (camera.get_viewing_mode() == PERSPECTIVE)
        mode_str = "Perspective";
    else
        mode_str = "First Person";
    Print("Angle=%d,%d  Dim=%.1f FOV=%d Projection=%s",camera.th,camera.ph,camera.dim,camera.fov,mode_str.c_str());
    //  Render the scene
}


void Renderer::render(Scene scene){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //  Enable Z-buffering in OpenGL
    glEnable(GL_DEPTH_TEST);
    //  Undo previous transformations
    glLoadIdentity();
    glEnable(GL_NORMALIZE);
    scene.getCamera().view(scene.dir_x, scene.dir_y, scene.dir_z);

    std::vector<Object*> objects = scene.get_objects();

    for(unsigned int i = 0; i < objects.size(); i++){
        Object object = *objects[i];
        std::vector<Polygon> polygons = object.get_polygons();
        glPushMatrix();
        glTranslatef(-(object.get_width()/2), 0, -(object.get_depth()/2));
        for(unsigned int j = 0; j < polygons.size(); j++){
            Polygon polygon = polygons[j];
            std::vector<Vector3> vertices = polygon.get_vertices();
            std::vector<Vector2> texture_vertices = polygon.get_texture_vertices();
            int color = polygon.get_color();

            unsigned int texture = polygon.get_texture();
            float repeats = polygon.get_texture_repeats();
            Vector3 normal = polygon.calculate_normal();
            if (polygon.contains_texture())
            {
                glEnable(GL_TEXTURE_2D);
                glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
                glBindTexture(GL_TEXTURE_2D, texture);
            }
            glBegin(GL_POLYGON);
            glColor3ub((color >> 16) & 0xFF,( color >> 8) & 0xFF,color & 0xFF);
            glNormal3f(normal.x, normal.y, normal.z);
            for(unsigned int k = 0; k < vertices.size(); k++){
                glTexCoord2f(texture_vertices[k].x * repeats, texture_vertices[k].y * repeats);
                glVertex3f(vertices[k].x, vertices[k].y, vertices[k].z);
            }
            glEnd();
            if (polygon.contains_texture())
            {
                glDisable(GL_TEXTURE_2D);
            }
        }
        glPopMatrix();
    }
    
    if (axis){
        render_axis();
    }

    if(debug){
        render_debug(scene);
    }

    ErrCheck("Renderer");
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