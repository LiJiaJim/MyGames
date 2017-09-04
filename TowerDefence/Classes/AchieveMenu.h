#pragma once
#include "cocos2d.h"
#include"MySceneManager.h"
USING_NS_CC;

class AchieveMenu : public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(AchieveMenu);

private:
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuType1Callback(Ref* pSender);
	void menuType2Callback(Ref* pSender);

	Sprite* bg_board;
	Sprite* bg_type1;
	Sprite* bg_type2;
};