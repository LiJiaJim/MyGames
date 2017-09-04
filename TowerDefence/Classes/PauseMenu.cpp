#include "PauseMenu.h"

bool PauseMenu::init() {
	if (!Layer::init()) {
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//ÆÁ±Îµ×²ã°´Å¥///////////
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

	//³õÊ¼»¯Ä¾°åºÍ°´Å¥ÎÆÀí¡¢Î»ÖÃ
	{
		bg_board = Sprite::create("PauseMenu/bg_board.png");
		bg_board->setPosition(Vec2(origin.x + 552.5, origin.y + 1000));
		this->addChild(bg_board, BOARD_LAYER);

		//246,276
		auto resumeItem = MenuItemImage::create("PauseMenu/bt_continue_1.png", "PauseMenu/bt_continue_2.png", CC_CALLBACK_1(PauseMenu::menuResumeCallback, this));
		resumeItem->setPosition(Vec2(361.5 - 246 + origin.x, 450 - 276 + origin.y));
		auto restartItem = MenuItemImage::create("PauseMenu/bt_restart_1.png", "PauseMenu/bt_restart_2.png", CC_CALLBACK_1(PauseMenu::menuRestartCallback, this));
		restartItem->setPosition(Vec2(550.5 - 246 + origin.x, 450 - 276 + origin.y));
		auto backItem = MenuItemImage::create("PauseMenu/bt_back_1.png", "PauseMenu/bt_back_2.png", CC_CALLBACK_1(PauseMenu::menuBackCallback, this));
		backItem->setPosition(Vec2(739.5 - 246 + origin.x, 450 - 276 + origin.y));
	
		menu = Menu::create(resumeItem, restartItem, backItem, NULL);
		menu->setPosition(Vec2(0,0));
		bg_board->addChild(menu, MENU_LAYER);		//½«²Ëµ¥Ç¶Èëµ½Ä¾°åÉÏ
	}

	//Ä¾°åµôÂäÐ§¹û
	{
		auto drop1 = MoveTo::create(0.18f, Vec2(origin.x + 552.5, origin.y + 414));
		auto rise1 = MoveTo::create(0.08f, Vec2(origin.x + 552.5, origin.y + 464));
		auto drop2 = MoveTo::create(0.18f, Vec2(origin.x + 552.5, origin.y + 429));
		auto rise2 = MoveTo::create(0.13f, Vec2(origin.x + 552.5, origin.y + 439)); 
		auto drop3 = MoveTo::create(0.15f, Vec2(origin.x + 552.5, origin.y + 434));
		EaseSineIn* easeSineIn1 = EaseSineIn::create(drop1);
		EaseSineIn* easeSineIn2 = EaseSineIn::create(rise1);
		EaseSineIn* easeSineIn3 = EaseSineIn::create(drop2);
		EaseSineIn* easeSineIn4 = EaseSineIn::create(rise2);
		EaseSineIn* easeSineIn5 = EaseSineIn::create(drop3);
		bg_board->runAction(Sequence::create(easeSineIn1, easeSineIn2, easeSineIn3, easeSineIn4, easeSineIn5, NULL));
	}

	//×óÓÒÌÙÂüÉì³ö
	{
		bg_left = Sprite::create("PauseMenu/bg_left.png");
		bg_left->setPosition(Vec2(origin.x -550, origin.y + 600));
		this->addChild(bg_left, BG_LAYER);
		
		bg_right = Sprite::create("PauseMenu/bg_right.png");
		bg_right->setPosition(Vec2(origin.x + 1650, origin.y + 200));
		this->addChild(bg_right, BG_LAYER);

		auto move1 = MoveTo::create(0.4f, Vec2(600, 600));
		EaseSineOut* _move1 = EaseSineOut::create(move1);
		auto back1 = MoveTo::create(0.1f, Vec2(550, 600));
		bg_left->runAction(Sequence::create(_move1,back1,NULL));

		auto move2 = MoveTo::create(0.4f, Vec2(500, 200));
		EaseSineOut* _move2 = EaseSineOut::create(move2);
		auto back2 = MoveTo::create(0.1f, Vec2(550, 200));
		bg_right->runAction(Sequence::create(_move2, back2, NULL));
	}

	//µ×²ãÌí¼Ó»ÒÉ«ÕÚÕÖ²ã
	{
		bg_grey = Sprite::create("PauseMenu/bg_grey.png");
		bg_grey->setPosition(visibleSize / 2);
		this->addChild(bg_grey, BOTTOM_LAYER);
	}


	return true;
}

void PauseMenu::menuResumeCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_normal.wav");

	//Ä¾°å²Ëµ¥Í¬²½ÉÏÀ­
	{
		auto delay = DelayTime::create(0.2f);

		auto drop1 = MoveTo::create(0.1f, Vec2(552.5,414));
		auto rise1 = MoveTo::create(0.2f, Vec2(552.5,1000));
		EaseSineOut* _drop1 = EaseSineOut::create(drop1);
		EaseSineIn* _rise1 = EaseSineIn::create(rise1);
		bg_board->runAction(Sequence::create(_drop1, _rise1, delay,CallFunc::create(this, callfunc_selector(PauseMenu::quitPauseMenu)), NULL));

		auto drop2 = MoveTo::create(0.1f, Vec2(0, -20));
		auto rise2 = MoveTo::create(0.2f, Vec2(0, 600));
		EaseSineOut* _drop2 = EaseSineOut::create(drop2);
		EaseSineIn* _rise2 = EaseSineIn::create(rise2);
		menu->runAction(Sequence::create(_drop2, _rise2, delay, NULL));

	}

	//×óÓÒÌÙÂüËõ»Ø È¥ÕÚÕÖ
	{
		auto move1 = MoveTo::create(0.4f, Vec2(600, 600));
		EaseSineIn* _move1 = EaseSineIn::create(move1);
		auto back1 = MoveTo::create(0.1f, Vec2(-550, 600));
		bg_left->runAction(Sequence::create(_move1, back1, NULL));

		auto move2 = MoveTo::create(0.4f, Vec2(500, 200));
		EaseSineIn* _move2 = EaseSineIn::create(move2);
		auto back2 = MoveTo::create(0.1f, Vec2(1650, 200));
		bg_right->runAction(Sequence::create(_move2, back2, NULL));

		bg_grey->setVisible(false);
	}
	
}

void PauseMenu::menuRestartCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_start.wav");

	MySceneManager::myGetInstance()->toGameScene();
}

void PauseMenu::menuBackCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_error.wav");

	MySceneManager::myGetInstance()->toMenuScene();
}

void PauseMenu::quitPauseMenu() {
	this->getParent()->resumeSchedulerAndActions();
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParent();
}