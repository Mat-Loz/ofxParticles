//
//  ofxParticleAttraction.cpp
//  ofxParticles
//
//  Created by Elie Zananiri on 2013-10-01.
//
//

#include "ofxParticleAttraction.h"

//--------------------------------------------------------------
ofxParticleAttraction::ofxParticleAttraction()
: ofxParticleForce()
{
    maxDist = 50.0f;
    minDist = 10.0f;
    bConsumeParticle = false;
}

//--------------------------------------------------------------
void ofxParticleAttraction::setup(const ofVec3f& position, float strength, float maxDist, float minDist, float bConsumeParticle)
{
    ofxParticleForce::setup(position, strength);
    this->maxDist = maxDist;
    this->minDist = minDist;
    this->bConsumeParticle = bConsumeParticle;
}

//--------------------------------------------------------------
void ofxParticleAttraction::apply(ofxParticle * p)
{
    if (p->position == position) return;
    
    ofVec3f force = position - p->position;
    float dist = force.length();
    if (dist > maxDist) {
        return;
    }
    if (dist < minDist) {
        if (bConsumeParticle) {
            p->life = 0;
        }
        return;
    }
    float pct = 1.0f - (dist / maxDist);  // stronger on the inside
    force.normalize().scale(strength * p->mass * pct);
    
    ofxParticleForce::apply(p, force);
}

//--------------------------------------------------------------
void ofxParticleAttraction::debug()
{
    ofxParticleForce::debug();
    ofCircle(position, minDist);
    ofCircle(position, maxDist);
}
