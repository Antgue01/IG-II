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
#include <OgreRenderTargetListener.h>
#include <OgreRenderTarget.h>

class Plano : public EntidadIG, public Ogre::RenderTargetListener, public Ogre::Viewport::Listener
{
public:
	Plano(Ogre::SceneNode* node,int ancho,int largo,std::string name, std::string matName);
	virtual ~Plano() { delete movPlane; }

	virtual void viewportDimensionsChanged(Ogre::Viewport* viewport);

	virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
	virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);

	void receiveEvent(EntidadIG* entidad, MSG msg);

	void setReflejo(Ogre::Camera* cam);

protected:
	
	Ogre::Entity* p;
	std::string name;
	Ogre::MovablePlane* movPlane = nullptr;
	Ogre::Camera* camRef = nullptr;
	Ogre::Camera* mainCamera = nullptr;
};

