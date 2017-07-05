#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "../sqlite/sqlite3.h"

class HelloWorld : public cocos2d::Layer
{
public:
    HelloWorld();
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
    sqlite3 *db;
    char* errorMessage;
};

#endif // __HELLOWORLD_SCENE_H__
