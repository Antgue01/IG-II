#pragma once
#include "EntidadIG.h"
#include <OgreSceneManager.h>
#include <OgreAnimationTrack.h>
#include <OgreAnimation.h>
#include <OgreKeyFrame.h>
#include <SDL.h>
#include <OgreFrameListener.h>

class Boya :
	public EntidadIG
{
public:
	Boya(Ogre::SceneNode* n);
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	virtual void frameRendered(const Ogre::FrameEvent& evt);


protected:
	Ogre::Entity* ent;
	Ogre::AnimationState* animS;

};

