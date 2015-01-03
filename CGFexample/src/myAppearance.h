#ifndef _myAppearance_h_
#define _myAppearance_h_

#include <stdio.h>
#include "CGFapplication.h"

using namespace std;

class myAppearance{
public:
	myAppearance();
    myAppearance(char *n, float s);
    string getName();
	string getTexRef();
	void setAmbient(float *amb);
	void setDiffuse(float *dif);
	void setSpecular(float *spec);
	void setTexRef(char *tf);
	float *getAmbient();
	float *getDiffuse();
	float *getSpecular();
	float getShininess();
    ~myAppearance();
    
private:
    string name, texRef;
	float ambient[4], diffuse[4], specular[4], shininess;
};
#endif /* defined(__CGFExample__myTexture__) */
