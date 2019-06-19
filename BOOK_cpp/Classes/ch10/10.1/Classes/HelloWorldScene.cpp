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
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	///////////////������ʼ//////////////////////
	Animation* animation = Animation::create();
	for( int i=1; i< 18; i++)
	{
		auto frameName = String::createWithFormat("fire/campFire%02d.png",i);
		log("frameName = %s",frameName->getCString());
		animation->addSpriteFrameWithFile(frameName->getCString());        
	}
	animation->setDelayPerUnit(0.11f);           //���ö�����֮֡��ʱ����
	animation->setRestoreOriginalFrame(true);    //����ִ�к�ԭ��ʼ״̬

	Animate* action = Animate::create(animation);

	auto sp01 = Sprite::create("fire/campFire01.png");
	sp01->setPosition(Vec2(visibleSize.width/2,
		visibleSize.height /2));
	this->addChild(sp01);
	sp01->runAction(RepeatForever::create(action));

	//////////////////��������///////////////////


	return true;
}
