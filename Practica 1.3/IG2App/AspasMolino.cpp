#include "AspasMolino.h"
#include <SDL_keycode.h>

AspasMolino::AspasMolino(Ogre::SceneNode* node, int num, std::string nombre) : EntidadIG(node),numAspas(num) 
{
	
	arrayAspas = new Aspa * [numAspas];
	cilindroCentral = mNode->createChildSceneNode("cilindrocentral" + (nombre));
	Ogre::Entity * ent = mSM->createEntity("Barrel.mesh");
	cilindroCentral->attachObject(ent);
	cilindroCentral->scale(Vector3(13));
	cilindroCentral->pitch(Ogre::Degree(90));
	//cilindroCentral->translate(Vector3())
	for (int i = 0; i < numAspas; i++)
	{
		SceneNode* aspasNodeAux = mNode->createChildSceneNode("aspa_" + std::to_string(i) + (nombre));
		arrayAspas[i] = new Aspa(aspasNodeAux, i,nombre);

		aspasNodeAux->roll(Degree((360 / numAspas) * i)); //Rotamos cada aspa 
		SceneNode* tablero = arrayAspas[i]->getTableroNode();

		tablero->scale(Vector3(.5));
		tablero->translate(250, 00, 0);
		SceneNode* cilindroNode = arrayAspas[i]->getCilindroNode();

		cilindroNode->roll(-Degree((360 / numAspas) * i));
		cilindroNode->translate(-1 * (20 + Ogre::Math::Sin(Ogre::Degree(360 / numAspas * i))), 20 + Ogre::Math::Cos
		(Ogre::Degree(360 / numAspas * i)), 0);

	}
}

AspasMolino::~AspasMolino()
{
	EntidadIG::~EntidadIG();

	for (int i = 0; i < numAspas; i++)
	{
		delete arrayAspas[i];
	}

	delete[] arrayAspas;
}

bool AspasMolino::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_g)
	{
		roll(5);
	}
	return true;
}

void AspasMolino::roll(float degrees)
{
	if (mNode != nullptr) mNode->roll(Degree(degrees)); //Rotamos las aspas

	for (int i = 0; i < numAspas; i++) //Rotamos los cilindros
	{
		arrayAspas[i]->getCilindroNode()->roll(Degree(-degrees));
	}
}
