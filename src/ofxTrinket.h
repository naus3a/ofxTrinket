//
//  ofxTrinket.h
//
//  magicLab 2017
//  http://www.magiclab.nyc
//  Created by enrico<naus3a>viola on 3/9/17.
//
//

#pragma once
#include "ofMain.h"
#include "ofxHIDapi.h"

class ofxTrinket{
public:
    ofxTrinket();
    ~ofxTrinket();
    inline void setReadBufferSize(int nBytes){hid.setReadBufferSize(nBytes);}
    bool connect(const wchar_t * serial_number=NULL);
    void close();
    bool isDeviceConnected();
    void send(string msg);
    inline unsigned char * getReadBuffer(){return hid.getReadBuffer();}
    inline const unsigned short & getVendorId(){return vendor_id;}
    inline const unsigned short & getProductId(){return product_id;}

    template<typename T>
    inline void addDataReceivedCallback(void(T::*func)(int), T* listener){
        readCallback = std::bind(func, listener, std::placeholders::_1);
    }

protected:
    void update(ofEventArgs & e);

    std::function<void(int)> readCallback;

    ofxHIDapi hid;
    const unsigned short vendor_id;
    const unsigned short product_id;
};
