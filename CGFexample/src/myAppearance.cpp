#include "myAppearance.h"

myAppearance::myAppearance(){
}

myAppearance::myAppearance(char *n, float s): name(n), shininess(s){
	this->texRef = NULL;
}

char *myAppearance::getName(){
    return this->name;
}

char *myAppearance::getTexRef(){
    return this->texRef;
}

void myAppearance::setAmbient(float *amb){
	this->ambient[0] = amb[0];
	this->ambient[1] = amb[1];
	this->ambient[2] = amb[2];
	this->ambient[3] = amb[3];
}

void myAppearance::setDiffuse(float *dif){
	this->diffuse[0] = dif[0];
	this->diffuse[1] = dif[1];
	this->diffuse[2] = dif[2];
	this->diffuse[3] = dif[3];
}

void myAppearance::setSpecular(float *spec){
	this->specular[0] = spec[0];
	this->specular[1] = spec[1];
	this->specular[2] = spec[2];
	this->specular[3] = spec[3];
}

void myAppearance::setTexRef(char *tf){
    this->texRef = tf;
}

float *myAppearance::getAmbient(){
	return ambient;
}

float *myAppearance::getDiffuse(){
	return diffuse;
}


float *myAppearance::getSpecular(){
	return specular;
}

float myAppearance::getShininess(){
	return shininess;
}

myAppearance::~myAppearance(){
}