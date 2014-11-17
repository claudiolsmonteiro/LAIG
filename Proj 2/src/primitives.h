#ifndef _primitives_h_
#define _primitives_h_

#include <stdio.h>
#include "CGFapplication.h"
#include "myTexture.h"

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

class Rectangle{
public:
	Rectangle();
	Rectangle(float xi, float yi, float xf, float yf);
	float getFirstX();
	float getFirstY();
	float getLastX();
	float getLastY();
	void draw(float s, float t);
	~Rectangle();
private:
	float x1,x2,y1,y2;
};

class Triangle{
public:
	Triangle();
	Triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	Point getP1();
	Point getP2();
	Point getP3();
	void draw(float s, float t);
	~Triangle();
private:
	Point p1, p2, p3;
	float p1x, p1y, p1z, p2x, p2y, p2z, p3x, p3y, p3z;
};

class Cylinder{
public:
	Cylinder();
	Cylinder(float b, float t, float h, int sl, int st);
	float getBase();
	float getTop();
	float getHeight();
	int getSlices();
	int getStacks();
	~Cylinder();
private:
	float base, top, height;
	int slices, stacks;
};

class Sphere{
public:
	Sphere();
	Sphere(float r, int sl, int st);
	float getRadius();
	int getSlices();
	int getStacks();
	~Sphere();
private:
	float radius;
	int slices, stacks;
};

class Torus{
public:
	Torus();
    Torus(float i, float o, int sl, int l);
	float getInner();
	float getOuter();
	int getSlices();
	int getLoops();
	void DrawTorus();
    ~Torus();
private:
	float inner, outer;
	int slices, loops;
};

class Plane
{
public:
    Plane(void);
    Plane(int);
    ~Plane(void);
    void draw();
private:
    int _numDivisions; // Number of triangles that constitute rows/columns
};

class Patch
{
public:
    Patch(void);
    Patch(int order, int partsU,int partsV,char *compute,float controlpointx, float controlpointy, float controlpointz);
    ~Patch(void);
    void draw();
private:
    int order,partsU,partsV;
    char * compute;
    float controlpointx,controlpointy,controlpointz;
};
class Primitive{
public:
    Primitive(Rectangle r);
	Primitive(Triangle t);
	Primitive(Cylinder c);
	Primitive(Sphere s);
	Primitive(Torus t);
    Primitive(Plane p);
    Primitive(Patch pt);
	Rectangle getRectangle();
	Triangle getTriangle();
	Cylinder getCylinder();
	Sphere getSphere();
	Torus getTorus();
    Plane getPlane();
    Patch getPatch();
	string getType();
	void draw(int texS, int texL);
    ~Primitive();
private:
	Rectangle rectangle;
	Triangle triangle;
	Cylinder cylinder;
	Sphere sphere;
	Torus torus;
    Plane plane;
    Patch patch;
	string type;
};

#endif