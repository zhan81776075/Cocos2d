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

	_tileMap = TMXTiledMap::create("map/MiddleMap.tmx");
	addChild(_tileMap,0,100);

	TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
	ValueMap spawnPoint = group->getObject("ninja");

	float x = spawnPoint["x"].asFloat();
	float y = spawnPoint["y"].asFloat();

	_player = Sprite::create("ninja.png");
	_player->setPosition(Vec2(x,y));
	addChild(_player, 2, 200);

	setTouchEnabled(true);
    //设置为单点触
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
    log("onTouchBegan");
    return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
    log("onTouchMoved");
}

void HelloWorld::onTouchEnded(Touch *touch, Event *event)
{
    log("onTouchEnded");
	//获得OpenGL坐标
	Vec2 touchLocation = touch->getLocation();
	log("touchLocation (%f ,%f) ",touchLocation.x,touchLocation.y);

    Vec2 playerPos = _player->getPosition();
    Vec2 diff = touchLocation - playerPos;
    
    if (abs(diff.x) > abs(diff.y)) {
        if (diff.x > 0) {
            playerPos.x += _tileMap->getTileSize().width;
            _player->runAction(FlipX::create(false));
        } else {
            playerPos.x -= _tileMap->getTileSize().width;
            _player->runAction(FlipX::create(true));
        }
    } else {
        if (diff.y > 0) {
            playerPos.y += _tileMap->getTileSize().height;
        } else {
            playerPos.y -= _tileMap->getTileSize().height;
        }
    }
	log("playerPos (%f ,%f) ",playerPos.x,playerPos.y);
	_player->setPosition(playerPos);	
}
