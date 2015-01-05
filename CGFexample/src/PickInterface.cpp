#include "PickInterface.h"
#include "PickScene.h"
#include "CGFapplication.h"

// buffer to be used to store the hits during picking
#define BUFSIZE 256
GLuint selectBuf[BUFSIZE];

void PickInterface::processMouse(int button, int state, int x, int y) 
{
	CGFinterface::processMouse(button,state, x, y);

	// do picking on mouse press (GLUT_DOWN)
	// this could be more elaborate, e.g. only performing picking when there is a click (DOWN followed by UP) on the same place
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		performPicking(x,y);
}

void PickInterface::performPicking(int x, int y) 
{
	// Sets the buffer to be used for selection and activate selection mode
	glSelectBuffer (BUFSIZE, selectBuf);
	glRenderMode(GL_SELECT);

	// Initialize the picking name stack
	glInitNames();

	// The process of picking manipulates the projection matrix
	// so we will be activating, saving and manipulating it
	glMatrixMode(GL_PROJECTION);

	//store current projmatrix to restore easily in the end with a pop
	glPushMatrix ();

	//get the actual projection matrix values on an array of our own to multiply with pick matrix later
	GLfloat projmat[16];
	glGetFloatv(GL_PROJECTION_MATRIX,projmat);

	// reset projection matrix
	glLoadIdentity();

	// get current viewport and use it as reference for 
	// setting a small picking window of 5x5 pixels around mouse coordinates for picking
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	// this is multiplied in the projection matrix
	gluPickMatrix ((GLdouble) x, (GLdouble) (CGFapplication::height - y), 5.0, 5.0, viewport);

	// multiply the projection matrix stored in our array to ensure same conditions as in normal render
	glMultMatrixf(projmat);

	// force scene drawing under this mode
	// only the names of objects that fall in the 5x5 window will actually be stored in the buffer
	scene->display();

	// restore original projection matrix
	glMatrixMode (GL_PROJECTION);
	glPopMatrix ();

	glFlush();

	// revert to render mode, get the picking results and process them
	GLint hits;
	hits = glRenderMode(GL_RENDER);
	processHits(hits, selectBuf);
}

void PickInterface::processHits (GLint hits, GLuint buffer[]) 
{
	GLuint *ptr = buffer;
	GLuint mindepth = 0xFFFFFFFF;
	GLuint *selected=NULL;
	GLuint nselected;

	// iterate over the list of hits, and choosing the one closer to the viewer (lower depth)
	for (int i=0;i<hits;i++) {
		int num = *ptr; ptr++;
		GLuint z1 = *ptr; ptr++;
		ptr++;
		if (z1 < mindepth && num>0) {
			mindepth = z1;
			selected = ptr;
			nselected=num;
		}
		for (int j=0; j < num; j++) 
			ptr++;
	}
	
	// if there were hits, the one selected is in "selected", and it consist of nselected "names" (integer ID's)
	if (selected!=NULL)
	{
		// this should be replaced by code handling the picked object's ID's (stored in "selected"), 
		// possibly invoking a method on the scene class and passing "selected" and "nselected"
		/*printf("Picked ID's: ");
		for (int i=0; i<nselected; i++)
			printf("%d ",selected[i]);
		printf("\n");*/
		if(((PickScene*) scene)->game->currentplayer == PLAYER1 || ((PickScene*) scene)->game->currentplayer == PLAYER2)
			((PickScene*) scene)->game->selectPiece(selected[0],selected[1]);
		else if(((PickScene*) scene)->game->currentplayer == COMP1 || ((PickScene*) scene)->game->currentplayer == COMP2)
			((PickScene*) scene)->game->computerPlay();
	}
	else
		printf("Nothing selected while picking \n");	
}


void PickInterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available    

	GLUI_Panel *DrawPanel = addPanel("Draw Mode", 1);
	GLUI_RadioGroup *drawtype = addRadioGroupToPanel(DrawPanel,&(((PickScene*) scene)->drawMode),3);
	addRadioButtonToGroup(drawtype, "Fill");
	addRadioButtonToGroup(drawtype, "Point");
	addRadioButtonToGroup(drawtype, "Wireframe");
	
	addColumn();

	GLUI_Panel *Difficulty = addPanel("Difficulty", 1);
	GLUI_RadioGroup *difftype = addRadioGroupToPanel(Difficulty,&(((PickScene*) scene)->gamediff),1);
	addRadioButtonToGroup(difftype, "Easy");
	addRadioButtonToGroup(difftype, "Medium");
	/*for(int i = 0; i < ((DemoScene*) scene)->getParser().getCameras().size(); i++) {
		addCheckboxToPanel(lightPanel, ((DemoScene*) scene)->getParser().getCameras()[i]., NULL, i)
    }*/

	addColumn();

	GLUI_Panel *GameType = addPanel("GameType", 1);
	GLUI_RadioGroup *gtype = addRadioGroupToPanel(GameType,&(((PickScene*) scene)->gametype),4);
	addRadioButtonToGroup(gtype, "H/H");
	addRadioButtonToGroup(gtype, "H/M");
	addRadioButtonToGroup(gtype, "M/M");

	addColumn();

	GLUI_Panel *Undo = addPanel("Undo", 5);
	addButtonToPanel(Undo,"Undo",5);



	addColumn();
	GLUI_Panel *ScenePanel = addPanel("Scene", 0);
	GLUI_RadioGroup *surrounding = addRadioGroupToPanel(ScenePanel,&(((PickScene*) scene)->surroundingScene),2);
	addRadioButtonToGroup(surrounding, "Cena1");
	addRadioButtonToGroup(surrounding, "Cena2");


}

void PickInterface::processGUI(GLUI_Control *ctrl)
{
	if(ctrl->user_id == 3)
		((PickScene*) scene)->drawMode = ctrl->get_int_val();
	else if(ctrl->user_id == 2)
		((PickScene*) scene)->changeScene(ctrl->get_int_val());
	else if(ctrl->user_id == 1) 
		((PickScene*) scene)->changediff(ctrl->get_int_val());
	else if(ctrl->user_id == 4) 
		((PickScene*) scene)->changetype(ctrl->get_int_val());
	else if(ctrl->user_id == 5) 
		((PickScene*) scene)->gameUndo();
}