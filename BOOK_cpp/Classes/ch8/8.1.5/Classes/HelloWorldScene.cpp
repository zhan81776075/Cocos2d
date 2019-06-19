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
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//��ͼ������ͼƬ��߱�����2��n���ݣ�128x128
	auto bg = Sprite::create("BackgroundTile.png", Rect(0, 0, visibleSize.width, visibleSize.height));
	//��ͼ�����������ˮƽ�ظ�ƽ�̣���ֱ�ظ�ƽ��
	Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
	bg->getTexture()->setTexParameters(tp);
	bg->setPosition(origin + Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(bg, 0);

	Sprite* boxA = Sprite::create("BoxA2.png");
	boxA->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(boxA, 10, kBoxA_Tag);

	return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	log("HelloWorld onEnter");

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
		log("Key with keycode %d pressed", keyCode);
	};

	listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event* event) {
		log("Key with keycode %d released", keyCode);
	};

	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	Layer::onExit();
	log("HelloWorld onExit");
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}