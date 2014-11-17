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

class myTexture{
public:
	myTexture();
    myTexture(char *n);
    myTexture(char *n, char *f, float s, float t);
    string getName();
	string getFile();
	float getSLenght();
	float getTLenght();
    ~myTexture();
    
private:
    string name, file;
	float sLenght, tLenght;
};
#endif /* defined(__CGFExample__myTexture__) */
