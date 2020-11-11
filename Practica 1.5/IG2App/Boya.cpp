#include "Boya.h"

Boya::Boya(Ogre::SceneNode* n) : EntidadIG(n), ent(nullptr) {
	ent = mSM->createEntity("Barrel.mesh");
	mNode->attachObject(ent);
	ent->setMaterialName("Practica1/cuadros");

	mNode->setScale(15, 25, 15);

	int duracion = 16;
	Ogre::Animation* anim = mSM->createAnimation("AnimVV", duracion);
	Ogre::NodeAnimationTrack* track = anim->createNodeTrack(0);
	int durPaso = duracion / 4;
	int longDesp = 100;
	track->setAssociatedNode(mNode);

	Ogre::Vector3 pos(-10, -250, 50);	 

	Ogre::Vector3 src(0, 0, 1);


	Ogre::TransformKeyFrame* kf = track->createNodeKeyFrame(0 * durPaso); //Frame 0
	kf->setScale(mNode->getScale());
	kf->setTranslate(pos);
	
	kf = track->createNodeKeyFrame(1 * durPaso);  //Frame 1
	pos += Ogre::Vector3::UNIT_Y * longDesp;
	kf->setTranslate(pos);
	kf->setRotation(src.getRotationTo(Ogre::Vector3(1, 0, 1))); // Yaw(45) 
	kf->setScale(mNode->getScale());

	kf = track->createNodeKeyFrame(2 * durPaso);  //Frame 2
	pos += Ogre::Vector3::NEGATIVE_UNIT_Y * longDesp;
	kf->setTranslate(pos);
	kf->setScale(mNode->getScale());
	

	kf = track->createNodeKeyFrame(3 * durPaso);  //Frame 3
	pos += Ogre::Vector3::UNIT_Y * longDesp;
	kf->setTranslate(pos);
	kf->setScale(mNode->getScale());
	kf->setRotation(src.getRotationTo(Ogre::Vector3(-1, 0, 1))); // Yaw(-45) 

	kf = track->createNodeKeyFrame(4 * durPaso);  //Frame 4
	pos += Ogre::Vector3::NEGATIVE_UNIT_Y * longDesp;
	kf->setTranslate(pos);
	kf->setScale(mNode->getScale());

	animS = mSM->createAnimationState("AnimVV");
	animS->setEnabled(true);
	animS->setLoop(true);
}


void Boya::frameRendered(const Ogre::FrameEvent& evt)
{
	animS->addTime(evt.timeSinceLastFrame);
}
