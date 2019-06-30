#include "HomeScene.h"

USING_NS_CC;

Scene* HomeScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HomeScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HomeScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	log("HomeScene::init");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//设置背景
	auto *bg = LayerColor::create(Color4B(220,220,220,255));//RGBA颜色值
	this->addChild(bg);
	
	//退出按钮
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HomeScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	///////////////////////
	//Chapter4Scene标签
	auto ChapterFourLabel = Label::createWithBMFont("fonts/fnt2.fnt", "ChapterFour");

    auto ChapterFourMenu = MenuItemLabel::create(ChapterFourLabel,
        CC_CALLBACK_1(HomeScene::menuChapterFourCallback, this));
	//设置位置
	ChapterFourMenu->setPosition(Director::getInstance()->convertToGL(Vec2(150,100)));
	///////////////////////

		///////////////////////
	//Chapter5Scene标签
	auto ChapterFiveLabel = Label::createWithBMFont("fonts/fnt2.fnt", "ChapterFive");

	auto ChapterFiveMenu = MenuItemLabel::create(ChapterFiveLabel,
		CC_CALLBACK_1(HomeScene::menuChapterFiveCallback, this));
	//设置位置
	ChapterFiveMenu->setPosition(Director::getInstance()->convertToGL(Vec2(150,200)));
	///////////////////////

	Menu* mu = Menu::create(closeItem,ChapterFourMenu,ChapterFiveMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);

	return true;
}


void HomeScene::menuChapterFourCallback(Ref* pSender)
{
	auto sc = ChapterFour::createScene();
	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);//replaceScene(reScene);
}
void HomeScene::menuChapterFiveCallback(Ref* pSender)
{
	auto sc = ChapterFive::createScene();
	auto reScene = TransitionSlideInR::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);//replaceScene(reScene);
}
void HomeScene::onEnter()
{
	Layer::onEnter();
	log("HelloWorld::onEnter");
}

void HomeScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("HelloWorld::onEnterTransitionDidFinish");
}

void HomeScene::onExit()
{
	Layer::onExit();
	log("HelloWorld::onExit");
}

void HomeScene::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("HelloWorld::onExitTransitionDidStart");
}

void HomeScene::cleanup()
{
	Layer::cleanup();
	log("HelloWorld::cleanup");
}

void HomeScene::menuCloseCallback(Ref* pSender)
{
	// 停止更新  
	unscheduleUpdate();

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}