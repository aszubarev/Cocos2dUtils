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

struct SliderStyle
{
    SliderStyle(const std::string &pFileBar,
                const std::string &pFileBall,
                const std::string &pFileLine);

    const std::string fileBar;
    const std::string fileBall;
    const std::string fileLine;
};

struct CheckBoxStyle
{
    CheckBoxStyle(const std::string& pFileBackGround,
                  const std::string& pFileCross);

    const std::string fileBackGround;
    const std::string fileCross;
};

namespace GUIUtils
{
    //Background
    Sprite *createBackground(const std::string &background, Size &visibleSize);

    //Label
    Label *createLabel(const std::string &text, LabelStyle &labelStyle);
    Label *createLabel(const std::string &text, const Vec2 &position, LabelStyle &labelStyle);
    void setStyleLabel(Label *label, LabelStyle &labelStyle);

    //Menu label
    Menu *createMenuLabel(const std::string &text, const Vec2 &position,
                                LabelStyle &labelStyle, const ccMenuCallback &callback);
    Menu *createMenu(Label *label, const Vec2 &position, const ccMenuCallback &callback);

    //Slider
    ui::Slider *createSlider(SliderStyle &style, int percent, const Vec2 &position,
                             const ui::Slider::ccSliderCallback &callback,
                             float scaleFactor = 1.0f);

    ui::Slider *createSlider(const std::string &fileNameBar,    // Background of slider
                             const std::string &fileNameBall,   // Ball of slider
                             const std::string &fileNameLine,   // Line of slider
                             int percent, const Vec2 &position,
                             const ui::Slider::ccSliderCallback &callback,
                             float scaleFactor = 1.0f);
    //CheckBox
    ui::CheckBox *createCheckBox(CheckBoxStyle &style,
                                 const Vec2 &position, bool is_active,
                                 const ui::CheckBox::ccCheckBoxCallback &callback,
                                 float scaleFactor = 1.0f);

    ui::CheckBox *createCheckBox(const std::string& backGround, const std::string& cross,
                                 const Vec2 &position, bool is_active,
                                 const ui::CheckBox::ccCheckBoxCallback &callback,
                                 float scaleFactor = 1.0f);

    //Button
    void setupButton(ui::Button *button, const Vec2 &position,
                     const ui::Widget::ccWidgetTouchCallback &callback,
                     float scaleFactor = 1.0f);

    ui::Button * createButton(const std::string &button, const Vec2 &position,
                              const ui::Widget::ccWidgetTouchCallback &callback);

    ui::Button * createButtonWithTitle(const std::string &button, const std::string &tilte,
                                       const Vec2 &position, TitletStyle &tileStyle,
                                       const ui::Widget::ccWidgetTouchCallback &callback);
};


#endif //COCOS2DUTILS_GUIUTILS_H
