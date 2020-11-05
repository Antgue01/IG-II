#include "Simbad.h"

Simbad::Simbad(Ogre::SceneNode* node) : EntidadIG(node)
{
	Ogre::Entity* e = mSM->createEntity("Sinbad.mesh");
	mNode->attachObject(e);
}
