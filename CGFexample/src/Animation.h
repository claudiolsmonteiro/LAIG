#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <vector>
#include <string.h>
#include <math.h>
#include "CGFapplication.h"

using namespace std;

class Point{
public:
	Point();
	Point(float x, float y, float z);
	float getX();
	float getY();
	float getZ();
private:
	float px, py, pz;
};

class LinearAnimation {
public:
	LinearAnimation();
	LinearAnimation(int x, int y, int z);
	LinearAnimation(char *id, float span, std::vector<Point> controlpts);
	void reset();
	void update(unsigned long t);
	void draw();
	float getPosX();
	float getPosY();
	float getPosZ();

private:
	string id;
	float span;
	std::vector<Point> controlpts;
	void init(unsigned long t);
	unsigned long startTime, oldTime;
	unsigned char doReset;
	float  posX, posY, posZ, obj_rotate, radius_speed_ms;
	unsigned int currentControlPoint;
	float translated;
	float currentDirX, currentDirZ;
};

class CircularAnimation{
public:
	CircularAnimation();
	CircularAnimation(char *id, float span, Point center, float radius, float startAng, float rotAng);
	void reset();
	void update(unsigned long t);
	void draw();
private:
	string id;
	float span;
	void init(unsigned long t);
	unsigned long startTime, oldTime;
	unsigned char doReset;
	Point center;
	float radius, startAng, rotAng;
	float currentRotate;
	float angularSpeed;
};

class Animation {
public:
Animation();
Animation(LinearAnimation la);
Animation(CircularAnimation ca);
void draw();
void update(unsigned long t);

private:
	LinearAnimation la;
	CircularAnimation ca;
	string type;
};
#endif

