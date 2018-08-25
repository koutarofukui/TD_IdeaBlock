//
//  ofxArchVertexFan.h
//  ofVertex
//
//  Created by koutaro fukui on 12/11/13.
//
//
#pragma once

#ifndef __ofVertex__archVertexFan__
#define __ofVertex__archVertexFan__

#include "ofMain.h"
#include <sstream>

class ofxArchVertexFan {

    public:
        void update();
        void draw();
        void setVertexNum(float _vNum);
        float  getVertexNum();
        void setTweenTime(float _time);
        float  getTweenTime();
        //constractor
        ofxArchVertexFan(int _division, float _r, float _thickdepth, ofColor _color, float _vertexNum, int _drawStartDeg, float _x, float _y, float _depth, float _time, int startTime,  float _rotateX, float _rotateY, int mode, bool _fill);
    
    

    
        //variable
    private:
        int division;
    float xPos;
    float yPos;
        float r;
        float thickdepth;
        float vertexNum;
        int drawStartDeg;
        float depth;
        ofColor color;
        float posMov;
        bool fill;
        float time;
        int startTime;
        int mode;
    
    float msCounter;
    
    float rotateX;
    float rotateY;
    
    ofTrueTypeFont font;
    
    struct S{
        string text;
        int r, g, b, x, y;
        ofRectangle rect;
    };
    S lifeTimeNum;
    

    

};

#endif /* defined(__ofVertex__ocustomVertexFan__) */
