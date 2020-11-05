#pragma once
#include <OgreInput.h>
#include "AspasMolino.h"
#include <OgreCameraMan.h>
#include "EntidadIG.h"

class Molino : public EntidadIG
	
{
public:
	Molino(Ogre::SceneNode* node);
	virtual ~Molino() { EntidadIG::~EntidadIG();  delete aspas; }
	
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
			
protected:
	Ogre::SceneNode* esfera;
	Ogre::SceneNode* cilindro;
	Ogre::SceneNode* aspasnode;
	Ogre::SceneNode* aspasnodeparent;
	AspasMolino* aspas;
	bool anim = true;
};

