#include "HeaderStyle.h"

HeaderStyle::HeaderStyle(float scaleFactor):
    textStyle(96.0f * scaleFactor, "menu/fonts/FredokaOne-Regular.ttf", Color4B(51, 204, 255, 255)),
    shadowStyle(Color4B::BLACK, Size(5, -5), 2),
    outlineStyle(Color4B::WHITE, 5),
    labelStyle(textStyle, shadowStyle, outlineStyle)
{}

HeaderStyle* HeaderStyle::getInstance()
{
    HeaderStyle* instance = new (std::nothrow) HeaderStyle(Director::getInstance()->getContentScaleFactor());
    instance->autorelease();

    return instance;
}
