#ifndef COCOS2DUTILS_IMAGEUTILS_H
#define COCOS2DUTILS_IMAGEUTILS_H

#include "cocos2d.h"
USING_NS_CC;

class ImageUtils
{
public:
    static Size getSize(const std::string &filename);

private:
    static std::string prefix_err_create_sprite;
};


#endif //COCOS2DUTILS_IMAGEUTILS_H
