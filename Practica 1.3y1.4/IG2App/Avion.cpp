#include "Avion.h"
#include <SDL_keycode.h>

Avion::Avion(Ogre::SceneNode* node) : EntidadIG(node)
{
	//-------------------Apartado 26-------------------------
	Ogre::Light* luz = mSM->createLight("LuzFoco");
	luz->setType(Ogre::Light::LT_SPOTLIGHT);
	luz->setDiffuseColour(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
	luz->setDirection(Ogre::Vector3(1, -1, 0));
	luz->setSpotlightInnerAngle(Ogre::Degree(5.0f));
	luz->setSpotlightOuterAngle(Ogre::Degree(45.0f));
	luz->setSpotlightFalloff(0.0f);
	luz->setCastShadows(false);

	foco = mNode->createChildSceneNode();
	foco->attachObject(luz);



	Ogre::Entity* ent = mSM->createEntity("sphere.mesh");
	cuerpoNode = mNode->createChildSceneNode("cuerpoNode");
	cuerpoNode->attachObject(ent);
	ent->setMaterialName("Practica1/rojo");

	ent = mSM->createEntity("cube.mesh");
	ent->setMaterialName("Practica1/cuadros");
	AlaINode = mNode->createChildSceneNode("AlaInode");
	AlaINode->attachObject(ent);
	ent = mSM->createEntity("cube.mesh");
	ent->setMaterialName("Practica1/cuadros");
	AlaDNode = mNode->createChildSceneNode("AlaDnode");
	AlaDNode->attachObject(ent);

	ent = mSM->createEntity("Barrel.mesh");
	frenteNode = mNode->createChildSceneNode("frenteNode");
	frenteNode->attachObject(ent);
	ent->setMaterialName("Practica1/naranja");

	ent = mSM->createEntity("ninja.mesh");
	pilotoNode = mNode->createChildSceneNode("PilotoInode");
	pilotoNode->attachObject(ent);
	ent->setMaterialName("Practica1/amarillo");

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

//----------------------Apartado 25-------------------------------
void Avion::frameRendered(const Ogre::FrameEvent& evt)
{
	Ogre::Real time = evt.timeSinceLastFrame;
	
	aspas1->roll(time * -500);
	aspas2->roll(time * -500);

	mNode->translate(400, 0, 0,Ogre::Node::TS_LOCAL);
	mNode->yaw(Degree(50*time));
    mNode->translate(-400, 0, 0, Ogre::Node::TS_LOCAL);
}
