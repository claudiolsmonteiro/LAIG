/* 
 * G0_Base: projeto inicial de CGra
 * 
 */

#include <iostream>
#include <exception>

#include "CGFapplication.h"
#include "ANFParser.h"
#include "ANFScene.h"
#include "DemoScene.h"
using std::cout;
using std::exception;


int main(int argc, char* argv[]) {

	CGFapplication app = CGFapplication();

	try {
		app.init(&argc, argv);


		//ANFScene *newScene;
		//newScene = new ANFScene();
		//newScene->setParser(*parser);

		app.setScene(new DemoScene());
		app.setInterface(new CGFinterface());
		
		app.run();
	}
	catch(GLexception& ex) {
		cout << "Error: " << ex.what();
		return -1;
	}
	catch(exception& ex) {
		cout << "Unexpected error: " << ex.what();
		return -1;
	}

	return 0;
}