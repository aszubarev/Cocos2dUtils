#include "TestScene.h"
#include "SimpleAudioEngine.h"
#include "../SpriteUtils/SpriteUtils.h"
#include <iostream>

USING_NS_CC;

HelloWorld::HelloWorld(): errorMessage()
{}


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();

    scene->getPhysicsWorld()->setFixedUpdateRate(300);
    scene->getPhysicsWorld()->setSpeed(0.7f);
    scene->getPhysicsWorld()->setGravity(Vect(0.f, -10000.0f));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(HelloWorld::onContactSeparate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    this->scheduleUpdate();
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
    Sprite* sprite = nullptr;
    try
    {
        sprite = SpriteUtils::createWithStaticBoxPB("HelloWorld.png", 1);
    }
    catch (std::invalid_argument &err)
    {
        std::cout << err.what() << std::endl;
        return true;
    }
    catch (std::runtime_error &err)
    {
        std::cout << err.what() << std::endl;
        return true;
    }
    catch (...)
    {
        std::cout << "UNKNOWN ERROR" << std::endl;
        return true;
    }


    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    _settingUtils = SettingsUtils::create();

//    // path for saving db
//    std::string dbName = "test2.db";
//    auto filePath = FileUtils::getInstance()->getWritablePath() + dbName;
//
//    auto status = sqlite3_open(filePath.c_str(), &db);
//    if(status != SQLITE_OK)
//    {
//        CCLOG("error for opening db.");
//    }
//    else
//    {
//        CCLOG("open successed!");
//    }
//
//    std::string path = FileUtils::getInstance()->getWritablePath()+"test.sqlite";
//    std::cout << path;

//    // create table
//    auto create_table = "create table user (id integer, age integer)";
//    status = sqlite3_exec(db, create_table, nullptr, nullptr, &errorMessage);
//    if(status != SQLITE_OK) CCLOG("create: %s", errorMessage);
//
//    // insert row
//    auto insert = "insert into user(id, age) values (1, 15)";
//    status = sqlite3_exec(db, insert, nullptr, nullptr, &errorMessage);
//    if(status != SQLITE_OK) CCLOG("insert: %s", errorMessage);
//
//    // update row
//    auto update = "update user set age = 20 where id = 1";
//    status = sqlite3_exec(db, update, nullptr, nullptr, &errorMessage);
//    if(status != SQLITE_OK) CCLOG("update: %s", errorMessage);
//
//    // select row(s)
//    sqlite3_stmt* statement = nullptr;
//    auto select = "select * from user where id = 1";
//    if(sqlite3_prepare_v2(db, select, -1, &statement, nullptr) != SQLITE_OK) CCLOG("prepare: %s", errorMessage);
//    else
//    {
//        if (sqlite3_step(statement) == SQLITE_ROW)
//        {
//            for (int i = 0; i < sqlite3_column_count(statement); i++)
//            {
//                std::string name = sqlite3_column_name(statement, i);
//                int columnType = sqlite3_column_type(statement, i);
//                if (columnType == SQLITE_INTEGER)
//                {
//                    CCLOG("%s = %d", name.c_str(), sqlite3_column_int(statement, i));
//                    continue;
//                }
//            }
//        }
//    }
//    sqlite3_reset(statement);
//    sqlite3_finalize(statement);
//
//    sqlite3_close(db);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
}

void HelloWorld::update(float dt)
{

}

bool HelloWorld::onContactBegin(cocos2d::PhysicsContact &contact)
{
    return false;
}

bool HelloWorld::onContactSeparate(cocos2d::PhysicsContact &contact)
{
    return false;
}


