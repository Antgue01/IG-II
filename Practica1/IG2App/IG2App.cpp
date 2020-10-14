#include "IG2App.h"

#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>
#include "Aspa.h";


using namespace Ogre;

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt)
{
  if (evt.keysym.sym == SDLK_ESCAPE)
  {
    getRoot()->queueEndRendering();
  }
  //-----------------APARTADO 3---------------------
  //else if (evt.keysym.sym == SDLK_g)
  //{

	 
	 // ////giramos las aspas
	 // //if (aspasNode != nullptr)
		// // aspasNode->roll(Degree(5));
	 // ////giramos los cilindros
	 // //for(SceneNode* n : cilindros)
	 // //{
		// // n->roll(Degree(-5));
	 // //}
  //}
  
  return true;
}

void IG2App::shutdown()
{
  mShaderGenerator->removeSceneManager(mSM);  
  mSM->removeRenderQueueListener(mOverlaySystem);  
					
  mRoot->destroySceneManager(mSM);  

  delete mTrayMgr;  mTrayMgr = nullptr;
  delete mCamMgr; mCamMgr = nullptr;

  if(aspasMolino!=nullptr) delete aspasMolino;
  
  // do not forget to call the base 
  IG2ApplicationContext::shutdown();
}

void IG2App::setup(void)
{
  // do not forget to call the base first
  IG2ApplicationContext::setup();

  mSM = mRoot->createSceneManager();  

  // register our scene with the RTSS
  mShaderGenerator->addSceneManager(mSM);

  mSM->addRenderQueueListener(mOverlaySystem);

  mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);  
  mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
  addInputListener(mTrayMgr);

  addInputListener(this);   
  setupScene();
}

void IG2App::setupScene(void)
{
  // create the camera
  Camera* cam = mSM->createCamera("Cam");
  cam->setNearClipDistance(1); 
  cam->setFarClipDistance(10000);
  cam->setAutoAspectRatio(true);
  //cam->setPolygonMode(Ogre::PM_WIREFRAME); 

  mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
  mCamNode->attachObject(cam);

  mCamNode->setPosition(0, 0, 1000);
  mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);
  //mCamNode->setDirection(Ogre::Vector3(0, 0, -1));  
  
  // and tell it to render into the main window
  Viewport* vp = getRenderWindow()->addViewport(cam);
  vp->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));

  //------------------------------------------------------------------------

  // without light we would just get a black screen 

  Light* luz = mSM->createLight("Luz");
  luz->setType(Ogre::Light::LT_DIRECTIONAL);
  luz->setDiffuseColour(0.75, 0.75, 0.75);

  mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
  //mLightNode = mCamNode->createChildSceneNode("nLuz");
  mLightNode->attachObject(luz);

  mLightNode->setDirection(Ogre::Vector3(0, 0, -1));  //vec3.normalise();
  //lightNode->setPosition(0, 0, 1000);
 
  //------------------------------------------------------------------------

  // finally something to render


  //-------------------------APARTADO 1---------------------

  //Nodo aspa
  //aspaNode = mSM->getRootSceneNode()->createChildSceneNode("aspa");

  //Nodo tablero
 /* Ogre::Entity* ent = mSM->createEntity("cube.mesh");
  Ogre::SceneNode* tableroNode = aspaNode->createChildSceneNode("tablero");
  tableroNode->attachObject(ent);
  tableroNode->scale(Vector3(10,1,0.2));*/

  //Nodo cilindro
  /*ent = mSM->createEntity("column.mesh");
  Ogre::SceneNode* cilindroNode = aspaNode->createChildSceneNode("adorno"); 
  cilindroNode->attachObject(ent);
  cilindroNode->scale(1, 0.2, 1);
  cilindroNode->translate(Vector3(450,-22,20));*/
  
  //------------------------APARTADO 2-----------------------------------

  //aspasNode = mSM->getRootSceneNode()->createChildSceneNode("aspas");

  //for (int i = 0; i < numAspas; i++)
  //{

	 // Ogre::SceneNode* aspaNodeAux = aspasNode->createChildSceneNode("aspa_"+std::to_string(i));
	 // 
	 // //tablero
	 // Ogre::Entity* ent = mSM->createEntity("cube.mesh");
	 // Ogre::SceneNode* tableroNode = aspaNodeAux->createChildSceneNode("tablero_"+std::to_string(i));
	 // tableroNode->attachObject(ent);
	 // tableroNode->scale(Vector3(10, 1, 0.2));
	
	 // //cilindro
	 // ent = mSM->createEntity("column.mesh");
	 // Ogre::SceneNode* cilindroNode = aspaNodeAux->createChildSceneNode("adorno_"+std::to_string(i));
	 // cilindroNode->attachObject(ent);
	 // cilindroNode->scale(1, 0.2, 1);
	 // cilindroNode->setPosition(Vector3(450, -22, 20));
	 //
	 // aspaNodeAux->roll(Degree((360/numAspas) * i)); //Rotamos el aspa


	 // //Rotamos y movemos los cilindros para que esten en vertical y bien colocados en cada tablero
	 // cilindroNode->roll(-Degree((360 / numAspas) * i));
	 // cilindroNode->translate(-1*(20 + Ogre::Math::Sin(Ogre::Degree(360 / numAspas * i))), 20 + Ogre::Math::Cos
	 // (Ogre::Degree(360 / numAspas * i)), 0);
		//  
	 // cilindros.push_back(cilindroNode);

  //}

  //-----------------APARTADO 4----------------------

  /*Aspa* aspa = new Aspa(mSM->getRootSceneNode()->createChildSceneNode("aspa"));
  addInputListener(aspa);*/
  //-------------------APARTADO 5---------------------------

   aspasMolino = new AspasMolino(mSM->getRootSceneNode()->createChildSceneNode("aspas"));
   addInputListener(aspasMolino);



  //------------------------------------------------------------------------

  mCamMgr = new OgreBites::CameraMan(mCamNode);
  addInputListener(mCamMgr);
  mCamMgr->setStyle(OgreBites::CS_ORBIT);  
  
  //mCamMgr->setTarget(mSinbadNode);  
  //mCamMgr->setYawPitchDist(Radian(0), Degree(30), 100);

  //------------------------------------------------------------------------

}

