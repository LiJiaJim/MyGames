#include"AchieveMenu.h"

bool AchieveMenu::init() {
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//屏蔽底层按钮///////////
	{
		auto callBack = [](Touch*, Event*)
		{
			return true;
		};
		EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
		listener->onTouchBegan = callBack;
		listener->setSwallowTouches(true);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	}

	//初始化木板和按钮纹理、位置
	{
		bg_board = Sprite::create("AchieveMenu/bg_board.png");
		bg_board->setPosition(Vec2(549.5, 800));
		this->addChild(bg_board, BOARD_LAYER);

		//木板左下角坐标 67,20
		auto typeItem1 = MenuItemImage::create("AchieveMenu/bt_type1.png", "AchieveMenu/bt_type1.png", CC_CALLBACK_1(AchieveMenu::menuType1Callback, this));
		typeItem1->setPosition(Vec2(352.5 - 67,469 - 20));
		auto typeItem2 = MenuItemImage::create("AchieveMenu/bt_type2.png", "AchieveMenu/bt_type2.png", CC_CALLBACK_1(AchieveMenu::menuType2Callback, this));
		typeItem2->setPosition(Vec2(767.5 - 67,468 - 20));
		auto closeItem = MenuItemImage::create("AchieveMenu/bt_close_1.png", "AchieveMenu/bt_close_2.png", CC_CALLBACK_1(AchieveMenu::menuCloseCallback, this));
		closeItem->setPosition(Vec2(923.5 - 67,717.5 - 20));
		auto menu = Menu::create(typeItem1, typeItem2,closeItem, NULL);
		menu->setPosition(Vec2::ZERO);
		bg_board->addChild(menu, MENU_LAYER);

		bg_type1 = Sprite::create("AchieveMenu/bg_type1.png");
		bg_type1->setPosition(Vec2(556.5 - 67, 306 - 20));
		bg_type2 = Sprite::create("AchieveMenu/bg_type2.png");
		bg_type2->setPosition(Vec2(556.5 - 67, 306 - 20));
		bg_board->addChild(bg_type1,BOARD_LAYER);
		bg_board->addChild(bg_type2,BG_LAYER);

	}

	//初始化累计建塔数、累计杀敌数标签
	{
		int allTowerNum = UserDefault::getInstance()->getIntegerForKey("allTowerNum", 0);
		int allKillNum = UserDefault::getInstance()->getIntegerForKey("allKillNum", 0);
		auto towerNum = Label::createWithTTF(String::createWithFormat("%d", allTowerNum)->getCString(), "fonts/Marker Felt.ttf", 32);
		auto killNum = Label::createWithTTF(String::createWithFormat("%d", allKillNum)->getCString(), "fonts/Marker Felt.ttf", 32);
		towerNum->setPosition(Vec2(352.5 - 67, 469 - 20 +100));
		killNum->setPosition(Vec2(767 - 67 + 50, 468 - 20 +100));
		towerNum->setColor(Color3B(187, 118, 19));
		killNum->setColor(Color3B(187, 118, 19));
		bg_board->addChild(towerNum, MENU_LAYER);
		bg_board->addChild(killNum, MENU_LAYER);
	}

	//木板掉落动作
	{
		auto drop1 = MoveTo::create(0.18f, Vec2(origin.x + 549.5, origin.y + 384));
		auto rise1 = MoveTo::create(0.08f, Vec2(origin.x + 549.5, origin.y + 434));
		auto drop2 = MoveTo::create(0.18f, Vec2(origin.x + 549.5, origin.y + 399));
		auto rise2 = MoveTo::create(0.13f, Vec2(origin.x + 549.5, origin.y + 409));
		auto drop3 = MoveTo::create(0.15f, Vec2(origin.x + 549.5, origin.y + 404));
		EaseSineIn* easeSineIn1 = EaseSineIn::create(drop1);
		EaseSineIn* easeSineIn2 = EaseSineIn::create(rise1);
		EaseSineIn* easeSineIn3 = EaseSineIn::create(drop2);
		EaseSineIn* easeSineIn4 = EaseSineIn::create(rise2);
		EaseSineIn* easeSineIn5 = EaseSineIn::create(drop3);
		bg_board->runAction(Sequence::create(easeSineIn1, easeSineIn2, easeSineIn3, easeSineIn4, easeSineIn5, NULL));
	}

	//初始化type1成就完成
	{
		//159,117
		if (UserDefault::getInstance()->getBoolForKey("normalAchieve1", false)) {
			auto finished = Sprite::create("AchieveMenu/finished.png");
			finished->setPosition(Vec2(887.5 - 159, 378.5 - 117));
			bg_type1->addChild(finished, MENU_LAYER);
		}
		if (UserDefault::getInstance()->getBoolForKey("normalAchieve2", false)) {
			auto finished = Sprite::create("AchieveMenu/finished.png");
			finished->setPosition(Vec2(887.5 - 159, 276.5 - 117));
			bg_type1->addChild(finished, MENU_LAYER);
		}
		if (UserDefault::getInstance()->getBoolForKey("normalAchieve3", false)) {
			auto finished = Sprite::create("AchieveMenu/finished.png");
			finished->setPosition(Vec2(887.5 - 159, 170.5 - 117));
			bg_type1->addChild(finished, MENU_LAYER);
		}
	}


	return true;
}


void AchieveMenu::menuCloseCallback(Ref* pSender) 
{

	this->removeAllChildrenWithCleanup(true);
	this->removeFromParent();

}

void AchieveMenu::menuType1Callback(Ref* pSender) {

	bg_type2->removeAllChildren();

	if (UserDefault::getInstance()->getBoolForKey("normalAchieve1", false)) {
		auto finished = Sprite::create("AchieveMenu/finished.png");
		finished->setPosition(Vec2(887.5 - 159, 378.5 - 117));
		bg_type1->addChild(finished, MENU_LAYER);
	}
	if (UserDefault::getInstance()->getBoolForKey("normalAchieve2", false)) {
		auto finished = Sprite::create("AchieveMenu/finished.png");
		finished->setPosition(Vec2(887.5 - 159, 276.5 - 117));
		bg_type1->addChild(finished, MENU_LAYER);
	}
	if (UserDefault::getInstance()->getBoolForKey("normalAchieve3", false)) {
		auto finished = Sprite::create("AchieveMenu/finished.png");
		finished->setPosition(Vec2(887.5 - 159, 170.5 - 117));
		bg_type1->addChild(finished, MENU_LAYER);
	}

	bg_type1->setZOrder(BOARD_LAYER);
	bg_type2->setZOrder(BG_LAYER);
}

void AchieveMenu::menuType2Callback(Ref* pSender) {

	bg_type1->removeAllChildren();

	if (UserDefault::getInstance()->getBoolForKey("specialAchieve1", false)) {
		auto finished = Sprite::create("AchieveMenu/finished.png");
		finished->setPosition(Vec2(900.5 - 159, 375.5 - 117));
		bg_type2->addChild(finished, MENU_LAYER);
	}
	if (UserDefault::getInstance()->getBoolForKey("specialAchieve2", false)) {
		auto finished = Sprite::create("AchieveMenu/finished.png");
		finished->setPosition(Vec2(900.5 - 159, 278.5 - 117));
		bg_type2->addChild(finished, MENU_LAYER);
	}
	if (UserDefault::getInstance()->getBoolForKey("specialAchieve3", false)) {
		auto finished = Sprite::create("AchieveMenu/finished.png");
		finished->setPosition(Vec2(900.5 - 159, 175.5 - 117));
		bg_type2->addChild(finished, MENU_LAYER);
	}

	bg_type2->setZOrder(BOARD_LAYER);
	bg_type1->setZOrder(BG_LAYER);
}
