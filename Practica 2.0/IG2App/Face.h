#pragma once
#include "EntidadIG.h"
#include <OgreSceneManager.h>

class Face :public EntidadIG  
{
public:
	Face(Ogre::SceneNode* node);
	virtual ~Face() {  }
	void receiveEvent(EntidadIG* entidad, MSG msg);
private:
	Ogre::Entity* e = nullptr;
};

