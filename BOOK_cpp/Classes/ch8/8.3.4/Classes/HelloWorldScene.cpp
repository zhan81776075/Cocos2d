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

	auto ball = Sprite::create("Ball.png");
	ball->setPosition(origin+Vec2(visibleSize.width/2, visibleSize.height/2));
	addChild(ball, 10, kBall_Tag);

	return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	log("HelloWorld onEnter");

	setAccelerometerEnabled(true);
}

void HelloWorld::onAcceleration(Acceleration* acc, Event *unused_event)
{
    log("{x = %f, y = %f}", acc->x,acc->y);
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
    //���С����ʵ��
	Sprite* ball = (Sprite*)this->getChildByTag(kBall_Tag);
	//���С�����С
    Size s = ball->getContentSize();
	//С����ĳ�ʼλ��
    Vec2 p0 = ball->getPosition();
    
	//С������˶�λ��x������
    float p1x =  p0.x + acc->x * SPEED ;

    if ((p1x - s.width/2) <0) {
        p1x = s.width/2;
    }
	//��ֹС����x�����곬����Ļ֮��
    if ((p1x + s.width / 2) > visibleSize.width) {
        p1x = visibleSize.width - s.width / 2;
    }
    
	//С������˶�λ��y������
    float p1y =  p0.y + acc->y * SPEED ;
    if ((p1y - s.height/2) < 0) {
        p1y = s.height/2;
    }
	//��ֹС����y�����곬����Ļ֮��
    if ((p1y + s.height/2) > visibleSize.height) {
        p1y = visibleSize.height - s.height/2;
    }
	//��������С���λ��
    ball->runAction(Place::create(Vec2( p1x, p1y))); 

}

void HelloWorld::onExit()
{
	Layer::onExit();
	log("HelloWorld onExit");
}