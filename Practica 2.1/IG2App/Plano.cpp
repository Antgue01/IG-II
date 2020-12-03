#include "Plano.h"
#include  <OgreMeshManager.h>

Plano::Plano(Ogre::SceneNode* node, int ancho, int largo, std::string name, std::string matName) : EntidadIG(node), name(name)
{
	EntidadIG::addListener(this);

	Ogre::MeshManager::getSingleton().createPlane(name,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
		ancho, largo, 100, 80, true,1, 1.0, 1.0, Ogre::Vector3::UNIT_Z);

	p = mSM->createEntity(name);
	p->setMaterialName(matName);

	mNode->attachObject(p);	
}

void Plano::viewportDimensionsChanged(Ogre::Viewport* viewport)
{
	camRef->setFarClipDistance(mainCamera->getFarClipDistance());
	camRef->setNearClipDistance(mainCamera->getNearClipDistance());
	camRef->setAspectRatio(mainCamera->getAspectRatio());
	Ogre::RealRect frust = mainCamera->getFrustumExtents();
	camRef->setFrustumExtents(frust.left,frust.right,frust.top,frust.bottom);
}

void Plano::preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
{
	EntidadIG::sendEvent(this, MSG::flipUpward);
}

void Plano::postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
{
	EntidadIG::sendEvent(this, MSG::flipRevert);
}

void Plano::receiveEvent(EntidadIG* entidad, MSG msg)
{
	if(msg == MSG::none && name== "planoSuelo")p->setMaterialName("Practica1/piedrasFondo");
}

void Plano::setReflejo(Ogre::Camera* cam)
{
	camRef = mSM->createCamera("RefCam");
	camRef->setNearClipDistance(cam->getNearClipDistance());
	camRef->setFarClipDistance(cam->getFarClipDistance());
	camRef->setAutoAspectRatio(true);
	mainCamera = cam;
	cam->getParentSceneNode()->attachObject(camRef);
	
	
	movPlane = new Ogre::MovablePlane(Ogre::Vector3::UNIT_Y, 0);
	mNode->attachObject(movPlane);

	camRef->enableReflection(movPlane);
	camRef->enableCustomNearClipPlane(movPlane);

	Ogre::TexturePtr rttRef = Ogre::TextureManager::getSingleton().createManual(
		"rttReflejo", 
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::TEX_TYPE_2D,
		(Ogre::Real)cam->getViewport()->getActualWidth(), // widht ejemplo
		(Ogre::Real)cam->getViewport()->getActualHeight(), // height ejemplo
		0, Ogre::PF_R8G8B8, Ogre::TU_RENDERTARGET);

 
	Ogre::RenderTexture* renderTexture = rttRef->getBuffer()->getRenderTarget();
	Ogre::Viewport* vpt = renderTexture->addViewport(camRef); // ocupando toda
	vpt->setClearEveryFrame(true); // la textura
	vpt->setBackgroundColour(Ogre::ColourValue::White); // black/white
	
	cam->getViewport()->addListener(this);
	renderTexture->addListener(this);
	
	Ogre::TextureUnitState* tu = p->getSubEntity(0)->getMaterial()->
		getTechnique(0)->getPass(0)->createTextureUnitState("rttReflejo");		 
	tu->setColourOperation(Ogre::LBO_MODULATE);

	tu->setProjectiveTexturing(true, camRef);
}
