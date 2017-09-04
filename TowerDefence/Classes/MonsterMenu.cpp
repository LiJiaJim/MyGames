//
//  MonsterMenu.cpp
//  test
//
//  Created by Li子青 on 2017/8/26.
//
//

#include "MonsterMenu.hpp"
#include "MySceneManager.h"

USING_NS_CC;
Scene* MonsterMenu::createScene() {
    auto scene = Scene::create();
    auto layer = MonsterMenu::create();
    scene->addChild(layer);
    
    return scene;
}


bool MonsterMenu::init(){
    if(!Layer::init()){
    return false;
    }
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();

    
    
    auto bg_monsterMenu = Sprite::create("MonsterMenu/bg_monsterMenu.png");
    bg_monsterMenu->setPosition(Vec2(origin.x + visibleSize.width/2,
                                     origin.y + visibleSize.height/2));

    this->addChild(bg_monsterMenu);
    //背景


    
    mon1 = Sprite::create("MonsterMenu/mon1.png");
    mon1->setPosition(Vec2(550, 612.5));
    mon1->setVisible(true);
    this->addChild(mon1);
    
    mon2 = Sprite::create("MonsterMenu/mon2.png");
    mon2->setPosition(Vec2(550, 612.5));
    mon2->setVisible(false);
    this->addChild(mon2);
    
    mon3 = Sprite::create("MonsterMenu/mon3.png");
    mon3->setPosition(Vec2(550, 612.5));
    mon3->setVisible(false);
    this->addChild(mon3);
    
    mon4 = Sprite::create("MonsterMenu/mon4.png");
    mon4->setPosition(Vec2(550, 612.5));
    mon4->setVisible(false);
    this->addChild(mon4);
    
    mon5 = Sprite::create("MonsterMenu/mon5.png");
    mon5->setPosition(Vec2(550, 612.5));
    mon5->setVisible(false);
    this->addChild(mon5);
    
    mon6 = Sprite::create("MonsterMenu/mon6.png");
    mon6->setPosition(Vec2(550, 612.5));
    mon6->setVisible(false);
    this->addChild(mon6);
    
    mon7 = Sprite::create("MonsterMenu/mon7.png");
    mon7->setPosition(Vec2(550, 612.5));
    mon7->setVisible(false);
    this->addChild(mon7);
    
    mon7 = Sprite::create("MonsterMenu/mon7.png");
    mon7->setPosition(Vec2(550, 612.5));
    mon7->setVisible(false);
    this->addChild(mon7);
    
    mon8 = Sprite::create("MonsterMenu/mon8.png");
    mon8->setPosition(Vec2(550, 612.5));
    mon8->setVisible(false);
    this->addChild(mon8);
    
    unknown = Sprite::create("MonsterMenu/unknown.png");
    unknown->setPosition(Vec2(550,612.5));
    unknown->setVisible(false);
    this->addChild(unknown);
    
    //怪物介绍图
    
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    mon1a = Sprite::createWithSpriteFrameName("monster1_1.png");
    mon1a->setPosition(Vec2(196, 610));
    mon1a->runAction(createAnimate1());
    this->addChild(mon1a);
    
    mon2a = Sprite::createWithSpriteFrameName("monster2_1.png");
    mon2a->setPosition(Vec2(196, 610));
    mon2a->runAction(createAnimate2());
    this->addChild(mon2a);
    
    mon3a = Sprite::createWithSpriteFrameName("monster3_1.png");
    mon3a->setPosition(Vec2(196, 610));
    mon3a->runAction(createAnimate3());
    this->addChild(mon3a);
    
    mon4a = Sprite::createWithSpriteFrameName("monster4_1.png");
    mon4a->setPosition(Vec2(196, 610));
    mon4a->runAction(createAnimate4());
    this->addChild(mon4a);
    
    mon5a = Sprite::createWithSpriteFrameName("monster5_1.png");
    mon5a->setPosition(Vec2(196, 610));
    mon5a->runAction(createAnimate5());
    this->addChild(mon5a);
    
    mon6a = Sprite::createWithSpriteFrameName("monster6_1.png");
    mon6a->setPosition(Vec2(196, 610));
    mon6a->runAction(createAnimate6());
    this->addChild(mon6a);
    
    mon7a = Sprite::createWithSpriteFrameName("monster7_1.png");
    mon7a->setPosition(Vec2(196, 610));
    mon7a->runAction(createAnimate7());
    this->addChild(mon7a);
    
    mon8a = Sprite::createWithSpriteFrameName("monster8_1.png");
    mon8a->setPosition(Vec2(196, 610));
    mon8a->runAction(createAnimate8());
    this->addChild(mon8a);

    mon1a->setVisible(true);
    mon2a->setVisible(false);
    mon3a->setVisible(false);
    mon4a->setVisible(false);
    mon5a->setVisible(false);
    mon6a->setVisible(false);
    mon7a->setVisible(false);
    mon8a->setVisible(false);
    
    auto Monster_1Item = MenuItemImage::create("MonsterMenu/monster1_1.png", "MonsterMenu/monster1_2.png",CC_CALLBACK_1(MonsterMenu::Monster_1Callback,this));
    Monster_1Item->setPosition(Vec2(145.5, 332));
    
    auto Monster_2Item = MenuItemImage::create("MonsterMenu/monster2_1.png", "MonsterMenu/monster2_2.png",CC_CALLBACK_1(MonsterMenu::Monster_2Callback,this));
    Monster_2Item->setPosition(Vec2(308.5,332));
    
    auto Monster_3Item = MenuItemImage::create("MonsterMenu/monster3_1.png", "MonsterMenu/monster3_2.png",CC_CALLBACK_1(MonsterMenu::Monster_3Callback,this));
    Monster_3Item->setPosition(Vec2(476,337.5));

    auto Monster_4Item = MenuItemImage::create("MonsterMenu/monster4_1.png", "MonsterMenu/monster4_2.png",CC_CALLBACK_1(MonsterMenu::Monster_4Callback,this));
    Monster_4Item->setPosition(Vec2(644, 333.5));
    
    auto Monster_5Item = MenuItemImage::create("MonsterMenu/monster5_1.png", "MonsterMenu/monster5_2.png",CC_CALLBACK_1(MonsterMenu::Monster_5Callback,this));
    Monster_5Item->setPosition(Vec2(820, 334));
    
    auto Monster_6Item = MenuItemImage::create("MonsterMenu/monster6_1.png", "MonsterMenu/monster6_2.png",CC_CALLBACK_1(MonsterMenu::Monster_6Callback,this));
    Monster_6Item->setPosition(Vec2(989, 334));
    
    auto Monster_7Item = MenuItemImage::create("MonsterMenu/monster7_1.png", "MonsterMenu/monster7_2.png",CC_CALLBACK_1(MonsterMenu::Monster_7Callback,this));
    Monster_7Item->setPosition(Vec2(139.5, 177));
    
    auto Monster_8Item = MenuItemImage::create("MonsterMenu/monster8_1.png", "MonsterMenu/monster8_2.png",CC_CALLBACK_1(MonsterMenu::Monster_8Callback,this));
    Monster_8Item->setPosition(Vec2(308.5, 176));
    
    auto unknown1 = MenuItemImage::create("MonsterMenu/unknow.png", "",CC_CALLBACK_1(MonsterMenu::unknownCallback,this));
    unknown1->setPosition(Vec2(476, 175));
    
    auto unknown2 = MenuItemImage::create("MonsterMenu/unknow.png", "",CC_CALLBACK_1(MonsterMenu::unknownCallback,this));
    unknown2->setPosition(Vec2(644, 175));
    
    auto unknown3= MenuItemImage::create("MonsterMenu/unknow.png", "",CC_CALLBACK_1(MonsterMenu::unknownCallback,this));
    unknown3->setPosition(Vec2(819, 175));
    
    auto unknown4= MenuItemImage::create("MonsterMenu/unknow.png", "",CC_CALLBACK_1(MonsterMenu::unknownCallback,this));
    unknown4->setPosition(Vec2(991, 175));
    //怪物按钮
    auto closeItem = MenuItemImage::create("MonsterMenu/close_1.png", "MonsterMenu/close_2.png",CC_CALLBACK_1(MonsterMenu::closeCallback,this));
    closeItem->setPosition(Vec2(1059.5, 731));
    //关闭按钮
    
    auto menu = Menu::create(closeItem, Monster_1Item, Monster_2Item, Monster_3Item, Monster_4Item, Monster_5Item, Monster_6Item, Monster_7Item, Monster_8Item,unknown1,unknown2,unknown3,unknown4, NULL);
    menu->setPosition(origin.x,origin.y);
    this->addChild(menu,20);
    //*****功能键*****
    
    
    
    
    
    return true;
}

void MonsterMenu::closeCallback(Ref * pSender){
   SimpleAudioEngine::getInstance()->playEffect("Music/click_error.wav");
    MySceneManager::myGetInstance()->toMenuScene();
}



void MonsterMenu::Monster_1Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
	setVisable(1);
    mon1a->setVisible(true);
}
void MonsterMenu::Monster_2Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
   	setVisable(2);
    mon2a->setVisible(true);

}
void MonsterMenu::Monster_3Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisable(3);
    mon3a->setVisible(true);
}
void MonsterMenu::Monster_4Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisable(4);
    mon4a->setVisible(true);
}
void MonsterMenu::Monster_5Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
	setVisable(5);
    mon5a->setVisible(true);
}
void MonsterMenu::Monster_6Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisable(6);
    mon6a->setVisible(true);
}
void MonsterMenu::Monster_7Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisable(7);
    mon7a->setVisible(true);
}
void MonsterMenu::Monster_8Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisable(8);
    mon8a->setVisible(true);
}
void MonsterMenu::unknownCallback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
	setVisable(9);
}



void MonsterMenu::setVisable(int num) {
	mon1->setVisible(false);
    mon2->setVisible(false);
    mon3->setVisible(false);
	mon4->setVisible(false);
    mon5->setVisible(false);
    mon6->setVisible(false);
    mon7->setVisible(false);
    mon8->setVisible(false);
    
    mon1a->setVisible(false);
    mon2a->setVisible(false);
    mon3a->setVisible(false);
    mon4a->setVisible(false);
    mon5a->setVisible(false);
    mon6a->setVisible(false);
    mon7a->setVisible(false);
    mon8a->setVisible(false);
    
    unknown->setVisible(false);
	switch (num)
	{
	case 1:		mon1->setVisible(true);		break;
	case 2:		mon2->setVisible(true);   	break;
	case 3:		mon3->setVisible(true);   	break;
	case 4:		mon4->setVisible(true);   	break;
	case 5:		mon5->setVisible(true);   	break;
    case 6:		mon6->setVisible(true);   	break;
    case 7:		mon7->setVisible(true);   	break;
    case 8:		mon8->setVisible(true);   	break;
    case 9:		unknown->setVisible(true);		break;
	default:	break;
	}
}
//设置图片切换

Animate* MonsterMenu::createAnimate1(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster1_%d.png",i));
        frameVec.pushBack(frame);
    }

    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* MonsterMenu::createAnimate2(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster2_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* MonsterMenu::createAnimate3(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster3_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* MonsterMenu::createAnimate4(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster4_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* MonsterMenu::createAnimate5(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster5_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* MonsterMenu::createAnimate6(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster6_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* MonsterMenu::createAnimate7(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster7_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* MonsterMenu::createAnimate8(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("MonsterMenu/monster_about.plist", "MonsterMenu/monster_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("monster8_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate * action = Animate::create(animation);
    return action;
}


//动画效果













