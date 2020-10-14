#ifndef __IG2App_H__
#define __IG2App_H__

#include "IG2ApplicationContext.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include <vector>
#include "AspasMolino.h"

class IG2App : public  OgreBites::IG2ApplicationContext, OgreBites::InputListener 
{
public:
  explicit IG2App() : IG2ApplicationContext("IG2App") { };  // new -> setup()  
  virtual ~IG2App() { };   // delete -> shutdown()  
 
protected:
  virtual void setup();
  virtual void shutdown();
  virtual void setupScene();

  virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
      
  Ogre::SceneManager* mSM = nullptr;
  OgreBites::TrayManager* mTrayMgr = nullptr;    
  Ogre::SceneNode* mLightNode = nullptr;
  Ogre::SceneNode* mCamNode = nullptr;
  //Ogre::SceneNode* aspaNode = nullptr; //Apartado 1

 // Ogre::SceneNode* aspasNode = nullptr; //Apartado 2

  OgreBites::CameraMan* mCamMgr = nullptr;

  //int numAspas = 12;
  //std::vector<Ogre::SceneNode*> cilindros;

  AspasMolino* aspasMolino = nullptr;
 
};

#endif
