#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"
#include "math.h"
#include <vector>

#define PI acos(-1.0);

class ExampleObject: public CGFobject {
	public:
		void draw();
		void drawPiece();
};

#endif