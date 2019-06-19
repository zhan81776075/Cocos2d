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

	//贴图的纹理图片宽高必须是2的n次幂，128x128
	auto bg = Sprite::create("BackgroundTile.png", Rect(0, 0, visibleSize.width, visibleSize.height));
	//贴图的纹理参数，水平重复平铺，垂直重复平铺
	Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
	bg->getTexture()->setTexParameters(tp);
	bg->setPosition(origin + Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(bg, 0);

	auto boxA = Sprite::create("BoxA2.png");
	boxA->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2) + Vec2(-120, 120));
	addChild(boxA, 10, kBoxA_Tag);

	auto boxB = Sprite::create("BoxB2.png");
	boxB->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(boxB, 20, kBoxB_Tag);

	setTouchEnabled(true);
	//设置为单点触摸
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	
	return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	log("onTouchBegan");
	//通过tag（标签）获得BoxA精灵
	auto boxA = this->getChildByTag(kBoxA_Tag);
	//如果BoxA精灵被点击 
	if (this->isTap(boxA, touch))
	{
		log("BoxA sprite Tap");
		boxA->runAction(ScaleBy::create(0.06f, 1.06f)); 
		return true;
	}
	//通过tag（标签）获得BoxB精灵
	auto boxB = this->getChildByTag(kBoxB_Tag);
	//如果BoxB精灵被点击
	if (this->isTap(boxB, touch))
	{
		log("BoxB sprite Tap");
		boxB->runAction(ScaleBy::create(0.06f, 1.06f)); 
		return true;
	}
	return false;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	log("onTouchMoved");
	//通过tag（标签）获得BoxA精灵
	auto boxA = this->getChildByTag(kBoxA_Tag);
	//如果BoxA精灵被点击
	if (this->isTap(boxA, touch))
	{
		log("BoxA sprite Tap");
		// 移动当前按钮精灵的坐标位置
		boxA->setPosition(boxA->getPosition() + touch->getDelta()); 
		return;
	}
	//通过tag（标签）获得BoxB精灵
	auto boxB = this->getChildByTag(kBoxB_Tag);
	//如果BoxB精灵被点击
	if (this->isTap(boxB, touch))
	{
		log("BoxB sprite Tap");
		// 移动当前按钮精灵的坐标位置
		boxB->setPosition(boxB->getPosition() + touch->getDelta());
		return;
	}
}

void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	log("onTouchEnded");	
	//通过tag（标签）获得BoxA精灵
	auto boxA = this->getChildByTag(kBoxA_Tag);
	//如果BoxA精灵被点击
	if (this->isTap(boxA, touch))
	{
		log("BoxA sprite Tap");
		boxA->runAction(ScaleTo::create(0.06f, 1.0f)); 
		return;
	}
	//通过tag（标签）获得BoxB精灵
	auto boxB = this->getChildByTag(kBoxB_Tag);
	//如果BoxB精灵被点击
	if (this->isTap(boxB, touch))
	{
		log("BoxB sprite Tap");
		boxB->runAction(ScaleTo::create(0.06f, 1.0f)); 
		return;
	}
}

bool HelloWorld::isTap(Node* node, Touch* touch)
{
	// 获取触摸点相对Node位置坐标
	Vec2 locationInNode = node->convertToNodeSpace(touch->getLocation());
	Size s = node->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		return true;
	}
	return false;
}
