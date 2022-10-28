#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(lowThreshold.setup("low threshold", 50, 0, 100));
    gui.add(lineVoteThreshold.setup("line vote threshold", 150, 0, 200));
    
    img.load("1.jpg");
    img.setImageType(OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 255, 255);
    img.draw(0,0);
    
    imgMat = toCv(img);
    cvtColor(imgMat, imgMat, CV_BGR2GRAY);
    mask = Mat::zeros(cv::Size(img.getWidth(),img.getHeight()), CV_8U);
    for(int i = 0; i < keyPoints.size(); i++){
        ofSetColor(0, 255, 0);
        ofDrawCircle(keyPoints[i].x, keyPoints[i].y, 5);
    }
    
    if(keyPoints.size()>=3){
        fillConvexPoly(mask, keyPoints.data(), keyPoints.size(), Scalar(255,255,255));
        bitwise_and(imgMat, mask, imgMat);
    }
    
    GaussianBlur(imgMat, imgMat, 3);
    Canny(imgMat, imgMat, lowThreshold, lowThreshold*2);
    drawMat(imgMat, 0, 0); // Draws the white edges on black background
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    if(x>=0&&x<img.getWidth()&&y>=0&&y<img.getHeight()){
        cv::Point p(x,y);
        keyPoints.push_back(p);
    }
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
