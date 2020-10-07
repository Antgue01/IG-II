#include "IG2App.h"
#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>

using namespace Ogre;

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_ESCAPE)
	{
		getRoot()->queueEndRendering();
	}
	else if (evt.keysym.sym == SDLK_g && Clock!=nullptr)
	{
		Clock->roll(Ogre::Degree(3));
	}
	else if (evt.keysym.sym == SDLK_h && padreEsferas!=nullptr) {
		padreEsferas->roll(Ogre::Degree(3));
	}

	return true;
}

void IG2App::shutdown()
{
	mShaderGenerator->removeSceneManager(mSM);
	mSM->removeRenderQueueListener(mOverlaySystem);

	mRoot->destroySceneManager(mSM);

	delete mTrayMgr;  mTrayMgr = nullptr;
	delete mCamMgr; mCamMgr = nullptr;

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
	vp->setBackgroundColour(Ogre::ColourValue(.7, .8, .9));

	//------------------------------------------------------------------------

	// without light we would just get a black screen 

	Light* luz = mSM->createLight("Luz");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(0.75, 0.75, 0.75);

	mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
	//mLightNode = mCamNode->createChildSceneNode("nLuz");
	mLightNode->attachObject(luz);
	//para la práctica 0
	//mLightNode->setDirection(Ogre::Vector3(-1, 0, 0));  //vec3.normalise();

	//para la práctica 0 cont
	mLightNode->setDirection(Ogre::Vector3(0, 0, -1));  //vec3.normalise();
	//lightNode->setPosition(0, 0, 1000);

	//------------------------------------------------------------------------

	// finally something to render

   //Escena de la espada
	/*Ogre::Entity* ent = mSM->createEntity("Sword.mesh");

	mSinbadNode = mSM->getRootSceneNode()->createChildSceneNode("nSinbad");
	mSinbadNode->attachObject(ent);
	*/
	//mSinbadNode->setPosition(400, 100, -300);
	//mSinbadNode->setScale(20, 20, 20);
	//mSinbadNode->yaw(Ogre::Degree(-45));
	//mSinbadNode->showBoundingBox(true);
	//mSinbadNode->setVisible(false);


	//escena del sinbad con los baños

/*	Ogre::Entity* ent = mSM->createEntity("RomanBathLower.mesh");
	//Nodo padre
	Ogre::SceneNode* escenario = mSM->getRootSceneNode()->createChildSceneNode("escenario");
	//Nodo para los baños
	Ogre::SceneNode* banos = escenario->createChildSceneNode("banos");
	banos->attachObject(ent);
	ent = mSM->createEntity("RomanBathUpper.mesh");
	banos->attachObject(ent);
	ent = mSM->createEntity("Columns.mesh");
	banos->attachObject(ent);
	//Nodo para sinbad
	Ogre::SceneNode* sinbad = escenario->createChildSceneNode("sinbad");
	ent = mSM->createEntity("Sinbad.mesh");
	sinbad->attachObject(ent);
	sinbad->scale(Vector3(20));
	sinbad->translate(0, 40, 0);
*/
//escena de las horas
/*	Clock = mSM->getRootSceneNode()->createChildSceneNode("Clock");
	int radious = 400;
	Ogre::Entity* ent = nullptr;
	for (int i = 0; i < 12; i++)
	{
		ent = mSM->createEntity("sphere.mesh");
		Ogre::SceneNode* aux = Clock->createChildSceneNode("Hora " + std::to_string(i));
		spheres.push_back(aux);
		aux->attachObject(ent);
		aux->setPosition(radious * Ogre::Math::Sin(Ogre::Degree(360 / 12 * i)),
			radious * Ogre::Math::Cos(Ogre::Degree(360 / 12 * i)), 0);
		aux->setScale(Vector3(.5));
	}
	for (int i = 0; i < 12; i += 2) {
		mSM->getSceneNode("Hora " + std::to_string(i))->setScale(Vector3(.25));
	}
*/
//escena del reloj con agujas
	Clock = mSM->getRootSceneNode()->createChildSceneNode("Clock");
	int radious = 400;
	Ogre::Entity* ent = nullptr;
	padreEsferas = Clock->createChildSceneNode("padreEsferas");
	for (int i = 0; i < 12; i++)
	{
		ent = mSM->createEntity("sphere.mesh");
		Ogre::SceneNode* aux = padreEsferas->createChildSceneNode("Hora " + std::to_string(i));
		spheres.push_back(aux);
		aux->attachObject(ent);
		aux->setPosition(radious * Ogre::Math::Sin(Ogre::Degree(360 / 12 * i)),
			radious * Ogre::Math::Cos(Ogre::Degree(360 / 12 * i)), 0);
		aux->setScale(Vector3(.5));
	}
	ent = mSM->createEntity("cube.mesh");
	segundero = Clock->createChildSceneNode("segundero");
	segundero->setScale(Vector3(.05, 3, 1));
	segundero->setPosition(0, -100, 0);
	segundero->attachObject(ent);

	minutero = Clock->createChildSceneNode("minutero");
	ent = mSM->createEntity("cube.mesh");
	minutero->setScale(Vector3(.1, 3.5, 1));
	minutero->setPosition(0, 100, 0);
	minutero->attachObject(ent);

	horas = Clock->createChildSceneNode("horas");
	ent = mSM->createEntity("cube.mesh");
	horas->setScale(Vector3(3, .2, 1));
	horas->setPosition(120, 0, 0);
	horas->attachObject(ent);
	//Ejercicio 20
	segundero->roll(Ogre::Degree(115));
	segundero->setPosition(-90, -50, 0);
	//------------------------------------------------------------------------

	mCamMgr = new OgreBites::CameraMan(mCamNode);
	addInputListener(mCamMgr);
	mCamMgr->setStyle(OgreBites::CS_ORBIT);

	//mCamMgr->setTarget(mSinbadNode);  
	//mCamMgr->setYawPitchDist(Radian(0), Degree(30), 100);

	//------------------------------------------------------------------------

}

