#include "Molino.h"
#include <SDL_keycode.h>
Molino::Molino(Ogre::SceneNode* node)	{
	mNode = node;
	Ogre::SceneManager* mSM = mNode->getCreator();

	//nodo ficticio
	/*aspasnodeparent = mNode->createChildSceneNode("nodeparent");
	aspas = new AspasMolino(aspasnodeparent->createChildSceneNode("aspas"),6);
	aspas->getNode()->scale(Vector3(.25));
	aspas->getNode()->translate(Vector3(0, 100, 80));*/

	//truco
	aspasNode = mNode->createChildSceneNode("aspasParent");
	aspas = new AspasMolino(aspasNode->createChildSceneNode("aspas"),6);
	aspasNode->scale(Vector3(.25));
	aspasNode->translate(Vector3(0, 100, 80));

	cilindro = mNode->createChildSceneNode("cilindro");
	Ogre::Entity* ent = mSM->createEntity("Barrel.mesh");
	cilindro->attachObject(ent);
	cilindro->scale(Vector3(30));
	cilindro->translate(Vector3(0, 0, 0));

	esfera = mNode->createChildSceneNode("esfera");
	ent = mSM->createEntity("sphere.mesh");
	esfera->attachObject(ent);
	esfera->scale(Vector3(.75));
	esfera->translate(Vector3(0, 100, 0));

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
		/*aspasnodeparent->yaw(Degree(5));*/

		//truco
		aspasNode->translate(0, -100, -80,Ogre::Node::TS_LOCAL);
		aspasNode->yaw(Degree(5));
		aspasNode->translate(0, 100, 80, Ogre::Node::TS_LOCAL);
	}
	return false;
}
