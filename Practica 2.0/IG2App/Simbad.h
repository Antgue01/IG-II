#pragma once
#include "EntidadIG.h"
#include <OgreSceneManager.h>
#include <OGRE\OgreAnimationState.h>
#include <OgreFrameListener.h>
#include "IG2ApplicationContext.h"

#include <OgreAnimationTrack.h>
#include <OgreAnimation.h>
#include <OgreKeyFrame.h>
#include <OgreFrameListener.h>

class Simbad : public EntidadIG
{
public:
	Simbad(Ogre::SceneNode* node);
	virtual ~Simbad() {  }
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	void receiveEvent(EntidadIG* entidad);



protected:
	Ogre::Entity* swordent;
	Ogre::Entity* simbadEnt;
	bool danceBool = false;
	bool rightHand = true;
	bool dead = false;
	Ogre::AnimationState* dance;
	Ogre::AnimationState* runarms;
	Ogre::AnimationState* idle;
	Ogre::AnimationState* runlegs;
	Ogre::AnimationState* moverse;
};

