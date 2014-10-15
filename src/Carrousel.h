

#ifndef carrousel_Carrousel_h
#define carrousel_Carrousel_h
#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "Ruleta.h"

using namespace std;

class Carrousel
{
    
public:
    
    Carrousel();
    
    class State *current;
    class AssetsManager *assetsManager;
    class Settings *settings;
    
    void setCurrent(State *s);
    void setAssetsManager(AssetsManager *a);
    void setSettings(Settings *s);
    
    void key_down();
    void jump();
    void getNextPrice();
    void draw();
    void disableCurrentPrice();
    string price, price_id;
    bool price_enabled; 
    Ruleta ruleta;
    void configureRuleta();
    
    
};

#endif
