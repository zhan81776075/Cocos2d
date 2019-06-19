#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto pItmLabel1 = Label::createWithBMFont("fonts/fnt8.fnt", "Explosion");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1,  CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu1->setTag(kExplosion);
	
	auto pItmLabel2 = Label::createWithBMFont("fonts/fnt8.fnt", "Fire");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu2->setTag(kFire);

	auto pItmLabel3 = Label::createWithBMFont("fonts/fnt8.fnt", "Fireworks");
    auto pItmMenu3 = MenuItemLabel::create(pItmLabel3, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu3->setTag(kFireworks);

	auto pItmLabel4 = Label::createWithBMFont("fonts/fnt8.fnt", "Flower");
    auto pItmMenu4 = MenuItemLabel::create(pItmLabel4, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu4->setTag(kFlower);

	auto pItmLabel5 = Label::createWithBMFont("fonts/fnt8.fnt", "Galaxy");
    auto pItmMenu5 = MenuItemLabel::create(pItmLabel5, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu5->setTag(kGalaxy);

	auto pItmLabel6 = Label::createWithBMFont("fonts/fnt8.fnt", "Meteor");
    auto pItmMenu6 = MenuItemLabel::create(pItmLabel6, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu6->setTag(kMeteor);

	auto pItmLabel7 = Label::createWithBMFont("fonts/fnt8.fnt", "Rain");
    auto pItmMenu7 = MenuItemLabel::create(pItmLabel7, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu7->setTag(kRain);

	auto pItmLabel8 = Label::createWithBMFont("fonts/fnt8.fnt", "Smoke");
    auto pItmMenu8 = MenuItemLabel::create(pItmLabel8, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu8->setTag(kSmoke);

	auto pItmLabel9 = Label::createWithBMFont("fonts/fnt8.fnt", "Snow");
    auto pItmMenu9 = MenuItemLabel::create(pItmLabel9, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu9->setTag(kSnow);

	auto pItmLabel10 = Label::createWithBMFont("fonts/fnt8.fnt", "Spiral");
    auto pItmMenu10 = MenuItemLabel::create(pItmLabel10, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu10->setTag(kSpiral);

	auto pItmLabel11 = Label::createWithBMFont("fonts/fnt8.fnt", "Sun");
    auto pItmMenu11 = MenuItemLabel::create(pItmLabel11, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu11->setTag(kSun);

	Menu* mn = Menu::create(pItmMenu1,pItmMenu2,pItmMenu3,pItmMenu4,pItmMenu5,
                                pItmMenu6,pItmMenu7,pItmMenu8,pItmMenu9,
								pItmMenu10,pItmMenu11, NULL);

	mn->alignItemsInColumns(2, 2, 2, 2, 2, 1, NULL);
    this->addChild(mn);

	return true;
}

void HelloWorld::OnClickMenu(Ref* pSender)
{
	MenuItem *nmitem = (MenuItem*)pSender;

	auto  sc = Scene::create();
	auto  layer = MyAction::create();
	layer->setTag(nmitem->getTag());

	sc->addChild(layer);

	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);
}
