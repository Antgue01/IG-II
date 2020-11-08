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

void Plano::receiveEvent(EntidadIG* entidad)
{
	if(name== "planoSuelo")p->setMaterialName("Practica1/piedrasFondo");

}
