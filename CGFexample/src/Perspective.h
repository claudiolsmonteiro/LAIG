#ifndef _Perspective_H_
#define _Perspective_H_

#include "CGFapplication.h"


class Perspective:public CGFcamera
{
public:
    Perspective(char *i,float n, float f, float a, float p[3], float t[3]);
    ~Perspective();
    char* getId();
    
protected:
    char *id;
    float near, far, angle, pos[3],target[3];
    void updateProjectionMatrix();
    void applyView();

    
};

#endif
