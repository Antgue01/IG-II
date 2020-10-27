#include "Aspa.h"
#include <SDL_keycode.h>

Aspa::Aspa(Ogre::SceneNode* node, int i,std::string nombre) {
	//La constructora pasa el nodo asociado al objeto
	//creado, como par�metro

	aspaNode = node;
	Ogre::SceneManager* mSM = aspaNode->getCreator();

	//tablero
    Ogre::Entity* ent = mSM->createEntity("cube.mesh");
    tableroNode = aspaNode->createChildSceneNode("tablero_"+std::to_string(i)+nombre);
    tableroNode->attachObject(ent);
    tableroNode->scale(Vector3(10,1,0.2));

    //cilindro
    ent = mSM->createEntity("Barrel.mesh");
    
    cilindroNode = aspaNode->createChildSceneNode("adorno_"+std::to_string(i)+nombre);
    cilindroNode->attachObject(ent);
    cilindroNode->scale(5, 10, 5);
    cilindroNode->translate(Vector3(450,-22,20));
}

bool Aspa::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_g)  
	{	
        
	}
	return true;
}