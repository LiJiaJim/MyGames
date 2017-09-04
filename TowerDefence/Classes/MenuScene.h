#pragma once
#include "cocos2d.h"
#include"MySceneManager.h"
USING_NS_CC;

class MenuScene : public cocos2d::Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(MenuScene);
	virtual bool init();

	MenuItemImage* leftItem;		//换关左右按钮
	MenuItemImage* rightItem;
	MenuItemImage* backItem;
	MenuItemImage* bgMusicItem;
	Sprite* musicRight;					//音乐按钮右边部分

private:

	void menuStartCallback(Ref* pSender);
	void menuAchieveCallback(Ref* pSender);
	void menuBackCallback(Ref* pSender);
	void menuMonsterCallback(Ref* pSender);
	void menuTowerCallback(Ref* pSender);
	void menuMusicCallback(Ref* pSender);
	void menuLeftCallback(Ref* pSender);
	void menuRightCallback(Ref* pSender);
	void setNowLevel(unsigned int);		//用于修改顶部数字和UserDefault中的nowLevel  + 修改底部本关信息
	void setMapMove(bool isNextLevel);		//用于移动地图执行动作
	void removeMap();

	Sprite* levelNum;	//顶部level右侧数字

	MenuItemImage* startItem;	//未解锁时Unable
	MenuItemImage* _startItem;

	Sprite* lastLevelMap;		//选关界面三个地图，用于执行动作
	Sprite*nowLevelMap;
	Sprite* nextLevelMap;
	Sprite* bottomLevelMap; //放在被移动的底层地图下，不执行动作

	Sprite* nowLevelInfo;		//底部本关信息
	
	unsigned int nowLevel;  //当前显示的关卡 （顶部数 中间图 以及向GameScene传的关卡值）
	unsigned int topLevel;
};
