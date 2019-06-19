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

	auto bg = Sprite::create("background-1.png");

	bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height /2));
	this->addChild(bg);

	auto particleSystem = ParticleSystemQuad::createWithTotalParticles(200);

	//设置雪花粒子纹理图片
	particleSystem->setTexture(Director::getInstance()->getTextureCache()->addImage("snow.png"));
	//设置发射粒子的持续时间-1表示永远持续
	particleSystem->setDuration(-1);											
	//设置粒子的重力方向 
	particleSystem->setGravity(Vec2(0,-240));							

	//设置角度以及偏差
	particleSystem->setAngle(90); 
	particleSystem->setAngleVar(360);

	//设置径向加速度以及偏差
	particleSystem->setRadialAccel(50);
	particleSystem->setRadialAccelVar(0);

	//设置粒子的切向加速度以及偏差
	particleSystem->setTangentialAccel(30);
	particleSystem->setTangentialAccelVar(0);

	// 设置粒子初始化位置偏差
	particleSystem->setPosVar(Vec2(400,0));

	//设置粒子生命期以及偏差
	particleSystem->setLife(4);
	particleSystem->setLifeVar(2);

	//设置粒子开始时候旋转角度以及偏差
	particleSystem->setStartSpin(30);
	particleSystem->setStartSpinVar(60);

	//设置结束时候的旋转角度以及偏差
	particleSystem->setEndSpin(60);
	particleSystem->setEndSpinVar(60);

	//设置开始时候的颜色以及偏差
	particleSystem->setStartColor(Color4F(1,1,1,1));
	//设置结束时候的颜色以及偏差
	particleSystem->setEndColor(Color4F(1,1,1,1));

	//设置开始时候粒子大小以及偏差
	particleSystem->setStartSize(30);
	particleSystem->setStartSizeVar(0);

	//设置粒子结束时候大小以及偏差
	particleSystem->setEndSize(20.0f);
	particleSystem->setEndSizeVar(0);

	//设置每秒钟产生粒子的数量
	particleSystem->setEmissionRate(100);

	particleSystem->setPosition(Vec2(visibleSize.width/2, visibleSize.height + 50));

	this->addChild(particleSystem);

	return true;
}
