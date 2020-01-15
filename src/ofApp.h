#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "sceneManager.h"
#include "appConstants.h"
#include "interactionManager.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        sceneManager SM;
        interactionManager IM;
    
        void fixScreenSize();
    
    
        bool bToggleUseRecording = true;
    
        ofPoint prevMouse;
    
#ifdef DRAW_TWO_SCREENS	
	void setScreenRects();
	int numScreens = 0;
	ofRectangle codeRect, sceneRect;
	vector<ofRectangle>screenRects;
#endif
	
#ifdef TEST_SCENES
	ofxPanel testGui;
	void loadTestGui();
	void saveTestGui(bool& );
	std::map<string, ofParameterGroup> parameters;
	ofEventListeners testListeners;
	
#endif
	
	
};
