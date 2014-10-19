//
//  Assets.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __carrousel__Assets__
#define __carrousel__Assets__

#include <stdio.h>
#include "ofMain.h"
#include "ofxJSON.h"
#include "Settings.h"

#define BACKGROUND_ANIMATIONS false
#define N_LANG 1
#define N_RULES 3

class Assets{
public:
    
    Assets();
    ~Assets();
    void load();
    
    std::map<std::string, ofImage> price_images, price_captions, price_winnings;
    ofImage background_animations[2], portal_animations[2];
    ofImage background, portal;
    ofImage rules_background[3];
    ofImage rules[3][4];
    
    Settings *settings;
    
    vector<string> prices;
    
    int price_number();
    int number_of_colors();
    void setSettings(Settings *s);
    bool bOnline;
    
private:
    void import_price_list();
};

#endif /* defined(__carrousel__Assets__) */
