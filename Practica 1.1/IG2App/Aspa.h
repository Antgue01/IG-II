#pragma once
#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

using namespace Ogre;

class Aspa : public OgreBites::InputListener {
public:
	Aspa(Ogre::SceneNode* node,int i); 
	~Aspa() { aspaNode->removeAndDestroyAllChildren();}
	// M�todos de InputListener que pueden redefinirse

	virtual void frameRendered(const Ogre::FrameEvent& evt) { }
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual bool keyReleased(const OgreBites::KeyboardEvent& evt){ return true; }
	virtual bool mousePressed(const OgreBites::MouseButtonEvent& evt){ return true; }
	virtual bool mouseRelease(const OgreBites::MouseButtonEvent& evt){ return true; }
	virtual bool mouseMoved(const OgreBites::MouseMotionEvent& evt){ return true; }
	virtual bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt){ return true; }
	inline SceneNode* getCilindroNode() { return cilindroNode; }


protected:
	
	SceneNode* aspaNode = nullptr;
	SceneNode* tableroNode = nullptr;
	SceneNode* cilindroNode = nullptr;
	Ogre::SceneManager* mSM = nullptr;

};

