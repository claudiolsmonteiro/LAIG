#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "primitives.h"
#include <vector>
#include <string.h>


class LinearAnimation {
public:
	LinearAnimation();
	LinearAnimation(char *id, float span, std::vector<Point> controlpts);
	void reset();
	void update(unsigned long t);
	void draw();

private:
	string id;
	float span;
	std::vector<Point> controlpts;
	void init(unsigned long t);
	unsigned long startTime;
	unsigned char doReset;
};




class Animation {
public:
Animation();
Animation(LinearAnimation la);


private:
	LinearAnimation la;
	//CircularAnimation ca;
	string type;


};
#endif

