//
//  Carrousel.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "state.h"

Carrousel::Carrousel(){
    
}


void Carrousel::setCurrent(State *s)
{
    current = s;
}

void Carrousel::setAssetsManager(AssetsManager *a)
{
    assetsManager = a;
}

void Carrousel::key_down()
{
    current->push(this);
}

void Carrousel::jump()
{
    current->jump(this);
}


void Carrousel::draw()
{
    current->draw(this);
}

void Carrousel::setSettings(Settings *s){
    settings = s;
}

void Carrousel::getNextPrice(){
    ofxJSONElement response;
    response.open("http://localhost:3000/prices/next.json");
    
    cout << response;
    price_enabled = response["enabled"].asBool();
    price_id = response["_id"]["$oid"].asString();
    price = response["type"].asString();
    
}

void Carrousel::disableCurrentPrice(){
    if(price_enabled){
        ofxJSONElement response;
        response.open("http://localhost:3000/prices/disable/" + price_id);
        cout << response;
        price_enabled = false;
    }    
}

void Carrousel::configureRuleta(){
    ruleta.setSettings(settings, assetsManager);
}