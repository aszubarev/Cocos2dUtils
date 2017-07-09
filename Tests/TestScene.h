#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
#include "../SettingsUtils/SettingsUtils.h"

class HelloWorld : public cocos2d::Layer
{
public:
    HelloWorld();
    ~HelloWorld();

    static cocos2d::Scene* createScene();

    virtual bool init();

    void update(float dt);
    bool onContactBegin( cocos2d::PhysicsContact &contact );
    bool onContactSeparate( cocos2d::PhysicsContact &contact );
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref *pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    SettingsUtils *_settingUtils;
    char* errorMessage;
};

#endif // __HELLOWORLD_SCENE_H__
