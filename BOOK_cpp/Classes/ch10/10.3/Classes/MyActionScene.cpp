#include "MyActionScene.h"

USING_NS_CC;

Scene* MyAction::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MyAction::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MyAction::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto pItmLabel = Label::createWithBMFont("fonts/fnt8.fnt", "<Back");
    auto backMenuItem = MenuItemLabel::create(pItmLabel,  CC_CALLBACK_1(MyAction::backMenu, this));
	backMenuItem->setPosition(Point(visibleSize.width - 100, 100));

	Menu* mn = Menu::create(backMenuItem,  NULL);
	mn->setPosition(Point::ZERO);
	this->addChild(mn);

	pLabel =  Label::createWithBMFont("fonts/fnt8.fnt", "");
	pLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height - 50));
	this->addChild(pLabel, 3);

	return true;
}

void MyAction::backMenu(Ref* pSender)
{
	auto sc = HelloWorld::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}


void MyAction::onEnterTransitionDidFinish()
{   
	Layer::onEnterTransitionDidFinish();

	ParticleSystem* system;

	switch (this->getTag()) {
	case kExplosion:
		system = ParticleExplosion::create();
		pLabel->setString("Explosion ");
		break;
	case kFire:
		system = ParticleFire::create();
		pLabel->setString("Fire");
		break;
	case kFireworks:
		system = ParticleFireworks::create();
		pLabel->setString("Fireworks");
		break;
	case kFlower:
		system = ParticleFlower::create();
		pLabel->setString("Flower");
		break;
	case kGalaxy:
		system = ParticleGalaxy::create();
		pLabel->setString("Galaxy");
		break;
	case kMeteor:
		system = ParticleMeteor::create();
		pLabel->setString("Meteor");
		break;
	case kRain:
		system = ParticleRain::create();
		pLabel->setString("Rain");
		break;
	case kSmoke:
		system = ParticleSmoke::create();
		pLabel->setString("Smoke");
		break;
	case kSnow:
		system = ParticleSnow::create();
		pLabel->setString("Snow");
		break;
	case kSpiral:
		system = ParticleSpiral::create();
		pLabel->setString("Spiral");
		break;
	case kSun:
		system = ParticleSun::create();
		pLabel->setString("Sun");
		break;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	system->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(system);
}