//
//  Created by �ض��� on 2016-3-18.
//  ������վ��http://www.51work6.com
//  �ǽݿ������߿��ã�http://www.zhijieketang.com/
//  �ǽݿ���΢�Ź����ţ�zhijieketang
//  ����΢����@tony_�ض���
//  ����΢�ţ�tony�ض���
//  QQ��569418560 ���䣺eorient@sina.com
//  QQ����Ⱥ��162030268
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
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("run.plist");

	auto bg = LayerColor::create(Color4B(217, 217, 217, 255)); //RGBA��ɫֵ
	this->addChild(bg);

	sprite = Sprite::createWithSpriteFrameName("h1.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite);

	//���ز˵�
	auto goSprite = Sprite::createWithSpriteFrameName("go.png");
	auto stopSprite = Sprite::createWithSpriteFrameName("stop.png");

	auto goToggleMenuItem = MenuItemSprite::create(goSprite, goSprite);
	auto stopToggleMenuItem = MenuItemSprite::create(stopSprite, stopSprite);

	auto toggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::OnAction, this),
		goToggleMenuItem, stopToggleMenuItem, NULL);

	toggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(930, 540)));

	auto mn = Menu::create(toggleMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	//��ʼ�����ű�ʶ״̬Ϊfalse
	isPlaying = false;

	return true;
}

void HelloWorld::OnAction(Ref* pSender)
{

	if (!isPlaying) {

		///////////////������ʼ//////////////////////
		Animation* animation = Animation::create();
		for (int i = 1; i <= 4; i++)
		{
			__String *frameName = __String::createWithFormat("h%d.png", i);
			log("frameName = %s", frameName->getCString());
			SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
			animation->addSpriteFrame(spriteFrame);
		}

		animation->setDelayPerUnit(0.15f);           //��������֡����ʱ��
		animation->setRestoreOriginalFrame(true);    //����ִ�к�ԭ��ʼ״̬

		Animate* action = Animate::create(animation);
		sprite->runAction(RepeatForever::create(action));
		//////////////////��������///////////////////

		//���ò��ű�ʶ״̬Ϊtrue
		isPlaying = true;

	}
	else {
		sprite->stopAllActions();
		isPlaying = false;
	}
}
