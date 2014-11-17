#ifndef _ANFScene_H_
#define _ANFScene_H_

#include "CGFscene.h"
#include "CGFshader.h"
#include "ANFParser.h"

class ANFScene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long t);
	void setParser(ANFParser p);
	~ANFScene();
private:
	ANFParser parser;
};

#endif
