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
	
	return true;
}

void IG2App::shutdown()
{
	mShaderGenerator->removeSceneManager(mSM);
	mSM->removeRenderQueueListener(mOverlaySystem);

	mRoot->destroySceneManager(mSM);
	delete mTrayMgr;  mTrayMgr = nullptr;
	delete mCamMgr; mCamMgr = nullptr;

	if (m != nullptr) delete m;		
	if (avion != nullptr) delete avion;
	if (planoSuelo != nullptr) { planoSuelo->removeListeners(); delete planoSuelo; }
	if (planoMolino != nullptr) delete planoMolino;
	if (simbad != nullptr) delete simbad;
	if (boya != nullptr) delete boya;
	if (face != nullptr) delete face;

	// do not forget to call the base 
	IG2ApplicationContext::shutdown();
}

void IG2App::setup(void)
{
	// do not forget to call the base first
	IG2ApplicationContext::setup();
	
	mSM = mRoot->createSceneManager();
	
	//mSM->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
		

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
	vp->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0)); //0.7, 0.8, 0.9

	//------------------------------------------------------------------------

	// without light we would just get a black screen 

	Light* luz = mSM->createLight("Luz");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(1.0, 1.0, 1.0);

	mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
	//mLightNode = mCamNode->createChildSceneNode("nLuz");
	mLightNode->attachObject(luz);

	mLightNode->setDirection(Ogre::Vector3(0, -1, -1));  //vec3.normalise();
	//lightNode->setPosition(0, 0, 1000);

	//------------------------------------------------------------------------

	// finally something to render

	//---------------------------Apartado 23-----------------------------------------

	m = new Molino(mSM->getRootSceneNode()->createChildSceneNode("molino"));
	m->getNode()->translate(450, -100, -300);
	addInputListener(m);


	avion = new Avion(mSM->getRootSceneNode()->createChildSceneNode("avion"));
	avion->getNode()->scale(0.4, 0.4, 0.4);
	avion->getNode()->translate(-400, 200, 0);
	addInputListener(avion);

	simbad = new Simbad(mSM->getRootSceneNode()->createChildSceneNode("simbad"));
	simbad->getNode()->scale(15, 15, 15);		
	simbad->getNode()->translate(-400, -113, 270);
	simbad->getNode()->setInitialState();
	addInputListener(simbad);

	planoMolino = new Plano(mSM->getRootSceneNode()->createChildSceneNode("planoMolino"),300,300,"planoSueloMolino","Practica1/naranja");
	planoMolino->getNode()->translate(380, -190, -240);

	planoSuelo = new Plano(mSM->getRootSceneNode()->createChildSceneNode("plano"),1080,800,"planoSuelo","IG2App/reflejo");
	planoSuelo->getNode()->translate(0, -200, 0);
	planoSuelo->setReflejo(cam);
	

	//---------------------------Apartado 30-----------------------------------------
	/*Ogre::Entity* e = mSM->createEntity("sphere.mesh");
	e->setMaterialName("Practica1/cara");
	faceNode = mSM->getRootSceneNode()->createChildSceneNode("face");
	faceNode->attachObject(e);
	faceNode->scale(0.2, 0.2, 0.2);
	faceNode->translate(470, -170, -150);*/

	face = new Face(mSM->getRootSceneNode()->createChildSceneNode("face"));
	addInputListener(face);

	//--------------------------Apartado 36-----------------------------------
	boya = new Boya(mSM->getRootSceneNode()->createChildSceneNode("boya"));
	SceneNode* aux = boya->getNode();
	//aux->setScale(15, 15, 15);
	aux->translate(-10, -250, 50);
	aux->setInitialState();
	addInputListener(boya);

	mSM->setSkyPlane(true, Plane(Vector3::UNIT_Z, -20), "IG2/SpaceGLSL", 1, 1, true, 1.0, 10, 10);
	//mSM->setSkyPlane(true, Plane(Vector3::UNIT_Z, -200), "IG2App/space", 1, 1, true, 0.0, 10, 10);


	mCamMgr = new OgreBites::CameraMan(mCamNode);
	addInputListener(mCamMgr);
	mCamMgr->setStyle(OgreBites::CS_ORBIT);
	//mCamMgr->setTarget(mSinbadNode);  
	//mCamMgr->setYawPitchDist(Radian(0), Degree(30), 100);

	//------------------------------------------------------------------------

}

