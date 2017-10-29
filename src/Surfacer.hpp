//
//  Surfacer.hpp
//  surfaceStudy
//
//  Created by m0Rya on 2017/10/16.
//

#ifndef Surfacer_hpp
#define Surfacer_hpp

#include <stdio.h>
#include "ofApp.h"

class Surfacer{
private:
    ofMesh mesh;
    int fineness;
    int rangeValue;
    ofColor color;
    float vec = 1.0;
    
    vector<ofVec3f> point;
    
    
    
public:
    Surfacer(int _fineness, int _rangeValue);
    
    //oasobi
    float vv = 0.0;
    float jj = 0.0;
    float dd = 0.0;
    float pp = 0.0;
    
    float vecVV = 1.0;
    float vecJJ = 1.0;
    float vecDD = 1.0;
    float vecPP = 1.0;
    //
    void draw();
    void update();

    //setter
    void setFineness(int _fineness);
    void setRangeValue(int _rangeValue);
    void setColor(ofColor _color);
    
    void setMesh();
    void setPoint();
    
    void setTorusPoint();

    
    //various function
    
    double func1(float _x, float _y){
        return 100.0 * cos(double(sqrt(_x*_x + _y*_y) / 20));
    }
    
    //doesnt work
    double func2(float _x, float _y){
        return _x*_x/25 - _y*_y/9;
    }
    
    //doesnt work
    double func3(float _x, float _y){
        return (_x*_x*_x - 3*_x*_y*_y);
    }
    
    double func4(float _x, float _y){
        return 10 * cos(_x*_y/200);
    }
    
    double func5(float _x, float _y){
        //return sin(sqrt(_x*_x+_y*_y))/sqrt(_x*_x+_y*_y);
        return 3*sin(vec) * pow(cos(_x) * cos(_y), 2);
    }
    

};
#endif /* Surfacer_hpp */
