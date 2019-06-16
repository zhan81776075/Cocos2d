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
	// 2. 增加一个菜单项，点击它的时候退出程序
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	/////////////////////////////
	// 3. 在下面添加你自己的代码
	auto label1 = LabelTTF::create("中国", "Arial", 30);
	label1->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - 150));
	this->addChild(label1, 1);

	auto label2 = LabelBMFont::create("中国", "fonts/bitmapFontChinese.fnt");
	label2->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - 250));
	this->addChild(label2, 1);

	auto label3 = Label::createWithBMFont("fonts/bitmapFontChinese.fnt", "中国3");
	label3->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - 350));
	this->addChild(label3, 1);

	TTFConfig ttfConfig("fonts/STLITI.ttf", 36, GlyphCollection::DYNAMIC);
	auto labe4 = Label::createWithTTF(ttfConfig, "您好，美好的一天啊",
		TextHAlignment::CENTER,
		visibleSize.width);
	labe4->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - 450));
	this->addChild(labe4, 1);

    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	// 停止更新  
	unscheduleUpdate();

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
