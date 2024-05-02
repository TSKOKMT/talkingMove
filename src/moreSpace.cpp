#include "moreSpace.h"

//--------------------------------------------------------------
moreSpace::moreSpace() {
    
    colors.resize(4);
    for (int i = 0; i < colors.size(); i++) {
        colors[i].resize(6);
    }
    
    colors[0][0].setHex(0xfadbd9);
    colors[0][1].setHex(0xef8a9c);
    colors[0][2].setHex(0xe1dc9d);
    colors[0][3].setHex(0xfedc00);
    colors[0][4].setHex(0xb1cc32);
    colors[0][5].setHex(0x9eb5e0);
    
    colors[1][0].setHex(0x87cfdb);
    colors[1][1].setHex(0x77c498);
    colors[1][2].setHex(0xf7b000);
    colors[1][3].setHex(0x4693cc);
    colors[1][4].setHex(0x007076);
    colors[1][5].setHex(0x9c4896);
    
    colors[2][0].setHex(0xc01d3a);
    colors[2][1].setHex(0xecbd14);
    colors[2][2].setHex(0xa38bbf);
    colors[2][3].setHex(0xef771d);
    colors[2][4].setHex(0x734122);
    colors[2][5].setHex(0x292e7f);
    
    colors[3][0].setHex(0xcbcfd0);
    colors[3][1].setHex(0x3d3c40);
    colors[3][2].setHex(0xf6e4cb);
    colors[3][3].setHex(0x41643c);
    colors[3][4].setHex(0xe84d29);
    colors[3][5].setHex(0xead762);
}

//--------------------------------------------------------------
void moreSpace::draw(ofRectangle frame_, float seed_, int season_, float intensity_) {
    
    intensity_ = ofNormalize(ofGetMouseX(), 0, ofGetWidth());
    
    time += (ofGetElapsedTimef() - time) / ofLerp(12, .5, intensity_);
    
    auto unit = sqrt(frame_.width * frame_.height) / 120.;
    
    ofSetLineWidth(unit / 4.);
    
    theSeed = seed_;
    
    float radius = yoRandom(4, 24) * unit;
    float spacing = radius * 2;
    
    float weight = yoRandom(.05, .5) * radius;
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    
    ofPushStyle();
    for (int v = -10; v <= 10; v++) {
        for (int h = -10; h <= 10; h++) {
            ofSetColor(colors[season_][(int)yoRandom(0, 6)]);
            ofPushMatrix();
            ofTranslate((h + (v % 2) * .5) * spacing, v * spacing * (sqrt(3) / 2.));
            ofTranslate(ofSignedNoise(time * yoRandom(.5, 1.5) + yoRandom(0, 10000)) * radius * 2 * intensity_, ofSignedNoise(time * yoRandom(.5, 1.5) + yoRandom(0, 10000)) * radius * 2 * intensity_);
            //ofScale(1 + pow(2, yoRandom(-1, 1)) * intensity_);
            moonModule::draw(ofPoint(0, 0), radius, weight, (int)yoRandom(0, 8) / 8. * TWO_PI + ofSignedNoise(time + yoRandom(0, 10000)) * PI / 2. * intensity_);
            ofPopMatrix();
        }
    }
    ofPopStyle();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
float moreSpace::yoRandom(float min_, float max_) {
    
    theSeed += pow(PI, 7);
    
    return ofWrap(ofNoise(theSeed) * PI * 100000, min_, max_);
}
