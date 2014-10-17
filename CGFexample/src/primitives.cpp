#include "primitives.h"

Primitive::Primitive(Rectangle r) {
    this->rectangle = r;
	this->type = "rectangle";
}
Primitive::Primitive(Triangle t) {
    this->triangle = t;
	this->type = "triangle";
}
Primitive::Primitive(Cylinder c) {
    this->cylinder = c;
	this->type = "cylinder";
}
Primitive::Primitive(Sphere s) {
    this->sphere = s;
	this->type = "sphere";
}
Primitive::Primitive(Torus t) {
    this->torus = t;
	this->type = "Torus";
}
Rectangle Primitive::getRectangle(){
	return rectangle;
}
Triangle Primitive::getTriangle(){
	return triangle;
}
Cylinder Primitive::getCylinder(){
	return cylinder;
}
Sphere Primitive::getSphere(){
	return sphere;
}
Torus Primitive::getTorus(){
	return torus;
}
char *Primitive::getType(){
	return type;
}
Primitive::~Primitive()
{
}


Rectangle::Rectangle(){
}
Triangle::Triangle(){
}
Cylinder::Cylinder(){
}
Torus::Torus(){
}
Sphere::Sphere(){
}

Rectangle::Rectangle(float xi, float yi, float xf, float yf): x1(xi), y1(yi), x2(xf), y2(yf){
}

float Rectangle::getFirstX(){
	return x1;
}
float Rectangle::getFirstY(){
	return y1;
}
float Rectangle::getLastX(){
	return x2;
}
float Rectangle::getLastY(){
	return y2;
}

Rectangle::~Rectangle(){
}

Triangle::Triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3): p1x(x1), p1y(y1), p1z(z1), p2x(x2), p2y(y2), p2z(z2), p3x(x3), p3y(y3), p3z(z3){
}

float Triangle::getFirstX(){
	return p1x;
}
float Triangle::getFirstY(){
	return p1y;
}
float Triangle::getFirstZ(){
	return p1z;
}
float Triangle::getMiddleX(){
	return p2x;
}
float Triangle::getMiddleY(){
	return p2y;
}
float Triangle::getMiddleZ(){
	return p2z;
}
float Triangle::getLastX(){
	return p3x;
}
float Triangle::getLastY(){
	return p3y;
}
float Triangle::getLastZ(){
	return p3z;
}

Triangle::~Triangle(){
}

Cylinder::Cylinder(float b, float t, float h, int sl, int st): base(b), top(t), height(h), slices(sl), stacks(st){
}

float Cylinder::getBase(){
	return base;
}
float Cylinder::getTop(){
	return top;
}
float Cylinder::getHeight(){
	return height;
}
int Cylinder::getSlices(){
	return slices;
}
int Cylinder::getStacks(){
	return stacks;
}

Cylinder::~Cylinder(){
}

Sphere::Sphere(float r, int sl, int st): radius(r), slices(sl), stacks(st){
}

float Sphere::getRadius(){
	return radius;
}
int Sphere::getSlices(){
	return slices;
}
int Sphere::getStacks(){
	return stacks;
}

Sphere::~Sphere(){
}

Torus::Torus(float i, float o, int sl, int l): inner(i), outter(o), slices(sl), loops(l){
}

float Torus::getInner(){
	return inner;
}
float Torus::getOutter(){
	return outter;
}
int Torus::getSlices(){
	return slices;
}
int Torus::getLoops(){
	return loops;
}
Torus::~Torus(){
}