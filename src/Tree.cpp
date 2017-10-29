//
//  Tree.cpp
//  surfaceStudy
//
//  Created by m0Rya on 2017/10/29.
//

#include "Tree.hpp"

Tree::Tree(){
    width = 30;
    baseHeight = 30;
    
    angle1 = 45;
    angle2 = 45;
    
}


void Tree::buildBranch(){
    //main branch
    
    treeMesh.addVertex(ofVec3f(width, width, 0));
    treeMesh.addVertex(ofVec3f(-width, width, 0));
    treeMesh.addVertex(ofVec3f(-width, -width, 0));
    treeMesh.addVertex(ofVec3f(width, -width, 0));
    
    treeMesh.addVertex(ofVec3f(width, width, baseHeight));
    treeMesh.addVertex(ofVec3f(-width, width, baseHeight));
    treeMesh.addVertex(ofVec3f(-width, -width, baseHeight));
    treeMesh.addVertex(ofVec3f(width, -width, baseHeight));
    
    point.push_back(ofVec3f(width, width, 0));
    point.push_back(ofVec3f(-width, width, 0));
    point.push_back(ofVec3f(-width, -width, 0));
    point.push_back(ofVec3f(width, -width, 0));
    for(int i=0; i<4; i++){
        point.push_back(ofVec3f(point[i].x, point[i].y, point[i].z + baseHeight));
    }
    
    ofVec3f tmp = point[0].getInterpolated(point[1], 0.2);
    
    tmp.z += 10 + baseHeight;
    
    point.push_back(tmp);
    point.push_back(ofVec3f(tmp.x, tmp.y -width*2, tmp.z));
    

    

    

    
    
    
}

void Tree::draw(){

    for(int i=0; i<point.size(); i++){
        ofSetColor(255, 0, 0);
        ofDrawBox(point[i].x, point[i].y, point[i].z, 1.0);
    }
    
}
