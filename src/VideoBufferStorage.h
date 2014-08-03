//
//  VideoBufferStorage.h
//
//  Created by David Haylock on 28/07/2014.
//
//

#include <iostream>
#include "ofMain.h"

class videoBuffer : public ofSimpleApp {
    
public:
    videoBuffer();
    ~videoBuffer();
    
    void update();
    
    void draw();
    void drawBlobPath();
    void drawMini(int x, int y);
    void renderImages();
    
    // Getters
    void getNewImages(vector<ofImage>img);
    void getPath(vector<ofVec2f>paths);
    int getNumberOfFrames();
    
    bool isFinished();
    bool isPlaying();
    
    void start();
    void stop();
    void clear();
    
private:
    vector<ofImage> buffer;
    vector<ofVec2f> bPath;
    int progress;
    int drawPathCounter;
    bool stillPlaying;
    bool canStartLoop;
    bool hasFinishedPlaying;
};

