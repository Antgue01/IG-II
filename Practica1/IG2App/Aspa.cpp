#include "Aspa.h"
#include <SDL_keycode.h>

Aspa::Aspa(Ogre::SceneNode* node, int i) {
	//La constructora pasa el nodo asociado al objeto
	//creado, como parámetro

	aspaNode = node;
	Ogre::SceneManager* mSM = aspaNode->getCreator();

	//tablero
    Ogre::Entity* ent = mSM->createEntity("cube.mesh");
    tableroNode = aspaNode->createChildSceneNode("tablero_"+std::to_string(i));
    tableroNode->attachObject(ent);
    tableroNode->scale(Vector3(10,1,0.2));

    //cilindro
    ent = mSM->createEntity("column.mesh");
    cilindroNode = aspaNode->createChildSceneNode("adorno_"+std::to_string(i));
    cilindroNode->attachObject(ent);
    cilindroNode->scale(1, 0.2, 1);
    cilindroNode->translate(Vector3(450,-22,20));
}

bool Aspa::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_g)  
	{	
        
	}
	return true;
}