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
#ifndef __MYACTION_SCENE_H__
#define __MYACTION_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"

class MyAction : public cocos2d::Layer
{
    cocos2d::Label* pLabel;

public:
	
	static cocos2d::Scene* createScene();
    virtual bool init();
	virtual void onEnterTransitionDidFinish();
    // implement the "static create()" method manually
    CREATE_FUNC(MyAction);
	
    void backMenu(cocos2d::Ref* pSender);
};

#endif // __MYACTION_SCENE_H__
