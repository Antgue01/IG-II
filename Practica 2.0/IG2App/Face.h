#pragma once
#include "EntidadIG.h"
#include <OgreRenderTargetListener.h>
#include <OgreRenderTarget.h>
#include <OgreSceneManager.h>
#include <OgreRenderTexture.h>

class Face :public EntidadIG 
{
public:
	Face(Ogre::SceneNode* node);
	virtual ~Face() {  }
	void receiveEvent(EntidadIG* entidad, MSG msg = MSG::none);
	
private:
	Ogre::Entity* ent;
};

