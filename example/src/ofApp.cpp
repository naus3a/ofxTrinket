#include "ofApp.h"

bool b;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    trinket.addDataReceivedCallback(&ofApp::onDataRcv, this);
    trinket.setReadBufferSize(8);
    trinket.connect();
    
    b=false;
}

void ofApp::onDataRcv(int nBytes){
    cout<<nBytes<<" bytes received"<<endl;
    unsigned char msg[nBytes];
    for(int i=0;i<nBytes;i++){
        msg[i] = trinket.getReadBuffer()[i];
    }
    cout<<"msg: "<<msg<<endl;
    if(msg[0]=='0'){
        b=false;
    }else if(msg[0]=='1'){
        b=true;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(b){
        ofClear(255, 0, 0);
    }else{
        ofClear(0, 255, 0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(trinket.isDeviceConnected()){
        cout<<"Sending "<<(unsigned char)(key)<<endl;
        trinket.send((unsigned char)(key));
    }
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
