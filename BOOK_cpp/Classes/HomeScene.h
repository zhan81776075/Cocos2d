#ifndef __HOME_SCENE_H__
#define __HOME_SCENE_H__

#include "cocos2d.h"
#include "Chapter4Scene.h"
#include "Chapter5Scene.h"

class HomeScene : public cocos2d::Layer
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
	void menuChapterFourCallback(cocos2d::Ref* pSender);
	void menuChapterFiveCallback(cocos2d::Ref* pSender);
	//推出按钮
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(HomeScene);
};

#endif // __HELLOWORLD_SCENE_H__
