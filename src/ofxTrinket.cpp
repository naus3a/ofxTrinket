//
//  ofxTrinket.cpp
//
//  magicLab 2017
//  http://www.magiclab.nyc
//  Created by enrico<naus3a>viola on 3/9/17.
//
//

#include "ofxTrinket.h"

ofxTrinket::ofxTrinket() : vendor_id(0x16c0), product_id(0x05df){
}

ofxTrinket::~ofxTrinket(){
    //close();
}



bool ofxTrinket::connect(const wchar_t * serial_number){
    hid.close();
    bool  b = hid.connect(vendor_id, product_id, serial_number);
    if(b){
        hid.setNonBlocking(true);
        ofAddListener(ofEvents().update, this, &ofxTrinket::update);
    }
    return b;
}

void ofxTrinket::close(){
    if(isDeviceConnected()){
        ofRemoveListener(ofEvents().update, this, &ofxTrinket::update);
        hid.close();
    }
}

bool ofxTrinket::isDeviceConnected(){
    return (hid.getHandle()!=NULL);
}

void ofxTrinket::update(ofEventArgs &e){
    int nBytes = hid.read();
    if(nBytes>0){
        readCallback(nBytes);
    }
}

void ofxTrinket::send(string msg){
    size_t sz = msg.length()+1;
    unsigned char data[sz];
    data[0] = 0x00;
    for(int i=1;i<int(sz);i++){
        data[i] = msg[i+1];
    }
    hid.sendFeatureReport(data, sz);
}
