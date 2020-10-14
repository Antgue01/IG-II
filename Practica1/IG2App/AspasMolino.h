#pragma once
#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <vector>
#include "Aspa.h"

using namespace Ogre;

class AspasMolino : public OgreBites::InputListener {
public:
	AspasMolino(Ogre::SceneNode* node);
	~AspasMolino();
	// M�todos de InputListener que pueden redefinirse

	virtual void frameRendered(const Ogre::FrameEvent& evt) { }
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
	virtual bool keyReleased(const OgreBites::KeyboardEvent& evt) { return true; }
	virtual bool mousePressed(const OgreBites::MouseButtonEvent& evt) { return true; }
	virtual bool mouseRelease(const OgreBites::MouseButtonEvent& evt) { return true; }
	virtual bool mouseMoved(const OgreBites::MouseMotionEvent& evt) { return true; }
	virtual bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) { return true; }

protected:

	SceneNode* aspasNode = nullptr;
	int numAspas = 12;
	Ogre::SceneManager* mSM = nullptr;
	/*std::vector<Ogre::SceneNode*> cilindros;*/
	Aspa** arrayAspas;

};

