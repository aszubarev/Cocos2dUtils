#ifndef COCOS2DUTILS_ANIMATEUTILS_H
#define COCOS2DUTILS_ANIMATEUTILS_H

#include "cocos2d.h"
USING_NS_CC;

class AnimateUtils
{
    static Animate* createAnimate(std::string &path, std::string &pattern,
                                  std::string &format, unsigned int numb_anim_frames, float delay = 0.0f);

    static std::string createFileName(std::string &path, std::string &pattern,
                                      std::string &format, unsigned int number);

    static Vector<SpriteFrame*> createVectorSpriteFrames(std::string &path, std::string &pattern,
                                                         std::string &format, unsigned int numb_anim_frames);

private:
    static const unsigned int max_anim_frames;
    static const unsigned int max_numb_digits;
};


#endif //COCOS2DUTILS_ANIMATEUTILS_H
