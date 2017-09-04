#pragma once
#include"Tower.h"
USING_NS_CC;

int ATKtable[3][3] = { { 50*2,			40 * 2,		20 * 2 },//第一级
									{ 70 * 2,			60 * 2,		30 * 2 },//第二级
									{ 80 * 2,		70 * 2,		50 * 2 } };//第三级

double delayTable[3][3] = { {	  1.0,		1.4,		2.0 },
												{ 0.9,		1.3,		1.7 },
												{ 0.75,		1.1,		1.3 } };

int rangeTable[3][3] = { {   180,   200,		200 },
										{ 210,	240,		240 },
										{ 240,	300,		280 } };

int valueTable[3][3] = { {	  120,	100,		80 },
										{ 160,	130,		120, },
										{ 220,	200,		180 } };

int sellTable[3][3] = { {   72,		60,		48 },//出售价格为成本的60%
									{ 168,	138,		128 },
									{ 300,	258,		308 } };

int BulletSpeedTable[3] = { 500,500,500 };

float BulletDurationTable[3][3] = { { 0,		2,		2 },
{ 0,		3,		3 } ,
{ 0,		5,		5 } };


Tower* Tower::create(int id)
{
	Tower* tower = new Tower();
	if (tower && tower->initWithFile(String::createWithFormat("GameScene/Tower/tower%d_R1.png", id)->getCString()))
	{
		tower->rank = 1;
		tower->id = id;
		tower->attack = ATKtable[0][id - 1];
		tower->delay = delayTable[0][id - 1];
		tower->range = rangeTable[0][id - 1];
		tower->value = valueTable[0][id - 1];
		tower->upValue = valueTable[1][id - 1];
		tower->sellValue = sellTable[0][id - 1];


		tower->bulletSpeed = BulletSpeedTable[tower->rank - 1];
		tower->bulletDuration = BulletDurationTable[0][id - 1];

		//升级箭头
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("GameScene/Tower/arrow_up.plist");

		Vector<SpriteFrame*> arrow_frames;

		arrow_frames.pushBack(cache->getSpriteFrameByName("arrow_up_1.png"));
		arrow_frames.pushBack(cache->getSpriteFrameByName("arrow_up_2.png"));

		tower->icon = Sprite::createWithSpriteFrame(arrow_frames.front());

		auto repeat = RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(arrow_frames, 0.5f)));

		tower->icon->runAction(repeat);

		tower->setScale(0.8f);
		tower->icon->setVisible(false);
		tower->addChild(tower->icon, 1);
		tower->icon->setPosition(20, 0);

		tower->isFiring = false;
		tower->isMax = false;

		return tower;
	}
	else
	{
		delete tower;
		tower = NULL;
		return NULL;
	}
}


void Tower::upgrade()
{
	//更新信息（当不是最高级时）
	rank++;

	attack = ATKtable[rank-1][id-1];
	delay = delayTable[rank - 1][id - 1];
	range = rangeTable[rank - 1][id - 1];
	value = valueTable[rank - 1][id - 1];
	sellValue = sellTable[rank - 1][id - 1];

	bulletDuration = BulletDurationTable[rank-1][id-1];
	if (rank == 3)
	{
		upValue = -1;
		icon->setVisible(false);
		isMax = true;
	}
	else
	{
		upValue = valueTable[rank][id - 1];
	}

	setTexture(String::createWithFormat("GameScene/Tower/tower%d_R%d.png", id,rank)->getCString());
}

