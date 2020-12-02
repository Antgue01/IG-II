#include "Simbad.h"

Simbad::Simbad(Ogre::SceneNode* node) : EntidadIG(node), swordent(nullptr)
{
	EntidadIG::addListener(this);
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
	idle = simbadEnt->getAnimationState("IdleTop");
	idle->setLoop(true);
	idle->setEnabled(false);


	int duracion = 16;
	Ogre::Animation* anim = mSM->createAnimation("Moverse", duracion);
	Ogre::NodeAnimationTrack* track = anim->createNodeTrack(0);
	int durPaso = duracion / 4;
	float longDespX = 400;
	float longDespZ = 270;
	track->setAssociatedNode(mNode);

	Ogre::Vector3 pos(0, 0, 0);
	Ogre::Vector3 src(0, 0, 1);
	Ogre::Vector3 rotation(400, 0, -270); rotation.normalise();

	Ogre::TransformKeyFrame* kf = track->createNodeKeyFrame(0 * durPaso); //Frame 0->posicion inicial
	kf->setTranslate(pos);
	kf->setRotation(src.getRotationTo(rotation));

	kf = track->createNodeKeyFrame(1 * durPaso);  //Frame 1-> va hacia el centro
	pos += Ogre::Vector3(longDespX, 0, -longDespZ);
	kf->setTranslate(pos);
	kf->setRotation(src.getRotationTo(rotation));

	kf = track->createNodeKeyFrame(2 * durPaso);  //Frame 2-> en el centro gira
	kf->setTranslate(pos);
	rotation = { -longDespX,0,longDespZ }; rotation.normalise();
	kf->setRotation(src.getRotationTo(rotation));

	kf = track->createNodeKeyFrame(3 * durPaso);  //Frame 3-> vuelve
	pos += Ogre::Vector3(-longDespX, 0, longDespZ);
	kf->setTranslate(pos);
	kf->setRotation(src.getRotationTo(rotation));

	moverse = mSM->createAnimationState("Moverse");
	moverse->setEnabled(true);
	moverse->setLoop(true);

	swordent = mSM->createEntity("Sword.mesh");
	simbadEnt->attachObjectToBone("Handle.R", swordent);
}

void Simbad::frameRendered(const Ogre::FrameEvent& evt)
{
	if (dead)idle->addTime(evt.timeSinceLastFrame);
	else if (danceBool)
		dance->addTime(evt.timeSinceLastFrame);
	else {
		runlegs->addTime(evt.timeSinceLastFrame);
		runarms->addTime(evt.timeSinceLastFrame);
		moverse->addTime(evt.timeSinceLastFrame);
	}


}

bool Simbad::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	switch (evt.keysym.sym) {
	case 'c': {
		if (!dead)
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

void Simbad::receiveEvent(EntidadIG* entidad, MSG msg)
{
	if (msg == MSG::none) {
		dead = true;
		dance->setEnabled(false);
		runarms->setEnabled(false);
		runlegs->setEnabled(false);
		idle->setEnabled(true);
		moverse->setEnabled(false);
		mNode->roll(Ogre::Degree(90));
		mNode->yaw(Ogre::Degree(90));
		mNode->translate(0, -60, 0);

	}
}
