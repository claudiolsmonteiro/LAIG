

#include "Orthocamera.h"

Orthocamera::Orthocamera(char d, float l, float r, float b, float t, float n, float f):direction(d),left(l),right(r),bottom(b),top(t),near(n),far(f){
    
}

void Orthocamera::updateProjectionMatrix(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, near, far);
}

void Orthocamera::applyView() {
    if (direction == 'x')
    {
        glRotatef(90.0, 0.f, 1.f, 0.f);
        
    }
    else if(direction == 'y')
    {
        glRotatef(90.0, 1.f, 0.f, 0.f);
    }
}
char* Orthocamera::getId(){
    return id;
}

Orthocamera::~Orthocamera()
{
}