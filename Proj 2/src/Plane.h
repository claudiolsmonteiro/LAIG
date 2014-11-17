#pragma once

#include "CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	Plane(int, double);
	~Plane(void);
	void draw();
	void draw(int,int);
	void drawWindowWall();
	void drawWindowWallOpen();
private:
	double _ratio;
	int _numDivisions; // Number of triangles that constitute rows/columns
};

