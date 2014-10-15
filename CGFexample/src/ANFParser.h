#ifndef _ANFParser_H_
#define _ANFParser_H_

#include "tinyxml.h"
#include "CGFapplication.h"
#include "myLight.h"
#include "myTexture.h"
#include "SceneGraph.h"
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
	std::map<char*,CGFcamera> getCameras();
	std::map<char*,CGFtexture> getTextures();
	std::map<char*,CGFappearance> getAppearances();
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

    char *drawing_mode,*drawing_shading,*culling_order,*culling_face,*initial_camera;
    float global_background[4],global_ambient[4];
    bool doublesided,local,enabled;
    unsigned int lightid;

    vector<myLight> lights;
    std::map<char*,CGFcamera>cameras;
    std::map<char*,CGFtexture>textures;
    std::map<char*,CGFappearance>appearances;

	SceneGraph graph;
    
};

#endif