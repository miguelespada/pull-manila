//
//  AssetsManager.h
//  carrousel
//
//  Created by miguel on 13/10/14.
//
//

#ifndef __carrousel__AssetsManager__
#define __carrousel__AssetsManager__

#include <stdio.h>
#include "Assets.h"

using namespace std;
class AssetsManager
{
    int background_index;
    int language;
    int rule;
    int animation;
    int price_sample;
    int ruleta_background;
    
public:
    class Assets *assets;
    
    AssetsManager();
    ~AssetsManager();
    
    void setAssets(Assets *a);
    ofColor back_color();
    
    int randomize_background(int frequency, int pace);
    string randomPrice();
    
    void drawRules();
    void animateRules(int frequency, int pace);
    void drawRuletaArt();
    void drawPrice(string name, int x);
    void drawWinner(string name);
};

#endif /* defined(__carrousel__AssetsManager__) */
