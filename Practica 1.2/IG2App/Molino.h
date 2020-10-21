#pragma once
#include <OgreInput.h>
#include "AspasMolino.h"
#include <OgreCameraMan.h>
class Molino :
	public OgreBites::InputListener
{
public:
	Molino(Ogre::SceneNode* node);
	~Molino() { mNode->removeAndDestroyAllChildren(); }
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
	Ogre::SceneNode* esfera;
	Ogre::SceneNode* cilindro;
	Ogre::SceneNode* aspasnode;
	Ogre::SceneNode* aspasnodeparent;
	AspasMolino* aspas;
};

