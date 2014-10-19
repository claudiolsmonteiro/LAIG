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
    void toggleLights(int l, int s);
    vector<CGFlight *> getSceneLights();
    vector<char*> getLightnames();
    vector<int>getEnabledlights();
    ANFParser getParser();
	~DemoScene();
    
    int lig0;
    int lig1;
    int lig2;
    int lig3;
    int windowLig;
    int robotTexture;
    int viewMode;
private:
    

    
	ANFParser *parser;
	CGFlight* light0;
    vector<char*> lightnames;
	vector<CGFlight *> sceneLights;
    vector<int>enabledlights;
	CGFobject* obj;
	CGFappearance* materialAppearance;
	CGFappearance* textureAppearance;
	CGFshader* shader;
};

#endif