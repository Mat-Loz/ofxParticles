//
//  ofxParticleRotation.h
//  ofxParticles
//
//  Created by Elie Zananiri on 2013-10-01.
//
//

#pragma once

#include "ofMain.h"

#include "ofxParticleForce.h"

//--------------------------------------------------------------
//--------------------------------------------------------------
class ofxParticleRotation : public ofxParticleForce
{
    public:
        ofxParticleRotation();
        void setup(const ofVec3f& position, float strength, float maxDist, float minDist = 10.0f, float bConsumeParticle = false);
        void apply(ofxParticle * p);
        void debug();
        
        float maxDist;
        float minDist;
        bool bConsumeParticle;
};