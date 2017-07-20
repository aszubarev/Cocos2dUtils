#ifndef COCOS2DUTILS_GUIUTILS_H
#define COCOS2DUTILS_GUIUTILS_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

struct TextStyle
{
    TextStyle(float pFontSize, const std::string &pFontFile, const Color4B &pTextColor);

    float fontSize;
    std::string fontFile;
    Color4B color;
};

struct LabelShadowStyle
{
    LabelShadowStyle(const Color4B &pShadowColor, Size pShadowOffset, int pBlurRadius);

    Color4B color;
    Size offset;
    int blurRadius;
};

struct LabelOutlineStyle
{
    LabelOutlineStyle(const Color4B &pOutlineColor, int pOutlineSize);

    Color4B color;
    int size;
};

struct LabelStyle
{
    LabelStyle(TextStyle &pTextStyle, LabelShadowStyle &pLabelShadowStyle, LabelOutlineStyle &pLabelOutlineStyle);

    TextStyle textStyle;
    LabelShadowStyle shadowStyle;
    LabelOutlineStyle outlineStyle;
};

struct TitletStyle
{
    TitletStyle(float pSize, const std::string &pfontName, const Color3B &pColor);

    float size;
    const std::string& fontName;
    const Color3B color;
};

namespace GUIUtils
{
    //Background
    Sprite *createBackground(const std::string &background, Size &visibleSize);

    //Label
    Label *createLabel(const std::string &text, LabelStyle &labelStyle);
    Label *createLabel(const std::string &text, Vec2 &position, LabelStyle &labelStyle);
    void setStyleLabel(Label *label, LabelStyle &labelStyle);

    //Menu label
    Menu *createMenuLabel(const std::string &text, Vec2 &position,
                                LabelStyle &labelStyle, const ccMenuCallback &callback);
    Menu *createMenu(Label *label, Vec2 &position, const ccMenuCallback &callback);

    //Slider
    ui::Slider *createSlider(const std::string &fileNameBar,    // Background of slider
                                    const std::string &fileNameBall,   // Ball of slider
                                    const std::string &fileNameLine,   // Line of slider
                                    int percent, Vec2 &position,
                                    const ui::Slider::ccSliderCallback &callback);
    //CheckBox
    ui::CheckBox *createCheckBox(const std::string& backGround, const std::string& cross,
                                        Vec2 position, bool is_active,
                                        const ui::CheckBox::ccCheckBoxCallback &callback);

    //Button
    ui::Button * createButton(const std::string &button, Vec2 position,
                                     const ui::Widget::ccWidgetTouchCallback &callback);

    ui::Button * createButtonWithTitle(const std::string &button, const std::string &tilte,
                                              Vec2 position, TitletStyle &tileStyle,
                                              const ui::Widget::ccWidgetTouchCallback &callback);
};


#endif //COCOS2DUTILS_GUIUTILS_H
