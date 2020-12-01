#include "Face.h"

Face::Face(Ogre::SceneNode* node):EntidadIG(node)
{
	Ogre::Entity* e = mSM->createEntity("sphere.mesh");
	e->setMaterialName("Practica1/cara");
	mNode->attachObject(e);
	mNode->scale(0.2, 0.2, 0.2);
	mNode->translate(470, -170, -150);
}

void Face::preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
{
	
}

void Face::postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
{
}
