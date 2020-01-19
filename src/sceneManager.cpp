//
//  sceneManager.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//


#include "sceneManager.h"
#include "baseScene.h"
#include "exampleScene.h"

/// MIT sketches

#include "mitScene1.h"
#include "aaronLillianSchwartz.h"
#include "aaronMurielCooper.h"
#include "aaronRosaMenkman.h"
#include "aaronVeraMolnar.h"
#include "ethanWhitneyScene.h"
#include "ethanMolnarScene.h"
#include "pbeshaiVideo1.h"
#include "pbeshaiMolnar1.h"
#include "pbeshaiSchwartz1.h"
#include "gauravVera.h"
#include "pbeshaiWhitney1.h"
#include "pbeshaiKnowlton1.h"
#include "lizVera.h"
#include "hannahVera.h"
#include "hannahMuriel.h"
#include "hannahSchwartz.h"
#include "hannahWhitney.h"
#include "mengfeiKen.h"
#include "mengfeiVera.h"
#include "mengfeiMuriel.h"
#include "mengfeiLillian.h"
#include "mengfeiWhitney.h"
#include "pbeshaiBurson1.h" // NOTE: requires facetracker data
#include "hannahMuriel2.h"
#include "lizVesulka.h"
#include "liangMuriel.h"
#include "liangVasulka.h"

#include "gauravMuriel.h"
#include "gauravMuriel2.h"
#include "gauravWhitney2.h"

#include "aliceWhitney.h"
#include "manaswiVeraMolnar.h"
#include "manaswiJohnWhitney.h"
#include "manaswiKenKnowlton.h"
#include "manaswiRosaMenkman.h"


#include "karstenVasulka.h"
#include "karstenJohnMaeda.h"
#include "karstenFaceMirror.h"
#include "karstenVeraMolnar.h"
#include "karstenKenKnowlton.h"
#include "karstenJohnWhitney.h"


/// SFPC sketches


#include "triangleScene.h"
#include "veraAnimatedScene.h"
#include "robbyMolnarScene.h"
#include "robbyRileyScene.h"
//#include "yeseulWhitneyScene.h"
#include "johnWhitneyShader01.h"
#include "johnWhitneyShader02.h"
#include "RoyWhitney1.h"
#include "veraFscene.h"
#include "anastasisRileyScene.h"
#include "loloWhitney.h"
#include "loloVera.h"
#include "andyMenkmanJpg.h"
#include "andyMenkmanPng.h"
#include "andyMenkmanTif.h"
#include "CooperBauhaus.h"
#include "memoAktenScene.h"
#include "submotionOrchestraScene.h"
#include "chrisMurielCooper.h"
#include "chrisRileyCascando.h"
#include "veraMolnarTrapezium.h"
#include "manfredMohrP196A.h"
#include "loloVera2.h"
#include "cantusFirmusRiley.h"
#include "chrisVeraInterruptions.h"
#include "aaronMarcusHieroglyphB.h"
#include "veraMolnarLines68.h"
//#include "Cooper3dText.h"
#include "alexLissamojiWhitney.h"
#include "janVantommeScene.h"
#include "rodrigoBelfort.h"
#include "rachelScene.h"
#include "RileyArcsRoy.h"
#include "robbyMenkmanScene.h"
#include "yosukeVeraSansTitre.h"
// #include "alexGifPaletteDitherMenkman.h"
#include "yeseulMenkmanInstitution.h"
#include "yeseulCooperMessages.h"
#include "yosukeJohnWhitneyMatrix.h"
#include "mgsCooperSymbols.h"
#include "mgsRileyDiamonds.h"
#include "mgsRileyEllipsesAndSquares.h"
#include "mgsRileyDescending.h"
//#include "mgsVeraMolnarLineStudy.h"
#include "mgsMaedaTimePainter.h"
#include "olegVeraV.h"
#include "sarahgpRileyCircle.h"
#include "mwalczykVeraSquares.h"
#include "yeseulRileyBrokencircle.h"
#include "zachTest.h"

#include "mattKnowlton.h"

#include "heatherMolnarScene.h"
#include "yingTanWhitneyMatrix.h"
#include "annMolnarRectangles.h"
#include "weiWhitney.h"
#include "yumiNishida01.h"

#include "niklasLissajous.h"
#include "niklasMolnar.h"
#include "niklasMorisawa.h"
#include "niklasWhitneySineWave.h"
#include "fernandoMuriel.h"
#include "fernandoWhitney.h"
#include "fernandoWhitney2.h"
#include "hyojinVeraMolnar.h"
#include "hyojinJohnWhitney.h"
#include "EstherKnowltonScene.h"
#include "jacobsonMolnar_01.h"
#include "jacobsonMolnar_02.h"
#include "jacobsonWhitney_01.h"
#include "aprilMenkman.h"
#include "runchalMolnar.h"
#include "weiMolnar_01.h"
#include "annCaseyWave.h"
#include "diegoScene_01.h"
#include "stacyButterflies.h"
#include "EstherMolnarScene.h"




//#include "testingScene.h"


//SCRIPT_PLACEHOLDER_INCLUDE -- DO NOT REMOVE THIS LINE. PLACE INCLUDES ABOVE.

float baseScene::smoothingSpeed = 0.02;

//-----------------------------------------------------------------------------------
sceneManager::~sceneManager(){
    ofRemoveListener(sync.ffwKeyPressed, this, &sceneManager::setAdvanceCurrentScene);
}
//-----------------------------------------------------------------------------------
void sceneManager::setup(){
    
    bDrawGui = false;
    
    font.load("fonts/ProggySmall.fon", 8, false ,false, false, 0, 96);
    
    
	{
        
#ifdef SHOW_MIT_2019
    //-------------------------------  alice
    scenes.push_back(new aliceWhitney()); // has recording
    //------------------------------- gaurav
    
    scenes.push_back(new gauravWhitney2()); // has recording
    scenes.push_back(new gauravMuriel2());  // has recording
    scenes.push_back(new gauravMuriel());   // has recording
    scenes.push_back(new gauravVera());     // has recording
    
    
    
    //------------------------------- mengfei
    

    scenes.push_back(new mengfeiKen());      // has recording
    scenes.push_back(new mengfeiLillian());  // has recording
    scenes.push_back(new mengfeiMuriel());   // has recording
    scenes.push_back(new mengfeiVera());            // has recording
    scenes.push_back(new mengfeiWhitney());         // has recording    
    
    
    // ----------------------- karsten
    
    
     scenes.push_back(new karstenVasulka());        // has recording
     scenes.push_back(new karstenJohnMaeda());      // has recording
    
#ifdef USE_FACE_TRACKING_SKETCHES
    ofFile fileTest("model/face.tracker");
    if (fileTest.exists()){
     scenes.push_back(new karstenFaceMirror());
    }
#endif
    
     scenes.push_back(new karstenVeraMolnar());     // has recording
     scenes.push_back(new karstenKenKnowlton());    // has recording
     scenes.push_back(new karstenJohnWhitney());    // has recording
    
    
    
    //-------------------------------  manaswi
    
    scenes.push_back(new manaswiJohnWhitney());
    scenes.push_back(new manaswiKenKnowlton());
    scenes.push_back(new manaswiRosaMenkman());
    scenes.push_back(new manaswiVeraMolnar());
    
    
   
    
    //------------------------------- liang
    
    
    scenes.push_back(new liangVasulka());       // has recording
    scenes.push_back(new liangMuriel());        // has recording
    
    
    

//------------------------------- peter
    // NOTE: pbeshaiBurson1 requires the ofxFaceTracker2 data (bin/data/shape_predictor_68_face_landmarks.dat)
    
    #ifdef USE_FACE_TRACKING_SKETCHES
    ofFile file("shape_predictor_68_face_landmarks.dat");
    if (file.exists()){
        
         scenes.push_back(new pbeshaiBurson1()); // has recording
    }
#endif
    
	/// MIT scenes
	
    
    scenes.push_back(new pbeshaiVideo1());      // has recording
    scenes.push_back(new pbeshaiKnowlton1());   // has recording
    scenes.push_back(new pbeshaiWhitney1());    // has recording
    scenes.push_back(new pbeshaiSchwartz1());   // has recording
    scenes.push_back(new pbeshaiMolnar1());     // has recording
    

    
    
    //------------------------------- hannah
//    scenes.push_back(new hannahVera());         // has recording
    scenes.push_back(new hannahMuriel());       // has recording
    scenes.push_back(new hannahMuriel2());      // has recording
    scenes.push_back(new hannahWhitney());      // has recording
    scenes.push_back(new hannahSchwartz());     // has recording
    
    
    //------------------------------- liz
    scenes.push_back(new lizVera());            // has recording
    scenes.push_back(new lizVesulka());         // has recording
    
    
    //------------------------------- aaron
    scenes.push_back(new aaronLillianSchwartz());
    scenes.push_back(new aaronRosaMenkman());
    scenes.push_back(new aaronMurielCooper());
    scenes.push_back(new aaronVeraMolnar());
    
    
    
    //------------------------------- ethan
    scenes.push_back(new ethanMolnarScene());
    scenes.push_back(new ethanWhitneyScene());
    
//    scenes.push_back(new mitScene1());
//    scenes.push_back(new exampleScene());

#endif
	
	/// SFPC scenes
	
	
	
	#ifdef SHOW_SFPC_FALL_2017
	   // ------- 2017 fall
//		scenes.push_back(new EstherMolnarScene());
//		scenes.push_back(new stacyButterflies());
		scenes.push_back(new diegoScene_01());
//		scenes.push_back(new annCaseyWave());
//		scenes.push_back(new weiMolnar_01());
		scenes.push_back(new runchalMolnar());
//		scenes.push_back(new aprilMenkman());
//		scenes.push_back(new heatherMolnarScene());
		scenes.push_back(new niklasLissajous());
//		scenes.push_back(new niklasMolnar());
		scenes.push_back(new niklasMorisawa());
		scenes.push_back(new niklasWhitneySineWave());
//		scenes.push_back(new fernandoMuriel());
//		scenes.push_back(new fernandoWhitney());
//		scenes.push_back(new fernandoWhitney2());
		scenes.push_back(new jacobsonWhitney_01());
		scenes.push_back(new jacobsonMolnar_02());
		scenes.push_back(new jacobsonMolnar_01());
		scenes.push_back(new hyojinVeraMolnar());
		scenes.push_back(new hyojinJohnWhitney());
//		scenes.push_back(new mattKnowlton());
		scenes.push_back(new EstherKnowltonScene());
//		scenes.push_back(new yingTanWhitneyMatrix());
//		scenes.push_back(new annMolnarRectangles());
		scenes.push_back(new weiWhitney());
		scenes.push_back(new yumiNishida01());
		

	#endif
	#ifdef SHOW_SFPC_FALL_2015
//		scenes.push_back(new zachTest());
		scenes.push_back(new CooperBauhaus());  // this might make for a good start scene -Robby & Becca
		scenes.push_back(new RileyArcsRoy());
		scenes.push_back(new rachelScene());
		scenes.push_back(new rodrigoBelfort());
//		scenes.push_back(new Cooper3dText());
		scenes.push_back(new chrisVeraInterruptions());
		scenes.push_back(new johnWhitneyShader02());
		scenes.push_back(new chrisRileyCascando());
		scenes.push_back(new memoAktenScene());
		scenes.push_back(new submotionOrchestraScene());
		scenes.push_back(new RoyWhitney1());
		scenes.push_back(new veraFscene());
		scenes.push_back(new robbyMolnarScene() );
		scenes.push_back(new veraAnimatedScene() );
		scenes.push_back(new robbyRileyScene() );
		scenes.push_back(new robbyMenkmanScene());
		scenes.push_back(new johnWhitneyShader01());
		scenes.push_back(new anastasisRileyScene());
		scenes.push_back(new loloWhitney());
		scenes.push_back(new loloVera());
		scenes.push_back(new andyMenkmanJpg());
		scenes.push_back(new andyMenkmanPng());
		scenes.push_back(new manfredMohrP196A());
		scenes.push_back(new veraMolnarTrapezium());
		scenes.push_back(new loloVera2());
		scenes.push_back(new cantusFirmusRiley());
		scenes.push_back(new aaronMarcusHieroglyphB());
		//scenes.push_back(new veraMolnarLines68());
		scenes.push_back(new alexLissamojiWhitney());
		scenes.push_back(new yosukeVeraSansTitre());
		//scenes.push_back(new alexGifPaletteDitherMenkman());
//		scenes.push_back(new yeseulMenkmanInstitution());
		scenes.push_back(new yeseulCooperMessages());
//		scenes.push_back(new yeseulWhitneyScene());
		scenes.push_back(new yeseulRileyBrokencircle());
		scenes.push_back(new yosukeJohnWhitneyMatrix());
//		scenes.push_back(new mgsCooperSymbols());
		scenes.push_back(new mgsRileyDiamonds());
//		scenes.push_back(new mgsRileyEllipsesAndSquares());
////		scenes.push_back(new mgsVeraMolnarLineStudy());
////		scenes.push_back(new mgsMaedaTimePainter());
		scenes.push_back(new mgsRileyDescending());
		scenes.push_back(new olegVeraV());
		scenes.push_back(new sarahgpRileyCircle());
		scenes.push_back(new mwalczykVeraSquares());

	#endif

		
}
#ifdef RANDOMIZE_SCENES
    ofRandomize(scenes);
#endif
    
#ifdef USE_MIDI_PARAM_SYNC
    sync.setup(0);
    
    // Disable MIDI smoothing by default
    sync.smoothing.set(0);
    
    ofAddListener(sync.player.playE, this, &sceneManager::startPlaying);
    ofAddListener(sync.recorder.recStartE, this, &sceneManager::recordingStart);
    ofAddListener(sync.recorder.recEndE, this, &sceneManager::recordingEnd);
#endif

	
	setupGui();
	
	
    sceneFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);

    codeFbo.allocate(CODE_WIDTH, CODE_HEIGHT, GL_RGB, 1);
	codeFbo.getTexture().setTextureMinMagFilter(GL_NEAREST,GL_NEAREST);
											
    
#ifdef USE_EXTERNAL_SOUNDS
    // open an outgoing connection
    oscSender.setup(OSC_HOST, OSC_PORT);
#else
    loadSounds();
    
    parameterChangeSound.setLoop(true);
    if (enableParameterSounds.get()) {
        parameterChangeSound.play();
    }
    parameterChangeSound.setVolume(0);
    
    TM.loadSounds();
#endif
    
    // disney
    for (auto scene : scenes){
        scene->dimensions.set(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        scene->setup();
        scene->enableMidi();
        scene->postSetup();
    }
    
    isTransitioning = false;
    currentScene = 0;

#ifdef TYPE_ANIMATION
    shouldDrawScene = false;
#else
    shouldDrawScene = true;
#endif
    shouldDrawCode = true;
    

    codeEnergyDecayRate.set("codeDecay", 0.1, 0, 0.3);
    codeEnergyPerFrame.set("codeEnergyPerFrame", 0.15, 0, 0.4);
    codeControls.setup("code settings", "codeSettings.xml");
    codeControls.add(codeEnergyDecayRate);
    codeControls.add(codeEnergyPerFrame);
    codeControls.loadFromFile("codeSettings.xml");
//    codeControls.setPosition(520+504+20, 500);
    
	
#ifdef TEST_SCENES
	loadTestGui();
#endif
	startCurrentScene();
    screenRect.set(0, 0, VISUALS_WIDTH+CODE_X_POS, VISUALS_HEIGHT);
    bShowCursor = true;
    ofAddListener(sync.ffwKeyPressed, this, &sceneManager::setAdvanceCurrentScene);
	
	
	
	#ifdef TEST_SCENES
			

			cout << "-------------SCENES LIST-------------" << endl;
			
			for(auto s: scenes){
				if(s){
					cout <<  s->author << " - " << s->originalArtist << " | " <<typeid(*s).name()<<endl;
				}
			}
			
			
			cout << "-------------------------------------" << endl;
			
	#endif

	
	
}

#ifdef USE_MIDI_PARAM_SYNC

//-----------------------------------------------------------------------------------
void sceneManager::setupGui(){
	gui.setDefaultWidth(300);
	gui.setup("SFPC_d4n", "SFPC_d4n_general_settings.xml");
	
	gui.add(enableParameterSounds.set("Enable parameter sounds", true));
	enableParameterSounds.addListener(this, &sceneManager::toggleParameterSounds);
	gui.add(drawScenePanel.set("draw scene ctrl", true));
	gui.add(enableMidiUpdate.set("enable midi update", true));
	gui.add(bAutoPlay.set("Auto Play on scene change", true));
	gui.add(autoadvanceDelay.set("Autoadvance", 0, 0, 60));
	gui.add(bSceneWaitForCode.set("Scene wait for code", true));
	gui.add(bFadeOut.set("Scene fade out", true));
	gui.add(bAutoAdvance.set("Auto Advance Scene", true));
#ifdef USE_SCENE_TRANSITIONS
	gui.add(sceneTweenDuration.set("fadeOutTime", 4.0, 0, 10.0));
	gui.add(codeTweenDuration.set("fadeInTime", 7.5, 0, 15));
#endif
	sync.smoothing.setName("MIDI Smoothing");
	gui.add(sync.smoothing);
	gui.add(ofSmoothing.set("OF Smoothing", 0.02, 0.01, 1));
	
	gui.loadFromFile("SFPC_d4n_general_settings.xml");
	//    gui.setWidthElements(300);
	//    gui.setDefaultWidth(300);
	gui.setPosition(ofGetWidth() - gui.getShape().width-20,  ofGetHeight() - gui.getShape().getHeight() - 100);
	
}
//-----------------------------------------------------------------------------------
void sceneManager::recordingStart(){
    scenes[currentScene]->reset();
    scenes[currentScene]->resetTiming();
}
//-----------------------------------------------------------------------------------
void sceneManager::recordingEnd(){
    if (sync.recorder.isRecording()) {
        sync.recorder.stop();
    }
    if (sync.recorder.recData.size()) {
        scenes[currentScene]->setSceneEnd();
        scenes[currentScene]->setRecData(sync.recorder.recData);
        sync.recorder.recData.clear();
    }

}
void sceneManager::toggleParameterSounds(bool &i){
    parameterChangeSound.setPaused(!enableParameterSounds);
}

//-----------------------------------------------------------------------------------
void sceneManager::startPlaying(){
    if(scenes[currentScene]->hasRecData()){
        scenes[currentScene]->resetTiming();
        sync.player.setData(scenes[currentScene]->getRecData());
        sync.player.play();
    }else{
        sync.player.clear();
    }
}
//-----------------------------------------------------------------------------------
void sceneManager::stopPlaying(){
    sync.player.stop();
	#ifdef TEST_SCENES
	if(scenes[currentScene]->bSceneTested.get() == false){
		checkedScenes++;
		scenes[currentScene]->bSceneTested = true;
	}
	#endif
	
}
#endif

//-----------------------------------------------------------------------------------
void sceneManager::startCurrentScene(){
	#ifdef TEST_SCENES
	while(scenes[currentScene]->bSceneTested.get() && checkedScenes < scenes.size()){
		checkedScenes++;
		currentScene ++;
		currentScene %= scenes.size();
	}
	#endif

	
	cout <<  "startCurrentScene  "  << currentScene  << endl;
	cout << scenes[currentScene]->author << " | " << scenes[currentScene]->originalArtist << endl;
	
    scenes[currentScene]->resetTiming();
    scenes[currentScene]->reset();
    TM.setup( (scenes[currentScene]), codeTweenDuration);
    lettersLastFrame = 0;
    lastPlayTime = 0;
    maxLetterX = 0;
    lastLetterY = 0;
#ifdef USE_MIDI_PARAM_SYNC
    sync.setSyncGroup(scenes[currentScene]->midiParameters, true);
    isMidiConnected = sync.enableMidi();
#endif
	loadSceneGui();
//#ifdef USE_EXTERNAL_SOUNDS
//    oscMessage.clear();
//    oscMessage.setAddress("/d4n/scene/load");
//    oscMessage.addIntArg(currentScene);
//    oscSender.sendMessage(oscMessage, false);
//#else
//#endif
    // TODO
    
}
//-----------------------------------------------------------------------------------
void sceneManager::nextScene(bool forward){
	cout << "nextScene. forward: " << boolalpha << forward << endl;
#ifdef USE_MIDI_PARAM_SYNC
    recordingEnd();
#endif

    stopPlaying();
    parameterChangeSound.setVolume(0);
//	bSaveScreenshot=true;
	if (forward && bFadeOut) {
		if (!isTransitioning) {
			isTransitioning = true;
			preTransitionStart = ofGetElapsedTimef();
			preTransitionPct = 0;
			return;
		} else {
			isTransitioning = false;
		}
	}
	
    if (forward){
        currentScene ++;
        currentScene %= scenes.size();
    } else {
        currentScene --;
        if (currentScene < 0){
            currentScene = scenes.size() - 1;
        }
    }
    
#ifdef TYPE_ANIMATION
    shouldDrawScene = false;
#else
    shouldDrawScene = true;
#endif

    isTransitioning = false;
    shouldDrawCode = true;


	
    startCurrentScene();

}

#ifdef TEST_SCENES
//--------------------------------------------------------------
void sceneManager::blacklistCurrentScene(){
	if(currentScene < scenes.size()){
		if(scenes[currentScene]){
			scenes[currentScene]->bBlacklist = true;
		}
	}
}
//--------------------------------------------------------------
void sceneManager::saveTestGui(bool& ){
	cout <<  "sceneManager::saveTestGui  : " << endl;
	testGui.saveToFile("Tested_Scenes.xml");
	
}
//--------------------------------------------------------------
void sceneManager::loadTestGui(){
	testGui.setup("Tested Scenes", "Tested_Scenes.xml");
	for(auto s: scenes){
		if(s){
			parameters[s->author].setName(s->author);
			if(parameters[s->author].contains(s->bSceneTested.getName())){
				s->bSceneTested.setName(s->bSceneTested.getName()+ typeid(s).name());
			}
			s->bBlacklist.setName("Blacklist"+s->bSceneTested.getName());
			parameters[s->author].add(s->bSceneTested);
			parameters[s->author].add(s->bBlacklist);
		}
	}
	for(auto& p: parameters){
		testGui.add(p.second);
	}
	testGui.loadFromFile("Tested_Scenes.xml");
	for(auto s: scenes){
		if(s){
			testListeners.push(s->bSceneTested.newListener(this, &sceneManager::saveTestGui));
			testListeners.push(s->bBlacklist.newListener(this, &sceneManager::saveTestGui));
		}
	}
	
	cout << "=====BLACKLIST======" << endl;
	for(auto s: scenes){
		if(s){
			if(s->bBlacklist){
				cout << s->author << "  -  " <<  s->bSceneTested.getName() << endl;
			}
		}
	}
	cout << "====================" << endl;
}
#endif


//-----------------------------------------------------------------------------------
void sceneManager::advanceScene(bool bUpdateAutoTime){
	nextScene(true);
	if(bUpdateAutoTime) lastAutoadvanceTime = ofGetElapsedTimef();
};
//-----------------------------------------------------------------------------------
void sceneManager::regressScene(){
    nextScene(false);
};
//-----------------------------------------------------------------------------------
void sceneManager::loadSceneGui(){
	
	sceneGui.clear();
    sceneGui.setup("scene settings");
    sceneGui.add(scenes[currentScene]->parameters);
    sceneGui.setPosition(20, 20);
	auto r = sceneGui.getShape();
	gui.setPosition(r.getTopRight() + glm::vec3(30, 0, 0));
	codeControls.setPosition(r.getBottomLeft() + glm::vec3(0, 30, 0));
	
	
#ifdef TEST_SCENES
	for(size_t i = 0; i < testGui.getNumControls(); i++){
		auto c = dynamic_cast<ofxGuiGroup*>(testGui.getControl(i));
		if(c){
			if(c->getName() == scenes[currentScene]->author){
				c->maximize();
				c->setHeaderBackgroundColor(ofColor::yellow);
				c->setTextColor(ofColor::black);
			}else{
				c->minimize();
				c->setHeaderBackgroundColor(ofColor(64));
				c->setTextColor(ofColor::white);
			}
		}
	}
	
	
	testGui.setPosition(ofGetWidth()- testGui.getShape().width, 20);
	
#endif
	
}
//-----------------------------------------------------------------------------------
void sceneManager::update(){

    if (autoadvanceDelay > 0.001 && !scenes[currentScene]->isEndSet()) {
        if (lastAutoadvanceTime == 0) {
            lastAutoadvanceTime = ofGetElapsedTimef();
        }
        if (ofGetElapsedTimef() - lastAutoadvanceTime > autoadvanceDelay) {
            advanceScene(true);
        }
    } else {
        if (bAutoAdvance && !sync.recorder.isRecording()) {
            if (!isTransitioning && scenes[currentScene]->isSceneDone()) {
                advanceScene(false);
            }
        }
        lastAutoadvanceTime = 0;
    }
    
    baseScene::smoothingSpeed = ofSmoothing;
    TM.animTime = codeTweenDuration;
    TM.energyDecayRate = codeEnergyDecayRate;
    TM.energyChangePerFrame = codeEnergyPerFrame;
    //the following is to avoid showing the mouse cursor if it is over what's being drawn to the screens,
    //but showing it if not.
    bool bInside =screenRect.inside(ofGetMouseX(), ofGetMouseY()) ;
    if ( bInside && bShowCursor) {
        //ofHideCursor();
        bShowCursor = false;
    } else if(!bInside && !bShowCursor){
        //ofShowCursor();
        bShowCursor = true;
    }
    
    
#ifdef TYPE_ANIMATION
    pctDelay = (ofGetElapsedTimef() - TM.setupTime) / (TM.animTime);
    if (bSceneWaitForCode) {
        if (!isTransitioning && !shouldDrawScene && pctDelay > FADE_DELAY_MIN){
            shouldDrawScene = true;
//			saveScreeshot();
            fadingIn = true;
#ifdef USE_EXTERNAL_SOUNDS
            oscMessage.clear();
            oscMessage.setAddress("/d4n/scene/start");
            oscMessage.addIntArg(1);
            oscSender.sendMessage(oscMessage, false);
#else
            animationStartSound.play();
#endif

        } else if (fadingIn && pctDelay > FADE_DELAY_MAX){
            fadingIn = false;
#ifdef USE_MIDI_PARAM_SYNC
            if (bAutoPlay) {
                startPlaying();
            }
#endif
        }
    } else {
        shouldDrawScene = true;
//		saveScreeshot();
    }
#endif
    if (isTransitioning) {
        preTransitionPct = (ofGetElapsedTimef() - preTransitionStart) / sceneTweenDuration;
        fadingOut = false;
        shouldDrawScene = false;
        shouldDrawCode = false;
        shouldPlaySceneChangeSound = false;

        if (preTransitionPct >= 1.0) {
            nextScene(true);
			isTransitioning = false;
            introCursor = false;
            
        } else if (preTransitionPct < SCENE_PRE_TRANSITION_FADE) {
            fadingOut = true;
            shouldDrawScene = true;
//			saveScreeshot();
            shouldDrawCode = true;
            hasTriggeredSceneChangeSound = false;
//        } else if (preTransitionPct > SCENE_PRE_TRANSITION_SOUND) {
//            if (!hasTriggeredSceneChangeSound) {
//                //shouldPlaySceneChangeSound = true;
//            }
        } else if (preTransitionPct > SCENE_PRE_TRANSITION_CURSOR) {
            introCursor = true;
        }
    }

    if (shouldDrawScene) {
#ifdef USE_MIDI_PARAM_SYNC
        
//        if (enableMidiUpdate.get() && scenes[currentScene]->recData.size()){
        if (enableMidiUpdate.get()){// && scenes[currentScene]->recData.size()){
            if(scenes[currentScene]->bAnimateScene){
                scenes[currentScene]->updateMidiParams();
            }
        }
#endif
        scenes[currentScene]->update();
    }
    
#ifdef USE_EXTERNAL_SOUNDS
    oscMessage.clear();
    oscMessage.setAddress("/d4n/scene/start");
    oscMessage.addIntArg(1);
    oscSender.sendMessage(oscMessage, false);
#else
    if (shouldPlaySceneChangeSound) {
        sceneChangeSound.play();
        hasTriggeredSceneChangeSound = true;
    }
#endif
    
    ofParameter < float > floatParam;

    float maxActivation = 0, maxPct;
    if (shouldDrawScene && TM.paramEnergy.size() > 0) {
        
        for (int i = 0; i < TM.paramEnergy.size(); i++) {
    
            if (TM.paramEnergy[i] > 0) {
                ofParameter<float> t = scenes[currentScene]->parameters[i].cast<float>();
                float pct = ofMap(t.get(), t.getMin(), t.getMax(), 0, 1, true);
                if (pct > maxActivation)
                    maxPct = pct;
                if (TM.paramChangedEnergy[i] > maxActivation)
                    maxActivation = TM.paramChangedEnergy[i];
            }
        }
        
        float vol;
        float maxVol = 0.5;
        if (isTransitioning) {
            vol = ofMap(preTransitionPct, 0, 0.2, maxVol, 0, true);
        }

        if (maxActivation > 0.1) {
            if (!isTransitioning) {
                vol = ofMap(maxActivation, 0.1, 1, 0, maxVol, true);
            }
            parameterChangeSound.setVolume(vol);
            parameterChangeSound.setSpeed(ofMap(maxActivation, 0, 1, 0.4, 1.0));
        } else {
            parameterChangeSound.setVolume(0);
        }
    } else {
#ifdef USE_EXTERNAL_SOUNDS
        oscMessage.clear();
        oscMessage.setAddress("/d4n/paramEnergy");
        oscMessage.addFloatArg(0);
        oscSender.sendMessage(oscMessage, false);
#else
        parameterChangeSound.setVolume(0);
#endif
    }
    
    
}
//-----------------------------------------------------------------------------------
void sceneManager::setAdvanceCurrentScene(){
    scenes[currentScene]->setSceneEnd();
    parameterChangeSound.setVolume(0);
}

void sceneManager::drawType(){
    ofSetColor(0);
    ofDrawRectangle(CODE_X_POS-1, 0, VISUALS_WIDTH+2, VISUALS_HEIGHT);
    ofSetColor(255);
    codeFbo.draw(CODE_X_POS, 0, VISUALS_WIDTH, VISUALS_HEIGHT);
}

void sceneManager::drawGui(){
    
    if (bDrawGui){
        if (drawScenePanel)
            sceneGui.draw();
        codeControls.draw();
        
        gui.draw();

    }
	#ifdef TEST_SCENES
		testGui.draw();
	#endif
}
//-----------------------------------------------------------------------------------
void sceneManager::renderSceneFbo(){
	if (shouldDrawScene) {
		   sceneFbo.begin();
		   ofClear(0,0,0,255);
		   ofPushStyle();
		   scenes[currentScene]->draw();
		   ofPopStyle();
		   ofClearAlpha();
		   sceneFbo.end();
	}
}
//-----------------------------------------------------------------------------------
void sceneManager::renderCodeFbo(){
	codeFbo.begin();
    ofSetColor(255,255,255);
    pctCode = (ofGetElapsedTimef() - TM.setupTime) / TM.animTime;
    
    if (pctCode > 1) pctCode = 1;
    if (pctCode < 0) pctCode = 0;
    
    if (pctCode < 0.5){
        pctCode *= 2;
        pctCode  = powf(pctCode, 3.0);
        pctCode *= 0.5;
    } else {
        pctCode -= 0.5;
        pctCode *= 2.0;
        pctCode  = powf(pctCode, 1.0/3.0);
        pctCode *= 0.5;
        pctCode += 0.5;
    }

    ofClear(0,0,0,255);
    vector < codeLetter > letters;
    if (shouldDrawCode)
        letters = TM.getCodeWithParamsReplaced(scenes[currentScene]);
    
    ofSetColor(255);
    
    bool bShiftUp = false, bShiftLeft = false;
    
    if (lastLetterY > (CODE_HEIGHT-20)) {
        bShiftUp = true;
    }

    if (maxLetterX > (CODE_WIDTH-20)) {
        bShiftLeft = true;
    }
    
    if (bShiftUp && !introCursor) {
        float dy = lastLetterY - (CODE_HEIGHT-20);
        ofPushMatrix();
        ofTranslate(0,-dy);
    }

    if (bShiftLeft && !introCursor) {
        float dx = maxLetterX - (CODE_WIDTH-20);
        dx = min((int)dx, 20);
        ofPushMatrix();
        ofTranslate(-dx,0);
    }

    const int codeDefaultStartX = 40;
	countLetters = 0;
    int xStart = codeDefaultStartX;
    int x = xStart;
    
    // Quick cache of how many lines we're going to draw
    int nLines = 0, currentLine = 0;
	maxActivationPerLine = 0;
	maxTotalActivation = 0;
    
    // One entry per line, stores id of param that is getting animated the most
    vector<int> lineHasAnimParam;

    lineHasAnimParam.push_back(-1);
    for (int i = 0; i < letters.size() * pctCode; i++) {
        if (letters[i].type == CHARACTER_PARAM) {
            float activation = TM.paramEnergy[letters[i].idOfChar];
            if (activation > 0.000001 && activation > maxActivationPerLine) {
                maxActivationPerLine = activation;
                lineHasAnimParam[currentLine] = letters[i].idOfChar;
            }
            if (activation > 0.000001 && activation > maxTotalActivation) {
                maxTotalActivation = activation;
            }
        }

        if (letters[i].character == '\n') {
            currentLine++;
            nLines++;
            maxActivationPerLine = 0;
            lineHasAnimParam.push_back(-1);
        }
    }

    // Set line Y based on how many lines we're going to draw over the total height
    int maxLinesWithoutScroll = (CODE_HEIGHT - 60*2) / 13;
    int maxLinesWithScroll = (CODE_HEIGHT-10*2) / 13;
    int y;
    
    if (nLines <= maxLinesWithoutScroll) {
        y = 60 + 13;
    } else if (nLines <= maxLinesWithScroll) {
        y = 60 + 13 + (maxLinesWithoutScroll - nLines + 1) * 13;
    } else {
        y = 10 + 13;
    }
    
    const int lineWithActiveParamDim = 255*0.9;
    const int lineWithoutActiveParamDim = 255*0.9;
    const int commentDim = 255*0.5;
    currentLine = 0;
    bool nonEmptyLetter = false;
    
    for (int i = 0; i < letters.size() * pctCode; i++){
        
        int lineBrightness = 255;
        if (lineHasAnimParam[currentLine] < 0) {
            lineBrightness -= maxTotalActivation * lineWithoutActiveParamDim;
        } else {
            float currActivation = TM.paramEnergy[lineHasAnimParam[currentLine]];
            lineBrightness -= (maxTotalActivation - currActivation) * lineWithActiveParamDim;
        }
//        ofSetColor(255);
//        font.drawString("This should always render." , 30, 30);
        ofSetColor(127);
        if (letters[i].type == CHARACTER_CODE) {
            ofSetColor(lineBrightness);
        } else if (letters[i].type == CHARACTER_PARAM) {
            int charBrightness = TM.paramEnergy[letters[i].idOfChar]*(255);
            ofSetColor(min(lineBrightness + charBrightness, 255));
        } else if (letters[i].type == CHARACTER_COMMENT) {
            ofSetColor(max(lineBrightness - commentDim * (1.0-maxTotalActivation), 0.0));
        }
    
        string s = "";
        s += (char)(letters[i].character);
        font.drawString(s , (int)x, (int)y);
        
        if (letters[i].character != ' ' &&
            letters[i].character != '\n' &&
            letters[i].character != '\t') {
            countLetters++;
            nonEmptyLetter = true;
        }
        
        x += 7;
        if (letters[i].character == '\n'){
            y += 13;
            x = xStart;
            currentLine++;
        }
        
        maxLetterX = max((int)maxLetterX, x);
        lastLetterY = y;
    }
    
    bool drawCursor, soundCursor = false;
    
    // Decide if we're going to draw a cursor
    if (!isTransitioning) {
        if (pctCode < 0.1) {
            drawCursor = int(letters.size() * pctCode) % 3 == 0;
        } else if (pctCode > 0.1 && pctCode < 1) {
            drawCursor = true;
        } else if (pctDelay > 1) {
            x = xStart;
            y += 13;
            drawCursor = (int)((pctDelay * TM.animTime) / 0.2) % 3 == 1;
            soundCursor = drawCursor;
        }

        if (!nonEmptyLetter) drawCursor = false;
        if (!(x != xStart || pctDelay > 1)) drawCursor = false;
    }
    if (isTransitioning && introCursor) {
        x = codeDefaultStartX;
        y = 60 + 13;
        soundCursor = drawCursor = (int)((preTransitionPct * sceneTweenDuration) / 0.2) % 3 == 1;
    }
    
    // Draw that cursor
    if (drawCursor && !shouldDrawScene) {
        ofSetColor(140);
        ofDrawRectangle(x, y-10, 7, 13);
    }
    
    if (soundCursor && !shouldDrawScene) {
        if (!hasTriggeredCursorSound) {
            triggerCursorSound();
            hasTriggeredCursorSound = true;
        }
    } else {
        hasTriggeredCursorSound = false;
    }
    
    if (bShiftLeft){
        ofPopMatrix();
    }
    
    if (bShiftUp){
        ofPopMatrix();
    }

    codeFbo.end();
    
}
//-----------------------------------------------------------------------------------
//void sceneManager::saveScreeshot(){
//	if(bSaveScreenshot){
//	ofSaveScreen(ofGetTimestampString() + "_" + scenes[currentScene]->author+"-"+scenes[currentScene]->originalArtist + ".png");
//		bSaveScreenshot = false;
//	}
//}
//-----------------------------------------------------------------------------------
void sceneManager::draw(){
	draw(ofRectangle(CODE_X_POS, 0, CODE_WIDTH, CODE_HEIGHT) ,ofRectangle(0,0,VISUALS_WIDTH, VISUALS_HEIGHT));
}
//-----------------------------------------------------------------------------------
void sceneManager::draw(const ofRectangle& codeRect, const ofRectangle& sceneRect, bool bDrawCode){
    sync.update();
    
	renderCodeFbo();
	
	if( bDrawCode){
		codeFbo.draw(codeRect);
	}
	renderSceneFbo();
    if (shouldDrawScene) {
		sceneFbo.draw(sceneRect);
        if (fadingIn) {
            float fadeOpacityRaw = ofMap(pctDelay, FADE_DELAY_MIN, FADE_DELAY_MAX, 0, PI);
            float fadeOpacityShaped = ofMap(cos(fadeOpacityRaw), 0, 1, 0, 255);
            ofSetColor(0, fadeOpacityShaped);
            ofFill();
			ofDrawRectangle(sceneRect.x, sceneRect.y, sceneRect.width+1, sceneRect.height);
        }
    } else {
        ofSetColor(0);
        ofFill();
        ofClearAlpha();
		ofDrawRectangle(sceneRect.x, sceneRect.y, sceneRect.width+1, sceneRect.height);
    }

    // Draw overlay rectangles on fade out
    if (isTransitioning && fadingOut) {
        float fadeOpacityRaw = ofMap(preTransitionPct, 0, SCENE_PRE_TRANSITION_FADE, 0, 1);
        ofSetColor(0, ofClamp(fadeOpacityRaw * 255, 0, 255));
        ofFill();
        
        // Draw over the frames
		ofDrawRectangle(sceneRect.x, sceneRect.y, sceneRect.width+1, sceneRect.height);
		ofDrawRectangle(codeRect.x-1, codeRect.y, codeRect.width+2, codeRect.height);

    }

  
#ifdef TYPE_ANIMATION
    if (!shouldDrawScene){
        ofSetColor(0,1);
        ofFill();
		ofDrawRectangle(sceneRect);
        int diff = (countLetters - (int)lettersLastFrame);
        if (diff > 0 && (ofGetElapsedTimeMillis()-lastPlayTime > ofRandom(50,87))) {
            lastPlayTime = ofGetElapsedTimeMillis();
            
#ifdef USE_EXTERNAL_SOUNDS
            if (ofNoise(pctCode*10, ofGetElapsedTimef()/10.0) > 0.5) {
                oscMessage.clear();
                oscMessage.setAddress("/d4n/keystroke");
                oscMessage.addIntArg(roundf(ofRandom(1,2)));
                oscSender.sendMessage(oscMessage, false);
            } else {
                oscMessage.clear();
                oscMessage.setAddress("/d4n/keystroke");
                oscMessage.addIntArg(roundf(ofRandom(3,4)));
                oscSender.sendMessage(oscMessage, false);
            }
#else
            if (ofNoise(pctCode*10, ofGetElapsedTimef()/10.0) > 0.5){
                TM.keystroke2Sound.play();
                TM.keystroke2Sound.setSpeed(ofRandom(0.9, 1.1));
                
            } else {
                TM.keystroke1Sound.play();
                TM.keystroke1Sound.setSpeed(ofRandom(0.9, 1.1));
            }
#endif
        }
        lettersLastFrame = countLetters;
        
    }
#endif

    
    ofSetColor(255);
}


//-----------------------------------------------------------------------------------
void sceneManager::screenGrab() {
    string path = "screengrabs/";
    ofImage sceneImg;
    ofImage codeImg;
    
    sceneFbo.readToPixels(sceneImg.getPixels());
    codeFbo.readToPixels(codeImg.getPixels());
    
    sceneImg.save(path+ofGetTimestampString()+"_scene.png");
    codeImg.save(path+ofGetTimestampString()+"_code.png");
    
}
//-----------------------------------------------------------------------------------
void sceneManager::loadSounds() {
    string path = "sounds/";
    sceneChangeSound.load(path+"sceneChange.aiff");
    
    cursorBlinkSound.load(path+"cursorBlink1.aiff");
    cursorBlinkSound.setLoop(false);
    cursorBlinkSound.setMultiPlay(false);


    animationStartSound.load(path+"animationStart.aiff");
    
    parameterChangeSound.load(path+"parameterChange.aiff");
    parameterChangeSound.setMultiPlay(false);
}
//-----------------------------------------------------------------------------------
void sceneManager::triggerCursorSound() {
#ifdef USE_EXTERNAL_SOUNDS
    ofxOscMessage oscMessage;
    oscMessage.clear();
    oscMessage.setAddress("/d4n/cursor");
    oscMessage.addTriggerArg();
    oscSender.sendMessage(oscMessage, false);
#else
    cursorBlinkSound.play();
#endif
}



