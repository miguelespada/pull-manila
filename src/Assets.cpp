//
//  Assets.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Assets.h"


Assets::Assets(){
    cout << "Constructing Assets " << endl;
}

Assets::~Assets(){
    cout << "Destroying Assets " << endl;
}

void Assets::import_price_list(){
    ofxJSONElement list;
    bOnline = list.open("http://localhost:3000/prices/list.json");
    for(int i = 0; i < list.size(); i++)
        prices.push_back(list[i].asString());
    prices.push_back("nothing");
}

void Assets::load(){
    
    import_price_list();
    
    string assets_path = settings->assetsPath();
    
    cout << "Loading assets from..." << assets_path << endl;
    
    
    string filename = assets_path + "background.png";
    background.loadImage(filename);
    cout << "Loading: " << filename << endl;
    
    filename = assets_path + "portal.png";
    portal.loadImage(filename);
    cout << "Loading: " << filename << endl;
    
    
    for(int i = 0; i < price_number(); i++){
        string filename = assets_path + "../icons/" + prices[i] + ".png";
        price_images[prices[i]].loadImage( filename );
        cout << "Loading: " << filename << endl;
        filename = assets_path + "names/" + prices[i] + ".png";
        price_captions[prices[i]].loadImage( filename );
        cout << "Loading: " << filename << endl;
        filename = assets_path + "win/" + prices[i] + ".png";
        price_winnings[prices[i]].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }
    
    for(int i = 0; i < N_LANG; i ++){
        for(int j = 0; j < N_RULES; j ++){
            string filename = assets_path + "rules/rule-" + ofToString(i) + "-" + ofToString(j) + ".png";
            rules[i][j].loadImage(filename);
            cout << "Loading: " << filename << endl;
        }
    }

    for(int i = 0; i < 2; i ++){
        string filename = assets_path + "rules/animation_" + ofToString(i) + ".png";
        background_animations[i].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }
    
    for(int i = 0; i < 1; i ++){
        string filename = assets_path + "rules/rules_background-" + ofToString(i) + ".png";
        rules_background[i].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }

    if(BACKGROUND_ANIMATIONS){
        for(int i = 0; i < 2; i ++){
            string filename = assets_path + "portal_animation_" + ofToString(i) + ".png";
            portal_animations[i].loadImage(filename);
            cout << "Loading: " << filename << endl;
        }
    }
}

int Assets::price_number(){
    return prices.size();
}

int Assets::number_of_colors(){
    return settings->back_colors.size();
}

void Assets::setSettings(Settings *s){
    settings = s;
}

