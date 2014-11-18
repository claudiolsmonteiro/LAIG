#ifndef _ANFParser_H_
#define _ANFParser_H_

#include "SceneGraph.h"
#include "tinyxml.h"
#include "CGFapplication.h"
#include "myLight.h"
#include "myTexture.h"
#include "myAppearance.h"
#include "Animation.h"
#include <map>

class ANFParser
{
public:
	ANFParser(char *filename);
	char *getDrawingMode();
	char *getDrawingShading();
	char *getCullingOrder();
	char *getCullingFace();
	char *getInitialCamera();
	float *getGlobalBackgroung();
	float *getGlobalAmbient();
	bool getDoublesided();
	bool getLocal();
	bool getEnabled();
	vector<myLight> getLights();
	vector<CGFcamera> getCameras();
	vector<myTexture> getTextures();
	vector<myAppearance> getAppearances();
	SceneGraph getGraph();

	~ANFParser();

	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);
	
protected:

	TiXmlDocument* doc;

	TiXmlElement* globalsElement; 
	TiXmlElement* camerasElement;
	TiXmlElement* lightsElement;
	TiXmlElement* texturesElement;
	TiXmlElement* appearancesElement;
	TiXmlElement* graphElement;
	TiXmlElement* animationElement;

    char *drawing_mode,*drawing_shading,*culling_order,*culling_face,*initial_camera;
    float global_background[4],global_ambient[4];
    bool doublesided,local,enabled;
    unsigned int lightid;

    vector<myLight> lights;
    vector<CGFcamera>cameras;
    vector<myTexture>textures;
    vector<myAppearance>appearances;
	map<string,Animation>animations;

	SceneGraph graph;
    
};

#endif