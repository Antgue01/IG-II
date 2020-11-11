#pragma once
#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include "EntidadIG.h"

using namespace Ogre;

class Aspa : public EntidadIG {
public:
	Aspa(Ogre::SceneNode* node,int i,std::string nombre="a"); 
	 ~Aspa() { }
	


	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	void receiveEvent(EntidadIG* entidad);
	inline SceneNode* getCilindroNode() { return cilindroNode; }
	inline SceneNode* getTableroNode() { return tableroNode; }


protected:	
	 //aspaNode heredado de EntidadIG
	SceneNode* tableroNode = nullptr;
	SceneNode* cilindroNode = nullptr;
};

