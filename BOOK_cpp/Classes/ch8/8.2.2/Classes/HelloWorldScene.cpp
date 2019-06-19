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

	auto boxA = Sprite::create("BoxA2.png");
	boxA->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2) + Vec2(-120, 120));
	addChild(boxA, 10, kBoxA_Tag);

	auto boxB = Sprite::create("BoxB2.png");
	boxB->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(boxB, 20, kBoxB_Tag);

	setTouchEnabled(true);
	//����Ϊ���㴥��
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	
	return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	log("onTouchBegan");
	//ͨ��tag����ǩ�����BoxA����
	auto boxA = this->getChildByTag(kBoxA_Tag);
	//���BoxA���鱻��� 
	if (this->isTap(boxA, touch))
	{
		log("BoxA sprite Tap");
		boxA->runAction(ScaleBy::create(0.06f, 1.06f)); 
		return true;
	}
	//ͨ��tag����ǩ�����BoxB����
	auto boxB = this->getChildByTag(kBoxB_Tag);
	//���BoxB���鱻���
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
	//ͨ��tag����ǩ�����BoxA����
	auto boxA = this->getChildByTag(kBoxA_Tag);
	//���BoxA���鱻���
	if (this->isTap(boxA, touch))
	{
		log("BoxA sprite Tap");
		// �ƶ���ǰ��ť���������λ��
		boxA->setPosition(boxA->getPosition() + touch->getDelta()); 
		return;
	}
	//ͨ��tag����ǩ�����BoxB����
	auto boxB = this->getChildByTag(kBoxB_Tag);
	//���BoxB���鱻���
	if (this->isTap(boxB, touch))
	{
		log("BoxB sprite Tap");
		// �ƶ���ǰ��ť���������λ��
		boxB->setPosition(boxB->getPosition() + touch->getDelta());
		return;
	}
}

void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
	log("onTouchEnded");	
	//ͨ��tag����ǩ�����BoxA����
	auto boxA = this->getChildByTag(kBoxA_Tag);
	//���BoxA���鱻���
	if (this->isTap(boxA, touch))
	{
		log("BoxA sprite Tap");
		boxA->runAction(ScaleTo::create(0.06f, 1.0f)); 
		return;
	}
	//ͨ��tag����ǩ�����BoxB����
	auto boxB = this->getChildByTag(kBoxB_Tag);
	//���BoxB���鱻���
	if (this->isTap(boxB, touch))
	{
		log("BoxB sprite Tap");
		boxB->runAction(ScaleTo::create(0.06f, 1.0f)); 
		return;
	}
}

bool HelloWorld::isTap(Node* node, Touch* touch)
{
	// ��ȡ���������Nodeλ������
	Vec2 locationInNode = node->convertToNodeSpace(touch->getLocation());
	Size s = node->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// �����Χ�жϼ��
	if (rect.containsPoint(locationInNode))
	{
		return true;
	}
	return false;
}
