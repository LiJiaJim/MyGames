#include "HelloScene.h"

Scene* HelloScene::createScene() {
	auto scene = Scene::create();
	auto layer = HelloScene::create();

	scene->addChild(layer);

	return scene;
}

bool HelloScene::init() {
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//////////////////////////////////////////////
	//auto bg_final = Sprite::create("GameScene/bg_final.png");
	//bg_final->setPosition(Vec2(-550, 600));		//550,600
	//this->addChild(bg_final, 30);

	//auto finalWave = Sprite::create("GameScene/final_1.png");
	//finalWave->setPosition(Vec2(300, -50));
	//bg_final->addChild(finalWave);

	//SpriteFrame* frame = NULL;
	//Vector<SpriteFrame*> frameVec;
	//SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
	//framecache->addSpriteFramesWithFile("GameScene/final.plist", "GameScene/final.png");

	//for (int i = 1; i <= 2; i++) {
	//	frame = framecache->getSpriteFrameByName(StringUtils::format("final_%d.png", i));
	//	frameVec.pushBack(frame);
	//}

	//Animation *animation = Animation::createWithSpriteFrames(frameVec);
	//animation->setLoops(-1);
	//animation->setDelayPerUnit(0.2f);
	//Animate * action = Animate::create(animation);

	//finalWave->runAction(action);

	//auto moveIn = MoveTo::create(1.5f, Vec2(550, 600));
	//auto moveOut = MoveTo::create(1.5f, Vec2(1750, 600));
	//auto _moveIn = EaseSineOut::create(moveIn);
	//auto _moveOut = EaseSineIn::create(moveOut);
	//bg_final->runAction(Sequence::create(_moveIn, _moveOut, NULL));

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

	auto enterItem = MenuItemImage::create("HelloScene/bt_enter_1.png", "HelloScene/bt_enter_2.png", CC_CALLBACK_1(HelloScene::menuEnterCallback, this));
	auto helpItem = MenuItemImage::create("HelloScene/bt_help_1.png", "HelloScene/bt_help_2.png", CC_CALLBACK_1(HelloScene::menuHelpCallback, this));
	auto quitItem = MenuItemImage::create("HelloScene/bt_quit_1.png","HelloScene/bt_quit_2.png",CC_CALLBACK_1(HelloScene::menuQuitCallback, this));
	auto bgMusicItem = MenuItemImage::create("MenuScene/bt_bgMusic.png", "MenuScene/bt_bgMusic.png", CC_CALLBACK_1(HelloScene::menuMusicCallback, this));

	enterItem->setPosition(Vec2(origin.x + 330,	   origin.y + 482.5));
	helpItem->setPosition(Vec2(origin.x + 334, origin.y + 405));
	quitItem->setPosition(Vec2(origin.x + 326, origin.y + 315.5));
	bgMusicItem->setPosition(Vec2(origin.x + 1020, origin.y + 750));

	auto menu = Menu::create(enterItem, helpItem, quitItem,bgMusicItem,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, MENU_LAYER);

	enterItem->setOpacity(0);		 helpItem->setOpacity(0);		 quitItem->setOpacity(0);

	auto bgImg = Sprite::create("HelloScene/bg_hello.png");
	bgImg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bgImg, BG_LAYER);


	//设置发光标题特效
	auto title = Sprite::create("HelloScene/title.png");
	//title->setPosition(Vec2(origin.x+340, origin.y+635));

	Size clipSize = title->getContentSize();
	Sprite* spark = Sprite::create("HelloScene/spark.png");
	spark->setPosition(-clipSize.width, 0);

	ClippingNode* clippingNode = ClippingNode::create();
	clippingNode->setPosition(Vec2(origin.x + 340, origin.y + 635));
	this->addChild(clippingNode,MENU_LAYER);

	clippingNode->setAlphaThreshold(0.05f); 
	clippingNode->setContentSize(clipSize);

	clippingNode->setStencil(title); 
	clippingNode->addChild(title, 3);  
	clippingNode->addChild(spark, 4); 

	MoveTo* moveAction = MoveTo::create(3.0f, Vec2(clipSize.width, 0));
	MoveTo* moveBackAction = MoveTo::create(0.0f, Vec2(-clipSize.width, 0));
	spark->runAction(RepeatForever::create(Sequence::create(moveAction, moveBackAction, NULL)));
	//标题设置完毕


	auto board = Sprite::create("HelloScene/board.png");
	board->setPosition(Vec2(origin.x + 314, origin.y + 1000));
	this->addChild(board, BOARD_LAYER);


	auto *drop1 = MoveTo::create(0.35f, Vec2(origin.x + 314, origin.y + 368));
	auto *rise1 = MoveTo::create(0.15f, Vec2(origin.x + 314, origin.y + 408));
	auto* drop2 = MoveTo::create(0.35f, Vec2(origin.x + 314, origin.y + 383));
	auto *rise2 = MoveTo::create(0.25f, Vec2(origin.x + 314, origin.y + 393));
	auto* drop3 = MoveTo::create(0.3f, Vec2(origin.x + 314, origin.y + 388));

	EaseSineIn* easeSineIn1 = EaseSineIn::create(drop1); 
	EaseSineIn* easeSineIn2 = EaseSineIn::create(rise1);
	EaseSineIn* easeSineIn3 = EaseSineIn::create(drop2);
	EaseSineIn* easeSineIn4 = EaseSineIn::create(rise2);
	EaseSineIn* easeSineIn5 = EaseSineIn::create(drop3);
	board->runAction(Sequence::create(easeSineIn1, easeSineIn2, easeSineIn3, easeSineIn4, easeSineIn5, NULL));

	auto delay1 = DelayTime::create(1.0f);	auto delay2 = DelayTime::create(1.4f);	auto delay3 = DelayTime::create(1.8f);
	auto fadeIn1 = FadeIn::create(0.8f);		auto fadeIn2 = FadeIn::create(0.8f);		auto fadeIn3 = FadeIn::create(0.8f);
	enterItem->runAction(Sequence::create(delay1,fadeIn1,NULL));
	helpItem->runAction(Sequence::create(delay2, fadeIn2, NULL));
	quitItem->runAction(Sequence::create(delay3, fadeIn3, NULL));


	Label* version = Label::createWithTTF("Ver3.0.3  8.30", "fonts/Marker Felt.ttf", 16);
	version->setPosition(Vec2(475, 230));
	this->addChild(version, MENU_LAYER);


	//设置星光特效

	auto star = Sprite::create("HelloScene/star.png");
	star->setPosition(Vec2(575, 626));
	star->setOpacity(0);
	this->addChild(star, MENU_LAYER + 1);

	auto delay_1 = DelayTime::create(2.2f);
	auto delay_2 = DelayTime::create(0.35f);
	auto fadeIn = FadeIn::create(0.3f);
	auto fadeOut = FadeOut::create(0.15f);
	auto rotate = RotateBy::create(0.45f, 120);
	auto zoomIn = ScaleTo::create(0.3f, 0.7f);
	auto zoomOut = ScaleTo::create(0.15f, 0.2f);

	auto spawn = Spawn::create(Sequence::create(fadeIn, fadeOut, NULL), rotate, Sequence::create(zoomIn, zoomOut, NULL), NULL);
	auto repeat = RepeatForever::create(Sequence::create(delay_1,spawn, delay_2, NULL));

	star->runAction(repeat);
	



	return true;
}

void HelloScene::menuQuitCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_click.wav");

	Director::getInstance()->end();
}

void HelloScene::menuEnterCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_click.wav");

	MySceneManager::myGetInstance()->toMenuScene();
}

void HelloScene::menuHelpCallback(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("Music/click_click.wav");

	MySceneManager::myGetInstance()->toHelpScene();
}

void HelloScene::menuMusicCallback(Ref* pSender) {
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
