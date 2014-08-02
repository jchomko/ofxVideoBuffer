//
//  VideoBufferStorage.h
//  ShadowingStage1
//
//  Created by David Haylock on 28/07/2014.
//
//

#ifndef __ShadowingStage1__VideoBufferStorage__
#define __ShadowingStage1__VideoBufferStorage__

#include <iostream>
#include "ofMain.h"


typedef struct {
    string blobID;
    vector<ofVec2f> path;
} blobPaths;

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
    
    
    void run();
    void stop();
    bool isFinished();
    void start();
    void clear();
    
private:
    vector<ofImage> buffer;
    vector<ofVec2f> bPath;
    int progress;
    int drawPathCounter;

    bool canStartLoop;
    bool hasFinishedPlaying;
};


#endif /* defined(__ShadowingStage1__VideoBufferStorage__) */
