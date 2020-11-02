#pragma once
#include "EntidadIG.h"
#include <OgreSceneManager.h>


class Plano : public EntidadIG 
{
public:
	Plano(Ogre::SceneNode* node,int ancho,int largo,std::string name);
	virtual ~Plano() { }

protected:
	

};

