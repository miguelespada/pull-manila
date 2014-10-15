//
//  Ruleta.h
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#ifndef __carrousel__Ruleta__
#define __carrousel__Ruleta__

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "Settings.h"
#include "AssetsManager.h"



class Ruleta{
    
    class priceIcon{
    public:
        priceIcon(){};
        ~priceIcon(){};
        priceIcon(float _x, string _name){
            name = _name;
            x = _x;
        }
        float x;
        string name;
    };

    
    class Settings *settings;
    class AssetsManager *assetsManager;
    
public:
    Ruleta();
    void setSettings(Settings *settings, AssetsManager *assetsManager);
    
    vector<priceIcon> ruleta;
    
float speed, price_x, time;
void start(string name);
void draw();
void drawPriceIcon(priceIcon p);
void drawMasks();
void update();
bool has_stopped();
bool cancelable();
};
#endif /* defined(__carrousel__Ruleta__) */
