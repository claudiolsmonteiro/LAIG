#include "DemoScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include "ExampleObject.h"

#include <math.h>

#include "CGFappearance.h"

#include "primitives.h"

void DemoScene::processNode(char *nodeid, int inh){
	glPushMatrix();
	unsigned int i,in=0;
	myTexture mt = myTexture();
	bool existe;

	for(i = 0; i < parser->getGraph().getNodes().size(); i++){
		if(strcmp(parser->getGraph().getNodes()[i].getName(), nodeid) == 0){
			existe = true;
			break;
		}
		existe = false;
	}

	if(!existe){
		//printf("Node %s nao encontrado!\n", nodeid);
		return;
	}

	if(strcmp(parser->getGraph().getNodes()[i].getAppearance(),"inherit") != 0){
		for(unsigned int j = 0; j < parser->getAppearances().size(); j++){
			if(strcmp(parser->getAppearances()[j].getName(),parser->getGraph().getNodes()[i].getAppearance()) == 0){
				sceneAppearances[j].apply();
				in = j;
				if(strcmp(parser->getAppearances()[j].getTexRef(),"") != 0){
					for(unsigned int t = 0; t < parser->getTextures().size(); t++){
						if(strcmp(parser->getTextures()[t].getName(), parser->getAppearances()[j].getTexRef()) == 0){
							mt = parser->getTextures()[t];
							break;
						}
					}
				}
			}
		}
	}
	else {
		sceneAppearances[inh].apply();
		for(unsigned int t = 0; t < parser->getTextures().size(); t++){
			if(strcmp(parser->getTextures()[t].getName(), parser->getAppearances()[inh].getTexRef()) == 0){
				mt = parser->getTextures()[t];
				break;
			}
		}
	}
	for(int l = 0; l < parser->getGraph().getNodes()[i].getTransforms().size(); l++) {
		/*if(parser->getGraph().getNodes()[i].getTransforms()[l][0]==0){
			glTranslatef(parser->getGraph().getNodes()[i].getTransforms()[l][1],parser->getGraph().getNodes()[i].getTransforms()[l][2],parser->getGraph().getNodes()[i].getTransforms()[l][3]);
		}
		else if(parser->getGraph().getNodes()[i].getTransforms()[l][0]==1) {
			if(parser->getGraph().getNodes()[i].getTransforms()[l][2]==0)
				glRotatef(parser->getGraph().getNodes()[i].getTransforms()[l][1],1,0,0);
			else if(parser->getGraph().getNodes()[i].getTransforms()[l][2]==1)
				glRotatef(parser->getGraph().getNodes()[i].getTransforms()[l][1],0,1,0);
			else if(parser->getGraph().getNodes()[i].getTransforms()[l][2]==2)
				glRotatef(parser->getGraph().getNodes()[i].getTransforms()[l][1],0,0,1);
		}
		else if(parser->getGraph().getNodes()[i].getTransforms()[l][0]==2) {
			glScalef(parser->getGraph().getNodes()[i].getTransforms()[l][1],parser->getGraph().getNodes()[i].getTransforms()[l][2],parser->getGraph().getNodes()[i].getTransforms()[l][3]);
		}*/
		float m[16];
		m[0] =  parser->getGraph().getNodes()[i].getTransforms()[l][0];
		m[4] =  parser->getGraph().getNodes()[i].getTransforms()[l][1];
		m[8] =  parser->getGraph().getNodes()[i].getTransforms()[l][2];
		m[12] =  parser->getGraph().getNodes()[i].getTransforms()[l][3];
		m[1] = parser->getGraph().getNodes()[i].getTransforms()[l][4];
		m[5] = parser->getGraph().getNodes()[i].getTransforms()[l][5];
		m[9] = parser->getGraph().getNodes()[i].getTransforms()[l][6];
		m[13] = parser->getGraph().getNodes()[i].getTransforms()[l][7];
		m[2] = parser->getGraph().getNodes()[i].getTransforms()[l][8];
		m[6] = parser->getGraph().getNodes()[i].getTransforms()[l][9];
		m[10] = parser->getGraph().getNodes()[i].getTransforms()[l][10];
		m[14] = parser->getGraph().getNodes()[i].getTransforms()[l][11];
		m[3] = parser->getGraph().getNodes()[i].getTransforms()[l][12];
		m[7] = parser->getGraph().getNodes()[i].getTransforms()[l][13];
		m[11] = parser->getGraph().getNodes()[i].getTransforms()[l][14];
		m[15] = parser->getGraph().getNodes()[i].getTransforms()[l][15];

		glMultMatrixf(m); 
	}

	for(unsigned int j = 0; j < parser->getGraph().getNodes()[i].getPrimitives().size(); j++){

		if(parser->getGraph().getNodes()[i].getPrimitives()[j].getType() == "rectangle" ){

			Rectangle r = parser->getGraph().getNodes()[i].getPrimitives()[j].getRectangle();

			r.draw(mt.getSLenght(), mt.getTLenght());
		}
		else if(parser->getGraph().getNodes()[i].getPrimitives()[j].getType() == "triangle" ){

			Triangle t = parser->getGraph().getNodes()[i].getPrimitives()[j].getTriangle();

			t.draw(mt.getSLenght(), mt.getTLenght());
		}
		else if(parser->getGraph().getNodes()[i].getPrimitives()[j].getType() == "cylinder" ){

			Cylinder c = parser->getGraph().getNodes()[i].getPrimitives()[j].getCylinder();
			GLUquadric* quadric;
			if((quadric = gluNewQuadric())!=0){
				gluCylinder(quadric,c.getBase(),c.getTop(),c.getHeight(),c.getSlices(),c.getStacks());
				glPushMatrix();
				glRotatef(180.0,0,1,0);
				gluDisk (quadric, 0, c.getBase(), c.getSlices(), c.getStacks());
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0,0,c.getHeight());
				gluDisk (quadric, 0, c.getTop(), c.getSlices(), c.getStacks());
				glPopMatrix();
			}
		}
		else if(parser->getGraph().getNodes()[i].getPrimitives()[j].getType() == "sphere" ){

			Sphere s = parser->getGraph().getNodes()[i].getPrimitives()[j].getSphere();
			GLUquadric* quadric;
			if((quadric = gluNewQuadric())!=0){
				gluSphere(quadric,s.getRadius(),s.getSlices(),s.getStacks());
			}
		}
		else if(parser->getGraph().getNodes()[i].getPrimitives()[j].getType() == "torus" ) {
			Torus to = parser->getGraph().getNodes()[i].getPrimitives()[j].getTorus();

			to.DrawTorus();
		}
	}
	for(unsigned int y = 0; y < parser->getGraph().getNodes()[i].getDescendants().size(); y++){
		processNode(parser->getGraph().getNodes()[i].getDescendants()[y], in);
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

		sceneTextures.push_back(newTexture);
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
		if(parser->getAppearances()[it].getTexRef()!= NULL)
			if(strcmp(parser->getAppearances()[it].getTexRef(), "") != 0){
				for(unsigned int i  = 0; i < parser->getTextures().size(); i++){
					if(strcmp(parser->getTextures()[i].getName(),parser->getAppearances()[it].getTexRef()) == 0){
						newAppearance->setTexture(sceneTextures[i]);
					}
				}
			}
			sceneAppearances.push_back(*newAppearance);
	}



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
	glPushMatrix();

	processNode(parser->getGraph().getRoot(), 0);

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
