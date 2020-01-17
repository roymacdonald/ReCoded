#include "ofApp.h"
#ifdef DRAW_TWO_SCREENS
#include "GLFW/glfw3.h"
#endif



//--------------------------------------------------------------
void ofApp::setup(){
	SM.setup();
	IM.setup();

	#ifdef DRAW_TWO_SCREENS
		setScreenRects();
		ofSetFullscreen(true);
		ofHideCursor();
	#else
		//ofSetWindowPosition(2000, 0);
		ofSetFullscreen(true);
	#endif

	//ofHideCursor();

	//-------------------------------------------
	IM.setLEDs(1,1,1,1);


}
//--------------------------------------------------------------
void ofApp::update(){
	SM.update();
	IM.update();


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(10);
	


	// cout << "------------------ " << SM.pctDelay << endl;
#ifdef DRAW_TWO_SCREENS
	ofSetColor(255);
	if(numScreens  > 1){
		SM.draw(codeRect, sceneRect, true);
	}else{
		ofDrawBitmapStringHighlight("Can not draw as it seems to be less than 2 screens", 30,30);
	}
	SM.drawGui();
	
	
#else
	ofPushMatrix();
#ifdef DRAW_TWO_UP
#ifndef BIG_TV
    
    ofPushMatrix();
    ofTranslate(0,(1080-960));
    ofScale(960.0/720.0, 960.0/720.0);
	SM.draw();
    ofPopMatrix();
    
#endif
#ifndef BIG_TV
	
    
    ofPushMatrix();
    ofTranslate(960,(1080-960));
    ofScale(960.0/720.0, 960.0/720.0);
    SM.codeFbo.draw(0,0);
//    ofLine(0,0,720, 720);
//    ofLine(0,720,0, 720);
    
    ofPopMatrix();
    
    //ofPushMatrix();
	
    //ofTranslate(720,0);
	//SM.codeFbo.draw(0, 0, 720,720);
	//ofPopMatrix();
     SM.drawGui();
#endif
    
#ifdef BIG_TV

    ofPushMatrix();
        float h = 504 * 1920.0/(float)(504+504);
        ofTranslate(0,(1080-h)*0.5);
        ofScale(1920.0/(float)(504+504), 1920.0/(float)(504+504));
        SM.draw();
    
    
    ofPopMatrix();

    ofPushMatrix();

    ofTranslate(h, (1080-h)*0.5);
    SM.codeFbo.draw(0, 0, 504*2, 504*2);
        //SM.drawType();
    ofPopMatrix();
    
     SM.drawGui();
#endif
#elif defined DRAW_ONE_BIG
	float scale = 1080.0/(float)(504);
	float w = scale * 504;
	ofTranslate((1920-w)*0.5, 0);
	ofScale(scale, scale);
	SM.draw();
       SM.drawGui();
#else
	SM.draw();
	SM.drawGui();
#endif
	ofPopMatrix();
#endif
    

		if (SM.pctDelay < SCENE_PRE_TRANSITION_FADE || SM.isTransitioning) {
			IM.turnOffLEDs();
		}
//		if (SM.pctDelay < FADE_DELAY_MIN) {
			// typing is happening...
			//SM.codeFbo.draw(0, 0, 520,520);
//		}
		if (SM.shouldDrawScene && !SM.isTransitioning) {
			int numParams = MIN(SM.scenes[SM.currentScene]->midiKnobs.size(),4);
	//        cout << "Number of parameters: " << numParams << endl;
			IM.setCurrentSceneParameterCount(numParams);
		}
		
	
    if (SM.bDrawGui){
		stringstream ss;
		ss << "interaction mode " << (IM.bInteracting == true ? "interacting" : "playback") << endl;
        for (int i = 0; i < 4; i++){
            ss <<  "knob value " << i << " = " << IM.prevPacket.knobValues[i] * 100 << endl << endl;
        }
		ss << endl;
		ss << "bUpdateParamFromRecording: " << (string)(SM.scenes[SM.currentScene]->bUpdateParamFromRecording?"TRUE":"FALSE") << endl;
		ss << "bToggleUseRecording: " << (string)(bToggleUseRecording?"TRUE":"FALSE") << endl;
		
		ss << "scene has rec data:  " << (string)(SM.scenes[SM.currentScene]->hasRecData()?"TRUE":"FALSE") << endl;
		ss << "scene rec data size: " << SM.scenes[SM.currentScene]->recData.size() << endl;
		
		ss << "Max Activation Per Line : " << SM.maxActivationPerLine << endl;
		ss << "Max Total Activation : " << SM.maxTotalActivation << endl;
		
		
		// For MIDI
		ss << "paramChangedEnergy:"<<endl;
		for(auto& p:SM.TM.paramChangedEnergy){
			ss << "    " << p <<endl;
		}
		ss << "paramEnergyTarget:"<<endl;
		for(auto& p:SM.TM.paramEnergyTarget){
			ss << "    " << p <<endl;
		}
		
		ss << "paramEnergy:"<<endl;
		for(auto& p:SM.TM.paramEnergy){
			ss << "    " << p <<endl;
		}
		
		ss << "Elapsed time: " << SM.scenes[SM.currentScene]->getElapsedTimef() << endl;
		
		ss << "codeRect " << codeRect <<endl;
		ss << "sceneRect " << sceneRect <<endl <<endl;
		
		ss << "Screen Rects: " << endl;
		for(auto& s: screenRects){
			ss << "   " << s << endl;
		}
		auto p = SM.gui.getShape().getTopRight() + glm::vec3(40,0,0);
		ofDrawBitmapStringHighlight(ss.str(), p);
		ofBitmapFont bf;
		auto bb = bf.getBoundingBox(ss.str(), p.x, p.y);
		auto bl = bb.getBottomLeft();
		SM.sync.drawDebug( bl.x, bl.y + 40);
    }
	
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == OF_KEY_RIGHT) {
		SM.advanceScene(true);
	} else if (key == OF_KEY_LEFT) {
		SM.regressScene();
	}
	if(key == 'g'){
		SM.bDrawGui ^= true;
	}
	
	if (key == 'f') {
		ofToggleFullscreen();
	}

	if (key == 's') {
		SM.screenGrab();
	}

	if (key == 'h') {
		ofHideCursor();
        SM.bDrawGui = false;
        
	}
	if (key == 'H') {
		ofShowCursor();
        SM.bDrawGui = true;
    }
	#ifdef TEST_SCENES
	if (key == 'B') {
		SM.blacklistCurrentScene();
	}
	#endif



	if (key == 'i') {
		bToggleUseRecording = !bToggleUseRecording;
		for (int i = 0; i < SM.scenes.size(); i++) {
			SM.scenes[i]->bUpdateParamFromRecording = bToggleUseRecording;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
#ifdef DRAW_TWO_SCREENS
	setScreenRects();
#endif
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

bool sortRects(const ofRectangle& a, const ofRectangle& b ){
	return a.x < b.x;
}

#ifdef DRAW_TWO_SCREENS
//--------------------------------------------------------------
void ofApp::setScreenRects(){
	numScreens = 0;
	auto monitors = glfwGetMonitors(&numScreens);
	screenRects.resize(numScreens);
	for(int i = 0; i < numScreens; i++){
		int x = 0, y = 0;
		glfwGetMonitorPos(monitors[i],&x,&y);
		auto mode = glfwGetVideoMode(monitors[i]);
		screenRects[i].set(x, y, mode->width, mode->height);
	}
	ofSort(screenRects, sortRects);
	
	if(numScreens > 1){
		sceneRect.set(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
		codeRect.set(0,0,CODE_WIDTH, CODE_HEIGHT);
		
		sceneRect.scaleTo(screenRects[0]);
		codeRect.scaleTo(screenRects[1]);
	}
}
#endif
