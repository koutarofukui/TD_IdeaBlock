//
//  ofCustomVertexFan.cpp
//  ofVertex
//
//  Created by koutaro fukui on 12/11/13.
//
//

#include "ofxArchVertexFan.h"



ofxArchVertexFan::ofxArchVertexFan(int _division, float _r, float _thickdepth, ofColor _color, float _vertexNum, int _drawStartDeg, float _x, float _y, float _depth, float _time, int _startTime, float _rotateX, float _rotateY, int _mode, bool _fill){
    
    division = _division;
    r = _r;
    thickdepth = _thickdepth;
    color = _color;
    vertexNum = _vertexNum; //61 will be complete circle
    
    xPos = _x;
    yPos = _y;
    
    drawStartDeg = _drawStartDeg;
    depth = _depth;
    posMov = 0;
    fill = _fill;
    
    time = _time;
    
    startTime = _startTime;
    mode =_mode;
    
    font.loadFont("verdana.ttf", 60);
    float num = 0;
    lifeTimeNum.text = num;
    std::ostringstream buffer;
    buffer << num;
    std::string str = buffer.str();
    //lifeTimeNum.rect = font.getStringBoundingBox(str, 0, 0);
    
    
    rotateX = _rotateX;
    rotateY = _rotateY;
}

void ofxArchVertexFan::update(){
//    if (posMov < 360) {
//        posMov = posMov + 0.25;
//    }
//    else{
//        posMov = 0;
//    }
    
//        msCounter = int(ofGetElapsedTimeMillis() - startTime);
//    if (msCounter >= time) {
//        startTime = msCounter;
//    }
    if (msCounter <= time) {
       msCounter = int(ofGetElapsedTimeMillis() - startTime);
    }
    

    //cout << vertexNum << endl;
    
    
}

void ofxArchVertexFan::draw(){
    ofPushMatrix();
    //ofRotateX(rotateX);
    ofTranslate(xPos, yPos);
    ofRotateY(rotateY);
    
    vertexNum = (division+1) - round(ofMap(msCounter, 0, time, 1, division+1));
    ofRotate(drawStartDeg);
    //
    if(fill == true){
        ofFill();
    }else{
        ofNoFill();
    }
    ofSetPolyMode(OF_POLY_WINDING_POSITIVE);

    float step =  360/ division;
    float xPos[(division+1)*2];
    float yPos[(division+1)*2];
    
    //int vertexNum = 0;

    //vertexNum = 45;
    for (int i = 0; i < vertexNum*2; i++) {
        if (i < vertexNum) {
            //cout << i << endl;
            xPos[i] = cos(ofDegToRad(i * step + posMov)) * r;
            yPos[i] = sin(ofDegToRad(i * step + posMov)) * r;
        }
        if (i >= vertexNum) {
            //change here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //cout << num*2 - i -1 << endl;
            xPos[i] = cos(ofDegToRad( (vertexNum*2 - i -1) * step + posMov)) * (r - thickdepth);
            yPos[i] = sin(ofDegToRad( (vertexNum*2 - i -1) * step + posMov)) * (r - thickdepth);
        }
    }
    
    
    ofSetColor(color);
    ofBeginShape();
    
    for (int i = 0; i < round(vertexNum)*2; i++) {
        ofVertex(xPos[i],yPos[i], depth);
    }
    ofEndShape();
    
    //outline circle
    ofSetCircleResolution(60);
    
    ofPushMatrix();
    if(mode == 1){
        ofSetColor(255, 255, 255, 255 * powf(ofMap(vertexNum, 0, time, 0, 1.0), 0.125));
        ofNoFill();
        ofCircle(0, 0,depth, r);
        ofCircle(0, 0,depth, r - thickdepth);
        
        float num = ofMap(vertexNum, 0, time, 0, 1.0);
        
        std::ostringstream buffer;
        buffer << num;
        std::string str = buffer.str();
        lifeTimeNum.text = str;
        //lifeTimeNum.rect = font.getStringBoundingBox(str, -r, -r);
        
        ofPushMatrix();
        ofTranslate(0, 0, depth);
        //ofRotateX(180);
        ofSetColor(255, 255, 255, 255 * powf(ofMap(vertexNum, 0, time, 0, 1.0), 0.005));
        font.drawString(lifeTimeNum.text, -(r+r/2), r);
        ofPopMatrix();
    }
    ofPopMatrix();
    
    ofPopMatrix();
    
    
    
}

void ofxArchVertexFan::setVertexNum(float _vNum){
    vertexNum = _vNum;
}

float ofxArchVertexFan::getVertexNum(){
    return vertexNum;
}
void ofxArchVertexFan::setTweenTime(float _time){
    time = _time;
}

float ofxArchVertexFan::getTweenTime(){
    return time;
}

