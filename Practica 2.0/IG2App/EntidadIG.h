#pragma once
#include <OgreInput.h>
#include <OGRE\OgreSceneNode.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
enum MSG {
	none,
	flipUpwards,
	flipRevert
};

class EntidadIG : public OgreBites::InputListener
{
public:
	//Constructora y destructora
	EntidadIG(Ogre::SceneNode* node);
	virtual ~EntidadIG();

	//Vector est�tico de listeners
	static std::vector<EntidadIG*> appListeners;
	//A�adir entidad como listener al vector con push_back()
	static void addListener(EntidadIG* entidad) { appListeners.push_back(entidad); };

	void sendEvent(EntidadIG* entidad, MSG msg = MSG::none);
	virtual void receiveEvent(EntidadIG* entidad, MSG msg = MSG::none) {};
	Ogre::SceneNode* getNode() { return mNode; }
protected:
	Ogre::SceneNode* mNode;
	Ogre::SceneManager* mSM;
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt)
	{


		return false;
	};

	virtual void frameRendered(const Ogre::FrameEvent& evt) { }
	virtual bool keyReleased(const OgreBites::KeyboardEvent& evt) { return true; }
	virtual bool mousePressed(const OgreBites::MouseButtonEvent& evt) { return true; }
	virtual bool mouseRelease(const OgreBites::MouseButtonEvent& evt) { return true; }
	virtual bool mouseMoved(const OgreBites::MouseMotionEvent& evt) { return true; }
	virtual bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) { return true; }


};

