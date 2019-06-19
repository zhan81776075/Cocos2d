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

#ifndef __Setting_SCENE_H__
#define __Setting_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class Setting : public cocos2d::Layer
{
	bool isEffect;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
    
    // a selector callback
    void menuSoundToggleCallback(cocos2d::Ref* pSender);
	void menuMusicToggleCallback(cocos2d::Ref* pSender);
	void menuOkCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Setting);
};

#endif // __Setting_SCENE_H__
