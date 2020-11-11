#include "Simbad.h"

Simbad::Simbad(Ogre::SceneNode* node) : EntidadIG(node), swordent(nullptr)
{
	simbadEnt = mSM->createEntity("Sinbad.mesh");
	mNode->attachObject(simbadEnt);
	dance = simbadEnt->getAnimationState("Dance");
	dance->setEnabled(true);
	dance->setLoop(true);
	runlegs = simbadEnt->getAnimationState("RunBase");
	runlegs->setLoop(true);
	runarms = simbadEnt->getAnimationState("RunTop");
	runarms->setLoop(true);

}

void Simbad::frameRendered(const Ogre::FrameEvent& evt)
{
	if (danceBool)
		dance->addTime(evt.timeSinceLastFrame);
	else {
		runlegs->addTime(evt.timeSinceLastFrame);
		runarms->addTime(evt.timeSinceLastFrame);
	}
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
