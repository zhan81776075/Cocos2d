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
	log("HelloWorld::init");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//���ñ���
    Sprite *bg = Sprite::create("background.png");
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height /2));
    this->addChild(bg);

	//��ʼ����
    Sprite *startSpriteNormal = Sprite::create("start-up.png");
    Sprite *startSpriteSelected = Sprite::create("start-down.png");

	MenuItemSprite *startMenuItem = MenuItemSprite::create(startSpriteNormal, 
													startSpriteSelected,
												   CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
	startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(700, 170)));
    
	// ����ͼƬ�˵�
    MenuItemImage *settingMenuItem = MenuItemImage::create(
                             "setting-up.png",
                             "setting-down.png",
							 CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this)); 
	settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(480, 400)));
	
	// ����ͼƬ�˵�
    MenuItemImage *helpMenuItem = MenuItemImage::create(
                             "help-up.png",
                             "help-down.png",
							 CC_CALLBACK_1(HelloWorld::menuItemHelpCallback, this));	
	helpMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(860, 480)));

	Menu* mu = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, NULL);	
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);
    
    return true;
}


void HelloWorld::menuItemSettingCallback(Ref* pSender)
{
	auto sc = Setting::createScene();
	auto reScene = TransitionJumpZoom::create(1.0f, sc);
	Director::getInstance()->pushScene(reScene);//replaceScene(reScene);
}

void HelloWorld::menuItemHelpCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Help %p", item);
}

void HelloWorld::menuItemStartCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Start %p", item);
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	log("HelloWorld::onEnter");
}

void HelloWorld::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("HelloWorld::onEnterTransitionDidFinish");
}

void HelloWorld::onExit()
{
	Layer::onExit();
	log("HelloWorld::onExit");
}

void HelloWorld::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("HelloWorld::onExitTransitionDidStart");
}

void HelloWorld::cleanup()
{
	Layer::cleanup();
	log("HelloWorld::cleanup");
}
