//
//  myTexture.cpp
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#include "myTexture.h"


myTexture::myTexture(char *n):name(n){
    
}

myTexture::myTexture(char *n, char *f):CGFtexture(f), name(n){
    
}

char *myTexture::getName(){
    return this->name;
}
myTexture::~myTexture(){
    
}