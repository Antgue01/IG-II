#include "AspasMolino.h"
#include <SDL_keycode.h>

AspasMolino::AspasMolino(Ogre::SceneNode* node,int num):numAspas(num) {
    //La constructora pasa el nodo asociado al objeto
    //creado, como par�metro

    aspasNode = node;
    Ogre::SceneManager* mSM = aspasNode->getCreator();

   // for (int i = 0; i < numAspas; i++)
   // {

	  //Ogre::SceneNode* aspaNodeAux = aspasNode->createChildSceneNode("aspa_"+std::to_string(i));
	  //
	  ////tablero
	  //Ogre::Entity* ent = mSM->createEntity("cube.mesh");
	  //Ogre::SceneNode* tableroNode = aspaNodeAux->createChildSceneNode("tablero_"+std::to_string(i));
		//tableroNode->scale(Vector3(.5));
		//tableroNode->translate(250, 00, 0);
	  //tableroNode->attachObject(ent);
	  //tableroNode->scale(Vector3(10, 1, 0.2));

	  ////cilindro
	  //ent = mSM->createEntity("Barrel.mesh");
	  //Ogre::SceneNode* cilindroNode = aspaNodeAux->createChildSceneNode("adorno_"+std::to_string(i));
	  //cilindroNode->attachObject(ent);
	  //cilindroNode->scale(5, 10, 5);
	  //cilindroNode->setPosition(Vector3(450, -22, 20));
	 
	  //aspaNodeAux->roll(Degree((360/numAspas) * i)); //Rotamos el aspa


	  ////Rotamos y movemos los cilindros para que esten en vertical y bien colocados en cada tablero
	  //cilindroNode->roll(-Degree((360 / numAspas) * i));
	  //cilindroNode->translate(-1*(20 + Ogre::Math::Sin(Ogre::Degree(360 / numAspas * i))), 20 + Ogre::Math::Cos
	  //(Ogre::Degree(360 / numAspas * i)), 0);
		 // 
	  //cilindros.push_back(cilindroNode);

   // }

	arrayAspas = new Aspa*[numAspas];
	for (int i = 0; i < numAspas;i++)
	{
		SceneNode* aspasNodeAux = aspasNode->createChildSceneNode("aspa_" + std::to_string(i));
		arrayAspas[i] = new Aspa(aspasNodeAux,i);
		SceneNode* tablero = arrayAspas[i]->getTableroNode();
		
			tablero->scale(Vector3(.5));
			tablero->translate(250,00, 0);
		aspasNodeAux->roll(Degree((360 / numAspas) * i)); //Rotamos cada aspa 

		SceneNode* cilindroNode = arrayAspas[i]->getCilindroNode();

		cilindroNode->roll(-Degree((360 / numAspas) * i));
		cilindroNode->translate(-1*(20 + Ogre::Math::Sin(Ogre::Degree(360 / numAspas * i))), 20 + Ogre::Math::Cos
	    (Ogre::Degree(360 / numAspas * i)), 0);
		

		
	}
}


AspasMolino::~AspasMolino() 
{ 
	aspasNode->removeAndDestroyAllChildren(); 

	for(int i =0;i<numAspas;i++)
	{
		delete arrayAspas[i];
	}

	delete [] arrayAspas;
}

bool AspasMolino::keyPressed(const OgreBites::KeyboardEvent& evt) {
    if (evt.keysym.sym == SDLK_g)
    {
		//-----------------------------APARTADO 6----------------------------
		////giramos las aspas
		//if (aspasNode != nullptr)
		//	aspasNode->roll(Degree(5));
		////giramos los cilindros
		//for (SceneNode* n : cilindros)
		//{
		//	n->roll(Degree(-5));
		//}

		//-----------------------APARTADO 8------------------------------------
		if (aspasNode != nullptr) aspasNode->roll(Degree(5)); //Rotamos las aspas

		for (int i = 0; i < numAspas; i++) //Rotamos los cilindros
		{
			arrayAspas[i]->getCilindroNode()->roll(Degree(-5));
		}
				


    }
    return true;
}
