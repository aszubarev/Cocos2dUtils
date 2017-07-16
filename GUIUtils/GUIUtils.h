#ifndef COCOS2DUTILS_GUIUTILS_H
#define COCOS2DUTILS_GUIUTILS_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

struct TextStyle
{
    TextStyle(float pFontSize, const std::string &pFontFile, const Color4B &pTextColor);

    float fontSize;
    const std::string fontFile;
    const Color4B color;
};

struct LabelShadowStyle
{
    LabelShadowStyle(const Color4B &pShadowColor, Size pShadowOffset, int pBlurRadius);

    const Color4B color;
    const Size offset;
    int blurRadius;
};

struct LabelOutlineStyle
{
    LabelOutlineStyle(const Color4B &pOutlineColor, int pOutlineSize);

    const Color4B color;
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

class GUIUtils
{
public:

    //Background
    static Sprite *createBackground(const std::string &background);

    //Label
    static Label *createLable(const std::string &text, LabelStyle &labelStyle);
    static void setStyleLabel(Label *label, LabelStyle &labelStyle);

    //Menu label
    static Menu *createMenuLabel(const std::string &text, Vec2 &position,
                                LabelStyle &labelStyle, const ccMenuCallback &callback);
    static Menu *createMenu(Label *label, Vec2 &position, const ccMenuCallback &callback);

    //Slider
    static ui::Slider *createSlider(const std::string &fileNameBar,    // Background of slider
                                    const std::string &fileNameBall,   // Ball of slider
                                    const std::string &fileNameLine,   // Line of slider
                                    int percent, Vec2 &position,
                                    const ui::Slider::ccSliderCallback &callback);
    //CheckBox
    static ui::CheckBox *createCheckBox(const std::string& backGround, const std::string& cross,
                                        Vec2 position, bool is_active,
                                        const ui::CheckBox::ccCheckBoxCallback &callback);

    //Button
    static ui::Button * createButton(const std::string &button, Vec2 position,
                                     const ui::Widget::ccWidgetTouchCallback &callback);

    static ui::Button * createButtonWithTitle(const std::string &button, const std::string &tilte,
                                              Vec2 position, TitletStyle &tileStyle,
                                              const ui::Widget::ccWidgetTouchCallback &callback);

CC_CONSTRUCTOR_ACCESS:
    GUIUtils() = delete;
    GUIUtils(const GUIUtils &obj) = delete;
    GUIUtils &operator=(const GUIUtils &obj) = delete;
    ~GUIUtils() = delete;
};


#endif //COCOS2DUTILS_GUIUTILS_H
