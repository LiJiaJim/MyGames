#pragma once
#include "cocos2d.h"
#include "MySceneManager.h"
USING_NS_CC;

class PauseMenu : public Layer {
public:
	virtual bool init();
	CREATE_FUNC(PauseMenu);


private:

	void menuResumeCallback(Ref* pSender);
	void menuRestartCallback(Ref* pSender);
	void menuBackCallback(Ref* pSender);

	void quitPauseMenu();
	 
	Sprite* bg_board;
	Menu* menu;
	Sprite* bg_left;
	Sprite* bg_right;
	Sprite* bg_grey;
};