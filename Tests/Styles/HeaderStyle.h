#ifndef HEADERSTYLES_H
#define HEADERSTYLES_H
#include "../../GUIUtils/GUIUtils.h"
#include "cocos2d.h"
USING_NS_CC;

class HeaderStyle: public Ref
{
public:
    HeaderStyle(float scaleFactor);
    static HeaderStyle* getInstance();

CC_CONSTRUCTOR_ACCESS:
    HeaderStyle() = delete;;
    HeaderStyle(const HeaderStyle &obj);
    HeaderStyle &operator =(const HeaderStyle &obj);
    ~HeaderStyle();

public:
    TextStyle textStyle;
    LabelShadowStyle shadowStyle;
    LabelOutlineStyle outlineStyle;
    LabelStyle labelStyle;
};

#endif // HEADERSTYLES_H
