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
        addCheckboxToPanel(lightPanel, ((DemoScene*) scene)->getLightnames()[i], &(((DemoScene*) scene)->getEnabledlights()[i]), i);
        printf("LIGHT NAME : %s, ENABLED LIGHTS: %d, I : %d\n\n\n\n",((DemoScene*) scene)->getLightnames()[i], (((DemoScene*) scene)->getEnabledlights()[i]), i);
    }
	addColumn();
    
    /*
    addStaticText("Cameras");
    GLUI_RadioGroup *CameraViewMode = addRadioGroup(&(((DemoScene*) scene)->viewMode), 7);

	addColumn();
	addStaticText("Drawing View mode");
	GLUI_RadioGroup *DrawingViewMode = addRadioGroup(&(((DemoScene*) scene)->viewMode), 7);
	addRadioButtonToGroup(DrawingViewMode, "Wireframe");
	addRadioButtonToGroup(DrawingViewMode, "Fill");
	
	// You could also pass a reference to a variable from the scene class, if public
	//addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((DemoScene*) scene)->sceneVar), 2);
*/
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
    if(ctrl->user_id < ((DemoScene*) scene)->getSceneLights().size()) {
        ((DemoScene*) scene)->toggleLights(ctrl->user_id, (((DemoScene*) scene)->getEnabledlights()[ctrl->user_id]));
        printf("ENABLED LIGHTS: %d, I : %d\n\n\n\n",(((DemoScene*) scene)->getEnabledlights()[ctrl->user_id]), ctrl->user_id);
    }
	
}

