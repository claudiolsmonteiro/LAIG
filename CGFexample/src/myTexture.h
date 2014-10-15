//
//  myTexture.h
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#ifndef _myTexture_h_
#define _myTexture_h_

#include <stdio.h>
#include "CGFapplication.h"

class myTexture:public CGFtexture{
public:
    myTexture(char *n);
    myTexture(char *n, char *f);
    char *getName();
    ~myTexture();
    
private:
    char *name;
};
#endif /* defined(__CGFExample__myTexture__) */
