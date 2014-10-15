//
//  State.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __carrousel__State__
#define __carrousel__State__

#include "Carrousel.h"
#include "ofMain.h"
#include "AssetsManager.h"

class State
{
public:
    virtual void push(Carrousel *c) =0;
    
    virtual void jump(Carrousel *c) {};
    virtual std::string toString() {
        return "base";
    }
    
    virtual void draw(Carrousel *c){}
    virtual void draw_background(Carrousel *c);
    
};

class IDLE: public State
{
public:
    
    
    IDLE(){};
    ~IDLE(){};
    
    void push(Carrousel *c);
    
    std::string toString() {
        return "idle";
    }
    void draw(Carrousel *c);
};

class STARTING: public State
{
public:
    STARTING();
    ~STARTING(){};
    
    void push(Carrousel *c);
    void jump(Carrousel *c);
    
    std::string toString() {
        return "starting";
    }
    void draw(Carrousel *c);
};

class RUNNING: public State
{
public:
    RUNNING(){};
    ~RUNNING(){};
    
    void push(Carrousel *c);
    
    std::string toString() {
        return "running";
    }
    void draw(Carrousel *c);
};

class WINNER: public State
{
public:
    WINNER();
    ~WINNER(){};
    
    float timer;
    void push(Carrousel *c);
    
    std::string toString() {
        return "winner";
    }
    void draw(Carrousel *c);
};

#endif /* defined(__carrousel__State__) */
