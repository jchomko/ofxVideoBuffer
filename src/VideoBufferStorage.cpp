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

}
//--------------------------------------------------------------
videoBuffer::~videoBuffer()
{
    //Danger Will Robinson!!!
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
                if (ofGetFrameNum() % 1 == 0)
                {
                    progress++;
                }
            }
            if (progress >= buffer.size()-30)
            {
                //fade.setParameters(1, easingLinear, ofxTween::easeOut, 255, 0, 1000, 0);
                //fade.start();
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
void videoBuffer::draw()
{
    ofPushStyle();
    /*
    if (progress <= 30)
    {
        _fadeValue += _fadeRate;
    }
    else if (progress > 30 && progress < buffer.size()-30)
    {
        _fadeValue = 255;
    }
    else if (progress >= buffer.size()-30)
    {
        _fadeValue -= _fadeRate;
    }
    */
    ofSetColor(255);
    if (canStartLoop == true)
    {
        if (!buffer.empty() && buffer.size() >= 30)
        {
            buffer[progress].draw(0, 0,ofGetWidth(),ofGetHeight());
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
    ofSetColor(255);
    ofFill();
    if (!buffer.empty())
    {
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
    stillPlaying = true;
    canStartLoop = true;
    //fade.setParameters(1,easingLinear,ofxTween::easeOut ,0, 255, 1000,0);
    
}
//--------------------------------------------------------------
void videoBuffer::reset()
{
    progress = 0;
    stillPlaying = true;
    canStartLoop = true;
    //fade.setParameters(1,easingLinear,ofxTween::easeOut ,0, 255, 1000,0);
}
//--------------------------------------------------------------
void videoBuffer::stop()
{
  
    stillPlaying = false;
    canStartLoop = false;
    //fade.setParameters(1,easingLinear,ofxTween::easeOut ,255, 0, 100,0);
    //progress = 0;
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
