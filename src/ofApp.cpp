#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(lowThreshold.setup("low threshold", 50, 0, 100));
    
    img.load("4.jpg");
    img.setImageType(OF_IMAGE_COLOR);
    
    pointsPushed = false;
    point = 0;
    toTheRight = true;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

void pushPoints(const ofImage& img, const Mat& imgMat, Boolean& pointsPushed, vector<cv::Point>& points) {
    if (!pointsPushed) {
        for(int i = 0; i < img.getWidth(); i++){
            for(int j = 0; j < img.getHeight(); j++){
                if(imgMat.data[int(i+img.getWidth()*j)] > 200){
                    cv::Point p(i,j);
                    points.push_back(p);
                    break;
                }
            }
        }
    }
    pointsPushed = true;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 255, 255);
    img.draw(0,0);
    
    
    // Getting the Edges
    imgMat = toCv(img);
    cvtColor(imgMat, imgMat, CV_BGR2GRAY);
    mask = Mat::zeros(cv::Size(img.getWidth(),img.getHeight()), CV_8U);
    GaussianBlur(imgMat, imgMat, 3);
    Canny(imgMat, imgMat, lowThreshold, lowThreshold*2);
    
    
    // Pushing Points
    pushPoints(img, imgMat, pointsPushed, points);
    
    
    if(ofGetElapsedTimeMillis() > 10) {
        
        // Movement
        if (toTheRight) point++;
        else point--;
        
        // Reverse
        if (point == points.size()) toTheRight = false;
        if (point == 0) toTheRight = true;
        
        // Timing
        ofResetElapsedTimeCounter();
    }
    
    // Drawing
    ofDrawCircle(points[point].x, points[point].y, 20);
    
    
    // Adjusting Threshold mechnism
    if (newThreshold != lowThreshold) {
        
        pointsPushed = false;
        newThreshold = lowThreshold;
        
        // Remove all points
        while(!points.empty()){
            points.pop_back();
        }
        
        // Pushing Points
        pushPoints(img, imgMat, pointsPushed, points);
        
    }
    
    // Draw the Edges
//    drawMat(imgMat, 0, 0); // Draws the white edges on black background on top of image
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
