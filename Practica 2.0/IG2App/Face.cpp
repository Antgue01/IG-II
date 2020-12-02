#include "Face.h"

Face::Face(Ogre::SceneNode* node):EntidadIG(node)
{
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/cara");
	mNode->attachObject(ent);
	mNode->scale(0.2, 0.2, 0.2);
	mNode->translate(470, -170, -150);
	EntidadIG::addListener(this);
	
	
}

void Face::receiveEvent(EntidadIG* entidad, MSG msg)
{
	if (msg == MSG::flipUpwards)
		ent->setMaterialName("IG2App/cara");
	else if (msg == MSG::flipRevert)
		ent->setMaterialName("Practica1/cara");
}


