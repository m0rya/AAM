#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Surfacer.hpp"
#include "generateGcode.hpp"
#include "Tree.hpp"

class ofApp : public ofBaseApp{
    

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    void generateGcode();
    void generateGcode2();
    void generateTuno();
    void generateOrnament();
    
    
    void generateAngleTest();
    
    void generateTestGcode();
    
    
    string fixDigit(float originNum, int digit);
    
    
    ofxPanel gui;
    ofxFloatSlider para1;
    ofxFloatSlider para2;
    ofxIntSlider para3;

    ofxIntSlider para4;
    ofxIntSlider para5;
    
    ofxIntSlider finenessSphere;
    ofxIntSlider posX;
    ofxIntSlider posY;
    ofxIntSlider radiusOfTuno;
    ofxIntSlider radiusHalfSphere;
    ofxIntSlider heightOfTuno;
    ofxIntSlider tes;
    ofxIntSlider decreasing;
    
    //ornament gui
    ofxIntSlider ornamentRadius;
    ofxIntSlider heightOrnament;
    ofxFloatSlider insideRadius;
    ofxIntSlider decreasingOrnament;
    
    
    
    ofxIntSlider para6;
    ofxIntSlider para7;

    void setMesh();
    double func(float _x, float _y);
    
    void setMeshPolar();
    ofVec3f polar(float r, float theta, float fi);
    
    ofVboMesh mesh;
    ofMesh polarMesh;
    ofMesh polarWire;
    
		
    ofEasyCam cam;
    ofLight pointlight;
    
    
    //Surfacer
    
};
