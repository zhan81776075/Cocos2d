//
//  Created by 关东升 on 2016-3-18.
//  本书网站：http://www.51work6.com
//  智捷课堂在线课堂：http://www.zhijieketang.com/
//  智捷课堂微信公共号：zhijieketang
//  作者微博：@tony_关东升
//  作者微信：tony关东升
//  QQ：569418560 邮箱：eorient@sina.com
//  QQ交流群：162030268
//

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
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = LayerColor::create(Color4B(217, 217, 217, 255)); //RGBA颜色值
	this->addChild(bg);

	auto pItmLabel1 = LabelBMFont::create("CallFunc", "fonts/fnt2.fnt");
    auto pItmMenu1 = MenuItemLabel::create(pItmLabel1, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu1->setTag(func);
	
	auto pItmLabel2 = LabelBMFont::create("CallFuncN", "fonts/fnt2.fnt");
    auto pItmMenu2 = MenuItemLabel::create(pItmLabel2, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
	pItmMenu2->setTag(funcN);

    Menu* mn = Menu::create(pItmMenu1,pItmMenu2, NULL);
    mn->alignItemsVertically();
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

