#include "moonModule.h"

//--------------------------------------------------------------
void moonModule::draw(ofPoint center_, float radius_, float weight_, float angle_) {
    
    int resolution = 128;
    
    ofPushMatrix();
    ofTranslate(center_);
    ofRotateRad(angle_ + HALF_PI);
    //ofTranslate(-radius_, 0);
    ofBeginShape();
    for (int j = 0; j <= resolution; j++) {
        float theAngle = j / (float)resolution * PI;
        ofVertex(cos(theAngle) * radius_, sin(theAngle) * radius_);
    }
    for (int j = 0; j <= 128; j++) {
        float theAngle = (1 - j / (float)resolution) * PI;
        ofVertex(cos(theAngle) * (radius_ - weight_), sin(theAngle) * (radius_ - weight_));
    }
    ofEndShape(true);
    ofPopMatrix();
}
