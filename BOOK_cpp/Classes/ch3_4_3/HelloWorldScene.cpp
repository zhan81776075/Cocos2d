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

	//创建背景
	auto bg = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(bg, 0);

	//3.4.3.1
	////创建Node1
	//auto node1 = Sprite::create("node1.png");
	//node1->setPosition(Vec2(400, 500));
	//node1->setAnchorPoint(Vec2(1, 1));

	//this->addChild(node1, 0);

	////创建Node2
	//auto node2 = Sprite::create("node2.png");
	//node2->setPosition(Vec2(200, 300));
	//node2->setAnchorPoint(Vec2(0.5, 0.5));

	//this->addChild(node2, 0);

	//Vec2 point1 = node1->convertToNodeSpace(node2->getPosition());

	//Vec2 point3 = node1->convertToNodeSpaceAR(node2->getPosition());

	//log("Node2 NodeSpace = (%f,%f)", point1.x, point1.y);

	//log("Node2 NodeSpaceAR = (%f,%f)", point3.x, point3.y);

	//3.4.3.2
	//创建Node1
	auto node1 = Sprite::create("node1.png");
	node1->setPosition(Vec2(400, 500));
	node1->setAnchorPoint(Vec2(1, 1));
	this->addChild(node1, 0);

	//创建Node2
	auto node2 = Sprite::create("node2.png");
	node2->setPosition(Vec2(0.0, 0.0));
	node2->setAnchorPoint(Vec2(1, 1));

	node1->addChild(node2, 0);

	Vec2 point2 = node1->convertToWorldSpace(node2->getPosition());
	Vec2 point4 = node1->convertToWorldSpaceAR(node2->getPosition());

	log("Node2 WorldSpace = (%f,%f)", point2.x, point2.y);
	log("Node2 WorldSpaceAR = (%f,%f)", point4.x, point4.y);

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
