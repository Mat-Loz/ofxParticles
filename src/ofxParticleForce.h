//
//  ofxParticleForce.h
//  ofxParticles
//
//  Created by Elie Zananiri on 2013-10-01.
//
//

#pragma once

#include "ofMain.h"

#include "ofxParticle.h"

//--------------------------------------------------------------
//--------------------------------------------------------------
class ofxParticleForce
{
    public:
        ofxParticleForce();
        void setup(const ofVec3f& position, float strength);
        void apply(ofxParticle * p, const ofVec3f& force);
        virtual void apply(ofxParticle * p) = 0;
        virtual void debug();
    
        ofVec3f position;
        float strength;
    
        bool bEnabled;
};