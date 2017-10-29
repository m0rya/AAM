//
//  Tree.hpp
//  surfaceStudy
//
//  Created by m0Rya on 2017/10/29.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <ofApp.h>

class Tree{
private:
    float width;
    float baseHeight;
    
    int angle1;
    int angle2;
    
    ofMesh treeMesh;
    
    vector<ofVec3f> point;
public:
    
    Tree();
    
    void buildBranch();
    void draw();
    
    
};

#endif /* Tree_hpp */
