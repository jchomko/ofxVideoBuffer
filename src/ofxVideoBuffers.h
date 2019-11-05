//--------------------------------------------------------------
//* Name: VideoBufferStorage.h
//* Project: Playable City 2014 Award
//* Author: David Haylock
//* Creation Date: 28-07-2014
//--------------------------------------------------------------

#include <iostream>
#include "ofMain.h"

#define WIDTH 320
#define HEIGHT 240
#define FRAMERATE 25

class videoBuffer{
    
public:
    videoBuffer();
    // ~videoBuffer();
    
    void update();
    
    void draw(int color);
    void drawBlobPath();
    void drawMini(int x, int y);
    void renderImages();
    
    // Getters
    void getNewImage(ofImage img);
    void getNewImages(vector<ofImage>img);
    void getPath(vector<ofVec2f>paths);
    int getNumberOfFrames();

    vector<ofImage> buffer;
    
    bool isFinished();
    bool isPlaying();
    bool isNearlyFinished();
    
    void reset();
    void start();
    void stop();
    void clear();
    void fadeOut();
    int fadeLength;

private:

    vector<ofVec2f> bPath;
    int progress;
    int drawPathCounter;
    bool stillPlaying;
    bool canStartLoop;
    bool hasFinishedPlaying;
    int _fadeV;
    bool _forceFade;
    long frameTimer;
};

