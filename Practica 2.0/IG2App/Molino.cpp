#include "Molino.h"
#include <SDL_keycode.h>

Molino::Molino(Ogre::SceneNode* node) : EntidadIG(node)
{	

	EntidadIG::addListener(this);

	//nodo ficticio
	/*aspasnodeparent = mNode->createChildSceneNode("nodeparent");
	aspas = new AspasMolino(aspasnodeparent->createChildSceneNode("aspas"),6);
	aspas->getNode()->scale(Vector3(.25));
	aspas->getNode()->translate(Vector3(0, 100, 80));*/

	//truco
	aspasNode = mNode->createChildSceneNode("aspasParent");
	aspas = new AspasMolino(aspasNode->createChildSceneNode("aspas"), 6);
	aspasNode->scale(Vector3(.25));
	aspasNode->translate(Vector3(0, 100, 80));

	cilindro = mNode->createChildSceneNode("cilindro");
	Ogre::Entity* ent = mSM->createEntity("Barrel.mesh");
	cilindro->attachObject(ent);
	cilindro->scale(Vector3(30));
	cilindro->translate(Vector3(0, 0, 0));
	ent->setMaterialName("Practica1/piedra");

	esfera = mNode->createChildSceneNode("esfera");
	entEsfera = mSM->createEntity("sphere.mesh");
	esfera->attachObject(entEsfera);
	esfera->scale(Vector3(.75));
	esfera->translate(Vector3(0, 100, 0));
	entEsfera->setMaterialName("Practica1/amarillo");
}

//----------------------Apartado 24-------------------------------
void Molino::frameRendered(const Ogre::FrameEvent& evt)
{
	if (moverAspas)
	{
	  Ogre::Real time = evt.timeSinceLastFrame;
	  aspas->roll(time * 15);
	}
}

bool Molino::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_g)
	{
		if (!anim)
			aspas->roll(5);
	}
	else if (evt.keysym.sym == SDLK_c) {
		aspas->getCentralCylinderNode()->translate(Vector3(0, 0, -5));
	}
	else if (evt.keysym.sym == SDLK_h) {
		//nodo ficticio
		//aspasnodeparent->yaw(Degree(5));

		//truco
		aspasNode->translate(0, 0, -80, Ogre::Node::TS_LOCAL);
		aspasNode->yaw(Degree(5));
		aspasNode->translate(0, 0, 80, Ogre::Node::TS_LOCAL);
	}
	return false;
}

//---------------Apartado 31--------------------
void Molino::receiveEvent(EntidadIG* entidad,MSG msg) 
{
	if (msg == MSG::none)
	{
	  entEsfera->setMaterialName("Practica1/rojo");
	  moverAspas = !moverAspas;
	}
}


