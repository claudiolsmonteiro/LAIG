#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "CGFscene.h"
//#include "CGFshader.h"
#include "ANFParser.h"
class DemoScene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long t);
	void processNode(string nodeid, string inh);
	void toggleLights(int l, int s);
    vector<CGFlight *> getSceneLights();
    vector<char*> getLightnames();
    vector<int>getEnabledlights();
	void setDrawingMode(int draw);
    ANFParser getParser();
    void CreateDisplayList(string n,string a);
    void Draw(Node n,string inh);
	void DrawDL(Node n,string inh);
	int drawMode;
	~DemoScene();
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
	CGFappearance* textureAppearance;
	CGFshader* shader;
	map<int, int> nodeDls; 
};

#endif