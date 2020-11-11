#include "Boya.h"

Boya::Boya(Ogre::SceneNode* n) : EntidadIG(n), ent(nullptr) {
	ent = mSM->createEntity("Barrel.mesh");
	mNode->attachObject(ent);
	mNode->setScale(15, 25, 15);
	ent->setMaterialName("Practica1/cuadros");
	Ogre::Animation* anim = mSM->createAnimation("AnimVV", 5);
	Ogre::NodeAnimationTrack* track = anim->createNodeTrack(0);
	int durPaso = 16 / 4;
	int maxPoint = 250;
	track->setAssociatedNode(mNode);

	Ogre::TransformKeyFrame* kf = track->createNodeKeyFrame(0 * durPaso);
	Ogre::Vector3 pos(-10, 0, 100);
	kf->setScale(mNode->getScale());
	kf->setTranslate(pos);
	
	kf = track->createNodeKeyFrame(1 * durPaso);
	pos += Ogre::Vector3::UNIT_Y * maxPoint;
	kf->setTranslate(pos);
	kf->setScale(mNode->getScale());

	kf = track->createNodeKeyFrame(2 * durPaso);
	pos += Ogre::Vector3::NEGATIVE_UNIT_Y * maxPoint;
	kf->setTranslate(pos);
	kf->setScale(mNode->getScale());

	kf = track->createNodeKeyFrame(3 * durPaso);
	pos += Ogre::Vector3::UNIT_Y * maxPoint;
	kf->setTranslate(pos);
	kf->setScale(mNode->getScale());

	kf = track->createNodeKeyFrame(4 * durPaso);
	pos += Ogre::Vector3::NEGATIVE_UNIT_Y * maxPoint;
	kf->setTranslate(pos);

	animS = mSM->createAnimationState("AnimVV");
	animS->setEnabled(true);
	animS->setLoop(true);

}


void Boya::frameRendered(const Ogre::FrameEvent& evt)
{
	animS->addTime(evt.timeSinceLastFrame);
}
