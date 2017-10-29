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
    
    int tempExtruder = 210;
    
    
public:
    
    generateGcode();
    generateGcode(string _name);
    
    //setter
    void setFilename(string _name);
    
    
    //
    
    void initGcode();
    void addGcode(string code);
    void finishGcode();
    void outputFile();

    
    
};
#endif /* generateGcode_hpp */
