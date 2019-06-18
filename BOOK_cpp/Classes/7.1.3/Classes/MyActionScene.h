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

#ifndef __MYACTION_SCENE_H__
#define __MYACTION_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"

class MyAction : public cocos2d::Layer
{
    cocos2d::Sprite *sprite;

public:
	
	static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(MyAction);
	
	// a selector callback
    void goMenu(cocos2d::Ref* pSender);
    void backMenu(cocos2d::Ref* pSender);

	void OnSequence(cocos2d::Ref* pSender);
    void OnSpawn(cocos2d::Ref* pSender);
    void OnRepeat(cocos2d::Ref* pSender);
    void OnReverse(cocos2d::Ref* pSender);
    void OnRepeatForever(cocos2d::Ref* pSender);
};

#endif // __MYACTION_SCENE_H__
