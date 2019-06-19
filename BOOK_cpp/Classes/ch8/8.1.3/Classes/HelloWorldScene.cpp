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
	boxA->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2) + Vec2(-120, 120));
	addChild(boxA, 10, kBoxA_Tag);

	Sprite* boxB = Sprite::create("BoxB2.png");
	boxB->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(boxB, 20, kBoxB_Tag);

	Sprite* boxC = Sprite::create("BoxC2.png");
	boxC->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2) + Vec2(120, 160));
	addChild(boxC, 30, kBoxC_Tag);


	return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	log("HelloWorld onEnter");

	// ����һ���¼������� OneByOne Ϊ���㴥��
	auto listener = EventListenerTouchOneByOne::create();
	// �����Ƿ���û�¼����� onTouchBegan �������� true ʱ��û
	listener->setSwallowTouches(true);
	// onTouchBegan �¼��ص�����
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::touchBegan, this);
	// onTouchMoved �¼��ص�����
	listener->onTouchMoved =  CC_CALLBACK_2(HelloWorld::touchMoved, this);
	// onTouchEnded �¼��ص�����
	listener->onTouchEnded =  CC_CALLBACK_2(HelloWorld::touchEnded, this);

	// ע�������
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, getChildByTag(kBoxA_Tag));
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(kBoxB_Tag));
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(kBoxC_Tag));

}

bool HelloWorld::touchBegan(Touch* touch, Event* event)
{
	// ��ȡ�¼����󶨵� target 
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	// ��ȡ��ǰ�����������԰�ť��λ������
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// �����Χ�жϼ��
	if (rect.containsPoint(locationInNode))
	{
		log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
		log("sprite tag = %d", target->getTag());
		target->runAction(ScaleBy::create(0.06f, 1.06f)); 
		return true;
	}
	return false;
}

void HelloWorld::touchMoved(Touch *touch, Event *event)
{
	log("onTouchMoved");
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	// �ƶ���ǰ��ť���������λ��
	target->setPosition(target->getPosition() + touch->getDelta());
}

void HelloWorld::touchEnded(Touch *touch, Event *event)
{
	log("onTouchEnded");
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	log("sprite onTouchesEnded.. ");

	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	// �����Χ�жϼ��
	if (rect.containsPoint(locationInNode))
	{
		log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
		log("sprite tag = %d", target->getTag());
		target->runAction(ScaleTo::create(0.06f, 1.0f)); 
	}
}

void HelloWorld::onExit()
{
	Layer::onExit();
	log("HelloWorld onExit");
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}
