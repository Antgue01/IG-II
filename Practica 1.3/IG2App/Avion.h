
#include "AspasMolino.h"
#pragma once
class Avion:public OgreBites::InputListener
{
public:
	Avion(Ogre::SceneNode* node); 
	~Avion() { mNode->removeAndDestroyAllChildren(); delete aspas1; delete aspas2; }
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

