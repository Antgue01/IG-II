#include "Simbad.h"

Simbad::Simbad(Ogre::SceneNode* node) : EntidadIG(node), swordent(nullptr)
{
	simbadEnt = mSM->createEntity("Sinbad.mesh");
	mNode->attachObject(simbadEnt);
	dance = simbadEnt->getAnimationState("Dance");
	dance->setLoop(true);
	runlegs = simbadEnt->getAnimationState("RunBase");
	runlegs->setEnabled(true);
	runlegs->setLoop(true);
	runarms = simbadEnt->getAnimationState("RunTop");
	runarms->setLoop(true);
	runarms->setEnabled(true);


	mNode->setScale(15, 15, 15);

	int duracion = 8;
	Ogre::Animation* anim = mSM->createAnimation("Moverse", duracion);
	Ogre::NodeAnimationTrack* track = anim->createNodeTrack(0);
	int durPaso = duracion / 2;
	int longDespX = 450;
	int longDespZ = 300;
	track->setAssociatedNode(mNode);

	Ogre::Vector3 pos(-450, -113, 300);
	Ogre::Vector3 src(0, 0, 1);

	Ogre::TransformKeyFrame* kf = track->createNodeKeyFrame(0 * durPaso); //Frame 0
	kf->setScale(mNode->getScale());
	kf->setTranslate(pos);
	kf->setRotation(src.getRotationTo(Ogre::Vector3(1, 0, -1))); // Yaw(45) 

	kf = track->createNodeKeyFrame(1 * durPaso);  //Frame 1
	pos += Ogre::Vector3(longDespX,0, -longDespZ);
	kf->setTranslate(pos);	
	kf->setScale(mNode->getScale());
	kf->setRotation(src.getRotationTo(Ogre::Vector3(-1, 0, 1))); // Yaw(45) 

	kf = track->createNodeKeyFrame(2 * durPaso);  //Frame 2
	pos += Ogre::Vector3(-longDespX, 0, longDespZ);
	kf->setTranslate(pos);
	kf->setScale(mNode->getScale());
	kf->setRotation(src.getRotationTo(Ogre::Vector3(1, 0, -1))); // Yaw(45) 


	moverse = mSM->createAnimationState("Moverse");
	moverse->setEnabled(true);
	moverse->setLoop(true);
}

void Simbad::frameRendered(const Ogre::FrameEvent& evt)
{
	if (danceBool)
		dance->addTime(evt.timeSinceLastFrame);
	else {
		runlegs->addTime(evt.timeSinceLastFrame);
		runarms->addTime(evt.timeSinceLastFrame);
	}

	moverse->addTime(evt.timeSinceLastFrame);


}

bool Simbad::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	switch (evt.keysym.sym) {
	case 'c': {
		if (danceBool) {
			danceBool = false;
			dance->setEnabled(false);
			runarms->setEnabled(true);
			runlegs->setEnabled(true);
		}
		else {
			danceBool = true;
			dance->setEnabled(true);
			runarms->setEnabled(false);
			runlegs->setEnabled(false);
		}
		break;
	}
	case 'e': {
		if (swordent == nullptr)
		{
			swordent = mSM->createEntity("Sword.mesh");
			simbadEnt->attachObjectToBone("Handle.R", swordent);
		}
		else {
			simbadEnt->detachObjectFromBone(swordent);
			if (rightHand)
			{
				rightHand = false;
				simbadEnt->attachObjectToBone("Handle.L", swordent);
			}
			else {
				rightHand = true;
				simbadEnt->attachObjectToBone("Handle.R", swordent);

			}
		}

		break;
	}
}
	return false;
}
