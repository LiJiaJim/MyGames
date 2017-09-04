#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "HelloScene.h"
#include "MenuScene.h"
#include "HelpScene.h"
#include "AchieveMenu.h"
#include "GameScene.h"
#include "PauseMenu.h"
#include "MonsterMenu.hpp"
#include "TowerMenu.hpp"
#include "EndMenu.h"

#define BOTTOM_LAYER (0)
#define BG_LAYER (1)
#define BOARD_LAYER (2)
#define MENU_LAYER (3)

#define MAX_LEVEL (6)

#define ACHIEVE_MONEY (1500)

USING_NS_CC;
using namespace CocosDenshion;

class MySceneManager 
{
public:
	static MySceneManager* myGetInstance();
	void toHelloScene();
	void toMenuScene();
	void toGameScene();
	void toHelpScene();
	void toMonsterMenu();
	void toTowerMenu();
	void toAchieveMenu(Node* node);		
	void toPauseMenu(Node* node);
	void toEndMenu(Node* node);


private:
	static MySceneManager* mySceneManager;

};
