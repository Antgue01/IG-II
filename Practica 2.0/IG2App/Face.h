#pragma once
#include "EntidadIG.h"
#include <OgreRenderTargetListener.h>
#include <OgreRenderTarget.h>
#include <OgreSceneManager.h>

class Face :public EntidadIG,public Ogre::RenderTargetListener   
{
public:
	Face(Ogre::SceneNode* node);
	virtual ~Face() {  }

	virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
	virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);

private:

};

