#pragma once
#include "AspasMolino.h"
#include "EntidadIG.h"
#include <OgreCameraMan.h>
#include<OgreBillboardSet.h>
#include<OgreParticleSystem.h>

class Avion : public EntidadIG
{
public:
	Avion(Ogre::SceneNode* node); 
	virtual ~Avion() { EntidadIG::~EntidadIG(); delete aspas1; delete aspas2; }

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	void receiveEvent(EntidadIG* entidad, MSG msg = MSG::none);
	
protected:
	Ogre::SceneNode* cuerpoNode;
	Ogre::SceneNode* AlaINode;
	Ogre::SceneNode* AlaDNode;
	Ogre::SceneNode* frenteNode;
	Ogre::SceneNode* pilotoNode;
	Ogre::SceneNode* helice1Node;
	Ogre::SceneNode* helice2Node;
	Ogre::SceneNode* foco;
	Ogre::Light* luz;
	AspasMolino* aspas1;
	AspasMolino* aspas2;
	bool rotate = true;
	BillboardSet* Bbs;
	Ogre::SceneNode* BboardNode;
	ParticleSystem* pSystem;
	ParticleSystem* smokeTrail;
	Ogre::SceneNode* smokeTrailNode;
	Ogre::SceneNode* pSystemNode;

};

