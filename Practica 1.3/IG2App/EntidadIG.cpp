#include "EntidadIG.h"

// Inicializaci�n del vector de listeners
std::vector<EntidadIG*> EntidadIG::appListeners = std::vector<EntidadIG*>(0, nullptr);

EntidadIG::EntidadIG(Ogre::SceneNode* nodo) {
	mNode = nodo;
	mSM = mNode->getCreator();
}

EntidadIG::~EntidadIG() {

	mNode->removeAndDestroyAllChildren();
}

void EntidadIG::sendEvent(EntidadIG* entidad)
{
	for (EntidadIG* e : appListeners)
		e->receiveEvent(this);
}
