#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "CGFscene.h"
#include "CGFshader.h"
#include "ANFParser.h"
class DemoScene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long t);
	void processNode(char *nodeid);
	~DemoScene();
private:
	ANFParser *parser;
	CGFlight* light0;
	vector<CGFlight *> sceneLights;
	CGFobject* obj;
	CGFappearance* materialAppearance;
	CGFappearance* textureAppearance;
	CGFshader* shader;
};

#endif