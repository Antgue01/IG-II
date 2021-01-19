#include "Face.h"

Face::Face(Ogre::SceneNode* node):EntidadIG(node)
{
	EntidadIG::addListener(this);

	e = mSM->createEntity("sphere.mesh");
	e->setMaterialName("Practica1/cara");
	mNode->attachObject(e);
	mNode->scale(0.2, 0.2, 0.2);
	mNode->translate(470, -170, -150);
}

void Face::receiveEvent(EntidadIG* entidad, MSG msg)
{
	if (msg == MSG::flipUpward)
	{
		e->setMaterialName("IG2App/cara");
	}
	else if (msg == MSG::flipRevert)
	{
		e->setMaterialName("Practica1/cara"); 
	}

}


