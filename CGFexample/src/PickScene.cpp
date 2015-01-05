#include "PickScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include "ExampleObject.h"

#include <math.h>

#include "CGFappearance.h"

#define NUM_OBJS 7
#define NUM_ROWS 5
#define NUM_COLS 4


void PickScene::init() 
{
	parser = new ANFParser("cena.anf");
	surroundingScene = 0;
	if (parser->getDrawingMode() == "fill") {
		drawMode = 0;
	}
	else if (parser->getDrawingMode() == "point") {
		drawMode = 1;
	}
	else if (parser->getDrawingMode() == "line") {
		drawMode = 2;
	}

	if (parser->getDrawingShading() == "gouraud")
		glShadeModel(GL_SMOOTH);
	else if (parser->getDrawingShading() == "flat")
		glShadeModel(GL_FLAT);

	float background_amb[4];
	for (int i = 0; i < 4; i++)
		background_amb[i] = parser->getGlobalBackgroung()[i];

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, background_amb);

	glEnable(GL_CULL_FACE);
	if (parser->getCullingFace() == "none")
		glDisable(GL_CULL_FACE);
	else if (parser->getCullingFace() == "front")
		glCullFace(GL_FRONT);
	else if (parser->getCullingFace() == "back")
		glCullFace(GL_BACK);
	else if (parser->getCullingFace() == "both")
		glCullFace(GL_FRONT_AND_BACK);

	if (parser->getCullingOrder() == "cw")
		glFrontFace(GL_CW);
	else if (parser->getCullingOrder() == "ccw")
		glFrontFace(GL_CCW);

	if (parser->getDoublesided())
		glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	else
		glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	if (parser->getLocal())
		glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	else
		glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);

	if (parser->getEnabled())
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);

	for (unsigned int i = 0; i < parser->getLights().size(); i++)
		printf("i: %x\n", parser->getLights()[i].getID());

	// Declares and enables lights
	float light_position[4];
	float amb[4], diff[4], spec[4];
	for (unsigned int i = 0; i < parser->getLights().size(); i++){
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

		if (parser->getLights()[i].getAngle() == -1){

			newLight = new CGFlight(parser->getLights()[i].getID(), light_position);
			newLight->setAmbient(amb);
			newLight->setDiffuse(diff);
			newLight->setSpecular(spec);
		}
		//its a spotlight
		else{
			float dir[3];

			dir[0] = parser->getLights()[i].getDirection()[0] - parser->getLights()[i].getPosition()[0];
			dir[1] = parser->getLights()[i].getDirection()[1] - parser->getLights()[i].getPosition()[1];
			dir[2] = parser->getLights()[i].getDirection()[2] - parser->getLights()[i].getPosition()[2];

			glLightf(parser->getLights()[i].getID(), GL_SPOT_EXPONENT, parser->getLights()[i].getExponent());
			glLightfv(parser->getLights()[i].getID(), GL_SPOT_DIRECTION, dir);

			newLight = new CGFlight(parser->getLights()[i].getID(), light_position);
			newLight->setAmbient(amb);
			newLight->setDiffuse(diff);
			newLight->setSpecular(spec);
			newLight->setAngle(parser->getLights()[i].getAngle());
		}

		if (parser->getLights()[i].isEnabled()) {
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
	for (unsigned int i = 0; i < parser->getTextures().size(); i++){

		CGFtexture *newTexture = new CGFtexture(parser->getTextures()[i].getFile());

		sceneTextures[parser->getTextures()[i].getName()] = newTexture;
		texturesSLength[parser->getTextures()[i].getName()] = parser->getTextures()[i].getSLenght();
		texturesTLength[parser->getTextures()[i].getName()] = parser->getTextures()[i].getTLenght();
	}

	//declares appearances
	for (unsigned int it = 0; it < parser->getAppearances().size(); it++){
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

		if (parser->getAppearances()[it].getTexRef() != ""){
			newAppearance->setTexture(sceneTextures[parser->getAppearances()[it].getTexRef()]);
		}
		std::cout << parser->getAppearances()[it].getName() << std::endl;
		sceneAppearances[parser->getAppearances()[it].getName()] = newAppearance;
	}

	unsigned long updatePeriod = 50;
	setUpdatePeriod(updatePeriod);

	// Defines a default normal
	glNormal3f(0,0,1);

	obj = new BoardObject();

	materialAppearance=sceneAppearances["Tabuleiro"];

	piecesAppearance1=sceneAppearances["Peca1"];

	piecesAppearance2=sceneAppearances["Peca2"];

	game = new Game(obj,materialAppearance,piecesAppearance1,piecesAppearance2);
	game->fillBoard();
	
}

void PickScene::update(unsigned long t)
{
	game->updateAnims(t);
}
void PickScene::display() 
{
	glutReshapeWindow(700, 700);
	if (drawMode == 0)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else if (drawMode == 1)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	else if (drawMode == 2)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//parser->getCameras()[0].applyView();
	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	CGFapplication::activeApp->forceRefresh();

	// Draw (and update) light
	for (unsigned int i = 0; i < parser->getLights().size(); i++){
		if (parser->getLights()[i].isMarked())
			sceneLights[i]->draw();
	}

	// Draw axis
	//axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN feature demos
	
	//Desenhar o tabuleiro____________________________

	glPushName(-1);
	
	glPushMatrix();
	glRotated(-90,1,0,0);
	glTranslated(1,-13.8,0);
	game->drawBoard();
	game->drawPieces();
	glPopMatrix();
	glPopName();
	drawScene();
	//________________________________________________

	// ---- END feature demos

	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

void PickScene::drawScene(){
	std::map<std::string, Node*>::iterator it;
	for (it=parser->getGraph()->nodes.begin(); it!=parser->getGraph()->nodes.end(); ++it){
		if(it->first != parser->getGraph()->getRoot()){
			sceneAppearances[it->second->getAppearance()]->apply();
			glPushMatrix();
			glMultMatrixf(it->second->getTransform());

			it->second->getPrimitives()[0].draw(texturesSLength[it->second->getAppearance()],texturesTLength[it->second->getAppearance()]);
			glPopMatrix();
		}
	}
}

void PickScene::changeScene(int scene){
	printf("%d\n",scene);
	if(scene == 0)
		this->parser = new ANFParser("cena.anf");
	else if(scene == 1)
		this->parser = new ANFParser("cena2.anf");

	surroundingScene = scene;
}
void PickScene::changediff(int gamediff) {
	game->setDiff(gamediff);
}
void PickScene::changetype(int gametype) {
	game->setType(gametype);
}
void PickScene::gameUndo() {
	game->undo();
}
PickScene::~PickScene()
{
	delete(materialAppearance);
	delete(obj);
	delete(game);
	delete(light0);
}

