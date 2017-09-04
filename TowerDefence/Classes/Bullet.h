#pragma once
#include"cocos2d.h"

class Monster;
class Tower;

class Bullet : public cocos2d::Sprite {
public:
	static Bullet* create(Tower*);

	void stopFlying();

public:
	int id;											//类型
	int speed;									//飞行速度
	int attack;									//攻击力
	bool isWithin;							//是否打到怪物里面

	float duration;

	bool isFlying;								//是否正在飞行的控制位

	Tower* tower;								//发射该子弹的塔

	cocos2d::Vector<cocos2d::SpriteFrame*> flyFrames;
	cocos2d::Vector<cocos2d::SpriteFrame*> blowFrames;
	cocos2d::Vector<cocos2d::SpriteFrame*>effectFrames;
};
