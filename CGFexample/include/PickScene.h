#ifndef PICKSCENE_H
#define PICKSCENE_H


#include "ANFParser.h"
#include "PickInterface.h"
#include "Game.h"

class PickScene : public CGFscene
{
	friend PickInterface;
public:
	void init();
	void display();
	void update(unsigned long t);
	void toggleLights(int l, int s);
	vector<CGFlight *> getSceneLights();
	vector<char*> getLightnames();
	vector<int>getEnabledlights();
	void setDrawingMode(int draw);
	ANFParser getParser();
	int drawMode;
	Game* game;
	~PickScene();
private:
	ANFParser *parser;
	CGFlight* light0;
	vector<CGFlight *> sceneLights;
	map<string, CGFtexture *> sceneTextures;
	vector<char*> lightnames;
	vector<int>enabledlights;
	map<string, CGFappearance> sceneAppearances;
	CGFappearance rootAppearance;
	CGFobject* obj;
	CGFappearance* materialAppearance;
	CGFappearance* piecesAppearance1;
	CGFappearance* piecesAppearance2;
	CGFappearance* textureAppearance;
};

#endif