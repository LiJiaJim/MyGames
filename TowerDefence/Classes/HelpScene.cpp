#include "HelpScene.h"

Scene* HelpScene::createScene() {
	auto scene = Scene::create();
	auto layer = HelpScene::create();

	scene->addChild(layer);

	return scene;
}

bool HelpScene::init() {
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	nowPage = 1;

	auto bgImg = Sprite::create("HelpScene/bg_help.png");
	bgImg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bgImg, BG_LAYER);

	bg_board = Sprite::create("HelpScene/pic_helpBoard.png");
	bg_board->setPosition(Vec2(origin.x+549.5 , origin.y+399.5));
	this->addChild(bg_board, BOARD_LAYER);

	//此处读取是否开启背景音乐
	if (UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		musicRight = Sprite::create("MenuScene/bt_bgMusicOpen.png");
		//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
	else {
		musicRight = Sprite::create("MenuScene/bt_bgMusicClose.png");

	}
	musicRight->setPosition(Vec2(origin.x + 1050, origin.y + 750));
	this->addChild(musicRight, MENU_LAYER);

	auto backItem = MenuItemImage::create("HelpScene/bt_return_1.png", "HelpScene/bt_return_2.png", CC_CALLBACK_1(HelpScene::menuReturnCallback, this));
	backItem->setPosition(Vec2(origin.x + 1044.5, origin.y + 47.5));
	leftItem = MenuItemImage::create("HelpScene/bt_left_1.png", "HelpScene/bt_left_2.png", CC_CALLBACK_1(HelpScene::menuLeftCallback, this));
	leftItem->setPosition(Vec2(origin.x + 225.5, origin.y + 149.5));
	rightItem = MenuItemImage::create("HelpScene/bt_right_1.png", "HelpScene/bt_right_2.png", CC_CALLBACK_1(HelpScene::menuRightCallback, this));
	rightItem->setPosition(Vec2(origin.x + 948.5, origin.y +149.5));
	auto bgMusicItem = MenuItemImage::create("MenuScene/bt_bgMusic.png", "MenuScene/bt_bgMusic.png", CC_CALLBACK_1(HelpScene::menuMusicCallback, this));
	bgMusicItem->setPosition(Vec2(origin.x + 1020, origin.y + 750));

	leftItem->setVisible(false);
	leftItem->setEnabled(false);

	auto menu = Menu::create(backItem, leftItem, rightItem, bgMusicItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, MENU_LAYER);

	page = Sprite::create("HelpScene/page1.png");
	page->setPosition(Vec2(530.5-73, 400-49));
	bg_board->addChild(page,MENU_LAYER);
	
	
	return true;
}

void HelpScene::menuReturnCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_error.wav");

	MySceneManager::myGetInstance()->toHelloScene();
}

void HelpScene::menuMusicCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_normal.wav");

	if (UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		musicRight->setTexture("MenuScene/bt_bgMusicClose.png");
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		UserDefault::getInstance()->setBoolForKey("isbgMusicOpen", false);
	}
	else {
		musicRight->setTexture("MenuScene/bt_bgMusicOpen.png");
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		UserDefault::getInstance()->setBoolForKey("isbgMusicOpen", true);
	}
	UserDefault::getInstance()->flush();

}

void HelpScene::menuLeftCallback(cocos2d::Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_normal.wav");

	nowPage -= 1;
	if (nowPage == 1) {
		leftItem->setVisible(false);
		leftItem->setEnabled(false);
	}
	if (nowPage == MAX_PAGE - 1) {
		rightItem->setVisible(true);
		rightItem->setEnabled(true);
	}
	setPage(nowPage);
}

void HelpScene::menuRightCallback(cocos2d::Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_normal.wav");

	nowPage += 1;
	if (nowPage == MAX_PAGE) {
		rightItem->setVisible(false);
		rightItem->setEnabled(false);
	}
	if (nowPage == 2) {
		leftItem->setVisible(true);
		leftItem->setEnabled(true);
	}
	setPage(nowPage);

}

void HelpScene::setPage(int nowPage) {
	bg_board->removeAllChildren();

	switch (nowPage)
	{
	case 1:
		page = Sprite::create("HelpScene/page1.png");
		page->setPosition(Vec2(530.5 - 73, 400 - 49));		//73,49
		break;
	case 2:
		page = Sprite::create("HelpScene/page2.png");
		page->setPosition(Vec2(620.5 - 73, 424.5 - 49));
		break;
	case 3:
		page = Sprite::create("HelpScene/page3.png");
		page->setPosition(Vec2(580 - 73, 427 - 49));
		break;
	case 4:
		page = Sprite::create("HelpScene/page4.png");
		page->setPosition(Vec2(562 - 73, 444 - 49));
		UserDefault::getInstance()->setBoolForKey("specialAchieve3", true);
		break;
	default:
		break;
	}
	bg_board->addChild(page, MENU_LAYER);
}