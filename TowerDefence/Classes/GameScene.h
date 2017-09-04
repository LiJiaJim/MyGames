#pragma once
#include"cocos2d.h"
#include "MySceneManager.h"
//#include"TowerOption.h"

class Monster;
class Tower;
class Bullet;
class Blow;
class Effect;

////////////////游戏中二倍速所需要修改的速度值
	//子弹飞行速度、
	//怪物动画播放速度、
	//	塔动画播放速度、
	//	塔攻击速度、
	//	怪物移动速度、
	//	刷怪速度、
	//	刷怪倒计时速度。


class GameScene : public cocos2d::Layer {
public:

	cocos2d::Sprite* Yeye;										//爷爷~

	int money;															//金钱
	int heart;																//生命力
	int nowWave;														//当前波数
	int wave;																//波数
	cocos2d::LabelTTF* moneyLabel;
	cocos2d::LabelTTF* heartLabel;
	cocos2d::LabelTTF* waveLabel;
	cocos2d::LabelTTF* levelLabel;					
	cocos2d::Sprite* bar;											//游戏上方菜单栏

	std::list<Monster*> monsterList;						//怪物容器
	std::list<Tower*> towerList;								//防御塔容器
	std::list<Bullet*>bulletList;								//子弹容器
	std::list<Blow*>blowList;									//效果容器
	std::list<Effect*>effectList;								//子弹效果容器

	cocos2d::Vector<Node*> blankVec;					//空白处容器
	cocos2d::TMXLayer* blankLayer;										

	std::vector<cocos2d::Point> path;					//路径

	std::vector<std::string>waveInfo;						//波数信息（第一项是波数，其余是每波怪物信息）

	bool isGameOver;												//游戏是否结束控制位
	int killNum;															//杀敌数
	int towerBuilt;														//本局建塔数
	bool isWon;															//游戏是否胜利控制位
	bool canCreateMonster;										//是否产生怪物控制位
	bool isShowingOption;										//是否正在显示菜单控制位
	bool isDoubleSpeed;											//二倍速控制位
	bool isFinalWave;												//是否是最后一波

	cocos2d::Size visibleSize;
	cocos2d::Point visibleOrigin;

	int level;																//关卡


	Monster* targetSelected;									//选中的怪物
	Tower* towerSelected;										//选中的塔（方便显示菜单）
	cocos2d::Point* cubeSelectedPoint;					//选中的建塔处（锚点为中心）

	cocos2d::Menu* menu;										//optionMenu
	cocos2d::MenuItemImage* menuItem_T1;		//防御塔1菜单项
	cocos2d::MenuItemImage* menuItem_T2;		//防御塔2菜单项
	cocos2d::MenuItemImage* menuItem_T3;		//防御塔3菜单项
	cocos2d::MenuItemImage* menuItem_Sell;		//出售菜单项
	cocos2d::MenuItemImage* menuItem_Up;		//升级菜单项


	cocos2d::Sprite*  cubeSelectedSp;					//选中空白的标识

public:
	CREATE_FUNC(GameScene);

	static cocos2d::Scene* createScene();

	virtual bool init();

	void initMap();													//读取地图信息

	void getWaveInfo();											//读取怪物波信息

	bool initPath();													//读取路径信息

	void initOptionMenu();										//初始化菜单层（一开始不可见、不可点击）

	void monsterCreate(float);								//产生下一波怪物

	void monsterMove();											//所有怪物移动

	void showOptionInBlank();								//空白处建选择菜单
	void showOptionWithTower();							//有塔处创建选择菜单

	bool onTouchBegan(cocos2d::Touch*,cocos2d::Event*);

	void towerAttack(Tower*);									//塔攻击

	void towerReload(Tower*);								//塔攻击间隔

	void getMoney(Point);										//获取金钱

	void showTip();													//开始时提示建塔处

	void countDown();												//开始前倒计时

	void startGame();												//开启游戏

	void finalWaveTip();											//最后一波怪物提示

	void cleanOption();											//取消菜单

	void Myupdate(float);
private:
	void createTowerCallBack(cocos2d::Ref*);		//建塔菜单回调事件

	void upgradeTowerCallBack(cocos2d::Ref*);	//塔升级菜单回调事件

	void menuPauseCallback(Ref* pSender);
	void menuMusicCallback(Ref* pSender);
	void menuWinCallback(Ref* psender);
	void menuFailCallback(Ref* psender);
	void menuSpeedCallback(Ref * psender);

	Sprite* musicRight;
	Sprite* speed;
};

///////////////////////////////
//存放爆炸的临时精灵
class Blow : public cocos2d::Sprite {
public:
	CREATE_FUNC(Blow);
	bool isBlowing = true;

	void stopBlow() { isBlowing = false; };
};

//////////////////////////////
//存放子弹特效的临时精灵
class Effect : public cocos2d::Sprite {
public:
	CREATE_FUNC(Effect);
	void stopUsing() { this->setVisible(false); };
};