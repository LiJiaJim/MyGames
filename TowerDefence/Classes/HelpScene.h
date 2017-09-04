#pragma once
#include "cocos2d.h"
#include"MySceneManager.h"
USING_NS_CC;

#define MAX_PAGE (4)

class HelpScene : public cocos2d::Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HelpScene);

private:
	void menuReturnCallback(cocos2d::Ref* pSender);
	void menuLeftCallback(cocos2d::Ref* pSender);
	void menuRightCallback(cocos2d::Ref* pSender);
	void menuMusicCallback(Ref* pSender);

	void setPage(int);
	
	Sprite* bg_board;
	Sprite* page;
	Sprite* musicRight;
	MenuItemImage* leftItem;
	MenuItemImage* rightItem;
	int nowPage;
};