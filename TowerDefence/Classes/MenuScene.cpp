#include"MenuScene.h"

Scene* MenuScene::createScene() {
	auto scene = Scene::create();
	auto layer = MenuScene::create();

	scene->addChild(layer);

	return scene;
}

bool MenuScene::init() {
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

	auto bgImg = Sprite::create("MenuScene/bg_menu.png");
	bgImg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bgImg, BG_LAYER);
	auto bgGrey = Sprite::create("MenuScene/bg_grey.png");
	bgGrey->setPosition(Vec2(visibleSize.width / 2 + origin.x, origin.y+400));
	this->addChild(bgGrey, BOARD_LAYER);
	auto bgLevel = Sprite::create("MenuScene/bg_level.png");
	bgLevel->setPosition(Vec2(visibleSize.width / 2 + origin.x - 50 , origin.y + 700));
	this->addChild(bgLevel, MENU_LAYER);

	
	//此处读取是否开启背景音乐
	if (UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		musicRight = Sprite::create("MenuScene/bt_bgMusicOpen.png");
	}
	else {
		musicRight = Sprite::create("MenuScene/bt_bgMusicClose.png");
		//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
	musicRight->setPosition(Vec2(origin.x + 1050, origin.y + 750));
	this->addChild(musicRight, MENU_LAYER);

	_startItem = MenuItemImage::create("MenuScene/bt_start.png", "MenuScene/bt_start.png", CC_CALLBACK_1(MenuScene::menuStartCallback, this));
	startItem = MenuItemImage::create("MenuScene/bt_start_1.png", "MenuScene/bt_start_2.png", CC_CALLBACK_1(MenuScene::menuStartCallback, this));
	auto achieveItem = MenuItemImage::create("MenuScene/bt_achieve_1.png", "MenuScene/bt_achieve_2.png", CC_CALLBACK_1(MenuScene::menuAchieveCallback, this));
	auto monsterItem = MenuItemImage::create("MenuScene/bt_monster_1.png", "MenuScene/bt_monster_2.png", CC_CALLBACK_1(MenuScene::menuMonsterCallback, this));
	auto towerItem = MenuItemImage::create("MenuScene/bt_tower_1.png", "MenuScene/bt_tower_2.png", CC_CALLBACK_1(MenuScene::menuTowerCallback, this));
	auto backItem = MenuItemImage::create("MenuScene/bt_back_1.png", "MenuScene/bt_back_2.png", CC_CALLBACK_1(MenuScene::menuBackCallback, this));
	auto bgMusicItem = MenuItemImage::create("MenuScene/bt_bgMusic.png", "MenuScene/bt_bgMusic.png", CC_CALLBACK_1(MenuScene::menuMusicCallback, this));
	leftItem = MenuItemImage::create("MenuScene/bt_left_1.png", "MenuScene/bt_left_2.png", CC_CALLBACK_1(MenuScene::menuLeftCallback, this));
	rightItem = MenuItemImage::create("MenuScene/bt_right_1.png", "MenuScene/bt_right_2.png", CC_CALLBACK_1(MenuScene::menuRightCallback, this));

	_startItem->setPosition(Vec2(558.5, 442.5));
	startItem->setPosition(Vec2(origin.x + 351, origin.y + 52));
	achieveItem->setPosition(Vec2(origin.x + 502, origin.y + 41.5));
	monsterItem->setPosition(Vec2(origin.x + 637.5, origin.y + 46));
	towerItem->setPosition(Vec2(origin.x + 766, origin.y + 48));
	backItem->setPosition(Vec2(origin.x + 1032.5, origin.y + 45.5));
	bgMusicItem->setPosition(Vec2(origin.x + 1020, origin.y + 750));
	leftItem->setPosition(Vec2(origin.x + 69.5, origin.y + 400.5));
	rightItem->setPosition(Vec2(origin.x + 1030.5, origin.y + 400.5));

	auto menu = Menu::create(_startItem, startItem,achieveItem, monsterItem, towerItem,backItem, bgMusicItem, leftItem, rightItem,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, MENU_LAYER+20);

	//此处读取当前要显示的关卡，并初始化左右按钮是否显示，其他所有需要关卡信息的内容在之后添加
	nowLevel = UserDefault::getInstance()->getIntegerForKey("nowLevel", 1);
	topLevel = UserDefault::getInstance()->getIntegerForKey("topLevel", 1);
	if (1 == nowLevel) {
		leftItem->setVisible(false);
	}
	else if (6 == nowLevel) {
		rightItem->setVisible(false);
	}


	//此处将当前显示的地图等信息的纹理切换为nowLevel的
	if (topLevel >= nowLevel - 1) 
		lastLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel - 1)->getCString());
	else
		lastLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel - 1)->getCString());
	
	if (topLevel >= nowLevel) {
		nowLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel )->getCString());
		startItem->setEnabled(true);
		_startItem->setEnabled(true);
	}
	else {
		nowLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel )->getCString());
		startItem->setEnabled(false);
		_startItem->setEnabled(false);
	}
	
	if (topLevel >= nowLevel+1) 
		nextLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel + 1)->getCString());
	else 
		nextLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel + 1)->getCString());
	
	lastLevelMap->setPosition(Vec2(359, 433.5));
	nowLevelMap->setPosition(Vec2(558.5, 442.5));
	nextLevelMap->setPosition(Vec2(741, 433.5));
	lastLevelMap->setScale(0.66f);
	nextLevelMap->setScale(0.66f);
	this->addChild(lastLevelMap, 11);
	this->addChild(nowLevelMap, 13);
	this->addChild(nextLevelMap, 11);


	nowLevelInfo = Sprite::create(String::createWithFormat("MenuScene/LevelInfo/Level_%d.png", nowLevel)->getCString());
	nowLevelInfo->setPosition(Vec2(550, 181));		//550, 196
	this->addChild(nowLevelInfo, MENU_LAYER);
	
	nowLevelInfo->setOpacity(0);
	auto fadeIn = FadeIn::create(0.3f);
	nowLevelInfo->runAction(fadeIn);

	levelNum = Sprite::create(String::createWithFormat("MenuScene/LevelNum/Level_%d.png", nowLevel)->getCString());
	levelNum->setPosition(Vec2(origin.x + visibleSize.width/2 + 80, origin.y + 700));
	this->addChild(levelNum, MENU_LAYER);



	return true;
}

void MenuScene::menuBackCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_error.wav");

	MySceneManager::myGetInstance()->toHelloScene();
}

void MenuScene::menuAchieveCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_click.wav");

	MySceneManager::myGetInstance()->toAchieveMenu(this);
}

void MenuScene::menuStartCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_start.wav");

	MySceneManager::myGetInstance()->toGameScene();
}

void MenuScene::menuMonsterCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_click.wav");

	MySceneManager::myGetInstance()->toMonsterMenu();
}

void MenuScene::menuTowerCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_click.wav");

	MySceneManager::myGetInstance()->toTowerMenu();
}

void MenuScene::menuMusicCallback(Ref* pSender) {
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

void MenuScene::menuLeftCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_normal.wav");

	--nowLevel;
	if (1 == nowLevel) {
		leftItem->setVisible(false);
		leftItem->setEnabled(false);
	}
	else if (MAX_LEVEL - 1 == nowLevel) {
		rightItem->setVisible(true);
		rightItem->setEnabled(true);
	}
	setNowLevel(nowLevel);
	setMapMove(false);
}

void MenuScene::menuRightCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_normal.wav");

	++nowLevel;
	if (MAX_LEVEL == nowLevel) {
		rightItem->setVisible(false);
		rightItem->setEnabled(false);
	}
	else if (2 == nowLevel) {
		leftItem->setVisible(true);
		leftItem->setEnabled(true);
	}
	setNowLevel(nowLevel);
	setMapMove(true);
}

void MenuScene::setNowLevel(unsigned int nowLevel) {
	levelNum->setTexture(String::createWithFormat("MenuScene/levelNum/level_%d.png", nowLevel)->getCString());
	nowLevelInfo->setOpacity(0);
	nowLevelInfo->setTexture(String::createWithFormat("MenuScene/LevelInfo/Level_%d.png", nowLevel)->getCString());
	auto fadeIn = FadeIn::create(0.3f);
	nowLevelInfo->runAction(fadeIn);

	UserDefault::getInstance()->setIntegerForKey("nowLevel", nowLevel);
	UserDefault::getInstance()->flush();
}

void MenuScene::setMapMove(bool isNextLevel) {
	if (isNextLevel) {
		if (topLevel >= nowLevel + 1)
			bottomLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel + 1)->getCString());
		else
			bottomLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel + 1)->getCString());
		
		bottomLevelMap->setPosition(Vec2(741, 433.5));
		bottomLevelMap->setScale(0.66f);
		this->addChild(bottomLevelMap, 10);

		auto zoomOut = ScaleTo::create(0.12f, 0.66f);
		auto move1 = MoveTo::create(0.12f, Vec2(359, 433.5));
		auto _move1 = EaseSineOut::create(move1);
		nowLevelMap->runAction(Spawn::create(zoomOut, _move1, NULL));
		nowLevelMap->setLocalZOrder(12);

		auto delay = DelayTime::create(0.05f);
		auto zoomIn = ScaleTo::create(0.3f, 1.0f);
		auto move2 = MoveTo::create(0.3f, Vec2(558.5, 442.5));
		auto _move2 = EaseSineIn::create(move2);
		nextLevelMap->runAction(Sequence::create(delay, Spawn::create(zoomIn, _move2, NULL), CallFunc::create(this, callfunc_selector(MenuScene::removeMap)), NULL));
		nextLevelMap->setLocalZOrder(13);
	}
	else {
		if (topLevel >= nowLevel - 1)
			bottomLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel - 1)->getCString());
		else
			bottomLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel - 1)->getCString());

		bottomLevelMap->setPosition(Vec2(359, 433.5));
		bottomLevelMap->setScale(0.66f);
		this->addChild(bottomLevelMap, 10);

		auto zoomOut = ScaleTo::create(0.12f, 0.66f);
		auto move1 = MoveTo::create(0.12f, Vec2(741, 433.5));
		auto _move1 = EaseSineOut::create(move1);
		nowLevelMap->runAction(Spawn::create(zoomOut, _move1, NULL));
		nowLevelMap->setLocalZOrder(12);

		auto delay = DelayTime::create(0.05f);
		auto zoomIn = ScaleTo::create(0.3f, 1.0f);
		auto move2 = MoveTo::create(0.3f, Vec2(558.5, 442.5));
		auto _move2 = EaseSineIn::create(move2);
		lastLevelMap->runAction(Sequence::create(delay, Spawn::create(zoomIn, _move2, NULL), CallFunc::create(this, callfunc_selector(MenuScene::removeMap)), NULL));
		lastLevelMap->setLocalZOrder(13);
	}

}

void MenuScene::removeMap(){

	lastLevelMap->removeFromParent();
	nowLevelMap->removeFromParent();
	nextLevelMap->removeFromParent();

	if (topLevel >= nowLevel - 1)
		lastLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel - 1)->getCString());
	else
		lastLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel - 1)->getCString());

	if (topLevel >= nowLevel) {
		nowLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel)->getCString());
		startItem->setEnabled(true);
		_startItem->setEnabled(true);
	}
	else {
		nowLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel)->getCString());
		startItem->setEnabled(false);
		_startItem->setEnabled(false);
	}

	if (topLevel >= nowLevel + 1)
		nextLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/Level_%d.png", nowLevel + 1)->getCString());
	else
		nextLevelMap = Sprite::create(String::createWithFormat("MenuScene/LevelMap/_Level_%d.png", nowLevel + 1)->getCString());

	lastLevelMap->setPosition(Vec2(359, 433.5));
	nowLevelMap->setPosition(Vec2(558.5, 442.5));
	nextLevelMap->setPosition(Vec2(741, 433.5));
	lastLevelMap->setScale(0.66f);
	nextLevelMap->setScale(0.66f);
		
	this->addChild(lastLevelMap, 11);
	this->addChild(nowLevelMap, 13);
	this->addChild(nextLevelMap, 11);

	if (bottomLevelMap) {
		bottomLevelMap->removeFromParent();
	}
}
