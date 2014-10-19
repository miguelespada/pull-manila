//
//  Ruleta.cpp
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#include "Ruleta.h"


Ruleta::Ruleta(){}

void Ruleta::setSettings(Settings *s, AssetsManager *manager){
    settings = s;
    assetsManager = manager;
}

void Ruleta::start(string name){
    
    speed = settings->speed;
    
    price_x = -settings->speed *
    (pow(settings->decay, settings->exp_time) - 1)/ (settings->decay - 1)
    - settings->linear_time * settings->speed;
    
    time = settings->exp_time + settings->linear_time;
    
    ruleta.clear();
    
    for(int i = 1; i < 5; i ++)
        ruleta.push_back(priceIcon(price_x - settings->icon_size * i,
                                   assetsManager->randomPrice()));
    ruleta.push_back(priceIcon(price_x, name));
    
    int xx = price_x + settings->icon_size;
    while(xx < settings->icon_size * 4){
        ruleta.push_back(priceIcon(xx, assetsManager->randomPrice()));
        xx += settings->icon_size;
    }
    
}

void Ruleta::drawPriceIcon(priceIcon p){
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    ofTranslate(settings->width/2 - settings->icon_size/2, -5);
    assetsManager->assets->price_images[p.name].draw(p.x, settings->height / 2 - settings->icon_size / 2  );
    ofPopMatrix();
    
    if(abs(p.x) < 45)
        assetsManager->assets->price_captions[p.name].draw(0, 0);
}


void Ruleta::draw(){
    
    for (std::vector<priceIcon>::iterator it = ruleta.begin() ; it != ruleta.end(); ++it){
        drawPriceIcon(*it);
        if (time > 0) (*it).x += speed;
    }
    
    drawMasks();
    ofSetColor(255);
    
    update();
    
}

void Ruleta::drawMasks(){
    ofSetColor(assetsManager->back_color(), 200);
    
    ofRect(0,
           settings->height/2  - settings->icon_size/2 - 10,
           settings->width/2 - settings->icon_size/2 + 1,
           settings->icon_size + 10);
    
    ofRect(settings->width/2 +  settings->icon_size/2 +  1,
           settings->height/2  - settings->icon_size/2 - 10,
           settings->width,
           settings->icon_size + 10);
    ofSetColor(255);
}


void Ruleta::update(){
    price_x += speed;
    
    if(time < settings->exp_time)
        speed *= settings->decay;
    
    time -= 1;
    
    if(time == 0)
        speed = 0;
    
    if(abs(price_x) < 1){
        time = 0;
    }
}

bool Ruleta::has_stopped(){
    return time == 0;
}


bool Ruleta::cancelable(){
    return speed == settings->speed;
}