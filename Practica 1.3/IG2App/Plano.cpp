#include "Plano.h"
#include  <OgreMeshManager.h>

Plano::Plano(Ogre::SceneNode* node) : EntidadIG(node)
{
	Ogre::MeshManager::getSingleton().createPlane("mPlane1080x800",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
		1080, 800, 100, 80, true, 1, 1.0, 1.0, Ogre::Vector3::UNIT_Z);

	Ogre::Entity* p = mSM->createEntity("mPlane1080x800");
	mNode = mSM->getRootSceneNode()->createChildSceneNode("planoNode");
	mNode->attachObject(p);
	
}
