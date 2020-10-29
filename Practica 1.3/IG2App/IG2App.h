#ifndef __IG2App_H__
#define __IG2App_H__

#include "IG2ApplicationContext.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include <vector>
#include "Plano.h"
#include "AspasMolino.h"
#include "Molino.h"
#include "Avion.h"

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


  OgreBites::CameraMan* mCamMgr = nullptr;


  SceneNode* Clock = nullptr;
  SceneNode* padreEsferas = nullptr;
  SceneNode* segundero = nullptr;
  SceneNode* minutero = nullptr;
  SceneNode* horas = nullptr;
  SceneNode* tierra = nullptr;
  SceneNode* sol = nullptr;
  SceneNode* luna = nullptr;
  std::vector<SceneNode*> spheres;
  Plano* planoNode = nullptr;
  Molino* m = nullptr;
  
};

#endif
