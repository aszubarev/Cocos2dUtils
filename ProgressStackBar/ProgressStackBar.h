#ifndef COCOS2DUTILS_PROGRESSSTACKBAR_H
#define COCOS2DUTILS_PROGRESSSTACKBAR_H
#include "cocos2d.h"

USING_NS_CC;

class ProgressStackBar : public Sprite
{
public:
    ProgressStackBar(std::string &emptyBall, std::string &yellowBall,
                     int currentLevel, int maxLevel);
    ~ProgressStackBar();

    static ProgressStackBar *create(std::string &emptyBall, std::string &yellowBall,
                    int currentLevel, int maxLevel);

    bool set_new_progress_bar(int newLevel);

private:
    std::string _emptyBall;
    std::string _yellowBall;
    int _currentLevel;
    int _maxLevel;

    Sprite *_emptyBallSprite;
    Sprite *_yellowBallSprite;
    Size _ballSize;
    float _gap;

    bool init(int newCurrentLevel, int newMaxLevel);
};


#endif //COCOS2DUTILS_PROGRESSSTACKBAR_H
