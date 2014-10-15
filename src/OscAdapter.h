//
//  OscAdapter.h
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#ifndef __carrousel__OscAdapter__
#define __carrousel__OscAdapter__

#include <stdio.h>
#include "Carrousel.h"
#include "ofxJSON.h"
#include "ofxOsc.h"


#define PORT 8080
#define REMOTE_PORT 8888
#define REMOTE_IP "192.168.1.177"


class OscAdapter{
    Carrousel *controller;
    void parseOsc();
    void registerOsc();
public:
    OscAdapter();
    ~OscAdapter();
    bool bOnline;
    
    ofxOscReceiver receiver;
    
    void setController(Carrousel *c);
    
    void update();
};



#endif /* defined(__carrousel__OscAdapter__) */
