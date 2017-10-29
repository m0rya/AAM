#include "ofApp.h"

ofMesh mesh;
int para = -100;
float vecPara = 1;
int v = 1;

const int ind = 250;
int range = 1500;

int counter = 0;


float vForPolar = 1.0;
float vForPolar2 = 1.0;
float vsForPolar = 1.0;

Surfacer surfacer(100, 5);
vector<ofVec3f> debugPoint;



//Gcode
generateGcode gcoder("tuno");

string gcodeText = "";
vector<ofVec3f> points;
vector<ofVec3f> newPoint;
vector<ofVec3f> tuno;
vector<ofVec3f> ornament;
generateGcode ornamentGcoder("ornament");


//angleTest
ofMesh baseObj;
vector<ofVec3f> angleTest;


//testGcode;-
vector<ofVec3f> testGcode;
generateGcode testGcoder("testGcode");


//Tree

Tree tree = Tree();


//--------------------------------------------------------------
void ofApp::setup(){
    
    //debug
    debugPoint.clear();
    
    //debug
    ofSetVerticalSync(true);
    ofBackground(256);
    
    gui.setup();
    /*
    gui.add(para1.setup("para1", 1.0, 0.1, 5.0));
    gui.add(para2.setup("para2", 0.0, -10.0, 10.0));
    gui.add(para3.setup("para3", 0, -10, 10));
    gui.add(para4.setup("para4", 1, -10, 10));
    gui.add(para5.setup("para5", 2, -10, 10));
    gui.add(para6.setup("para6", 0, 0, 49));
    gui.add(para7.setup("para7", 0, 0, 101));
     */
    
    gui.add(finenessSphere.setup("fineness Sphere", 100, 1, 500));
    gui.add(posX.setup("pos x", 0, 0, 50));
    gui.add(posY.setup("pos y", 50, 0, 100));
    /*
    gui.add(radiusOfTuno.setup("radius Tuno", 5, 1, 10));
    gui.add(radiusHalfSphere.setup("radius half sphere", 20, 5, 40));
    gui.add(heightOfTuno.setup("height of Tuno", 100, 10, 300));
    gui.add(tes.setup("tes", 0, 0, 500));
    gui.add(decreasing.setup("decreasing", 5, 1, 10));
     */
    
    //ornament gui
    gui.add(ornamentRadius.setup("ornament radius", 15, 5, 30));
    gui.add(heightOrnament.setup("height of ornament", 10, 5, 30));
    gui.add(insideRadius.setup("radius of inside ornament", 1, 1, 10));
    gui.add(decreasingOrnament.setup("decreasing ornament", 5, 0, 20));

    
    
    ofEnableDepthTest();
    ofEnableSmoothing();
    ofSetFrameRate(24);
    
    //lighing
    pointlight.setSpotlight();
    pointlight.setDirectional();
    pointlight.setAmbientColor(ofFloatColor(0.5, 0.2, 0.2, 1.0));
    pointlight.setDiffuseColor(ofFloatColor(.86, .85, .55));
    pointlight.setSpecularColor(ofFloatColor(1.f, 1.f, 1.f));
    
    ofVec3f lightPos = ofVec3f(-40, 60, 600);
    pointlight.setPosition(lightPos);
    pointlight.enable();
    
    //setMesh();
    //surfacer.setMesh();
    //surfacer.setColor(ofColor(255, 0, 0));
    setMeshPolar();
    //generateGcode();
    //generateTuno();
    //generateGcode2();

    
    //Tree
    //tree.buildBranch();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    /*
    vForPolar += 0.1;
    vForPolar2 += 0.05;
    
    vsForPolar = 30*sin(ofGetFrameNum()/60);
    
    if(para > 230){
        v = -1;
    }else if(para < -230){
        v = 1;
    }

    vecPara = ofMap(abs(para), 0, 300, 2, 10);

    para += vecPara*v;
    
    if(counter %3 == 0 || counter%3 == 1){
        setMesh();
        
    }else if(counter % 3 == 2){
        surfacer.setColor(ofColor::fromHsb(ofGetFrameNum() % 256, 255, 255));
        surfacer.update();
    }
    
     */
    
    setMeshPolar();
    //generateTuno();
    generateOrnament();
    

    //generateTestGcode();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableDepthTest();
    ofBackground(0);

    ofEnableLighting();
    ofDisableLighting();

    
    cam.begin();
    
    ofSetLineWidth(0.01);
    
    /*
    if(counter %3 == 2){
        
        for(int i=0; i<3; i++){
            ofSetColor(255, 0, 0);
            ofPushMatrix();
            ofRotateZ(360/3 * i);
            surfacer.draw();
            //ofPopMatrix();
            
            ofPushMatrix();
            ofRotateY(360/3 * i);
            surfacer.draw();
            //ofPopMatrix();
 
            
            ofPushMatrix();
            ofRotateX(360/3 * i);
            surfacer.draw();
            ofPopMatrix();
        }
    }else{
        mesh.drawWireframe();
    }
     */

    //polarMesh.draw();
    //polarWire.drawWireframe();
    
    
    /*
    ofDrawSphere(debugPoint[posX * (finenessSphere +1) + posY].x, debugPoint[posX * (finenessSphere + 1) + posY].y, debugPoint[posX * (finenessSphere + 1) + posY].z, 5);

     */

    //generateOrnament
    
    ofSetColor(255);
    for(int i=0; i<debugPoint.size(); i++){
        ofDrawBox(debugPoint[i].x, debugPoint[i].y, debugPoint[i].z, 0.1);
    }


    ofSetColor(0, 0, 255);
    
    //for(int i=0; i<tuno.size(); i++){
    //    ofDrawBox(tuno[i].x, tuno[i].y, tuno[i].z, 0.1);
    //}

    for(int i=0; i<ornament.size()-1; i++){
       ofDrawBox(ornament[i].x, ornament[i].y, ornament[i].z, 0.1);
    }

    //ofSetColor(ofColor(0, 255, 0));
    //ofDrawBox(tuno[tes].x, tuno[tes].y, tuno[tes].z, 0.1);
    
    
    
    
    //generate angle test
    /*
    generateAngleTest();
    baseObj.drawWireframe();
    //generateAngleTest();
    
    ofSetColor(ofColor(255, 0, 0));
    cout << angleTest.size() << endl;
    
    for(int i=0; i<angleTest.size()/4; i++){
        ofDrawBox(angleTest[i].x, angleTest[i].y, angleTest[i].z, 0.1);
        ofDrawLine(angleTest[4*i], angleTest[4*i+1]);
        ofDrawLine(angleTest[4*i+1], angleTest[4*i+2]);
        ofDrawLine(angleTest[4*i+2], angleTest[4*i+3]);
        ofDrawLine(angleTest[4*i+3], angleTest[4*i]);
    }
     
     */
    /*
    ofSetColor(255, 0, 0);
    cout << testGcode.size() << endl;
    for(int i=0; i<testGcode.size(); i++){
        ofDrawBox(testGcode[i].x, testGcode[i].y, testGcode[i].z, 0.5);
    }
    */
    
    
    //Tree
    //tree.draw();
    
    
    cam.end();
    ofDisableDepthTest();
    gui.draw();
    

}



//--------------------------------------------------------------

void ofApp::generateTestGcode(){
    
    float heightTest = 0.15;
    ofVec3f upper = ofVec3f(0, 0, 1.0);
    float zOffset = 2.5;
    
    testGcode.clear();
    
    vector<ofVec3f> basePoint;
    
    
  
    for(int j=0; j<5; j++){
            
        for(int k=0; k<180; k+=1){
            testGcode.push_back(ofVec3f(float(10/180.0) * k + j*10, 0, 5*sin(ofDegToRad(k))));
            //basePoint.push_back(ofVec3f(foat(10/180.0) * k + j*10, 0, 5*sin(ofDegToRad(k))) + upper*i);
        }
    }
    

    testGcoder.initGcode();
    string tmpGcode = "G1 Z50 F1800\n";
    
    tmpGcode += "G1 X" + ofToString(testGcode[0].x) + " Y" + ofToString(testGcode[0].y) + " F1800\n";
    tmpGcode += "G1 Z" + ofToString(testGcode[0].z + zOffset) + " F1800\n";
    tmpGcode += "T0\n";
    testGcoder.addGcode(tmpGcode);
    
    float e=0.0;
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5*180; j++){
            
            if(i%2 == 0){
                if(j == 0){
                    e += 0;
                }else{
                    e = testGcoder.calcEValue(testGcode[j-1], testGcode[j], e);
                }
                
                tmpGcode = "G1 X" + ofToString(testGcode[j].x) + " Y" + ofToString(testGcode[j].y) + " Z" + ofToString(testGcode[j].z + zOffset + heightTest*i) + " E" + ofToString(e) + " F350\n";
                
                
            }else if(i%2 == 1){
                if(j == 0){
                    e += 0;
                }else{
                    e = testGcoder.calcEValue(testGcode[5*180-j], testGcode[5*180-j-1], e);
                }
                
                tmpGcode = "G1 X" + ofToString(testGcode[5*180-j-1].x) + " Y" + ofToString(testGcode[5*180-j-1].y) + " Z" + ofToString(testGcode[5*180-j-1].z + zOffset + heightTest*i) + " E" + ofToString(e) + " F350\n";
            }
            
            testGcoder.addGcode(tmpGcode);
            
            
            
        }
    }
    
    /*
    for(int i=0; i<5; i++){
        
        for(int j=0; j<5; j++){
            for(int k=0; k<180; k+=1){
                
                
                if(i%2 == 0){
                    if(j == 0){
                        e += 0;
                    }else{
                        //e += float(testGcode[k+j*180].distance(testGcode[k+j*180-1])/0.223 * 0.006);
                        e = testGcoder.calcEValue(testGcode[k+j*180-1], testGcode[k+j*180], e);
                    }
                    
                    tmpGcode = "G1 X" + ofToString(testGcode[k + j*180].x) + " Y" + ofToString(testGcode[k+j*180].y) + " Z" + ofToString(testGcode[k+ j*180].z + zOffset + heightTest*i) + " E" + ofToString(e) + " F600\n";

                }else if(i%2 == 1){
                    if(j == 0){
                        e += 0;
                    }else{
                        e = testGcoder.calcEValue(testGcode[(j+1)*180] - k], testGcode[(j+1)*180 - (k+1)], e);
                    }
                    
                    tmpGcode = "G1 X" + ofToString(testGcode[(j+1)*180-k].x) + " Y" + ofToString(testGcode[(j+1)*180 -k].y)) + " Z" + ofToString(testGcode[(j+1)*180)

                    
                    
                    
                }
                
                testGcoder.addGcode(tmpGcode);

                
            }
        }
    }
    */
    
    testGcoder.finishGcode();
    testGcoder.outputFile();
    
    
}
//--------------------------------------------------------------

void ofApp::generateAngleTest(){
    
    //base Object
    float width = 60;
    
    ofVec3f baseObject[6];
    
    baseObject[0] = ofVec3f(-30, 30, 0);
    baseObject[1] = ofVec3f(-30, -30, 0);
    baseObject[2] = ofVec3f(-2.62, -30.0, 32.62);
    baseObject[3] = ofVec3f(-2.62, 30.0, 32.62);
    baseObject[4] = ofVec3f(30, -30, 0);
    baseObject[5] = ofVec3f(30, 30, 0);
    
    for(int i=0; i<6; i++){
        baseObj.addVertex(baseObject[i]);
        baseObj.addColor(ofColor(255));
    }
    
    int ind[6][3] = {{0,1,2}, {0,2,3}, {2,4,5}, {2,5,3}, {1,4,2}, {0,3,5}};
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            baseObj.addIndex(ind[i][j]);
        }
    }
    
    int heightTest = 5;
    
    ofVec3f normalForMesh = (baseObject[3]-baseObject[2]).getPerpendicular(baseObject[4]-baseObject[2]);
    
    normalForMesh.normalize();
    normalForMesh *= -1;
    
    angleTest.clear();
    for(float i; i<heightTest; i+=0.15){
        ofVec3f tmp = normalForMesh * i;

        angleTest.push_back(baseObject[3] + tmp);
        angleTest.push_back(baseObject[2] + tmp);
        angleTest.push_back(baseObject[4] + tmp);
        angleTest.push_back(baseObject[5] + tmp);
        

    }


    

    

    
    
    
    
}
//--------------------------------------------------------------

void ofApp::generateOrnament(){
    
    ornament.clear();
    
    
    //ornament will be added to basePoint of half Sphere
    ofVec3f basePoint = debugPoint[posX*(finenessSphere+1) + posY];
    
    const int fineness = 360;
    ofVec3f baseOrnament[(fineness+1)];
    
    
    //radius of ornament
    int radius = ornamentRadius;
    //radius of sin wave
    int inRadius = insideRadius;
    
    //height of ornament
    int heightOfOrnament = heightOrnament;
    //offset is layer height
    float offset = 0.15;
   
    //for rotating
    float angleForRotate = ofVec3f(0, 0, 1).angle(basePoint);
    ofVec3f axisVec = ofVec3f(0,0,1).getPerpendicular(basePoint);
    
    
    //for layering
    ofVec3f tmpAxis = basePoint;
    basePoint.normalize();
    
    //create ornament layer
    for(float j=0; j<heightOfOrnament - offset; j+=offset){
        
        for(int i=0; i<(fineness+1); i++){
            
            float angle = float(float(360.0/fineness) * i) + float(j*decreasingOrnament);
            float tmpRadius = radius * float((heightOfOrnament-j)/heightOfOrnament);
            
            ofVec3f tmp = ofVec3f(tmpRadius * cos(ofDegToRad(angle)), tmpRadius * sin(ofDegToRad(angle)), 120);
            ofVec3f baseVec = ofVec3f(0,0,120) - tmp;
            baseVec.normalize();
            tmp += baseVec * inRadius * sin(ofDegToRad(360/30 * (i%30)));
            int baseSphereRadius = 100;
            tmp *= float(baseSphereRadius/tmp.length());
            
            
            tmp.rotate(angleForRotate, axisVec);
            tmp += basePoint * j;
            ornament.push_back(tmp);
            
        }
    }
}
//--------------------------------------------------------------
void ofApp::generateTuno(){
    tuno.clear();
    
    const int fineness = 180;
    
    ofVec3f base = debugPoint[posY * finenessSphere + posX];
    ofVec3f offset = base.normalize();
    offset *= 0.15;

    ofVec3f firstPerpen = ofVec3f(base.y, -base.x, 0);
    firstPerpen.normalize();
    firstPerpen *= float(float(radiusOfTuno)/10.0);
    
    cout << firstPerpen.length() << endl;
    //radius

    
    ofVec3f baseCircle[fineness];
    for(int i=0; i<fineness; i++){
        firstPerpen.rotate(360/fineness, base);
        ofVec3f tmp = base + firstPerpen;
        float dist = ofVec3f(0, 0, 0).distance(tmp);
        tmp = tmp*(radiusHalfSphere/dist);
        
        baseCircle[i] = tmp;
    }
    
    for(int i=0; i<heightOfTuno; i++){
        
        for(int j=0; j<fineness; j++){
            
            ofVec3f result = baseCircle[j];
            
            firstPerpen.rotate(360/fineness, base);
            ofVec3f decreaseVec = (firstPerpen * -1);
            decreaseVec.normalize();
            //decreaseVec *= float(float(radiusOfTuno/heightOfTuno) * i);
            decreaseVec *= ((float(i)/float(heightOfTuno)) * decreasing);
            //decreaseVec *= 0.5;

            
            result += decreaseVec;
            
            result += (offset * i);
            tuno.push_back(result);
        }
    }
    
    
    /*
    for(int j=0; j<heightOfTuno; j++){
        
        for(int i=0; i<fineness; i++){
        
            firstPerpen.rotate(2, base);
            ofVec3f tmp = base+firstPerpen;
        
            float dist = ofVec3f(0, 0, 0).distance(tmp);
            tmp = tmp*(radiusHalfSphere/dist);
            
        
            tuno.push_back(tmp + offset*j);
        }
        
        base *= 1.03;
    }
     */
    
    
    //generateGcode
    offset = base.normalize();
    offset *= 0.15;
    
    float zOffset = 2.8;
    
    //gcoder.setFilename("tuno");
    gcoder.initGcode();
    
    string tmp = "G1 Z50 F1800\n";
    
    

    tmp += "G1 X" + fixDigit(float(tuno[0].x + offset.x), 3) + " Y" + fixDigit(float(tuno[0].y + offset.y), 3) + " F1800\n";
    tmp += "G1 Z" + fixDigit(float(tuno[0].z + offset.z + zOffset), 3) + " F1800\n";
    tmp += "T0\n";
    gcoder.addGcode(tmp);
    
    
    for(int j=0; j<heightOfTuno; j++){
        
        tmp = "; layer " + ofToString(j) + "\n";
        gcoder.addGcode(tmp);
        
        for(int i=0; i<fineness; i++){
            
            ofVec3f humpty = tuno[j*fineness + i];
            humpty += offset;
            
            //tmp = "E92 E0\n";
            tmp = "G1 X" + fixDigit(float(humpty.x), 3) + " Y" + fixDigit(float(humpty.y), 3) + " Z" + fixDigit(float(humpty.z + zOffset), 3);
            
            
            if(i == 0){
                tmp += " F1800\n";
            }else if(i == 1){
                //tmp += " E3.1234";
                tmp += " E" + ofToString(float(i/170.0 + fineness*j/170.0));
                tmp += " F800\n";

            }else{
                //tmp += " E0.5123\n";
                tmp += " E" + ofToString(float(i/170.0 + fineness*j/170.0)) + "\n";
            }
            
            gcoder.addGcode(tmp);
        }
    }

    
    
    gcoder.finishGcode();
    gcoder.outputFile();
}


//--------------------------------------------------------------


string ofApp::fixDigit(float originNum, int digit){
    string result = ofToString(originNum);

    int index = 0;
    for(int i=0; i<result.size(); i++){
        if(result[i] == char('.')){
            index = i;
            break;
        }
    }
    
    return result.substr(0, index+digit+1);
}
void ofApp::generateGcode(){
    int toggleCount = 1;
    
    for(int i=49; i>0; i--){
        for(int j=0; j<101; j++){
            
            if(j==0){

                //gcodeText += ("G1 X" + ofToString(debugPoint[i*101 + j].x) + " Y" + ofToString(debugPoint[i*101 + j].y) + " Z" + ofToString(debugPoint[i*101 + j].z -3.14107 + 2.98) + " F1800\n");
                gcodeText += ("G1 X" + ofToString(50 + debugPoint[i*101 + j].x) + " Y" + ofToString(50 + debugPoint[i*101 + j].y) + " Z" + ofToString(debugPoint[i*101 + j].z -3.14107 + 2.98) + " F1800\n");
                continue;
            }
           
            float dist = debugPoint[i*101 + j].distance(debugPoint[i*101 + j -1]);
            //z -3.14107 = 0;
            //z offset 2.8 + (layersou/2 = 0.1)
            //z offset 2.8 + 0.18
            //
            float e = dist/0.887 * 50;
            
            //gcodeText += ("G1 X" + ofToString(debugPoint[i*101 + j].x) + " Y" + ofToString(debugPoint[i*101 + j].y) + " E" + ofToString(e) + "\n");
            gcodeText += ("G1 X" + ofToString(50 + debugPoint[i*101 + j].x) + " Y" + ofToString(50 + debugPoint[i*101 + j].y) + " E" + ofToString(e) + "\n");

        }
    }
     
    for(int j=0; j<101; j++){
        for(int i=0; i<50; i++){
            
            /*
            if(i == 0){
                if(toggleCount == 1){
                    
                    gcodeText += ("G1 X" + ofToString(50 + debugPoint[i*101 + j].x) + " Y" + ofToString(50 + debugPoint[i*101 + j].y) + " Z" + ofToString(debugPoint[i*101 + j].z -3.14107 + 2.98) + " F1800\n");
                }else if(toggleCount == -1){
                    
                    gcodeText += ("G1 X" + ofToString(50 + debugPoint[49*101 + j].x) + " Y" + ofToString(50 + debugPoint[49*101 + j].y) + " Z" + ofToString(debugPoint[i*101 + 49].z -3.14107 + 2.98) + " F1800\n");
                }
                
                continue;
            }
             */
            
            float dist = debugPoint[i*101 + j].distance(debugPoint[(i-1)*101 + j]);
            //z -3.14107 = 0;
            //z offset 2.8 + (layersou/2 = 0.1)
            //z offset 2.8 + 0.18
            //
            float e = dist/0.887 * 50;
            
            
            if(toggleCount == 1){
                
                gcodeText += ("G1 X" + ofToString(50 + debugPoint[i*101 + j].x) + " Y" + ofToString(50+ debugPoint[i*101 + j].y) + " Z" + ofToString(debugPoint[i*101 + j].z) + " E" + ofToString(e) + "\n");
            }else if(toggleCount == -1){
                
                gcodeText += ("G1 X" + ofToString(50 + debugPoint[(50-i)*101 + j].x) + " Y" + ofToString(50 + debugPoint[(50-i)*101 + j].y) + " Z" + ofToString(debugPoint[(50-i)*101 + j].z) + " E" + ofToString(e) + "\n");
            }
        }
        toggleCount *= -1;
        
    }
    
    ofBuffer buffer = ofBuffer(gcodeText);
    ofBufferToFile("tes.gcode", buffer);
}


//--------------------------------------------------------------

void ofApp::generateGcode2(){
    string textGcode = "";
    
    int fineness = 30;
    int radius = 40;
    
    int nRadius = 5;
    
    //vector<ofVec3f> points;
    //vector<ofVec3f> newPoint;

    
    for(int i=0; i<fineness; i++){
        points.push_back(ofVec3f(radius * cos(2*PI/fineness*i), radius * sin(2*PI/fineness*i), 0));
    }

    for(int i=0; i<fineness; i++){
        
        ofVec3f vec = points[(i+1)%fineness] - points[i];
        vec /=20;
        for(int j=0; j<20; j++){
            newPoint.push_back(ofVec3f(float(points[i].x + vec.x*j), float(points[i].y + vec.y*j), float(nRadius * sin(PI/20 * j))));
        }
    }

    //debug
    for(int i=0; i<newPoint.size(); i++){
        cout << newPoint[i] << endl;
    }
    
    textGcode += "G1 X" + ofToString(newPoint[0].x) + " Y" + ofToString(newPoint[0].y) + " Z" + ofToString(newPoint[0].z + 2.6) + " F4800\n";
    
    for(int i=1; i<newPoint.size(); i++){

        textGcode += "G1 X" + ofToString(newPoint[i].x) + " Y" + ofToString(newPoint[i].y) + " Z" + ofToString(newPoint[i].z + 2.6) + " E150" + " F500\n";
        
    }
    
    ofBuffer buffer = ofBuffer(textGcode);
    ofBufferToFile("tes.gcode", buffer);
    
    
}

//--------------------------------------------------------------
void ofApp::setMeshPolar(){
    polarMesh.clear();
    polarWire.clear();
    debugPoint.clear();

    int fineness = finenessSphere;
    //float newRadius = radiusHalfSphere;
    float newRadius = 100;
    
    
    /*
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++){
            
            ofVec3f tmp = polar(radius, float((PI/50)*j), float((2*PI/50)*i));
            polarMesh.addVertex(tmp);
            polarMesh.addNormal(ofVec3f(0, -1.0, 0));
            polarMesh.addColor(ofColor(255, 0, 0));
            
        }
    }
     */
    
    for(int i=0; i<(fineness+1)/2; i++){
        for(int j=0; j<(fineness+1); j++){
            //float newRadius = float(radius * ((2+para1 + sin(float((5.0+para2) * (PI/fineness)*i))*sin(float((3.0+para3) * (2*PI/fineness)*j)))));
            //float newRadius = 100;
            //float newRadius = 100 * sin(float(para2*PI/fineness)*i);
            //float newRadius = 100 * sin(float(para3*PI/fineness)*j);
            //float newRadius = 100 * cos(float(para2*PI/fineness)*j);
            //float newRadius = 100* sin(float(2+vForPolar + PI/fineness*i)) * cos(float(3 + vForPolar + para3*PI/fineness*j));
            //float newRadius = 100 * cos(float(2 + PI/fineness*i)) * cos(float(3 + vForPolar + PI/fineness*j)));

            ofVec3f tmp = polar(newRadius, float(((PI)/fineness)*i), float((2*PI/fineness)*j));
            polarMesh.addVertex(tmp);
            polarMesh.addNormal(ofVec3f(0, -1.0, 0));
            polarMesh.addColor(ofColor(255, 0, 0));
            
            polarWire.addVertex(tmp);
            //polarWire.addColor(ofColor(0,0,0));
            //polarWire.addColor(ofColor(ofMap(tmp.x, -radius, radius, 0, 255), ofMap(tmp.y, -radius, radius, 0, 255), ofMap(tmp.z, -radius, radius, 0, 255)));
            polarWire.addColor(ofColor(0, 255, 0));
            
            debugPoint.push_back(tmp);
            
        }
    }
    for(int i=0; i<fineness/2; i++){
        for(int j=0; j<fineness; j++){
            polarMesh.addIndex(i*(fineness+1) + j);
            polarMesh.addIndex((i+1)*(fineness+1) + j);
            polarMesh.addIndex((i+1)*(fineness+1) + j + 1);
            
            polarMesh.addIndex(i*(fineness+1) + j);
            polarMesh.addIndex((i+1)*(fineness+1) + j + 1);
            polarMesh.addIndex(i*(fineness+1) + j + 1);
            
            polarWire.addIndex(i*(fineness+1) + j);
            polarWire.addIndex((i+1)*(fineness+1) + j);
            polarWire.addIndex((i+1)*(fineness+1) + j + 1);
            
            polarWire.addIndex(i*(fineness+1) + j);
            polarWire.addIndex((i+1)*(fineness+1) + j + 1);
            polarWire.addIndex(i*(fineness+1) + j + 1);
        }
    }
    
    
    //gcoder
}
ofVec3f ofApp::polar(float r, float theta, float fi){
    float x = float(r * sin(theta) * cos(fi));
    float y = float(r * sin(theta) * sin(fi));
    float z = float(r * cos(theta));
    
    return ofVec3f(x, y, z);
}
void ofApp::setMesh(){
    
    /*
    mesh.clearVertices();
    mesh.clearIndices();
    mesh.clearColors();
     */
    mesh.clear();

    
    float originValue[ind+1];
    float originValue2[ind+1];
    
    float pointX[ind+1][ind+1];
    float pointY[ind+1][ind+1];
    double pointZ[ind+1][ind+1];

    //set range
    
    for(int i=0; i<(ind+1); i++){
        originValue[i] = -range+ i*2*range/ind;
        //originValue[i] = float(range * sin(float(2*PI/ind)*i));
        //originValue2[i] = float(range * cos(float(2*PI/ind)*i));
    }
    
    //set X and Y
    for(int i=0; i<(ind+1); i++){
        for(int j=0; j<(ind+1); j++){
            pointX[i][j] = float(originValue[i]);
            pointY[i][j] = float(originValue[j]);
        }
    }
    
    
    for(int i=0; i<(ind+1); i++){
        for(int j=0; j<(ind+1); j++){
            //pointZ[i][j] = func(pointX[i][j], pointY[i][j]);
            mesh.addVertex(ofVec3f(pointX[i][j], func(pointX[i][j], pointY[i][j]), pointY[i][j]));
            mesh.addNormal(ofVec3f(0, -1.0, 0));
            mesh.addColor(ofColor(255, 0, 0));
        }
    }
    
    
    for(int i=0; i<ind; i++){
        for(int j=0; j<ind; j++){
            mesh.addIndex(i*(ind+1) + j);
            mesh.addIndex(i*(ind+1) + j + 1);
            mesh.addIndex((i+1)*(ind+1) + j);
            
            mesh.addIndex(i*(ind+1) + j + 1);
            mesh.addIndex((i+1)*(ind+1) + j);
            mesh.addIndex((i+1)*(ind+1) + j + 1);
            
        }
    }
    

    
    
}

double ofApp::func(float _x, float _y){
    
    if(counter % 2 == 0){
        return 100.0 * cos(double(sqrt(_x*_x + _y*_y) / para));
    }else if(counter % 2 == 1){
        return 50 * cos((_x*_y)/para/10);
    }
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 's'){
        
        //output gcode file as ornment
        float offset = 0.15;
        int heightOfOrnament = heightOrnament;
        int fineness = 360;
        ornamentGcoder.initGcode();
        float zOffset = 2.8;
        float eValue = 0.0;
        
        
        string tmpGcode = "G1 Z50 F1800\n";
        tmpGcode += "G1 X" + ofToString(ornament[0].x) + " Y" + ofToString(ornament[0].y) + " F1800\n";
        tmpGcode += "G1 Z" + ofToString(ornament[0].z + zOffset) + " F1800\n";
        tmpGcode += "T0\n";
        ornamentGcoder.addGcode(tmpGcode);
        
        
        for(int j=0; j<int(heightOfOrnament/offset)-1; j++){
            
            tmpGcode = "; layer " + ofToString(j) + "\n";
            tmpGcode += "G92 E0\n";
            eValue = 0.0;
            
            ornamentGcoder.addGcode(tmpGcode);
            
            for(int i=0; i<(fineness+1); i++){
                ofVec3f tmp = ornament[j*(fineness+1) + i];
                
                //set E Value
                if(i == 0){
                    eValue += 0.0;
                }else{
                    eValue = ornamentGcoder.calcEValue(ornament[j*(fineness+1) + i-1], ornament[j*(fineness+1) + i], eValue);
                }
                
                
                tmpGcode = "G1 X" + ofToString(tmp.x) + " Y" + ofToString(tmp.y) + " Z" + ofToString(tmp.z + zOffset);
                
                if(i ==0){
                    tmpGcode += " F1800\n";
                }else if(i == 1){
                    //tmpGcode += " E" + ofToString(float(i/170.0 + fineness*j/170.0));
                    tmpGcode += " E" + ofToString(eValue);
                    
                    tmpGcode += " F1800\n";
                }else{
                    //tmpGcode += " E" + ofToString(float(i/170.0 + fineness*j/170.0)) + "\n";
                    tmpGcode += " E" + ofToString(eValue) + "\n";
                }
                ornamentGcoder.addGcode(tmpGcode);
                
            }
        }
        
        ornamentGcoder.finishGcode();
        ornamentGcoder.outputFile();
        
    }
    
    /*
    if(key == 's'){
        para += 2;
        setMesh();
        cout << para << endl;
    }else if(key == 'a'){
        para -= 2;
        setMesh();
    }else if(key == 'z'){
        counter ++;
    }
     */

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
