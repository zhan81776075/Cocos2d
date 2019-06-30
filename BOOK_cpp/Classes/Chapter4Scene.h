#ifndef __Chapter4_SCENE_H__
#define __Chapter4_SCENE_H__

#include "cocos2d.h"
#include "HomeScene.h"

class ChapterFour : public cocos2d::Layer
{
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

	//菜单项回调函数
	void menuSoundToggleCallback(cocos2d::Ref* pSender);
	void menuMusicToggleCallback(cocos2d::Ref* pSender);
	void backMenu(cocos2d::Ref* pSender);

	//4.3.1
	void menuItem1_4_3_1Callback(cocos2d::Ref* pSender);
	void menuItem2_4_3_1Callback(cocos2d::Ref* pSender);
	//4.3.2
	void menuItemHelpCallback(cocos2d::Ref* pSender);
	void menuItemStartCallback(cocos2d::Ref* pSender);
	void menuItemSettingCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(ChapterFour);
};

#endif // __Setting_SCENE_H__