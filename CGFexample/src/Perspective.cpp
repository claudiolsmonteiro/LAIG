

#include "Perspective.h"

Perspective::Perspective(char *i,float n, float f, float a, float p[3], float t[3]):id(i),near(f),far(f),angle(a){
    for(int i = 0; i < 3;i++) {
        pos[i] = p[i];
        target[i] = t[i];
    }
}

void Perspective::updateProjectionMatrix(int width, int height){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, (float) CGFapplication::width / (float) CGFapplication::height, near, far);
}

void Perspective::applyView() {
   	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, 1.0, near, far);
    gluLookAt(pos[0],pos[1], pos[2], target[0], target[1],target[2], 0, 1, 0);
	
}
char* Perspective::getId(){
    return id;
}

Perspective::~Perspective()
{
}