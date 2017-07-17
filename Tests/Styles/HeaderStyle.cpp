#include "HeaderStyle.h"

HeaderStyle::HeaderStyle():
    textStyle()
{

}

HeaderStyle HeaderStyle::getInstance()
{
    HeaderStyle* instance = new (std::nothrow) HeaderStyle();
    instance->autorelease();

    return instance;
}
