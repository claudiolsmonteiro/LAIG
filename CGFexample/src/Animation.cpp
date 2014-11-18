#include "Animation.h"

Animation::Animation() {
}
Animation::Animation(LinearAnimation la) {
	this->la = la;
	this->type = "linear";
}

LinearAnimation::LinearAnimation() {
}
LinearAnimation::LinearAnimation(char *id, float span,std::vector<Point> controlpts) {
	string n(id);
	this->id = n;
	this->span = span;
	this->controlpts = controlpts;
}
void LinearAnimation::init(unsigned long t)
{
	startTime=t;
	doReset=false;
}

void LinearAnimation::reset()
{
	doReset=true;
}


void LinearAnimation::update(unsigned long t)
{
	if (doReset)
		init(t);
	else
	{
		unsigned long animT=t-startTime;
		//obj_rotate= START_ANGLE + animT* rotate_speed_ms;
		//obj_radius= START_RADIUS + animT* radius_speed_ms;
	}
}

void LinearAnimation::draw()
{

}