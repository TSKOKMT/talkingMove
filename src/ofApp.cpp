#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetWindowShape(ofGetScreenWidth() * (16 / 18.), ofGetScreenWidth() / 2.);
    ofSetWindowPosition((ofGetScreenWidth() - ofGetWidth()) / 2., (ofGetScreenHeight() - ofGetHeight()) / 2.);
    ofBackground(0);
    ofSetCircleResolution(128);
    ofSetLineWidth(4);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle("Talking Move | " + ofToString(round(ofGetFrameRate())));
}

//--------------------------------------------------------------
void ofApp::draw(){

    auto frame = ofGetWindowRect();
    
    auto time = ofGetElapsedTimef();
    
    auto unit = sqrt(frame.width * frame.height) / 120.;
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(255);
    ofDrawRectangle(frame);
    
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    moreSpace.draw(frame, seed, seed % 4, 1);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    seed++;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
