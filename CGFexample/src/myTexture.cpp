//
//  myTexture.cpp
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#include "myTexture.h"

myTexture::myTexture():sLenght(0), tLenght(0){
    
}

myTexture::myTexture(char *n){
	string s(n);
	this->name = s;
}

myTexture::myTexture(char *n, char *f, float s, float t):file(f), sLenght(s), tLenght(t){
    string str(n);
	this->name = str;
}

string myTexture::getName(){
    return this->name;
}

string myTexture::getFile(){
	return this->file;
}

float myTexture::getSLenght(){
	return this->sLenght;
}

float myTexture::getTLenght(){
	return this->tLenght;
}

myTexture::~myTexture(){
    
}