#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "state.h"
#include "Settings.h"
#include "Assets.h"
#include "OscAdapter.h"


class ofApp : public ofBaseApp{
public:
    ~ofApp();
    ofApp();
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    bool bInfo = false;
    Carrousel carrousel;
    Settings settings;
    Assets assets;
    AssetsManager assetsManager;
    OscAdapter oscAdapter;
};


