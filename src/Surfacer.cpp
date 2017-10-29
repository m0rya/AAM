//
//  Surfacer.cpp
//  surfaceStudy
//
//  Created by m0Rya on 2017/10/16.
//

#include "Surfacer.hpp"


Surfacer::Surfacer(int _fineness, int _rangeValue){
    fineness = _fineness;
    rangeValue = _rangeValue;
    
    setMesh();
    
}

void Surfacer::setPoint(){
    
    vec += 0.1;
    
    point.clear();
    
    for(int i=0; i<(fineness+1); i++){
        for(int j=0; j<(fineness+1); j++){

            float x = float(-rangeValue + j * 2.0 * rangeValue / fineness);
            float y = float(-rangeValue + i * 2.0 * rangeValue / fineness);
            
            float z = func5(x, y);
            
            //hoge
            x *= 100;
            y *= 100;
            z *= 100;
            
            point.push_back(ofVec3f(x, z, y));

        }
    }
}



void Surfacer::setTorusPoint(){
    mesh.clear();
    point.clear();
    
    for(int i=0; i<(fineness+1); i++){
        for(int j=0; j<(fineness+1); j++){
            float s = float(2.0*PI/fineness * i);
            float t = float(2.0*PI/fineness * j);
            
            float x = float(((3.0+vv) + cos(s)) * cos(t));
            float y = float(((3.0+jj) + cos(s)) * sin(t));
            float z = float(sin(s) + (0.5 + dd)*sin(5*t));
            
           /*
            x = float(((5+vv)-0.3*t + 1.2 * cos(s)) * cos(t));
            y = float(((5+jj)-0.3*t + 1.2 * cos(s)) * sin(t));
            z = float((1.2+dd) * sin(s) + 0.3 * t);
            */
            
            x *= 70;
            y *= 70;
            z *= 70;
            
            point.push_back(ofVec3f(x, y, z));
        }
    }
}


void Surfacer::setMesh(){
    mesh.clear();
    
    //setPoint();
    setTorusPoint();
    
    for(int i=0; i<(fineness+1); i++){
        for(int j=0; j<(fineness+1); j++){
            mesh.addVertex(point[i*(fineness+1) + j]);
            mesh.addNormal(ofVec3f(0, -1.0, 0));
            mesh.addColor(color);
        }
    }
    
    for(int i=0; i<fineness; i++){
        for(int j=0; j<fineness; j++){
            mesh.addIndex(i*(fineness+1) + j);
            mesh.addIndex(i*(fineness+1) + j + 1);
            mesh.addIndex((i+1) * (fineness+1) + j);
            
            mesh.addIndex(i*(fineness+1) + j + 1);
            mesh.addIndex((i+1)*(fineness+1) + j);
            mesh.addIndex((i+1) * (fineness+1) + j + 1);
        }
    }
    
}

void Surfacer::update(){
    if(vv > 10){
        vecVV = -1.0;
    }else if(vv< -10){
        vecVV = 1.0;
    }
    
    if(jj > 10){
        vecJJ= -1.0;
    }else if(jj < -10){
        vecJJ= 1.0;
    }
    
    if(dd > 3){
        vecDD= -1.0;
    }else if(dd < -3){
        vecDD= 1.0;
    }
    if(pp > 3){
        vecPP= -1.0;
    }else if(pp < -3){
        vecPP= 1.0;
    }
    
    vv += vecVV/2.0;
    jj += vecJJ/2.5;
    dd += vecDD/2.0;
    setMesh();
}

void Surfacer::draw(){
    //mesh.draw();
    mesh.drawWireframe();
}


void Surfacer::setFineness(int _fineness){
    fineness = _fineness;
}

void Surfacer::setRangeValue(int _rangeValue){
    rangeValue = _rangeValue;
}

void Surfacer::setColor(ofColor _color){
    color = _color;
}


