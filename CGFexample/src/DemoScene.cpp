#include "primitives.h"
#include "DemoScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include "ExampleObject.h"

#include <math.h>

#include "CGFappearance.h"





void DemoScene::processNode(string nodeid, string inh){
    
    unsigned int i;

    bool existe;

    
    for(i = 0; i < parser->getGraph().getNodes().size(); i++){
        if(parser->getGraph().getNodes()[i].getName() == nodeid){
            existe = true;
            break;
        }
        existe = false;
    }
    
    if(!existe){
        return;
    }
    
    if(parser->getGraph().getNodes()[i].isDisplayList())
        glCallList(nodeDls[i]);
    else {
        Draw(parser->getGraph().getNodes()[i],inh);
    }
}
void DemoScene::Draw(Node n,string inh) {
    myTexture mt = myTexture();
    string in = inh;
    
	int i;
	for(i = 0; i < parser->getGraph().getNodes().size(); i++){
        if(parser->getGraph().getNodes()[i].getName() == n.getName()){
            break;
        }
    }

    if(n.isDisplayList())
		glCallList(nodeDls[i]);
    else {
		glPushMatrix();

		if(n.getAppearance() != "inherit"){
			sceneAppearances[n.getAppearance()].apply();
			in = n.getAppearance();
		}
		else{
			sceneAppearances[inh].apply();
		}
		for(int l = 0; l < n.getTransforms().size(); l++) {
        
			float m[16];
			m[0] =  n.getTransforms()[l][0];
			m[4] =  n.getTransforms()[l][1];
			m[8] =  n.getTransforms()[l][2];
			m[12] =  n.getTransforms()[l][3];
			m[1] = n.getTransforms()[l][4];
			m[5] = n.getTransforms()[l][5];
			m[9] = n.getTransforms()[l][6];
			m[13] = n.getTransforms()[l][7];
			m[2] = n.getTransforms()[l][8];
			m[6] = n.getTransforms()[l][9];
			m[10] = n.getTransforms()[l][10];
			m[14] = n.getTransforms()[l][11];
			m[3] = n.getTransforms()[l][12];
			m[7] = n.getTransforms()[l][13];
			m[11] = n.getTransforms()[l][14];
			m[15] = n.getTransforms()[l][15];
        
			glMultMatrixf(m);
		}
    
		for(unsigned int j = 0; j < n.getPrimitives().size(); j++){
			n.getPrimitives()[j].draw(mt.getSLenght(), mt.getTLenght());
		}
		Node no;
		for(unsigned int y = 0; y < n.getDescendants().size(); y++){
			for(int h = 0; h < parser->getGraph().getNodes().size(); h++){
				if(parser->getGraph().getNodes()[h].getName() == n.getDescendants()[y]){
					no = parser->getGraph().getNodes()[h];
					Draw(no, in);
				}
			}
			//processNode(n.getDescendants()[y], in);
		}
		glPopMatrix();
	}
    
}

void DemoScene::DrawDL(Node n,string inh) {
    myTexture mt = myTexture();
    string in = inh;

		glPushMatrix();
		if(n.getAppearance() != "inherit"){
			sceneAppearances[n.getAppearance()].apply();
			in = n.getAppearance();
		}
		else{
			sceneAppearances[inh].apply();
		}
		for(int l = 0; l < n.getTransforms().size(); l++) {
        
			float m[16];
			m[0] =  n.getTransforms()[l][0];
			m[4] =  n.getTransforms()[l][1];
			m[8] =  n.getTransforms()[l][2];
			m[12] =  n.getTransforms()[l][3];
			m[1] = n.getTransforms()[l][4];
			m[5] = n.getTransforms()[l][5];
			m[9] = n.getTransforms()[l][6];
			m[13] = n.getTransforms()[l][7];
			m[2] = n.getTransforms()[l][8];
			m[6] = n.getTransforms()[l][9];
			m[10] = n.getTransforms()[l][10];
			m[14] = n.getTransforms()[l][11];
			m[3] = n.getTransforms()[l][12];
			m[7] = n.getTransforms()[l][13];
			m[11] = n.getTransforms()[l][14];
			m[15] = n.getTransforms()[l][15];
        
			glMultMatrixf(m);
		}
    
		for(unsigned int j = 0; j < n.getPrimitives().size(); j++){
			n.getPrimitives()[j].draw(mt.getSLenght(), mt.getTLenght());
		}
		Node no;
		for(unsigned int y = 0; y < n.getDescendants().size(); y++){
			for(int h = 0; h < parser->getGraph().getNodes().size(); h++){
				if(parser->getGraph().getNodes()[h].getName() == n.getDescendants()[y]){
					no = parser->getGraph().getNodes()[h];
					Draw(no, in);
				}
			}
			//processNode(n.getDescendants()[y], in);
		}
		glPopMatrix();
}


void DemoScene::init()
{
    parser = new ANFParser("exemplo.anf");
    
    if(parser->getDrawingMode() == "fill") {
        drawMode = 0;
    }
    else if(parser->getDrawingMode() == "point") {
        drawMode = 1;
    }
    else if(parser->getDrawingMode() == "line") {
        drawMode = 2;
    }
    
    if(parser->getDrawingShading() == "gouraud")
        glShadeModel(GL_SMOOTH);
    else if(parser->getDrawingShading() == "flat")
        glShadeModel(GL_FLAT);
    
    float background_amb[4];
    for(int i = 0; i < 4;i++)
        background_amb[i]= parser->getGlobalBackgroung()[i];
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,background_amb);
    
    glEnable(GL_CULL_FACE);
    if(parser->getCullingFace() == "none")
        glDisable(GL_CULL_FACE);
    else if(parser->getCullingFace() == "front")
        glCullFace(GL_FRONT);
    else if(parser->getCullingFace() == "back")
        glCullFace(GL_BACK);
    else if(parser->getCullingFace() == "both")
        glCullFace(GL_FRONT_AND_BACK);
    
    if(parser->getCullingOrder() == "cw")
        glFrontFace(GL_CW);
    else if(parser->getCullingOrder() == "ccw")
        glFrontFace(GL_CCW);
    
    if(parser->getDoublesided())
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    else
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    
    if(parser->getLocal())
        glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    else
        glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_FALSE);
    
    if(parser->getEnabled())
        glEnable(GL_LIGHTING);
    else
        glDisable(GL_LIGHTING);
    
    for(unsigned int  i = 0; i < parser->getLights().size(); i++)
        printf("i: %x\n", parser->getLights()[i].getID());
    
    // Declares and enables lights
    float light_position[4];
    float amb[4], diff[4], spec[4];
    for(unsigned int  i = 0; i < parser->getLights().size(); i++){
        light_position[0] = parser->getLights()[i].getPosition()[0];
        light_position[1] = parser->getLights()[i].getPosition()[1];
        light_position[2] = parser->getLights()[i].getPosition()[2];
        light_position[3] = 1;
        
        amb[0] = parser->getLights()[i].getAmbient()[0];
        amb[1] = parser->getLights()[i].getAmbient()[1];
        amb[2] = parser->getLights()[i].getAmbient()[2];
        amb[3] = parser->getLights()[i].getAmbient()[3];
        
        diff[0] = parser->getLights()[i].getDiffuse()[0];
        diff[1] = parser->getLights()[i].getDiffuse()[1];
        diff[2] = parser->getLights()[i].getDiffuse()[2];
        diff[3] = parser->getLights()[i].getDiffuse()[3];
        
        spec[0] = parser->getLights()[i].getSpecular()[0];
        spec[1] = parser->getLights()[i].getSpecular()[1];
        spec[2] = parser->getLights()[i].getSpecular()[2];
        spec[3] = parser->getLights()[i].getSpecular()[3];
        
        CGFlight *newLight;
        
        if(parser->getLights()[i].getAngle() == -1){
            
            newLight = new CGFlight(parser->getLights()[i].getID(),light_position);
            newLight->setAmbient(amb);
            newLight->setDiffuse(diff);
            newLight->setSpecular(spec);
        }
        //its a spotlight
        else{
            float dir[3];
            
            dir[0] = parser->getLights()[i].getDirection()[0]-parser->getLights()[i].getPosition()[0];
            dir[1] = parser->getLights()[i].getDirection()[1]-parser->getLights()[i].getPosition()[1];
            dir[2] = parser->getLights()[i].getDirection()[2]-parser->getLights()[i].getPosition()[2];
            
            glLightf(parser->getLights()[i].getID(),GL_SPOT_EXPONENT,parser->getLights()[i].getExponent());
            glLightfv(parser->getLights()[i].getID(),GL_SPOT_DIRECTION,dir);
            
            newLight = new CGFlight(parser->getLights()[i].getID(),light_position);
            newLight->setAmbient(amb);
            newLight->setDiffuse(diff);
            newLight->setSpecular(spec);
            newLight->setAngle(parser->getLights()[i].getAngle());
        }
        
        if(parser->getLights()[i].isEnabled()) {
            enabledlights.push_back(0);
            newLight->enable();
        }
        else {
            newLight->disable();
            enabledlights.push_back(1);
        }
        
        
        lightnames.push_back(parser->getLights()[i].getName());
        sceneLights.push_back(newLight);
    }
    
    //declares textures
    for(unsigned int i = 0; i < parser->getTextures().size(); i++){
        
        CGFtexture *newTexture = new CGFtexture(parser->getTextures()[i].getFile());
        
        sceneTextures[parser->getTextures()[i].getName()] = newTexture;
    }
    
    //declares appearances
    for(unsigned int it = 0; it < parser->getAppearances().size(); it++){
        amb[0] = parser->getAppearances()[it].getAmbient()[0];
        amb[1] = parser->getAppearances()[it].getAmbient()[1];
        amb[2] = parser->getAppearances()[it].getAmbient()[2];
        amb[3] = parser->getAppearances()[it].getAmbient()[3];
        
        diff[0] = parser->getAppearances()[it].getDiffuse()[0];
        diff[1] = parser->getAppearances()[it].getDiffuse()[1];
        diff[2] = parser->getAppearances()[it].getDiffuse()[2];
        diff[3] = parser->getAppearances()[it].getDiffuse()[3];
        
        spec[0] = parser->getAppearances()[it].getSpecular()[0];
        spec[1] = parser->getAppearances()[it].getSpecular()[1];
        spec[2] = parser->getAppearances()[it].getSpecular()[2];
        spec[3] = parser->getAppearances()[it].getSpecular()[3];
        
        CGFappearance *newAppearance = new CGFappearance(amb, diff, spec, parser->getAppearances()[it].getShininess());
        
        if(parser->getAppearances()[it].getTexRef() != ""){
            newAppearance->setTexture(sceneTextures[parser->getAppearances()[it].getTexRef()]);
        }
        sceneAppearances[parser->getAppearances()[it].getName()] = *newAppearance;
    }

	CreateDisplayList(parser->getGraph().getRoot(),"");
    // Defines a default normal
    glNormal3f(0,0,1);
    
    obj=new ExampleObject();
    materialAppearance=new CGFappearance();
    textureAppearance=new CGFappearance("../data/pyramid.jpg",GL_REPEAT, GL_REPEAT);
    shader=new CGFshader("../data/texshader.vert","../data/texshader.frag");
    
    setUpdatePeriod(30);
}

void DemoScene::update(unsigned long t)
{
    shader->bind();
    shader->update(t/400.0);
    shader->unbind();
    
}

void DemoScene::display()
{
    if(drawMode == 0)
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    else if(drawMode == 1)
        glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
    else if(drawMode == 2)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // ---- BEGIN Background, camera and axis setup
    
    // Clear image and depth buffer everytime we update the scene
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    
    
    // Initialize Model-View matrix as identity (no transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //parser->getCameras()[0].applyView();
    // Apply transformations corresponding to the camera position relative to the origin
    CGFscene::activeCamera->applyView();
    
    
    
    CGFapplication::activeApp->forceRefresh();
    
    // Draw (and update) light
    for(unsigned int  i = 0; i < parser->getLights().size(); i++){
        if(parser->getLights()[i].isMarked())
            sceneLights[i]->draw();
    }
    
    // Draw axis
    axis.draw();
    
    
    // ---- END Background, camera and axis setup
    
    
    // ---- BEGIN feature demos
    
    // Simple object
    
    // textured object
    
    // shader object
    
    //graph
	Node root;
	int i;
	for(i = 0; i < parser->getGraph().getNodes().size(); i++){
		if(parser->getGraph().getRoot() == parser->getGraph().getNodes()[i].getName()){
			root = parser->getGraph().getNodes()[i];
            break;
        }
    }
    glPushMatrix();
    
    //processNode(parser->getGraph().getRoot(), "");
    //CreateDisplayList(parser->getGraph().getRoot(),"")
    Draw(root , "");
    glPopMatrix();
    
    
    
    // ---- END feature demos
    
    // We have been drawing in a memory area that is not visible - the back buffer,
    // while the graphics card is showing the contents of another buffer - the front buffer
    // glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
    glutSwapBuffers();
}

void DemoScene::toggleLights(int l, int s){
    if(s == 0) {
        parser->getLights()[l].enable(s);
        sceneLights[l]->disable();
        enabledlights[l]=1;
    }
    else if(s == 1){
        parser->getLights()[l].enable(s);
        sceneLights[l]->enable();
        enabledlights[l]=0;
    }
    sceneLights[l]->update();
}

void DemoScene::CreateDisplayList(string n,string a) {
	unsigned int i;
    for(i = 0; i < parser->getGraph().getNodes().size(); i++){
        if(parser->getGraph().getNodes()[i].getName() == n){
            break;
        }
    }

    for(unsigned int y = 0; y < parser->getGraph().getNodes()[i].getDescendants().size(); y++){
        CreateDisplayList(parser->getGraph().getNodes()[i].getDescendants()[y], parser->getGraph().getNodes()[i].getAppearance());
    }

	printf("chega aqui: %d\n", i);
    if(parser->getGraph().getNodes()[i].isDisplayList()) {
		unsigned int x = glGenLists(1);
		nodeDls[i] = x;
		printf("genLists value: %d\n", nodeDls[i]);
        glNewList(nodeDls[i], GL_COMPILE);
		DrawDL(parser->getGraph().getNodes()[i],a);
		glEndList();
    }
        
       


    //processNode(parser->getGraph().getNodes()[i].getName(), a);
    //draw

}




ANFParser DemoScene::getParser(){
    return *parser;
}

vector<CGFlight *> DemoScene::getSceneLights() {
    return sceneLights;
}
vector<char*> DemoScene::getLightnames() {
    return lightnames;
}

vector<int> DemoScene::getEnabledlights() {
    return enabledlights;
}

DemoScene::~DemoScene()
{
    delete(shader);
    delete(textureAppearance);
    delete(materialAppearance);
    delete(obj);
    delete(light0);
}
