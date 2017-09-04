#pragma once
#include"cocos2d.h"

class Monster;
class GameScene;

//Tower类的成员函数只处理自身的操作
class Tower : public cocos2d::Sprite {
public:
	int id;																					//类型
	int attack;																			//攻击力
	int range;																			//范围
	int rank;																				//等级
	double delay;																		//发射间隔
	int value;																				//当前价格
	int upValue;																		//升级价格（升到顶级时upValue = -1，isMax = true）
	int sellValue;																		//出售价格	

	int bulletSpeed;
	float bulletDuration;

	bool isFiring;																		//开火标志位
	bool isMax;																			//顶级标志位

	cocos2d::Sprite* icon;														//升级图标（一开始不可见）

	Monster* target;																	//进入射程内的敌人

public:
	static Tower* create(int id);

	void fire() { isFiring = true; };
	void reload() { isFiring = false; };

	void showIcon() { icon->setVisible(true); };

	void upgrade();
};