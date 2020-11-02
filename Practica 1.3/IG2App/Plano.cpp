#include "Plano.h"
#include  <OgreMeshManager.h>

Plano::Plano(Ogre::SceneNode* node, int ancho, int largo, std::string name) : EntidadIG(node)
{
	Ogre::MeshManager::getSingleton().createPlane(name,
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::Plane(Ogre::Vector3::UNIT_Y, 0),
		ancho, largo, 100, 80, true,1, 1.0, 1.0, Ogre::Vector3::UNIT_Z);

	Ogre::Entity* p = mSM->createEntity(name);
	//mNode = mSM->getRootSceneNode()->createChildSceneNode("planoNode");
	mNode->attachObject(p);
	
}
