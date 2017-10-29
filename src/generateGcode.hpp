//
//  generateGcode.hpp
//  surfaceStudy
//
//  Created by m0Rya on 2017/10/21.
//

#ifndef generateGcode_hpp
#define generateGcode_hpp

#include <stdio.h>
#include <ofApp.h>

class generateGcode{
private:
    string fileName;
    string textGcode;
    
    float layerHeight;
    float extruderDiameter;
    float filamentDiameter;

    int tempExtruder = 190;
    
    
public:
    
    generateGcode();
    generateGcode(string _name);
    generateGcode(string _name, float _layerHeight);
    
    //setter
    void setFilename(string _name);
    void setLayerHeight(float _layerHeight);
    
    //
    
    void initGcode();
    void addGcode(string code);
    void finishGcode();
    void outputFile();
    float calcEValue(ofVec3f point1, ofVec3f point2, float e);

    
    
};
#endif /* generateGcode_hpp */
