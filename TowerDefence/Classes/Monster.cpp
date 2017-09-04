#include"Monster.h"
#include"GameScene.h"
USING_NS_CC;

										// 1      2     3       4        5       6       7       8
double bloodTable[8] = { 300, 200, 500, 1400, 1600, 900, 1600, 8000 };
int speedTable[8] =        { 50,   100, 80,    45,     90,    120, 100,    70 };
int ZOTabel[8] = { 1,    2,   1,   1,   2,   3,   3,   4 };

#define BURN_EFFECT (25)	//子弹燃烧伤害

Monster* Monster::create(int id,int way)
{
	Monster* monster = new Monster();

	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile(String::createWithFormat("GameScene/Monster/monster%d.plist", id)->getCString());


	Vector<SpriteFrame*> frames;
	frames.pushBack(cache->getSpriteFrameByName(String::createWithFormat("monster%d_1.png", id)->getCString()));
	frames.pushBack(cache->getSpriteFrameByName(String::createWithFormat("monster%d_2.png", id)->getCString()));

	if (monster&&monster->initWithSpriteFrame(frames.front()))
	{
		monster->id = id;

		monster->maxblood = monster->blood =bloodTable[id - 1];
		monster->speed = speedTable[id - 1];
		monster->zo = ZOTabel[id-1];
		monster->dir = RIGHT;
		monster->way = way;

		monster->autorelease();


		auto animation = Animation::createWithSpriteFrames(frames,0.3f);
		auto animate = Animate::create(animation);

		monster->runAction(RepeatForever::create(animate));

		//血槽
		monster->bloodBox = Sprite::create("GameScene/Monster/bloodbox.png");
		monster->bloodBox->setPosition(Point(monster->getContentSize().width/2, monster->getContentSize().height / 2));
		monster->addChild(monster->bloodBox, 1);

		//血条
		monster->bloodSp = Sprite::create("GameScene/Monster/blood.png");
		monster->timer = ProgressTimer::create(monster->bloodSp);
		monster->timer->setType(ProgressTimer::Type::BAR);
		monster->timer->setMidpoint(Point(0,0));
		monster->timer->setPosition(Point(monster->getContentSize().width / 2, monster->getContentSize().height / 2));
		monster->timer->setPercentage(100);
		monster->timer->setBarChangeRate(Point(1,0));
		
		monster->addChild(monster->timer, 2);


		//被选中标识(箭头)
		monster->icon = Sprite::create("GameScene/Monster/arrow_down.png");
		monster->icon->setScale(0.8f);
		monster->icon->setPosition(Point(monster->getContentSize().width/2,monster->getContentSize().height));
		monster->icon->setVisible(false);
		monster->addChild(monster->icon, 10);
		
		return monster;
	}
	else
	{
		delete monster;
		monster = NULL;
		return NULL;
	}
}

void Monster::move(Point nextPoint)
{
		isMoving = true;

		double time;										//移动时间

		//确定朝向
		if (nextPoint.x - this->getPosition().x != 0)
		{
			if (nextPoint.x - this->getPosition().x > 0)
				dir = RIGHT;
			else
				dir = LEFT;
			time = abs((this->getPosition().x - nextPoint.x)/speed);
		}
		else
		{
			if (nextPoint.y - this->getPosition().y > 0)
				dir = UP;
			else
				dir = DOWN;
			time = abs((this->getPosition().y - nextPoint.y)/speed);
		}

		switch (dir)
		{
		case UP:
		case RIGHT:
			this->setFlippedX(false);
			break;
		case DOWN:
		case LEFT:
			this->setFlippedX(true);
			break;
		}

		auto callfunc = [&]() {--way; };//移动后怪物在路径中的位置 -1

		//运动
		auto seq = Sequence::create(
			MoveTo::create(time, nextPoint),
			CallFuncN::create(CC_CALLBACK_0(Monster::setMove, this)),
			CallFunc::create(callfunc),
			NULL);
		this->runAction(seq);
}

void Monster::cutBlood()
{
	//持续攻击不能使怪物致死
	if (blood - BURN_EFFECT >30)
	{
		blood -= BURN_EFFECT;
		timer->setPercentage(blood / maxblood * 100);
	}
}

void Monster::resumeFromB2()
{
	isGettingHurt = false;
}

void Monster::slowDown(int rank)
{
	switch (rank)
	{
	case 1:
		this->speed *= 0.75;
		break;
	case 2:
		this->speed *= 0.60;
		break;
	case 3:
		this->speed *= 0.5;
		break;
	}
}

void Monster::resumeFromB3(int rank)
{
	switch (rank)
	{
	case 1:
		this->speed /= 0.75;
		break;
	case 2:
		this->speed /= 0.60;
		break;
	case 3:
		this->speed /= 0.5;
		break;
	}
	isGettingHurt = false;
}
