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

	auto bg = Sprite::create("background-1.png");

	bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
	this->addChild(bg);

	auto particleSystem = ParticleSystemQuad::createWithTotalParticles(200);

	//����ѩ����������ͼƬ
	particleSystem->setTexture(Director::getInstance()->getTextureCache()->addImage("snow.png"));
	//���÷������ӵĳ���ʱ��-1��ʾ��Զ����
	particleSystem->setDuration(-1);											
	//�������ӵ��������� 
	particleSystem->setGravity(Vec2(0,-240));							

	//���ýǶ��Լ�ƫ��
	particleSystem->setAngle(90); 
	particleSystem->setAngleVar(360);

	//���þ�����ٶ��Լ�ƫ��
	particleSystem->setRadialAccel(50);
	particleSystem->setRadialAccelVar(0);

	//�������ӵ�������ٶ��Լ�ƫ��
	particleSystem->setTangentialAccel(30);
	particleSystem->setTangentialAccelVar(0);

	// �������ӳ�ʼ��λ��ƫ��
	particleSystem->setPosVar(Vec2(400,0));

	//���������������Լ�ƫ��
	particleSystem->setLife(4);
	particleSystem->setLifeVar(2);

	//�������ӿ�ʼʱ����ת�Ƕ��Լ�ƫ��
	particleSystem->setStartSpin(30);
	particleSystem->setStartSpinVar(60);

	//���ý���ʱ�����ת�Ƕ��Լ�ƫ��
	particleSystem->setEndSpin(60);
	particleSystem->setEndSpinVar(60);

	//���ÿ�ʼʱ�����ɫ�Լ�ƫ��
	particleSystem->setStartColor(Color4F(1,1,1,1));
	//���ý���ʱ�����ɫ�Լ�ƫ��
	particleSystem->setEndColor(Color4F(1,1,1,1));

	//���ÿ�ʼʱ�����Ӵ�С�Լ�ƫ��
	particleSystem->setStartSize(30);
	particleSystem->setStartSizeVar(0);

	//�������ӽ���ʱ���С�Լ�ƫ��
	particleSystem->setEndSize(20.0f);
	particleSystem->setEndSizeVar(0);

	//����ÿ���Ӳ������ӵ�����
	particleSystem->setEmissionRate(100);

	particleSystem->setPosition(Vec2(visibleSize.width/2, visibleSize.height + 50));

	this->addChild(particleSystem);

	return true;
}
