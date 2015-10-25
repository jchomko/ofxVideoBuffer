//--------------------------------------------------------------
//* Name: VideoBufferStorage.cpp
//* Project: Playable City 2014 Award
//* Author: David Haylock
//* Creation Date: 28-07-2014
//--------------------------------------------------------------

#include "VideoBufferStorage.h"
//--------------------------------------------------------------
videoBuffer::videoBuffer()
{
    progress = 0;
    canStartLoop = false;
    hasFinishedPlaying = false;
    _fadeV = 255;
    fadeLength = 6;
    buffer.reserve(900);
    for(int i = 0;i  < 900; i ++){
	buffer[i].allocate(WIDTH, HEIGHT,OF_IMAGE_GRAYSCALE);
	}

}
//--------------------------------------------------------------
videoBuffer::~videoBuffer()
{

}
//--------------------------------------------------------------
void videoBuffer::update()
{
    if(canStartLoop == true)
    {
        if (!isFinished())
        {
            if(!buffer.empty() && progress <= buffer.size()-1)
            {
 		//time based playback???
//                if (ofGetFrameNum() % 1 == 0)
                if (ofGetElapsedTimeMillis() - frameTimer > 33)
		{
                    progress++;
			frameTimer = ofGetElapsedTimeMillis();
                }
            }
            if (progress >= buffer.size()-30)
            {

            }
        }
        else
        {

        }
    }
    else
    {

    }
}
//--------------------------------------------------------------
void videoBuffer::draw(int color)
{
    ofPushStyle();
    //isNearlyFinished();
    
    
    if (canStartLoop == true)
    {
        if (!buffer.empty() && buffer.size() >= fadeLength)
        {
            if (_forceFade == false)
            {
                if (progress <= fadeLength) //*2
                {
                    ofSetColor(255,ofMap(progress, 0, fadeLength, 0, 255)); //*2
                }
                else if (progress >= fadeLength && progress <= buffer.size()-fadeLength)
                {
                    ofSetColor(255,255);
                }
                else if (progress >= buffer.size()-fadeLength)
                {
                    ofSetColor(255,ofMap(progress, buffer.size()-fadeLength, buffer.size()-1, 255, 0));
                }
            }
            else if(_forceFade == true)
            {
                ofSetColor(255,_fadeV);
                if (_fadeV >= 1)
                {
                    _fadeV -=15;
                }
                else
                {
                    _fadeV = 0;
                }
            }
            else
            {
                
            }
            //buffer[progress].draw(0, 0,ofGetWidth(),ofGetHeight());
            buffer[progress].draw(0, 0, WIDTH, HEIGHT);
        }
            
    }
    else
    {
        
    }
    ofPopStyle();
}
//--------------------------------------------------------------
void videoBuffer::drawMini(int x, int y)
{
    ofPushStyle();
    ofFill();
    if (!buffer.empty())
    {
        if (progress <= 60)
        {
            ofSetColor(255,ofMap(progress, 0, 60, 0, 255));
        }
        else if (progress >= 60 && progress <= buffer.size()-30)
        {
            ofSetColor(255,255);
        }
        else if (progress >= buffer.size()-30)
        {
            ofSetColor(255,ofMap(progress, buffer.size()-30, buffer.size()-1, 255, 0));
        }
        buffer[progress].draw(x, y,320/4,240/4);
    }
    
    ofDrawBitmapStringHighlight(ofToString(progress), x, y);
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofRect(x, y, 320/4,240/4);
    ofPopStyle();
}
//--------------------------------------------------------------
void videoBuffer::drawBlobPath()
{
    ofPushMatrix();
    ofNoFill();
    if (!bPath.empty())
    {
        ofSetColor(255, 0, 0);
        ofBeginShape();
        for (int p = 0; p < bPath.size(); p++)
        {
            ofVertex(ofMap(bPath[p].x,0,320,0,ofGetWidth()),ofMap(bPath[p].y,0,240,0,ofGetHeight()));
        }
        ofEndShape(false);
    }
    
    ofSetColor(255);
    ofPopMatrix();
    
}
//--------------------------------------------------------------
void videoBuffer::start()
{
    _forceFade = false;
    stillPlaying = true;
    canStartLoop = true;
}
//--------------------------------------------------------------
void videoBuffer::reset()
{
    progress = 0;
    stillPlaying = true;
    canStartLoop = true;
    _forceFade = false;
}
//--------------------------------------------------------------
void videoBuffer::stop()
{
    stillPlaying = false;
    canStartLoop = false;
    _forceFade = false;
}
//--------------------------------------------------------------
void videoBuffer::fadeOut()
{
    _forceFade == true;
}
//--------------------------------------------------------------
bool videoBuffer::isFinished()
{
    if (progress >= buffer.size()-1 && canStartLoop == true)
    {
        stop();
        return true;
    }
    else
    {
        return false;
    }
}
//--------------------------------------------------------------
bool videoBuffer::isNearlyFinished()
{
    if (progress >= buffer.size()-20) {
     
    }
}
//--------------------------------------------------------------
bool videoBuffer::isPlaying()
{
    return stillPlaying;
}
//--------------------------------------------------------------
void videoBuffer::getPath(vector<ofVec2f> paths)
{
    
    if (paths.empty())
    {
        ofLog(OF_LOG_ERROR,"Nothing to Copy to the Path ... Its going to Crash!");
        return;
    }
    else if (!paths.empty() && paths.size() <= 30)
    {
        ofLog(OF_LOG_ERROR,"No the Path is Too Small ... Its going to Crash! " + ofToString(paths.size()));
        return;
    }
    else if (!paths.empty() && paths.size() >=30)
    {
        bPath = paths;
        ofLog(OF_LOG_NOTICE,"Paths Copied");
    }
    else
    {
        ofLog(OF_LOG_ERROR,"How the Hell did you end up here!!!");
    }
    
}
//--------------------------------------------------------------
void videoBuffer::getNewImage(ofImage img)
{
    buffer.push_back(img);
}
//--------------------------------------------------------------
void videoBuffer::getNewImages(vector<ofImage>img)
{
    
    if (img.empty())
    {
        ofLog(OF_LOG_ERROR,"Nothing to Copy to the Buffer ... Its going to Crash!");
        return;
    }
    else if (!img.empty() && img.size() <= 30)
    {
        ofLog(OF_LOG_ERROR,"No the Buffer is Too Small ... Its going to Crash! " + ofToString(img.size()));
        
        return;
    }
    else if (!img.empty() && img.size() >=30)
    {
        buffer = img;
        ofLog(OF_LOG_NOTICE,"Buffer Copied");
    }
    else
    {
        ofLog(OF_LOG_ERROR,"How the Hell did you end up here!!!");
    }
    
}
//--------------------------------------------------------------
int videoBuffer::getNumberOfFrames()
{
    if (!buffer.empty())
    {
        return buffer.size();
    }
    else
    {
        return 0;
    }
}
//--------------------------------------------------------------
void videoBuffer::clear()
{
    buffer.clear();
}
//--------------------------------------------------------------
void videoBuffer::renderImages()
{
    
}
