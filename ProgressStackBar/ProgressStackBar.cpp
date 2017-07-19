#include "ProgressStackBar.h"

ProgressStackBar::ProgressStackBar(std::string &emptyBall, std::string &yellowBall, std::string &stackBackGround,
                                   int currentLevel, int maxLevel):
                                _emptyBall(emptyBall), _yellowBall(yellowBall), _stackBackGround(stackBackGround),
                                _currentLevel(currentLevel), _maxLevel(maxLevel)
{
    init(emptyBall, yellowBall, stackBackGround, currentLevel, maxLevel);
}

ProgressStackBar::~ProgressStackBar()
{

}

ProgressStackBar *ProgressStackBar::create(std::string &emptyBall, std::string &yellowBall, std::string &stackBackGround,
            int currentLevel, int maxLevel)
{
    ProgressStackBar *progressStackBar = new (std::nothrow) ProgressStackBar(emptyBall, yellowBall, stackBackGround, currentLevel, maxLevel);
    progressStackBar->autorelease();
    return progressStackBar;
}

bool ProgressStackBar::init(std::string &emptyBall, std::string &yellowBall, std::string &stackBackGround,
                            int currentLevel, int maxLevel)
{
    _director = Director::getInstance();
    _visible_size = _director->getVisibleSize();
    _origin = _director->getVisibleOrigin();

    _emptyBallSprite = Sprite::create(emptyBall);
    _yellowBallSprite = Sprite::create(yellowBall);
    _ballSize = _emptyBallSprite->getContentSize();
    _gap = _ballSize.width / 4;

    Vec2 firstBallPosition = Vec2(_visible_size.width / 2, _visible_size.height / 4);
    _yellowBallSprite->setPosition(firstBallPosition);

    _emptyBallSprite->setPosition(firstBallPosition.x + _gap + _ballSize.width,
                                  firstBallPosition.y);


}

Sprite* ProgressStackBar::set_yellow_ball()
{
    return _yellowBallSprite;
}

Sprite* ProgressStackBar::set_empty_ball()
{
    return _emptyBallSprite;
}

