#ifndef _Orthocamera_H_
#define _Orthocamera_H_

#include "CGFapplication.h"


class Orthocamera:public CGFcamera
{
public:
    Orthocamera(char d, float l, float r, float b, float t, float n, float f);
    ~Orthocamera();
    char* getId();
    
protected:
    char direction,*id;
    float left, right, bottom, top, near, far;
    void updateProjectionMatrix();
    void applyView();
    
    
};

#endif
