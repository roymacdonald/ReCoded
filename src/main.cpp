#include "ofMain.h"
#include "ofApp.h"
#include "ofxWatchdog.h"

//========================================================================
int main( ){

	ofxWatchdog::boot(3000, true, true, true);
	
	ofGLFWWindowSettings settings;
	
	settings.setSize(1920, 1080);

	#ifdef DRAW_TWO_SCREENS
	settings.multiMonitorFullScreen = true;
	settings.windowMode = OF_FULLSCREEN;
	#endif
	
	ofCreateWindow(settings);
	
	ofxWatchdog::trap();
	
	ofRunApp(new ofApp());
}
