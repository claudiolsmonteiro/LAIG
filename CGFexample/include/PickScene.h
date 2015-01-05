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
	int surroundingScene;
	int gamediff;
	int gametype;
	Game* game;
	void drawScene();
	void changeScene(int scene);
	void changediff(int gamediff);
	void changetype(int gametype);
	void gameUndo();
	~PickScene();
private:
	ANFParser *parser;
	CGFlight* light0;
	vector<CGFlight *> sceneLights;
	vector<char*> lightnames;
	vector<int>enabledlights;
	map<string, CGFtexture*> sceneTextures;
	map<string, float> texturesSLength;
	map<string, float> texturesTLength;
	map<string, CGFappearance*> sceneAppearances;
	CGFappearance rootAppearance;
	CGFobject* obj;
	CGFappearance* materialAppearance;
	CGFappearance* piecesAppearance1;
	CGFappearance* piecesAppearance2;
	CGFappearance* textureAppearance;
};

#endif