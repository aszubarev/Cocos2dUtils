#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
#include "../SettingsUtils/SettingsUtils.h"
#include "../GUIUtils/GUIUtils.h"

class HelloWorld : public cocos2d::Layer
{
public:
    HelloWorld();
    ~HelloWorld();

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void callback_start(cocos2d::Ref *pSender);
    void callbackSliderEffect(Ref* psender, ui::Slider::EventType type);
    void callbackCheckBox(Ref* psender, ui::CheckBox::EventType type);
    void callbackButton(Ref *pSender, ui::Widget::TouchEventType type);
private:
    cocos2d::Director *_director;
    cocos2d::Size _visible_size;
    Vec2 _origin;

    SettingsUtils *_settingUtils;

    char* errorMessage;
    cocos2d::Layer *_layer;

    Sprite *_background_sprite;
    Label *_header_label;
    Label *_menu_label;
    ui::Slider *_slider;
    ui::CheckBox *_check_box;
    ui::Button* _button;

    int _music_percent;
    bool _check_box_active;
};

#endif // __HELLOWORLD_SCENE_H__
