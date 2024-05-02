#pragma once

#include "ofMain.h"

#include "moonModule.h"

class moreSpace {

public:
    moreSpace();
    void draw(ofRectangle frame_, float seed_, int season_, float intensity_);
    
private:
    float theSeed;
    float yoRandom(float min_, float max_);
    
    vector<vector<ofColor>> colors;
    
    float time;
    float previousTime;
};
