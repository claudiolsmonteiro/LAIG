//
//  myLight.cpp
//  CGFExample
//
//  Created by Cláudio Monteiro on 12/10/14.
//  Copyright (c) 2014 me. All rights reserved.
//

#include "myLight.h"

myLight::myLight(unsigned int id, float *pos, char *n, bool e, bool m):id(id), name(n), enabled(e), marked(m){
	this->position[0] = pos[0];
	this->position[1] = pos[1];
	this->position[2] = pos[2];
	angle = -1;
    
}

myLight::myLight(unsigned int id, float *pos, float *dir, char *n, bool e, bool m):id(id), name(n), enabled(e), marked(m){
    this->position[0] = pos[0];
	this->position[1] = pos[1];
	this->position[2] = pos[2];

	this->direction[0] = dir[0];
	this->direction[1] = dir[1];
	this->direction[2] = dir[2];
	angle = -1;
}

unsigned int myLight::getID(){
	return id;
}

char *myLight::getName(){
    return this->name;
}

float* myLight::getPosition(){
	return position;
}

float* myLight::getDirection(){
	return direction;
}

void myLight::setAmbient(float *amb){
	this->ambient[0] = amb[0];
	this->ambient[1] = amb[1];
	this->ambient[2] = amb[2];
	this->ambient[3] = amb[3];
}

void myLight::setDiffuse(float *dif){
	this->diffuse[0] = dif[0];
	this->diffuse[1] = dif[1];
	this->diffuse[2] = dif[2];
	this->diffuse[3] = dif[3];
}

void myLight::setSpecular(float *spec){
	this->specular[0] = spec[0];
	this->specular[1] = spec[1];
	this->specular[2] = spec[2];
	this->specular[3] = spec[3];
}

void myLight::setAngle(float a){
	this->angle = a;
}

void myLight::setExponent(float e){
	exponent = e;
}

float *myLight::getAmbient(){
	return ambient;
}

float *myLight::getDiffuse(){
	return diffuse;
}


float *myLight::getSpecular(){
	return specular;
}

float myLight::getAngle(){
	return angle;
}

float myLight::getExponent(){
	return exponent;
}


bool myLight::isEnabled(){
    return this->enabled;
}

bool myLight::isMarked(){
    return this->marked;
}

myLight::~myLight()
{
}