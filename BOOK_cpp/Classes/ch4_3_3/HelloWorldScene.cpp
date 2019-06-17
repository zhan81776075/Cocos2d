#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
	// 1. 初始化父类
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	/////////////////////////////
	//2. 在下面添加你自己的代码
	Sprite *bg = Sprite::create("menu/setting-back.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	//音效
	auto soundOnMenuItem = MenuItemImage::create(
		"menu/on.png",
		"menu/on.png");
	auto soundOffMenuItem = MenuItemImage::create(
		"menu/off.png",
		"menu/off.png");

	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuSoundToggleCallback, this),
		soundOnMenuItem,
		soundOffMenuItem,
		NULL);
	soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 220)));

	//音乐
	auto musicOnMenuItem = MenuItemImage::create(
		"menu/on.png",
		"menu/on.png");
	auto musicOffMenuItem = MenuItemImage::create(
		"menu/off.png",
		"menu/off.png");
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuMusicToggleCallback, this),
		musicOnMenuItem,
		musicOffMenuItem,
		NULL);
	musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 362)));

	//Ok按钮
	auto okMenuItem = MenuItemImage::create(
		"menu/ok-down.png",
		"menu/ok-up.png");
	okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(600, 510)));

	Menu* mn = Menu::create(soundToggleMenuItem, musicToggleMenuItem, okMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

    return true;
}


void HelloWorld::menuSoundToggleCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch menuSoundToggleCallback %p", item);
}


void HelloWorld::menuMusicToggleCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch menuMusicToggleCallback %p", item);
}
