#ifndef COCOS2DUTILS_PROGRESSSTACKBAR_H
#define COCOS2DUTILS_PROGRESSSTACKBAR_H
#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"

USING_NS_CC;

class ProgressStackBar : public Ref
{
public:
    ProgressStackBar(std::string &emptyBall, std::string &yellowBall, std::string &stackBackGround,
                     int currentLevel, int maxLevel);
    ~ProgressStackBar();

    bool init(std::string &emptyBall, std::string &yellowBall, std::string &stackBackGround,
              int currentLevel, int maxLevel);

    static ProgressStackBar *create(std::string &emptyBall, std::string &yellowBall, std::string &stackBackGround,
                    int currentLevel, int maxLevel);

    Sprite* set_yellow_ball();
    Sprite* set_empty_ball();
private:
    std::string _emptyBall;
    std::string _yellowBall;
    std::string _stackBackGround;
    int _currentLevel;
    int _maxLevel;

    Sprite *_emptyBallSprite;
    Sprite *_yellowBallSprite;
    Size _ballSize;
    float _gap;

    cocos2d::Director *_director;
    cocos2d::Size _visible_size;
    Vec2 _origin;
};


#endif //COCOS2DUTILS_PROGRESSSTACKBAR_H
