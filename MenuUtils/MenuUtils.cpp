#include "MenuUtils.h"

MenuUtils *MenuUtils::create()
{
    MenuUtils* menuUtils = new (std::nothrow) MenuUtils();
    menuUtils->autorelease();

    return menuUtils;
}

MenuUtils::MenuUtils()
{
    _director = Director::getInstance();
    _visible_size = _director->getVisibleSize();
    _origin = _director->getVisibleOrigin();

    _background_img = "menu/background-clouds.png";

    _font_header_label = "menu/fonts/FredokaOne-Regular.ttf";
    _color_header_label = Color4B(51, 204, 255, 255);

    _color_menu_label = Color4B(71, 243, 255, 150);

    return;
}

MenuUtils::~MenuUtils()
{}

//Set background
Sprite *MenuUtils::setBackground()
{
    Sprite *background_sprite = Sprite::create(_background_img);

    float scaleY = _visible_size.height / background_sprite->getContentSize().height;
    float scaleX = _visible_size.width / background_sprite->getContentSize().width;

    if (scaleX > scaleY) { background_sprite->setScale(scaleX); }
    else { background_sprite->setScale(scaleY); }

    background_sprite->setPosition(Point(_origin.x + _visible_size.width / 2, _origin.y + _visible_size.height / 2));
    return background_sprite;
}
//

//Set header label
Label *MenuUtils::setHeaderLabel(const std::string& text)
{
    float scale_factor = _director->getContentScaleFactor();
    std::stringstream scale;
    scale << scale_factor;
//    auto labelName = createLable(scale.str(), _font_header_label, _visible_size.height / 8);
    Label *label_name = createLable(text, _font_header_label, _visible_size.height / 8);

    label_name->setPosition(Vec2(_origin.x + _visible_size.width / 2, _origin.y + _visible_size.height - 1.1 * label_name->getContentSize().height));

    setStyleHeaderLabel(label_name);
    return label_name;
}

void MenuUtils::setStyleHeaderLabel(Label *label)
{
    label->setTextColor(_color_header_label);
    label->enableShadow(Color4B::BLACK, Size(5, -5), 2);
    label->enableOutline(Color4B::WHITE, 5);
}

Label *MenuUtils::createLable(const std::string &label_text, const std::string &font, float fontSize)
{
    return Label::createWithTTF(label_text, font, fontSize);
}
//

//Set Menu label
Label *MenuUtils::setMenuLabel(const std::string &text, Vec2 position, const ccMenuCallback &callback)
{
    Label *label = createLable(text, _font_header_label, _visible_size.width / 20);
    setStyleMenuLabel(label);
    Menu *menu = createLabelWithCallback(label, position, callback);
    return label;
}

void MenuUtils::setStyleMenuLabel(Label *label)
{
    label->setTextColor(_color_menu_label);
    label->enableShadow(Color4B::BLACK, Size(2, -2), 1);
    label->enableOutline(Color4B::WHITE, 2);
}

Menu *MenuUtils::createLabelWithCallback(Label *label, Vec2 position, const ccMenuCallback &callback)
{
    MenuItemLabel* menu_item = MenuItemLabel::create(label, callback);
    menu_item->setPosition(position);
    Menu* menu_label = Menu::create(menu_item, nullptr);
    menu_label->setPosition(Vec2::ZERO);
    return menu_label;
}
//

//Set Slider
ui::Slider *MenuUtils::setSlider(Vec2 position, int startValue, const ui::Slider::ccSliderCallback& callback)
{
    ui::Slider *slider = ui::Slider::create("menu/settingsMenu/slider/slider.png", "menu/settingsMenu/slider/greenPoint.png");
    slider->setPosition(position);
    slider->addEventListener(callback);

    slider->loadProgressBarTexture("menu/settingsMenu/slider/sliderLine.png");
    slider->setPercent(startValue);
    return slider;
}
//

//Set checkboox
ui::CheckBox * MenuUtils::setCheckBox(Vec2 position, bool is_active, const ui::CheckBox::ccCheckBoxCallback& callback)
{
    ui::CheckBox *check_box = ui::CheckBox::create("menu/settingsMenu/checkbox/greenCheckBoxNotActive.png",
                                          "menu/settingsMenu/checkbox/greenCheckBoxActive.png");
    check_box->setPosition(position);
    check_box->addEventListener(callback);
    if(is_active)
    {
        check_box->setSelected(true);
//        _slider->setPercent()
    }
    else
    {
        check_box->setSelected(false);
    }
    return check_box;
}
//

//Set Button
ui::Button *MenuUtils::setButton(Vec2 position, const ui::Widget::ccWidgetTouchCallback& callback)
{
    ui::Button* btn = ui::Button::create("menu/settingsMenu/buttons/buttonLanguage.png");
    if (btn == nullptr)
    {
        std::string err = "Can not create button menu/settingsMenu/buttons/buttonLanguage.png";
        throw std::runtime_error(err);
    }
    btn->setPosition(position);
    btn->addTouchEventListener(callback);
    btn->setTitleColor(Color3B::BLUE);
    btn->setTitleText("en");
    btn->setTitleFontSize(_visible_size.height / 16);
    return btn;
}
//