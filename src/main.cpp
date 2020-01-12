#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLFWWindowSettings settings;
	
	settings.setSize(1920, 1080);

	#ifdef DRAW_TWO_SCREENS
	settings.multiMonitorFullScreen = true;
	settings.windowMode = OF_FULLSCREEN;
	#endif

	ofCreateWindow(settings);
	
	
	ofRunApp(new ofApp());
}
