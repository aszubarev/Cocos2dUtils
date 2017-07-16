#include "TestScene.h"
#include "SimpleAudioEngine.h"
#include "../SpriteUtils/SpriteUtils.h"
#include <iostream>

USING_NS_CC;

HelloWorld::HelloWorld(): errorMessage()
{}

HelloWorld::~HelloWorld()
{
    CC_SAFE_RELEASE_NULL(_settingUtils);
}

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
//    //////////////////////////////
//    // 1. super init first
//    if ( !Layer::init() )
//    {
//        return false;
//    }
//    _director = Director::getInstance();
//    _visible_size = _director->getVisibleSize();
//    _origin = _director->getVisibleOrigin();
//
//    _music_percent = 73;
//    if(_music_percent)
//    {
//        _check_box_active = true;
//    }
//
//    _menuUtils = GUIUtils::create();
//    _menuUtils->retain();
//
//    _background_sprite = _menuUtils->createBackground();
//    this->addChild(_background_sprite, -1);
//
//    _header_label = _menuUtils->setHeaderLabel("STRIKE TOWER");
//    this->addChild(_header_label);
//
//    _menu_label = _menuUtils->createMenuLabel("menu", Vec2(_origin.x + _visible_size.width / 2,
//                                                           _origin.y + _visible_size.height * 4 / 8),
//                                              CC_CALLBACK_1(HelloWorld::callback_start, this));
//    this->addChild(_menu_label);
//
//    _slider = _menuUtils->createSlider(
//            Vec2(_origin.x + _visible_size.width / 2, _origin.y + _visible_size.height * 3 / 8),
//            _music_percent, CC_CALLBACK_2(HelloWorld::callbackSliderEffect, this));
//    this->addChild(_slider);
//
//    _check_box = _menuUtils->createCheckBox(
//            Vec2(_origin.x + _visible_size.width * 6 / 7, _origin.y + _visible_size.height * 3 / 8),
//            _check_box_active, CC_CALLBACK_2(HelloWorld::callbackCheckBox, this));
//    this->addChild(_check_box);
//
//    _button = _menuUtils->createButtonWithTitle(
//            Vec2(_origin.x + _visible_size.width / 2, _origin.y + _visible_size.height * 2 / 8),
//            CC_CALLBACK_2(HelloWorld::callbackButton, this));
//    this->addChild(_button);
//
//
//    this->scheduleUpdate();
//
//    _settingUtils = SettingsUtils::getInstance();
//    _settingUtils->retain();
//
//    _settingUtils->setVolumeEffect(23);
//    std::cout << _settingUtils->getVolumeEffect();

    return true;
}

void HelloWorld::callback_start(cocos2d::Ref *pSender)
{
    _director->pushScene(TransitionFade::create(0.7, HelloWorld::createScene()));
    this->removeFromParent();
}

void HelloWorld::callbackSliderEffect(Ref* psender, ui::Slider::EventType type)
{
    auto slider = dynamic_cast<ui::Slider*>(psender);
    if(type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
         _music_percent = slider->getPercent();
        CCLOG("percentage = %d", _music_percent);
        if(_music_percent != 0)
        {
            _check_box->setSelected(true);
        }
        else
        {
            _check_box->setSelected(false);
        }
//      _settingsUtils->setVolumeEffect(percent);
    }
}

void HelloWorld::callbackCheckBox(Ref* psender, ui::CheckBox::EventType type)
{
    if(_slider == nullptr)
    {
        return;
    }
    switch(type)
    {
        case ui::CheckBox::EventType::SELECTED:
        {
            _slider->setPercent(_music_percent);
            _check_box_active = true;
        }break;
        case ui::CheckBox::EventType::UNSELECTED:
        {
            _slider->setPercent(0);
            _check_box_active = false;
        }break;
        default:
            break;
    }
}

void HelloWorld::callbackButton(Ref *pSender, ui::Widget::TouchEventType type)
{
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
        {
            _button->setTitleText("ru");
        }break;
        case ui::Widget::TouchEventType::ENDED:
        {

        }break;
        default:
            break;
    }
}
