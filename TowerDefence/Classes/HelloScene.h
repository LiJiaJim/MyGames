#pragma once

#include "cocos2d.h"
#include"MySceneManager.h"
USING_NS_CC;

class HelloScene : public Layer
{
public:
	CREATE_FUNC(HelloScene);
	static Scene* createScene();
	virtual bool init();

private:
	void menuEnterCallback(Ref* pSender);
	void menuHelpCallback(Ref* pSender);
	void menuQuitCallback(Ref* pSender);
	void menuMusicCallback(Ref* pSender);

	Sprite* musicRight;
};
