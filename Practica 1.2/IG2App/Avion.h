
#include "AspasMolino.h"
#pragma once
class Avion:public OgreBites::InputListener
{
public:
	Avion(Ogre::SceneNode* node){
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
	aspas1 = new AspasMolino(mNode->createChildSceneNode("helice1node"), 6,"asdfg");
	helice1Node = aspas1->getNode();
	aspas2 = new AspasMolino(mNode->createChildSceneNode("helice2node"), 6,"aea");
	helice2Node = aspas2->getNode();
	helice1Node->scale(.1, .1, .1);
	helice2Node->scale(.1,.1,.1);
	AlaDNode->translate(200, 0, 0);
	AlaDNode->scale(2.3, .2, 1);
	AlaINode->translate(-200, 0,0);
	AlaINode->scale(2.3, .2, 1);
	pilotoNode->yaw(Degree(180));
	pilotoNode->translate(0,-50,0);

	}
	~Avion() { mNode->removeAndDestroyAllChildren(); }
	// M�todos de InputListener que pueden redefinirse

	virtual void frameRendered(const Ogre::FrameEvent& evt) { }
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual bool keyReleased(const OgreBites::KeyboardEvent& evt) { return true; }
	virtual bool mousePressed(const OgreBites::MouseButtonEvent& evt) { return true; }
	virtual bool mouseRelease(const OgreBites::MouseButtonEvent& evt) { return true; }
	virtual bool mouseMoved(const OgreBites::MouseMotionEvent& evt) { return true; }
	virtual bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) { return true; }
protected:
	Ogre::SceneNode* mNode;
	Ogre::SceneNode* cuerpoNode;
	Ogre::SceneNode* AlaINode;
	Ogre::SceneNode* AlaDNode;
	Ogre::SceneNode* frenteNode;
	Ogre::SceneNode* pilotoNode;
	Ogre::SceneNode* helice1Node;
	Ogre::SceneNode* helice2Node;
	AspasMolino* aspas1;
	AspasMolino* aspas2;
};

