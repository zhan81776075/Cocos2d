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

bool HelloWorld::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("menu/background.png");    
	bg->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height /2));
	this->addChild(bg);

	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(86); 
	MenuItemFont *item1 = MenuItemFont::create("Start", 
		CC_CALLBACK_1(HelloWorld::menuItem1Callback, this)); 


	MenuItemAtlasFont *item2 = MenuItemAtlasFont::create("Help", 
		"menu/tuffy_bold_italic-charmap.png", 48, 65, ' ',
		CC_CALLBACK_1(HelloWorld::menuItem2Callback, this));

	Menu* mn = Menu::create(item1, item2, NULL); 
	mn->alignItemsVertically();	
	this->addChild(mn); 

	return true;
}


void HelloWorld::menuItem1Callback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Start Menu Item %p", item);
}

void HelloWorld::menuItem2Callback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Help Menu Item %p", item);
}

