#pragma once
#include"cocos2d.h"

typedef enum {
	UP,
	DOWN,
	RIGHT,
	LEFT
}Direction;


//Monster类的成员函数只处理自身的操作
class Monster : public cocos2d::Sprite {
public:
	double blood;																	//当前血量
	double maxblood;															//最大血量
	int id;																				//类型
	int zo;																				//ZOrder
	double speed;																	//速度
	Direction dir;																	//朝向
	int way;																			//当前在路径的位置
	cocos2d::Sprite* bloodBox;											//血条框
	cocos2d::Sprite* bloodSp;												//血条
	cocos2d::Sprite* icon;													//被选中的标识
	cocos2d::ProgressTimer* timer;											

	bool isMoving;																//怪物是否在移动标志位

	bool isGettingHurt = false;		

	cocos2d::Vector<cocos2d::SpriteFrame*> getHitFrames;	//子弹击中怪物

public:
	static Monster* create(int,int );
	void move(cocos2d::Point);
	void setMove() { isMoving = false; };

	/////////////////////////////
	void cutBlood();
	void resumeFromB2();
	void slowDown(int);
	void resumeFromB3(int);
};