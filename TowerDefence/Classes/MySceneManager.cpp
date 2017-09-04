#include "MySceneManager.h"

MySceneManager* MySceneManager::mySceneManager = NULL;

MySceneManager* MySceneManager::myGetInstance() {
	if (!mySceneManager) {
		mySceneManager = new MySceneManager();
	}
	return mySceneManager;
}

void MySceneManager::toHelloScene() {

	Scene* scene = HelloScene::createScene();
	auto* tt = TransitionFade::create(0.3f, scene);
	Director::getInstance()->replaceScene(tt);

	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/bg_HelloScene.wav",true);

	if (!UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}

}

void MySceneManager::toMenuScene() {

	Scene* scene = MenuScene::createScene();
	auto* tt = TransitionFade::create(0.4f, scene);
	Director::getInstance()->replaceScene(tt);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/bg_MenuScene.wav",true);
	if (!UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
}

void MySceneManager::toGameScene() {

	Scene* scene = GameScene::createScene();
	auto* tt = TransitionFade::create(0.4f, scene);
	Director::getInstance()->replaceScene(tt);

}

void MySceneManager::toHelpScene() {

	Scene* scene = HelpScene::createScene();
	auto* tt = TransitionFade::create(0.4f, scene);
	Director::getInstance()->replaceScene(tt);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/bg_HelpScene.wav",true);
	if (!UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}

}

void MySceneManager::toAchieveMenu(Node* node) {
	auto layer = AchieveMenu::create();
	node->addChild(layer,100);
}

void MySceneManager::toMonsterMenu() {
	Scene* scene = MonsterMenu::createScene();
	auto* tt = TransitionFade::create(0.4f, scene);
	Director::getInstance()->replaceScene(tt);
}

void MySceneManager::toTowerMenu() {
	Scene* scene = TowerMenu::createScene();
	auto* tt = TransitionFade::create(0.4f, scene);
	Director::getInstance()->replaceScene(tt);
}

void MySceneManager::toPauseMenu(Node* node) {
	auto layer = PauseMenu::create();
	node->addChild(layer,100);
}

void MySceneManager::toEndMenu(Node* node) {
	auto layer = EndMenu::create();
	layer->isWon = ((GameScene*)node)->isWon;
	layer->killNum = ((GameScene*)node)->killNum;
	layer->showMenu();		
	node->addChild(layer, 100);
	
	if (layer->isWon) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/bg_win.wav");
	}
	else {
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/bg_fail.wav");
	}

	if (!UserDefault::getInstance()->getBoolForKey("isbgMusicOpen")) {
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
}
