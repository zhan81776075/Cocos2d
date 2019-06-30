#include "Chapter5Scene.h"

USING_NS_CC;

Scene* ChapterFive::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ChapterFive::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
// on "init" you need to initialize your instance
bool ChapterFive::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	log("Setting::init");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//ÉèÖÃ±³¾°
	auto *bg = LayerColor::create(Color4B(220, 220, 220, 255));//RGBAÑÕÉ«Öµ
	this->addChild(bg);

	auto backMenuItem = MenuItemImage::create("Back-up.png", "Back-down.png", CC_CALLBACK_1(ChapterFive::backMenu, this));
	backMenuItem->setPosition(Vec2(origin.x + backMenuItem->getContentSize().width / 2,
		origin.y + visibleSize.height - backMenuItem->getContentSize().height / 2));
	backMenuItem->setScale(0.7);

	Menu* mn = Menu::create(backMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	/////////////////////////////
	//5.1.2
	auto tree1 = Sprite::create("tree1.png", Rect(604, 38, 302, 295));
	tree1->setPosition(Vec2(origin.x + 300,
		origin.y + visibleSize.height - 300));
	this->addChild(tree1, 0);

	Texture2D* cache = Director::getInstance()->getTextureCache()->addImage("tree1.png");
	auto tree2 = Sprite::create();
	tree2->setTexture(cache);
	tree2->setTextureRect(Rect(73, 72, 182, 270));
	tree2->setPosition(Vec2(origin.x + 300,
		origin.y + visibleSize.height - 600));
	this->addChild(tree2, 0);
	/////////////////////////////

	/////////////////////////////
	//5.2.1
	auto mountain1 = Sprite::create("SpirteSheet.png", Rect(2, 391, 934, 388));
	mountain1->setAnchorPoint(Vec2::ZERO);
	mountain1->setPosition(Vec2(origin.x + 400,
		origin.y + visibleSize.height - 300));
	mountain1->setScale(0.5);
	this->addChild(mountain1, 0);

	Texture2D* cache_2 = Director::getInstance()->getTextureCache()->addImage("SpirteSheet.png");
	auto hero1 = Sprite::create();
	hero1->setTexture(cache_2);
	hero1->setTextureRect(Rect(2, 1706, 391, 327));
	hero1->setPosition(Vec2(origin.x + 600,
		origin.y + visibleSize.height - 600));
	this->addChild(hero1, 0);
	/////////////////////////////

	/////////////////////////////
	//5.2.2
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("SpirteSheet.plist");

	auto mountain2 = Sprite::createWithSpriteFrameName("mountain1.png");
	mountain2->setAnchorPoint(Vec2::ZERO);
	mountain2->setPosition(Vec2(origin.x + 800,
		origin.y + visibleSize.height - 300));
	mountain2->setScale(0.5);
	this->addChild(mountain2, 0);

	SpriteFrame *heroSpriteFrame = frameCache->getSpriteFrameByName("hero1.png");
	Sprite *hero2 = Sprite::createWithSpriteFrame(heroSpriteFrame);
	hero2->setPosition(Vec2(origin.x + 1000,
		origin.y + visibleSize.height - 600));
	this->addChild(hero2, 0);
	/////////////////////////////
	return true;
}
void ChapterFive::backMenu(Ref* pSender)
{
	auto sc = HomeScene::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);

}

void ChapterFive::menuSoundToggleCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch menuSoundToggleCallback %p", item);
}


void ChapterFive::menuMusicToggleCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch menuMusicToggleCallback %p", item);
}


void ChapterFive::onEnter()
{
	Layer::onEnter();
	log("Setting::onEnter");
}

void ChapterFive::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("Setting::onEnterTransitionDidFinish");
}

void ChapterFive::onExit()
{
	Layer::onExit();
	log("Setting::onExit");
}

void ChapterFive::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("Setting::onExitTransitionDidStart");
}

void ChapterFive::cleanup()
{
	Layer::cleanup();
	log("Setting::cleanup");
}