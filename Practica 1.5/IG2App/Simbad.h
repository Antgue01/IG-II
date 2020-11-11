#pragma once
#include "EntidadIG.h"
#include <OgreSceneManager.h>
#include <OGRE\OgreAnimationState.h>
#include <OgreFrameListener.h>
#include "IG2ApplicationContext.h"

class Simbad : public EntidadIG
{
public:
	Simbad(Ogre::SceneNode* node);
	virtual ~Simbad() {  }
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);



protected:
	Ogre::Entity* swordent;
	Ogre::Entity* simbadEnt;
	bool danceBool = true;
	bool rightHand = true;
	Ogre::AnimationState* dance;
	Ogre::AnimationState* runarms;
	Ogre::AnimationState* runlegs;
};

