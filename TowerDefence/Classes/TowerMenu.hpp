//
//  TowerMenu.hpp
//  test
//
//  Created by Li子青 on 2017/8/28.
//
//

#ifndef TowerMenu_hpp
#define TowerMenu_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "MySceneManager.h"

USING_NS_CC;

class TowerMenu:public Layer{
public:
    static Scene* createScene();
    CREATE_FUNC(TowerMenu);
    virtual bool init();
    
    
private:
    void closeCallback(Ref * pSender);
    
    void Tower_1Callback(Ref * pSender);
    void Tower_2Callback(Ref * pSender);
    void Tower_3Callback(Ref * pSender);
    
    
    void setVisible(int num);
    
    
    Animate* selectAnimate1();
    Animate* selectAnimate2();
    Animate* selectAnimate3();
    Animate* TR_Animation1_1();
    Animate* TR_Animation1_2();
    Animate* TR_Animation1_3();
    Animate* TR_Animation2_1();
    Animate* TR_Animation2_2();
    Animate* TR_Animation2_3();
    Animate* TR_Animation3_1();
    Animate* TR_Animation3_2();
    Animate* TR_Animation3_3();
    

    Sprite* TR_1;
    Sprite* TR_2;
    Sprite* TR_3;
    Sprite* Tower_1Img;
    Sprite* Tower_2Img;
    Sprite* Tower_3Img;
    Sprite * TR_animation1_1;
    Sprite * TR_animation1_2;
    Sprite * TR_animation1_3;
    Sprite * TR_animation2_1;
    Sprite * TR_animation2_2;
    Sprite * TR_animation2_3;
    Sprite * TR_animation3_1;
    Sprite * TR_animation3_2;
    Sprite * TR_animation3_3;
    
    
};



#endif /* TowerMenu_hpp */
