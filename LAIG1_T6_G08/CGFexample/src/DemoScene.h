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
	void processNode(char *nodeid, int inh);
	void toggleLights(int l, int s);
    vector<CGFlight *> getSceneLights();
    vector<char*> getLightnames();
    vector<int>getEnabledlights();
	void setDrawingMode(int draw);
    ANFParser getParser();
	int drawMode;
	~DemoScene();
private:
	ANFParser *parser;
	CGFlight* light0;
	vector<CGFlight *> sceneLights;
	vector<CGFtexture *> sceneTextures;
	vector<char*> lightnames;
    vector<int>enabledlights;
	vector<CGFappearance> sceneAppearances;
	CGFappearance rootAppearance;
	CGFobject* obj;
	CGFappearance* materialAppearance;
	CGFappearance* textureAppearance;
	CGFshader* shader;
};

#endif