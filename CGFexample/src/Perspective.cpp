

#include "Perspective.h"

Perspective::Perspective(char *i,float n, float f, float a, float p[3], float t[3]):id(i),near(f),far(f),angle(a){
    for(int i = 0; i < 3;i++) {
        pos[i] = p[i];
        target[i] = t[i];
    }
}

void Perspective::updateProjectionMatrix(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, 1.0, near, far);
}

void Perspective::applyView() {
    if (mode==EXAMINE_MODE)
    {
        glTranslatef(pos[0],pos[1], pos[2]);
        // glTranslatef(0, 0, position[2]); // or this, if we ignore panning
        
        glRotatef(target[0], 1.f, 0.f, 0.f);
        glRotatef(target[1], 0.f, 1.f, 0.f);
        glRotatef(target[2], 0.f, 0.f, 1.f);
        
    }
    else
    {
        glRotatef(target[0], 1.f, 0.f, 0.f);
        glRotatef(target[1], 0.f, 1.f, 0.f);
        glRotatef(target[2], 0.f, 0.f, 1.f);
        
        glTranslatef(pos[0], pos[1], pos[2]);
    }
}
char* Perspective::getId(){
    return id;
}

Perspective::~Perspective()
{
}