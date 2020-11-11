#pragma once
#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <vector>
#include "Aspa.h"
#include "EntidadIG.h"
using namespace Ogre;

class AspasMolino : public EntidadIG {
public:
	AspasMolino(Ogre::SceneNode* node, int num, std::string nombre = "0");
	virtual ~AspasMolino();
	// M�todos de InputListener que pueden redefinirse

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
	
	inline SceneNode* getCentralCylinderNode() { return cilindroCentral; }
	inline SceneNode* getNode() { return mNode; }
	void roll(float degrees);

protected:

	//aspasNode heredado de EntidadIG
	SceneNode* cilindroCentral = nullptr;
	int numAspas;
	/*std::vector<Ogre::SceneNode*> cilindros;*/
	Aspa** arrayAspas;

};

