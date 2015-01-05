#include "Animation.h"

Point::Point(){
}

Point::Point(float x, float y, float z): px(x), py(y), pz(z){
}

float Point::getX(){
	return px;
}

float Point::getY(){
	return py;
}

float Point::getZ(){
	return pz;
}


Animation::Animation() {
}
Animation::Animation(LinearAnimation la) {
	this->la = la;
	this->type = "linear";
}
Animation::Animation(CircularAnimation ca) {
	this->ca = ca;
	this->type = "circular";
}
void Animation::draw(){
	if(type.compare("linear") == 0)
		la.draw();
	else if(type.compare("circular") == 0)
		ca.draw();
}
void Animation::update(unsigned long t){
	if(type.compare("linear") == 0)
		la.update(t);
	else if(type.compare("circular") == 0)
		ca.update(t);
}

float getMovementDistance(std::vector<Point> controlpts){
	float dist = 0, dx, dy, dz;

	for(unsigned int i = 1; i < controlpts.size(); i++){
		dx = controlpts[i].getX()-controlpts[i-1].getX();
		dy = controlpts[i].getY()-controlpts[i-1].getY();
		dz = controlpts[i].getZ()-controlpts[i-1].getZ();
		dist+= sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));
	}
	printf("movement distance: %f\n",dist);
	return dist;
}

float calcDistance(Point p1, Point p2){
	float dist, dx, dy, dz;
	dx=p2.getX()-p1.getX();
	dy=p2.getY()-p1.getY();
	dz=p2.getZ()-p1.getZ();
	dist= sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));
	return dist;
}
LinearAnimation::LinearAnimation() {

}
LinearAnimation::LinearAnimation(int x,int y, int z) {
	posX=x;
	posY=y;
	posZ=z;
}
LinearAnimation::LinearAnimation(char *id, float span,std::vector<Point> controlpts) {
	std::string n(id);
	this->id = n;
	this->span = span;
	for(unsigned int i = 0; i < controlpts.size(); i++){
		this->controlpts.push_back(controlpts[i]);
	}
	radius_speed_ms= getMovementDistance(controlpts) /span/ 1000;
	obj_rotate = 0;
	posX = 0;
	posY = 0;
	posZ = 0;
	currentControlPoint = 1;
	translated = 0;
	currentDirX = 0;
	currentDirZ = 1;

}
void LinearAnimation::init(unsigned long t)
{
	oldTime = t;
	doReset=false;
	currentControlPoint = 1;
	posX = controlpts[0].getX();
	posY = controlpts[0].getY();
	posZ = controlpts[0].getZ();
	obj_rotate = 0;

}

void LinearAnimation::reset()
{
	doReset=true;
}


void LinearAnimation::update(unsigned long t)
{
	if(controlpts.size() == 0)
		return;
	if (doReset)
		init(t);
	else{
		unsigned long newTime = t-oldTime;
		oldTime = t;
		float speed = radius_speed_ms*newTime;

		float directionX = controlpts[currentControlPoint].getX()-controlpts[currentControlPoint-1].getX();
		float directionY = controlpts[currentControlPoint].getY()-controlpts[currentControlPoint-1].getY();
		float directionZ = controlpts[currentControlPoint].getZ()-controlpts[currentControlPoint-1].getZ();
		float dist = calcDistance(controlpts[currentControlPoint-1], controlpts[currentControlPoint]);

		directionX = (float)(directionX/dist);
		directionY = (float)(directionY/dist);
		directionZ = (float)(directionZ/dist);

		//rotate
		float scaleProd = directionX * currentDirX + directionZ * currentDirZ;
		float denom = sqrt(pow(directionX, 2)+pow(directionZ,2)) * sqrt(pow(currentDirX, 2)+pow(currentDirZ,2));
		float ang = acos(scaleProd/denom)*180/3.1416;
		obj_rotate += ang;
		currentDirX = directionX;
		currentDirZ = directionZ;
		//translate
		posX+=directionX*speed;
		posY+=directionY*speed;
		posZ+=directionZ*speed;

		translated += speed;
		if(translated >= dist){
			translated-=dist;
			posX = controlpts[currentControlPoint].getX();
			posY = controlpts[currentControlPoint].getY();
			posZ = controlpts[currentControlPoint].getZ();
			currentControlPoint = (currentControlPoint + 1) % controlpts.size();
			if(currentControlPoint == 0)
				controlpts.clear();
		}
	}
}

void LinearAnimation::draw()
{
	glTranslated(posX, posY, posZ);
	//glRotated(obj_rotate, 0,1,0);
}
float LinearAnimation::getPosX() {
	return posX;
}

float LinearAnimation::getPosY() {
	return posY;
}

float LinearAnimation::getPosZ() {
	return posZ;
}


CircularAnimation::CircularAnimation(){
}
CircularAnimation::CircularAnimation(char *id, float span, Point center, float radius, float startAng, float rotAng)
{
	std::string n(id);
	this->id = n;
	this->span = span;
	this->center = center;

	this->radius = radius;
	this->startAng = startAng;
	this->rotAng = rotAng;
	this->angularSpeed = radius * rotAng/1000.0/span;
	this->currentRotate = startAng;
}

void CircularAnimation::init(unsigned long t)
{
	oldTime = t;
	doReset=false;
	this->currentRotate = this->startAng;
}

void CircularAnimation::reset()
{
	doReset=true;
}

void CircularAnimation::update(unsigned long t)
{
	if(doReset)
	{
		init(t);
	}
	else
	{
			float newTime = t - oldTime;
			oldTime = t;
			float speed = angularSpeed * newTime;
			currentRotate += speed;
	}
}

void CircularAnimation::draw()
{
	glTranslatef(center.getX(), center.getY(), center.getZ());
	glRotatef(currentRotate, 0, 1, 0);
	glTranslatef(radius, 0, 0);
}

