//
//  Settings.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __carrousel__Settings__
#define __carrousel__Settings__

#include <stdio.h>
#include "ofxJSON.h"
#include "ofMain.h"

class Settings{
public:
    Settings();
    ~Settings();
    
    void load();
    int exp_time, linear_time;
    float speed, decay;
    int width, height, icon_size;
    int sleep_time;
    vector<int> back_colors;
    int price_sample_x, price_sample_y;
    int pace;
    
    string assetsPath();
    
private:
    ofxJSONElement settings;
};
#endif /* defined(__carrousel__Settings__) */
