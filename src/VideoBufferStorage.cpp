//
//  VideoBufferStorage.cpp
//  ShadowingStage1
//
//  Created by David Haylock on 28/07/2014.
//
//

#include "VideoBufferStorage.h"

//--------------------------------------------------------------
videoBuffer::videoBuffer()
{
    progress = 0;
    //drawPathCounter = 0;
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
    /*
    if(progress >= buffer.size()-1)
    {
        progress = 0;
    }
    */
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
        }
        else
        {
            
        }
    }
    else
    {
        
    }
    
    /*
    if(drawPathCounter >= bPath.size()-1)
    {
        drawPathCounter = 0;
    }
    if(!bPath.empty())
    {
        if (ofGetFrameNum() % 1 == 0)
        {
            drawPathCounter++;
        }
    }
    */
}
//--------------------------------------------------------------
void videoBuffer::draw()
{
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofPushStyle();
    ofSetColor(255);
    if (canStartLoop == true)
    {
        if (!buffer.empty() && buffer.size() >= 30)
        {
            //buffer[progress].mirror(false, true);
            buffer[progress].draw(0, 0,ofGetWidth(),ofGetHeight());
        }
    }
    else
    {
        if (!buffer.empty() && buffer.size() >= 30)
        {
         //   buffer[0].draw(0, 0,ofGetWidth(),ofGetHeight());
        }
    }
    ofPopStyle();
    //ofDisableBlendMode();
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
    
    ofPushMatrix();
    ofTranslate(x, y);
    ofNoFill();
    if (!bPath.empty())
    {
        ofSetColor(255, 0, 0);
        ofBeginShape();
        for (int p = 0; p < bPath.size(); p++)
        {
            ofVertex(ofMap(bPath[p].x,0,320,0,320/4),ofMap(bPath[p].y,0,240,0,240/4));
        }
        ofEndShape(false);
    }
    
    ofSetColor(0);
    ofPopMatrix();
    ofDrawBitmapStringHighlight(ofToString(progress), x+10, y+10);
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
    //progress = 0;
    //drawPathCounter = 0;
    ofLog(OF_LOG_NOTICE, "Started Playing Buffer");
    canStartLoop = true;
}
//--------------------------------------------------------------
void videoBuffer::stop()
{
    progress = 0;
    
}
//--------------------------------------------------------------
void videoBuffer::clear()
{
    
    
}
//--------------------------------------------------------------
bool videoBuffer::isFinished()
{
    if (progress >= buffer.size()-1 && canStartLoop == true)
    {
        
        canStartLoop = false;
        progress = 0;
        ofLog(OF_LOG_NOTICE, "Buffer has Finished Playing");
        return true;
    }
    else
    {
        return false;
    }
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
void videoBuffer::renderImages()
{

}
