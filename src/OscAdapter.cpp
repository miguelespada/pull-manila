//
//  OscAdapter.cpp
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#include "OscAdapter.h"

OscAdapter::OscAdapter(){
    receiver.setup(PORT);
    cout << "listening for osc messages on port " << PORT << "\n";
    bOnline = false;
}

OscAdapter::~OscAdapter(){
    cout << "Destroying Osc adapter" << endl;
}

void OscAdapter::setController(Carrousel *c){
    controller = c;
}

void OscAdapter::parseOsc(){
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        cout << "..";
        // get the next message
        bOnline = true;
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        cout << m.getAddress() << endl;
        if(m.getAddress() == "/key_down")
            controller->key_down();
    }
}

void OscAdapter::update(){
    parseOsc();
    if(ofGetFrameNum() % 300 == 0 && !bOnline)
        registerOsc();
}


void OscAdapter::registerOsc(){
    ofxOscSender sender;
    sender.setup(REMOTE_IP, REMOTE_PORT);
    ofxOscMessage m;
    m.setAddress("/register");
    sender.sendMessage(m);
}