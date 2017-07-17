#ifndef HEADERSTYLES_H
#define HEADERSTYLES_H
#include "../../GUIUtils/GUIUtils.h"
#include "cocos2d.h"
USING_NS_CC;

class HeaderStyle: public Ref
{
public:
    HeaderStyle();
    static HeaderStyle getInstance();

private:

    TextStyle textStyle;
    LabelShadowStyle shadowStyle;
    LabelOutlineStyle outlineStyle;

    LabelStyle labelStyle;

};

#endif // HEADERSTYLES_H
