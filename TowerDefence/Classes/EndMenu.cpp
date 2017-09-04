#include"EndMenu.h"

bool EndMenu::init() {
	if (!Layer::init()) {
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

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

	//初始化背景木板和按钮纹理位置 + 杀敌数
	{
		bg_bottom = Sprite::create("EndMenu/bottom_win.png");
		bg_bottom->setPosition(Vec2(550, 400));
		bg_bottom->setOpacity(0);
		this->addChild(bg_bottom, BG_LAYER);

		bg_board = Sprite::create("EndMenu/board_win.png");
		bg_board->setPosition(Vec2(539.5,1000));
		this->addChild(bg_board, BOARD_LAYER);

		title = Sprite::create("EndMenu/title_win.png");
		title->setPosition(Vec2(545.5,601.5));
		title->setOpacity(0);
		title->setScale(0.2f);
		this->addChild(title, MENU_LAYER);

		//204，232
		nextItem = MenuItemImage::create("EndMenu/bt_next_1.png", "EndMenu/bt_next_2.png", CC_CALLBACK_1(EndMenu::menuNextCallback, this));
		nextItem->setPosition(Vec2(548-204 + origin.x, 362.5-232 + origin.y));
		auto restartItem = MenuItemImage::create("EndMenu/bt_restart_1.png", "EndMenu/bt_restart_2.png", CC_CALLBACK_1(EndMenu::menuRestartCallback, this));
		restartItem->setPosition(Vec2(362-204 + origin.x, 359.5-232 + origin.y));
		auto backItem = MenuItemImage::create("EndMenu/bt_back_1.png", "EndMenu/bt_back_2.png", CC_CALLBACK_1(EndMenu::menuBackCallback, this));
		backItem->setPosition(Vec2(735-204 + origin.x, 359.5-232 + origin.y));

		menu = Menu::create(nextItem, restartItem, backItem, NULL);
		menu->setPosition(Vec2::ZERO);
		bg_board->addChild(menu, MENU_LAYER);

		auto killNumImg = Sprite::create("EndMenu/killNumber.png");
		killNumImg->setPosition(Vec2(477-204, 460-232));
		bg_board->addChild(killNumImg);
		

	}

	//木板掉落效果
	{
		//539.5,424.5
		auto drop1 = MoveTo::create(0.18f, Vec2(origin.x + 539.5, origin.y + 404));
		auto rise1 = MoveTo::create(0.08f, Vec2(origin.x + 539.5, origin.y + 454));
		auto drop2 = MoveTo::create(0.18f, Vec2(origin.x + 539.5, origin.y + 419));
		auto rise2 = MoveTo::create(0.13f, Vec2(origin.x + 539.5, origin.y + 429));
		auto drop3 = MoveTo::create(0.15f, Vec2(origin.x + 539.5, origin.y + 424));
		EaseSineIn* easeSineIn1 = EaseSineIn::create(drop1);
		EaseSineIn* easeSineIn2 = EaseSineIn::create(rise1);
		EaseSineIn* easeSineIn3 = EaseSineIn::create(drop2);
		EaseSineIn* easeSineIn4 = EaseSineIn::create(rise2);
		EaseSineIn* easeSineIn5 = EaseSineIn::create(drop3);
		bg_board->runAction(Sequence::create(easeSineIn1, easeSineIn2, easeSineIn3, easeSineIn4, easeSineIn5, NULL));
	}

	//标题淡入放大，背景淡入
	{
		auto fadeIn = FadeIn::create(0.2f);
		auto zoomIn = ScaleTo::create(0.2f, 1.2f);
		auto zoomOut = ScaleTo::create(0.1f, 1.0f);
		title->runAction(Sequence::create(fadeIn, zoomIn, zoomOut, NULL));

		auto fadeIn2 = FadeIn::create(0.4f);
		bg_bottom->runAction(fadeIn2);
		
	}


	return true;
}

void EndMenu::showMenu() {

	//RGB : 187,118,19
	auto killNumLabel = Label::createWithTTF(String::createWithFormat("%d", killNum)->getCString(), "fonts/arial.ttf", 36);
	killNumLabel->setColor(Color3B(187, 118, 19));
	killNumLabel->setPosition(Vec2(597 - 204, 460 - 230));
	bg_board->addChild(killNumLabel);

	if (isWon) {
		
		//考虑放到GameScene isWon=true 调用toEnd之前
		int nowLevel = UserDefault::getInstance()->getIntegerForKey("nowLevel");
		switch (nowLevel)
		{
		case 1:
			UserDefault::getInstance()->setBoolForKey("normalAchieve1", true);
			break;
		case 3:
			UserDefault::getInstance()->setBoolForKey("normalAchieve2", true);
			break;
		case 6:
			UserDefault::getInstance()->setBoolForKey("normalAchieve3", true);
			break;
		default:
			break;
		}
		int topLevel = UserDefault::getInstance()->getIntegerForKey("topLevel");
		if (nowLevel == topLevel) {
			UserDefault::getInstance()->setIntegerForKey("topLevel", ++nowLevel);
		}
		UserDefault::getInstance()->flush();

	}
	else {
		auto yeYe = Sprite::create("EndMenu/trembleyy.png");
		yeYe->setPosition(Vec2(562.5-204, 353-232));//204，232
		bg_board->addChild(yeYe);
		bg_bottom->setTexture("EndMenu/bottom_fail.png");
		bg_board->setTexture("EndMenu/board_fail.png");
		title->setTexture("EndMenu/title_fail.png");
		nextItem->setVisible(false);
		nextItem->setEnabled(false);

	}

	if (!UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
}

void EndMenu::menuNextCallback(Ref* pSender) {
	int nowLevel = UserDefault::getInstance()->getIntegerForKey("nowLevel");
	if (nowLevel == MAX_LEVEL) {
		MySceneManager::myGetInstance()->toMenuScene();
	}
	else {
		UserDefault::getInstance()->setIntegerForKey("nowLevel", ++nowLevel);
		MySceneManager::myGetInstance()->toGameScene();
	}
}

void EndMenu::menuRestartCallback(Ref* pSender) {
	MySceneManager::myGetInstance()->toGameScene();
}

void EndMenu::menuBackCallback(Ref* pSender) {
	if (isWon) {
		int nowLevel = UserDefault::getInstance()->getIntegerForKey("nowLevel");
		int topLevel = UserDefault::getInstance()->getIntegerForKey("topLevel");

		if (++nowLevel > topLevel) {
			UserDefault::getInstance()->setIntegerForKey("topLevel", nowLevel);
		}
	}

	MySceneManager::myGetInstance()->toMenuScene();
}

