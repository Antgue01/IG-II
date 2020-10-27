#include "Avion.h"
#include <SDL_keycode.h>

Avion::Avion(Ogre::SceneNode* node)
{
	mNode = node;
	Ogre::SceneManager* mSM = mNode->getCreator();


	Ogre::Entity* ent = mSM->createEntity("sphere.mesh");
	cuerpoNode = mNode->createChildSceneNode("cuerpoNode");
	cuerpoNode->attachObject(ent);
	ent = mSM->createEntity("cube.mesh");
	AlaINode = mNode->createChildSceneNode("AlaInode");
	AlaINode->attachObject(ent);
	ent = mSM->createEntity("cube.mesh");
	AlaDNode = mNode->createChildSceneNode("AlaDnode");
	AlaDNode->attachObject(ent);
	ent = mSM->createEntity("Barrel.mesh");
	frenteNode = mNode->createChildSceneNode("frenteNode");
	frenteNode->attachObject(ent);
	ent = mSM->createEntity("ninja.mesh");
	pilotoNode = mNode->createChildSceneNode("PilotoInode");
	pilotoNode->attachObject(ent);
	aspas1 = new AspasMolino(mNode->createChildSceneNode("helice1node"), 6, "asdfg");
	helice1Node = aspas1->getNode();
	aspas2 = new AspasMolino(mNode->createChildSceneNode("helice2node"), 6, "aea");
	helice2Node = aspas2->getNode();
	helice1Node->scale(.2, .2, .2);
	helice1Node->translate(-180, 0, 60);
	helice2Node->scale(.2, .2, .2);
	helice2Node->translate(180, 0, 60);
	AlaDNode->translate(200, 0, 0);
	AlaDNode->scale(2.3, .2, 1);
	AlaINode->translate(-200, 0, 0);
	AlaINode->scale(2.3, .2, 1);
	pilotoNode->yaw(Degree(180));
	pilotoNode->translate(0, -50, 0);
	frenteNode->scale(15, 15, 15);
	frenteNode->pitch(Degree(90));
	frenteNode->translate(0, 0, 65);

}

bool Avion::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	//-------------Apartado 17 -----------------------
	if (evt.keysym.sym == SDLK_g)
	{
		aspas1->roll(-5);
		aspas2->roll(-5);
	}
	return false;
}
