//
//  generateGcode.cpp
//  surfaceStudy
//
//  Created by m0Rya on 2017/10/21.
//

#include "generateGcode.hpp"

generateGcode::generateGcode(){
}


generateGcode::generateGcode(string _name){
    fileName = _name;
    
    layerHeight = 0.15;
    extruderDiameter = 0.4;
    filamentDiameter = 1.75;
}

generateGcode::generateGcode(string _name, float _layerHeight){
    fileName = _name;
    
    layerHeight = _layerHeight;
    extruderDiameter = 0.4;
    filamentDiameter = 1.75;
}



void generateGcode::initGcode(){
    textGcode = "";
    
    textGcode += "G90\n"; //set to absolute positioning
    textGcode += "M82\n"; //set extruder to absolute mode
    textGcode += "M106 S255\n"; //fan on $$im not sure s255 work or not, so you must check
    textGcode += "M104 S" + ofToString(tempExtruder) + " T0\n"; //set extruder temperture
    textGcode += "M109 S" + ofToString(tempExtruder) + " T0\n"; //set extruder temp and wait
    textGcode += "G28\n"; //go home
    
    textGcode += "G92 E0\n"; //set position; E -> new extruder position
    textGcode += "G1 E-1.0000 F1800\n"; //retract
    
    
    
}

void generateGcode::addGcode(string code){
    textGcode += code;
    
}
void generateGcode::finishGcode(){
    
    textGcode += "G92 E0\n";
    textGcode += "G1 E-1.0000 F1800\n";
    textGcode += "M104 S0\n"; //turn off extruder
    textGcode += "M140 s0\n"; //turn off motors
    textGcode += "G28\n";
    textGcode += "M84\n"; //disable motors

}

void generateGcode::outputFile(){
    
    ofBuffer buffer = ofBuffer(textGcode);
    ofBufferToFile(fileName+".gcode", buffer);
    
    cout << "Output " << fileName << ".gcode" << endl;
    
}

void generateGcode::setFilename(string _name){
    fileName = _name;
}

void generateGcode::setLayerHeight(float _layerHeight){
    layerHeight = _layerHeight;
}

float generateGcode::calcEValue(ofVec3f point1, ofVec3f point2, float e){
    float tmpE = ((point1.distance(point2) * layerHeight * extruderDiameter)) / (PI * float(filamentDiameter/2.0) * float(filamentDiameter/2.0));
    

    return (e + tmpE);
    
}

