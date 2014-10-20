#include "TPinterface.h"
#include "DemoScene.h"
#include <iostream>

TPinterface::TPinterface()
{

}

void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
    // Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
    // CGFinterface::processKeyboard(key, x, y);
    
    
}



void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *lightPanel= addPanel("Lights", 1);
    for(int i = 0; i < ((DemoScene*) scene)->getSceneLights().size(); i++) {
		if(((DemoScene*) scene)->getEnabledlights()[i]==0)
			addCheckboxToPanel(lightPanel, ((DemoScene*) scene)->getLightnames()[i], NULL, i)->set_int_val(1);
		else{
			addCheckboxToPanel(lightPanel, ((DemoScene*) scene)->getLightnames()[i], NULL, i)->set_int_val(0);
		}
    }
	addColumn();
    

	GLUI_Panel *DrawPanel = addPanel("Draw Mode", 1);
	GLUI_RadioGroup *drawtype = addRadioGroupToPanel(DrawPanel,&(((DemoScene*) scene)->drawMode),((DemoScene*) scene)->getSceneLights().size());
	addRadioButtonToGroup(drawtype, "Fill");
	addRadioButtonToGroup(drawtype, "Point");
	addRadioButtonToGroup(drawtype, "Wireframe");
	
	addColumn();

	GLUI_Panel *CameraPanel = addPanel("Cameras", 1);
	/*for(int i = 0; i < ((DemoScene*) scene)->getParser().getCameras().size(); i++) {
		addCheckboxToPanel(lightPanel, ((DemoScene*) scene)->getParser().getCameras()[i]., NULL, i)
    }*/
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
    if(ctrl->user_id < ((DemoScene*) scene)->getSceneLights().size()) {
        ((DemoScene*) scene)->toggleLights(ctrl->user_id, (((DemoScene*) scene)->getEnabledlights()[ctrl->user_id]));
    }
	if(ctrl->user_id == ((DemoScene*) scene)->getSceneLights().size())
		((DemoScene*) scene)->drawMode = ctrl->get_int_val();
}

