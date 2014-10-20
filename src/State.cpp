//
//  State.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "State.h"
#include "Settings.h"
#include "Assets.h"


void State::draw_background(Carrousel *c){
    ofBackground(c->assetsManager->back_color());
}

//========================================================================


void IDLE::draw(Carrousel *c){
    draw_background(c);
    c->assetsManager->randomize_background(24, c->settings->pace);
    c->assetsManager->drawRules();
    c->assetsManager->animateRules(1, c->settings->pace);
};

void IDLE::push(Carrousel *c)
{
    c->getNextPrice();
    c->setCurrent(new STARTING());
    c->ruleta.start(c->price);
    delete this;
};


//========================================================================

STARTING::STARTING(){
}

void STARTING::draw(Carrousel *c){
    draw_background(c);
    c->assetsManager->drawRuletaArt();
    c->ruleta.draw();

    if(!c->ruleta.cancelable()){
        c->setCurrent(new RUNNING());
        delete this;
    };
};


void STARTING::push(Carrousel *c)
{
    c->setCurrent(new IDLE());
    delete this;
};


void STARTING::jump(Carrousel *c)
{
    c->setCurrent(new WINNER());
    delete this;
};

//========================================================================


void RUNNING::draw(Carrousel *c){
    draw_background(c);
    c->assetsManager->drawRuletaArt();
    c->ruleta.draw();
    
    if(c->ruleta.has_stopped()){
        ofSleepMillis(c->settings->sleep_time);
        c->setCurrent(new WINNER());
        c->disableCurrentPrice();
        delete this;
    }
};

void RUNNING::push(Carrousel *c)
{
};

//========================================================================

WINNER::WINNER(){
    timer = ofGetElapsedTimeMillis();
}

void WINNER::draw(Carrousel *c){
    draw_background(c);
    c->assetsManager->drawWinner(c->price);

    if((ofGetElapsedTimeMillis() - timer) > c->settings->sleep_time * 4){
        c->setCurrent(new IDLE());
        delete this;
    }
};

void WINNER::push(Carrousel *c)
{
};