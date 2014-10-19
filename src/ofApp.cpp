#include "ofApp.h"

ofApp::ofApp(){
    cout << "Constructing app" << endl;
}

ofApp::~ofApp(){
    cout << "Destroying app" << endl;
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    
    ofSetWindowPosition(0, 0);
    ofHideCursor();
    
    settings.load();
    
    assets.setSettings(&settings);
    assets.load();
    
    assetsManager.setAssets(&assets);
    oscAdapter.setController(&carrousel);
    
    carrousel.setAssetsManager(&assetsManager);
    carrousel.setSettings(&settings);
    carrousel.setCurrent(new IDLE());
    carrousel.configureRuleta();
}

//--------------------------------------------------------------
void ofApp::update(){
    oscAdapter.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    carrousel.draw();
    

    if(!assets.bOnline || !oscAdapter.bOnline){
        ofBackground(0);
        if(!assets.bOnline) ofDrawBitmapString("SERVER not connected", ofPoint(20, 20));
        if(!oscAdapter.bOnline) ofDrawBitmapString("ARDUINO not connected", ofPoint(20, 40));
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case ' ':
            oscAdapter.bOnline = true;
            carrousel.key_down();
            break;
        case 'q':
            carrousel.jump();
            break;
        case 'c':
            ofHideCursor();
            break;
        case 'C':
            ofShowCursor();
            break;
        default:
            break;
    }
    
}

