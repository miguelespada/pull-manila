//
//  Settings.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Settings.h"

Settings::Settings(){
    cout << "Constructing Settings " << endl;
    
}
Settings::~Settings(){
    cout << "Destroying Settings " << endl;
}

void Settings::load(){
    settings.open(ofToDataPath("settings.json"));
    
    speed = settings["speed"].asInt();
    decay = settings["decay"].asFloat();
    exp_time = settings["exponential_time"].asInt();
    linear_time = settings["linear_time"].asInt();
    
    width = settings["width"].asInt();
    height = settings["height"].asInt();
    icon_size = settings["icon"].asInt();
    sleep_time = settings["sleep"].asInt();
    price_sample_x = settings["price_sample_x"].asInt();
    price_sample_y = settings["price_sample_y"].asInt();
    pace = settings["pace"].asInt();
    sleep_time = settings["sleep"].asInt();
    
    cout << "Adding background colors: " ;
    for(int i = 0; i < settings["background"].size(); i ++){
        string str = settings["background"][i].asString();
        int hex = std::strtol(str.c_str(), NULL, 16);
        back_colors.push_back(hex);
        cout << hex << " ";
    }
    cout << endl;
}


string Settings::assetsPath(){
    return ofToDataPath("assets") + "/" + ofToString(width) + "x" + ofToString(height) + "/" ;
}