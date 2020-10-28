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
	// M�todos de InputListener que pueden redefinirse

	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	

	virtual void receiveEvent(EntidadIG* entidad);
		
	


protected:
	Ogre::SceneNode* esfera;
	Ogre::SceneNode* cilindro;
	Ogre::SceneNode* aspasnode;
	Ogre::SceneNode* aspasnodeparent;
	AspasMolino* aspas;
};

