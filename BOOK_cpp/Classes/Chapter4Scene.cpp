#include "Chapter4Scene.h"

USING_NS_CC;

Scene* ChapterFour::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ChapterFour::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ChapterFour::init()
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

	auto backMenuItem = MenuItemImage::create("Back-up.png", "Back-down.png", CC_CALLBACK_1(ChapterFour::backMenu, this));
	backMenuItem->setPosition(Vec2(origin.x+backMenuItem->getContentSize().width/2,
		origin.y+visibleSize.height-backMenuItem->getContentSize().height/2));
	backMenuItem->setScale(0.7);

	Menu* mn = Menu::create(backMenuItem,NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);
	
	///////////////////////////////
	//4.2.1
	auto label1 = Label::createWithSystemFont("Hello World1", "Arial", 36);
	label1->setPosition(Vec2(origin.x + visibleSize.width / 6,
		origin.y + visibleSize.height - 100));
	this->addChild(label1, 1);

	auto label2 = Label::createWithTTF("Hello World2", "fonts/Marker Felt.ttf", 36);
	label2->setPosition(Vec2(origin.x + visibleSize.width / 6,
		origin.y + visibleSize.height - 200));
	this->addChild(label2, 1);

	auto label3 = Label::createWithBMFont("fonts/BMFont.fnt", "Hello World3");
	label3->setPosition(Vec2(origin.x + visibleSize.width / 6,
		origin.y + visibleSize.height - 300));
	this->addChild(label3, 1);

	TTFConfig ttfConfig("fonts/Marker Felt.ttf",
		36,
		GlyphCollection::DYNAMIC);

	auto label4 = Label::createWithTTF(ttfConfig, "Hello World4");
	label4->setPosition(Vec2(origin.x + visibleSize.width / 6,
		origin.y + visibleSize.height - 400));
	this->addChild(label4, 1);

	ttfConfig.outlineSize = 4;
	auto label5 = Label::createWithTTF(ttfConfig, "Hello World5");
	label5->setPosition(Vec2(origin.x + visibleSize.width / 6,
		origin.y + visibleSize.height - 500));
	label5->enableShadow(Color4B(255, 255, 255, 128), Size(4, -4));
	label5->setColor(Color3B::RED);

	this->addChild(label5, 1);
	///////////////////////////////

	///////////////////////////////
	//4.3.1
	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(86);
	MenuItemFont *item1 = MenuItemFont::create("Start",
		CC_CALLBACK_1(ChapterFour::menuItem1_4_3_1Callback, this));
	item1->setPosition(Vec2(origin.x + 700,
		origin.y + visibleSize.height - 100));

	MenuItemAtlasFont *item2 = MenuItemAtlasFont::create("Help",
		"menu/tuffy_bold_italic-charmap.png", 48, 65, ' ',
		CC_CALLBACK_1(ChapterFour::menuItem2_4_3_1Callback, this));

	item2->setPosition(Vec2(origin.x + 700,
		origin.y + visibleSize.height - 300));

	Menu* mn_1 = Menu::create(item1, item2, NULL);
	mn_1->setPosition(Vec2::ZERO);
	this->addChild(mn_1);
	///////////////////////////////

	///////////////////////////////
	//4.3.2
	//¿ªÊ¼¾«Áé
	Sprite *startSpriteNormal = Sprite::create("menu/start-up.png");
	Sprite *startSpriteSelected = Sprite::create("menu/start-down.png");

	MenuItemSprite *startMenuItem = MenuItemSprite::create(startSpriteNormal,
		startSpriteSelected,
		CC_CALLBACK_1(ChapterFour::menuItemStartCallback, this));

	startMenuItem->setPosition(Vec2(origin.x + 1000,
		origin.y + visibleSize.height - 100));
	// ÉèÖÃÍ¼Æ¬²Ëµ¥
	MenuItemImage *settingMenuItem = MenuItemImage::create(
		"menu/setting-up.png",
		"menu/setting-down.png",
		CC_CALLBACK_1(ChapterFour::menuItemSettingCallback, this));

	settingMenuItem->setPosition(Vec2(origin.x + 1000,
		origin.y + visibleSize.height - 300));
	// °ïÖúÍ¼Æ¬²Ëµ¥
	MenuItemImage *helpMenuItem = MenuItemImage::create(
		"menu/help-up.png",
		"menu/help-down.png",
		CC_CALLBACK_1(ChapterFour::menuItemHelpCallback, this));

	helpMenuItem->setPosition(Vec2(origin.x + 1000,
		origin.y + visibleSize.height - 500));

	Menu* mu_2 = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, NULL);
	mu_2->setPosition(Vec2::ZERO);
	this->addChild(mu_2);
	///////////////////////////////

	///////////////////////////////
	//4.3.3 ÒôÐ§
	auto soundOnMenuItem = MenuItemImage::create(
		"menu/on.png",
		"menu/on.png");
	auto soundOffMenuItem = MenuItemImage::create(
		"menu/off.png",
		"menu/off.png");

	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(ChapterFour::menuSoundToggleCallback, this),
		soundOnMenuItem,
		soundOffMenuItem,
		NULL);
	soundToggleMenuItem->setPosition(Vec2(origin.x + 1400,
		origin.y + visibleSize.height - 100));
	//ÒôÀÖ
	auto musicOnMenuItem = MenuItemImage::create(
		"menu/on.png",
		"menu/on.png");
	auto musicOffMenuItem = MenuItemImage::create(
		"menu/off.png",
		"menu/off.png");
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(ChapterFour::menuMusicToggleCallback, this),
		musicOnMenuItem,
		musicOffMenuItem,
		NULL);
	musicToggleMenuItem->setPosition(Vec2(origin.x + 1400,
		origin.y + visibleSize.height - 300));
	Menu* mn_3 = Menu::create(soundToggleMenuItem, musicToggleMenuItem, NULL);
	mn_3->setPosition(Vec2::ZERO);
	this->addChild(mn_3);

	return true;
}
///////////////////////////////
//4.3.1
void ChapterFour::menuItem1_4_3_1Callback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Start Menu Item %p", item);
}

void ChapterFour::menuItem2_4_3_1Callback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Help Menu Item %p", item);
}
///////////////////////////////

///////////////////////////////
//4.3.2
void ChapterFour::menuItemHelpCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Help %p", item);
}

void ChapterFour::menuItemStartCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Start %p", item);
}

void ChapterFour::menuItemSettingCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Setting %p", item);
}
///////////////////////////////
void ChapterFour::backMenu(Ref* pSender)
{
	auto sc = HomeScene::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);

}

void ChapterFour::menuSoundToggleCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch menuSoundToggleCallback %p", item);
}


void ChapterFour::menuMusicToggleCallback(Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch menuMusicToggleCallback %p", item);
}


void ChapterFour::onEnter()
{
	Layer::onEnter();
	log("Setting::onEnter");
}

void ChapterFour::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("Setting::onEnterTransitionDidFinish");
}

void ChapterFour::onExit()
{
	Layer::onExit();
	log("Setting::onExit");
}

void ChapterFour::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("Setting::onExitTransitionDidStart");
}

void ChapterFour::cleanup()
{
	Layer::cleanup();
	log("Setting::cleanup");
}