//
//  AssetsManages.cpp
//  carrousel
//
//  Created by miguel on 13/10/14.
//
//

#include "AssetsManager.h"
#include "Assets.h"


AssetsManager::AssetsManager(){
    ruleta_background = 0;
    language = 0;
    rule = 3;
    animation = 0;
    price_sample = 0;
    background_index = 0;
    
    cout << "Constructing Assets Manager" << endl;
}

AssetsManager::~AssetsManager(){
    cout << "Destroying Assets Manager" << endl;
}

void AssetsManager::setAssets(Assets *a)
{
    assets = a;
}

ofColor AssetsManager::back_color(){
    return ofColor::fromHex(assets->settings->back_colors[background_index]);
}

int AssetsManager::randomize_background(int frequency, int pace){
    
    if(ofGetFrameNum() % (frequency * pace) == 0){
        background_index =  int(ofRandom( assets->number_of_colors()));
    }
};


void AssetsManager::drawRules(){
    ofSetColor(255);
    assets->rules_background[language].draw(0,0);
    assets->rules[language][rule].draw(0, 0);
    assets->background_animations[animation].draw(0,0);
    assets->price_images[assets->prices[price_sample]].draw(assets->settings->price_sample_x, assets->settings->price_sample_y);
}

void AssetsManager::animateRules(int frequency, int pace){
    if(ofGetFrameNum() % (frequency * pace) == 0)
        animation = (animation + 1) % 2;
    
    if(ofGetFrameNum() % (frequency * 4 *  pace) == 0){
        if(assets->price_number() > 1)
            price_sample = (price_sample + 1) % (assets->price_number() - 1);
    }
    
    if(ofGetFrameNum() % (frequency *  8 * pace) == 0){
        rule = (rule + 1) % 4;
        if(rule == 0)
            language = (language + 1) % 3;
    }
}

void AssetsManager::drawRuletaArt(){
    
    ofSetColor(255);
    assets->background.draw(0, 0);
    assets->portal.draw(0, 0);
    assets->portal_animations[ruleta_background].draw(0, 0);
    
    if(ofGetFrameNum() % 60 == 0)
        ruleta_background = (ruleta_background + 1) % 2;
}

void AssetsManager::drawPrice(string name, int x){
    
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(assets->settings->width/2 - assets->settings->icon_size/2, 0);
    assets->price_images[name].draw(x, assets->settings->height / 2 - assets->settings->icon_size / 2  );
    ofPopMatrix();
    
    if(abs(x) < 45)
        assets->price_captions[name].draw(0, 0);
}

void AssetsManager::drawWinner(string name){
    assets->price_winnings[name].draw(0, 0);
}

string AssetsManager::randomPrice(){
    return assets->prices[ofRandom(assets->price_number())];
}