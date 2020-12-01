#pragma once
#include "EntidadIG.h"
#include <OgreSceneManager.h>
#include <OgreTextureManager.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreMovablePlane.h>
#include "IG2ApplicationContext.h"
#include <OgreRenderTexture.h>
#include <OgreTexture.h>
#include <OgreRenderTarget.h>
#include<OgreHardwarePixelBuffer.h>
#include <OgreSubEntity.h>
#include <OgreMaterial.h>
#include <OgreTechnique.h>
#include <OgrePass.h>



class Plano : public EntidadIG 
{
public:
	Plano(Ogre::SceneNode* node,int ancho,int largo,std::string name, std::string matName);
	virtual ~Plano() { delete movPlane; }

	void receiveEvent(EntidadIG* entidad);

	void setReflejo(Ogre::Camera* cam);

protected:
	
	Ogre::Entity* p;
	std::string name;
	Ogre::MovablePlane* movPlane = nullptr;
	/*Ogre::SceneNode* camRefNode = nullptr;*/
};

