//
//  TowerMenu.cpp
//  test
//
//  Created by Li子青 on 2017/8/28.
//
//

#include "TowerMenu.hpp"
USING_NS_CC;

Scene* TowerMenu::createScene() {
    auto scene = Scene::create();
    auto layer = TowerMenu::create();
    scene->addChild(layer);
    return scene;
}


bool TowerMenu::init(){
    if(!Layer::init()){
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_bt.plist", "TowerMenu/tower_bt.png");
    SpriteFrameCache * aboutcache = SpriteFrameCache::getInstance();
    aboutcache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
   
    
    auto bg_towerMenu = Sprite::create("TowerMenu/bg_towerMenu.png");
    bg_towerMenu->setPosition(Vec2(origin.x + visibleSize.width/2,
                                   origin.y + visibleSize.height/2));
    this->addChild(bg_towerMenu);
    //添加背景
    
    
    TR_1 = Sprite::create("TowerMenu/tower_data_1.png");
    TR_1->setPosition(Vec2(551.5, 273.5));
    TR_1->setVisible(true);
    this->addChild(TR_1);
    //数值介绍部分
    
    TR_animation1_1 = Sprite::createWithSpriteFrameName("tower_about_A_1_2.png");
    TR_animation1_1->setPosition(Vec2(322, 380));
    TR_animation1_1->runAction(TR_Animation1_1());
    this->addChild(TR_animation1_1);
    //level1效果
    
    TR_animation1_2 = Sprite::createWithSpriteFrameName("tower_about_A_2_1.png");
    TR_animation1_2->setPosition(Vec2(555, 380));
    TR_animation1_2->runAction(TR_Animation1_2());
    this->addChild(TR_animation1_2);
    //level2效果
    
    TR_animation1_3 = Sprite::createWithSpriteFrameName("tower_about_A_3_1.png");
    TR_animation1_3->setPosition(Vec2(788, 380));
    TR_animation1_3->runAction(TR_Animation1_3());
    this->addChild(TR_animation1_3);
    //level3效果
    /******塔1********/
    
    
    TR_2 = Sprite::create("TowerMenu/tower_data_2.png");
    TR_2->setPosition(Vec2(551.5, 273.5));
    TR_2->setVisible(false);
    this->addChild(TR_2);
    //数值介绍部分
    
    TR_animation2_1 = Sprite::createWithSpriteFrameName("tower_about_B_1_2.png");
    TR_animation2_1->setPosition(Vec2(322, 380));
    TR_animation2_1->runAction(TR_Animation2_1());
    TR_animation2_1->setVisible(false);
    this->addChild(TR_animation2_1);
    //level1效果
    
    TR_animation2_2 = Sprite::createWithSpriteFrameName("tower_about_B_2_1.png");
    TR_animation2_2->setPosition(Vec2(555, 380));
    TR_animation2_2->runAction(TR_Animation2_2());
    TR_animation2_2->setVisible(false);
    this->addChild(TR_animation2_2);
    //level2效果
    
    TR_animation2_3 = Sprite::createWithSpriteFrameName("tower_about_B_3_1.png");
    TR_animation2_3->setPosition(Vec2(788, 380));
    TR_animation2_3->runAction(TR_Animation2_3());
    TR_animation2_3->setVisible(false);
    this->addChild(TR_animation2_3);
    //level3效果
    /******塔2********/
    
    
    
    TR_3 = Sprite::create("TowerMenu/tower_data_3.png");
    TR_3->setPosition(Vec2(551.5, 273.5));
    TR_3->setVisible(false);
    this->addChild(TR_3);
    //数值介绍部分
    
    TR_animation3_1 = Sprite::createWithSpriteFrameName("tower_about_C_1_2.png");
    TR_animation3_1->setPosition(Vec2(322, 380));
    TR_animation3_1->runAction(TR_Animation3_1());
    TR_animation3_1->setVisible(false);
    this->addChild(TR_animation3_1);
    //level1效果
    
    TR_animation3_2 = Sprite::createWithSpriteFrameName("tower_about_C_2_1.png");
    TR_animation3_2->setPosition(Vec2(555, 380));
    TR_animation3_2->runAction(TR_Animation3_2());
    TR_animation3_2->setVisible(false);
    this->addChild(TR_animation3_2);
    //level2效果
    
    TR_animation3_3 = Sprite::createWithSpriteFrameName("tower_about_C_3_1.png");
    TR_animation3_3->setPosition(Vec2(788, 380));
    TR_animation3_3->runAction(TR_Animation3_3());
    TR_animation3_3->setVisible(false);
    this->addChild(TR_animation3_3);
    //level3效果
    /******塔3********/
    
    
    
    Tower_1Img = Sprite::createWithSpriteFrameName("Tower_1_1.png");
    Tower_1Img->setPosition(Vec2(244, 604));
    this->addChild(Tower_1Img,20);
    auto Tower_1Item = MenuItemImage::create("TowerMenu/tower_bt_bg.png", "",CC_CALLBACK_1(TowerMenu::Tower_1Callback,this));
    Tower_1Item->setPosition(Vec2(244, 604));
    Tower_1Item->setOpacity(7);
    
    
    
    Tower_2Img = Sprite::createWithSpriteFrameName("Tower_2_1.png");
    Tower_2Img->setPosition(Vec2(550, 604));
    this->addChild(Tower_2Img,20);
    auto Tower_2Item = MenuItemImage::create("TowerMenu/tower_bt_bg.png", "",CC_CALLBACK_1(TowerMenu::Tower_2Callback,this));
    Tower_2Item->setPosition(Vec2(500, 550));
    Tower_2Item->setOpacity(7);
    
    
    Tower_3Img = Sprite::createWithSpriteFrameName("Tower_3_1.png");
    Tower_3Img->setPosition(Vec2(856, 604));
    this->addChild(Tower_3Img,20);
    auto Tower_3Item = MenuItemImage::create("TowerMenu/tower_bt_bg.png", "",CC_CALLBACK_1(TowerMenu::Tower_3Callback,this));
    Tower_3Item->setPosition(Vec2(856, 604));
    Tower_3Item->setOpacity(7);
    //选择塔
    
    auto closeItem = MenuItemImage::create("TowerMenu/close_1.png", "TowerMenu/close_2.png",CC_CALLBACK_1(TowerMenu::closeCallback,this));
    closeItem->setPosition(Vec2(1036.5, 731));
    //关闭
    
    
    auto menu = Menu::create(closeItem, Tower_1Item , Tower_2Item , Tower_3Item , NULL);
    menu->setPosition(origin.x,origin.y);
    this->addChild(menu);
    //*******功能按钮******
    
    return true;
}





void TowerMenu::closeCallback(Ref * pSender){
    SimpleAudioEngine::getInstance()->playEffect("Music/click_error.wav");
    MySceneManager::myGetInstance()->toMenuScene();
}

void TowerMenu::Tower_1Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisible(1);
    Tower_1Img->runAction(selectAnimate1());
    
}
void TowerMenu::Tower_2Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisible(2);
    Tower_2Img->runAction(selectAnimate2());
}
void TowerMenu::Tower_3Callback(Ref * pSender){
	SimpleAudioEngine::getInstance()->playEffect("Music/menu_click.wav");
    setVisible(3);
    Tower_3Img->runAction(selectAnimate3());
}

void TowerMenu::setVisible(int num) {
    
    TR_1->setVisible(false);
    TR_2->setVisible(false);
    TR_3->setVisible(false);
    TR_animation1_1->setVisible(false);
    TR_animation1_2->setVisible(false);
    TR_animation1_3->setVisible(false);
    TR_animation2_1->setVisible(false);
    TR_animation2_2->setVisible(false);
    TR_animation2_3->setVisible(false);
    TR_animation3_1->setVisible(false);
    TR_animation3_2->setVisible(false);
    TR_animation3_3->setVisible(false);
    switch (num){
        case 1:  TR_1->setVisible(true);
            TR_animation1_1->setVisible(true);
            TR_animation1_2->setVisible(true);
            TR_animation1_3->setVisible(true);
            break;
        case 2:  TR_2->setVisible(true);
            TR_animation2_1->setVisible(true);
            TR_animation2_2->setVisible(true);
            TR_animation2_3->setVisible(true);
            break;
        case 3:  TR_3->setVisible(true);
            TR_animation3_1->setVisible(true);
            TR_animation3_2->setVisible(true);
            TR_animation3_3->setVisible(true);
            break;
        default:	break;
    }
}


Animate* TowerMenu::selectAnimate1(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/Tower_bt.plist", "TowerMenu/Tower_bt.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("Tower_1_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(1);
    animation->setDelayPerUnit(0.1f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* TowerMenu::selectAnimate2(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/Tower_bt.plist", "TowerMenu/Tower_bt.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("Tower_2_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(1);
    animation->setDelayPerUnit(0.1f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* TowerMenu::selectAnimate3(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/Tower_bt.plist", "TowerMenu/Tower_bt.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("Tower_3_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(1);
    animation->setDelayPerUnit(0.1f);
    Animate * action = Animate::create(animation);
    return action;
}

Animate* TowerMenu::TR_Animation1_1(){
    int iframeNum = 4;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_A_1_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation1_2(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_A_2_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.4f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation1_3(){
    int iframeNum = 5;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_A_3_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.4f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation2_1(){
    int iframeNum = 4;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_B_1_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation2_2(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_B_2_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.4f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation2_3(){
    int iframeNum = 5;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_B_3_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.4f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation3_1(){
    int iframeNum = 4;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_C_1_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.1f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation3_2(){
    int iframeNum = 2;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_C_2_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.4f);
    Animate * action = Animate::create(animation);
    return action;
    
}

Animate* TowerMenu::TR_Animation3_3(){
    int iframeNum = 5;
    SpriteFrame* frame= NULL;
    Vector<SpriteFrame*> frameVec;
    SpriteFrameCache * framecache = SpriteFrameCache::getInstance();
    framecache->addSpriteFramesWithFile("TowerMenu/tower_about.plist", "TowerMenu/tower_about.png");
    
    for (int i = 1; i <= iframeNum; i++){
        frame = framecache->getSpriteFrameByName(StringUtils::format("tower_about_C_3_%d.png",i));
        frameVec.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.4f);
    Animate * action = Animate::create(animation);
    return action;
    
}


