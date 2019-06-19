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
	auto bg = Sprite::create("zippo.png");

	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bg);

	auto particleSystem = ParticleFire::create();

	//�������ӵ�����
	particleSystem->setGravity(Vec2(45, 300));
	//���þ�����ٶ�
	particleSystem->setRadialAccel(58);
	//�������ӳ�ʼ����С
	particleSystem->setStartSize(84);
	//�������ӳ�ʼ����Сƫ��
	particleSystem->setStartSizeVar(73);
	//������������Сƫ��
	particleSystem->setEndSize(123);
	//������������Сƫ��
	particleSystem->setEndSizeVar(17);
	//��������������ٶ�
	particleSystem->setTangentialAccel(70);
	//��������������ٶ�ƫ��
	particleSystem->setTangentialAccelVar(47);
	//��������������
	particleSystem->setLife(0.79f);
	//��������������ƫ��
	particleSystem->setLifeVar(0.45f);

	particleSystem->setPosition(Director::getInstance()->convertToGL(Vec2(270, 380)));

	this->addChild(particleSystem);

	return true;
}