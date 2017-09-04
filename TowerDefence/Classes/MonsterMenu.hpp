//
//  MonsterMenu.hpp
//  test
//
//  Created by Li子青 on 2017/8/26.
//
//

#ifndef MonsterMenu_hpp
#define MonsterMenu_hpp

#include <stdio.h>
#include "cocos2d.h"
//#include "MySceneManager.h"

USING_NS_CC;

class MonsterMenu:public Layer{
public:
    static Scene* createScene();
    CREATE_FUNC(MonsterMenu);
    virtual bool init();
    
    Map<int, Sprite*> getMonster();
    Sprite * M_origin;
    
private:
    void closeCallback(Ref * pSender);
    
    void Monster_1Callback(Ref * pSender);
    void Monster_2Callback(Ref * pSender);
    void Monster_3Callback(Ref * pSender);
    void Monster_4Callback(Ref * pSender);
    void Monster_5Callback(Ref * pSender);
    void Monster_6Callback(Ref * pSender);
    void Monster_7Callback(Ref * pSender);
    void Monster_8Callback(Ref * pSender);
    void unknownCallback(Ref * pSender);
     
    void setVisable(int num);
    
    Animate* createAnimate1();
    Animate* createAnimate2();
    Animate* createAnimate3();
    Animate* createAnimate4();
    Animate* createAnimate5();
    Animate* createAnimate6();
    Animate* createAnimate7();
    Animate* createAnimate8();
    Animate* selectAnimate1();
    Animate* selectAnimate2();
    Animate* selectAnimate3();
    
    Sprite* mon1;
    Sprite* mon2;
    Sprite* mon3;
    Sprite* mon4;
    Sprite* mon5;
    Sprite* mon6;
    Sprite* mon7;
    Sprite* mon8;
    Sprite* unknown;
    
    Sprite* mona;
    Sprite* mon1a;
    Sprite* mon2a;
    Sprite* mon3a;
    Sprite* mon4a;
    Sprite* mon5a;
    Sprite* mon6a;
    Sprite* mon7a;
    Sprite* mon8a;
    Sprite* unknowna;
    

    
};



#endif /* MonsterMenu_hpp */
