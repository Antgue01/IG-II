#include "Molino.h"
#include <SDL_keycode.h>
Molino::Molino(Ogre::SceneNode* node)	{
	mNode = node;
	Ogre::SceneManager* mSM = mNode->getCreator();
	//nodo ficticio
	/*aspasnodeparent = mNode->createChildSceneNode("nodeparent");
	aspas = new AspasMolino(aspasnodeparent->createChildSceneNode("aspas"),6);*/
	aspas = new AspasMolino(mNode->createChildSceneNode("aspas"),6);
	cilindro = mNode->createChildSceneNode("cilindro");
	esfera = mNode->createChildSceneNode("esfera");
	Ogre::Entity* ent = mSM->createEntity("Barrel.mesh");
	cilindro->attachObject(ent);
	ent = mSM->createEntity("sphere.mesh");
	esfera->attachObject(ent);
	aspasnode = aspas->getNode();
	aspasnode->scale(Vector3(.25));
	aspasnode->translate(Vector3(0, 0, 80));
	esfera->scale(Vector3(.75));
	cilindro->scale(Vector3(30));
	cilindro->translate(Vector3(0, -100, 0));

}

bool Molino::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_g)
	{
		aspas->roll(5);
	}
	else if (evt.keysym.sym == SDLK_c) {
		aspas->getCentralCylinderNode()->translate(Vector3(0, 0, -5));
	}
	else if (evt.keysym.sym == SDLK_h) {
		//nodo ficticio
		//aspasnodeparent->yaw(Degree(5));

		//truco
		aspasnode->translate(0, 0, -80,Ogre::Node::TS_LOCAL);
		aspasnode->yaw(Degree(5));
		aspasnode->translate(0, 0, 80, Ogre::Node::TS_LOCAL);
	}
	return false;
}
