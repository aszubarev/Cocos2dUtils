#ifndef COCOS2DUTILS_MENUUTILS_H
#define COCOS2DUTILS_MENUUTILS_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class MenuUtils : public Ref
{
public:

    MenuUtils();
    ~MenuUtils();
    MenuUtils(const MenuUtils &obj) = delete;
    MenuUtils &operator=(const MenuUtils &obj) = delete;

    static MenuUtils* create();

    //Background
    Sprite *setBackground();
    //

    //Header label
    Label *setHeaderLabel(const std::string& text);
    void setStyleHeaderLabel(Label *label);
    Label *createLable(const std::string &label_text, const std::string &font, float fontSize);
    //

    //Menu label
    Label *setMenuLabel(const std::string &text, Vec2 position, const ccMenuCallback &callback);
    void setStyleMenuLabel(Label *label);
    Menu *createLabelWithCallback(Label *label, Vec2 position, const ccMenuCallback &callback);
    //

    //Set slider, callback должен находиться в том классе откуда идет создание и вызов
    ui::Slider *setSlider(Vec2 position, int startValue, const ui::Slider::ccSliderCallback& callback);
    //

    //Set checkBoox
    ui::CheckBox *setCheckBox(Vec2 position, bool is_active, const ui::CheckBox::ccCheckBoxCallback& callback);
    //

    //Set Button
    ui::Button * setButton(Vec2 position, const ui::Widget::ccWidgetTouchCallback& callback);
    //
private:

    Director *_director;
    cocos2d::Size _visible_size;
    Vec2 _origin;

    std::string _background_img;
    std::string _font_header_label;

    Color4B _color_header_label;
    Color4B _color_menu_label;
};


#endif //COCOS2DUTILS_MENUUTILS_H
