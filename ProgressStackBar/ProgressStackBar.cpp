#include "ProgressStackBar.h"

ProgressStackBar::ProgressStackBar(std::string &emptyBall, std::string &yellowBall,
                                   int currentLevel, int maxLevel):
                                _emptyBall(emptyBall), _yellowBall(yellowBall),
                                _currentLevel(currentLevel), _maxLevel(maxLevel)
{
    if(!init(_currentLevel, maxLevel))
    {
        CCLOG("Error in PROGRESSSTACKBAR INIT");
    }
}

ProgressStackBar::~ProgressStackBar()
{}

ProgressStackBar *ProgressStackBar::create(std::string &emptyBall, std::string &yellowBall,
            int currentLevel, int maxLevel)
{
    ProgressStackBar *progressStackBar = new (std::nothrow) ProgressStackBar(emptyBall, yellowBall, currentLevel, maxLevel);
    progressStackBar->autorelease();
    return progressStackBar;
}

bool ProgressStackBar::init(int newCurrentLevel, int newMaxLevel)
{
    _currentLevel = newCurrentLevel;
    _maxLevel = newMaxLevel;
    _emptyBallSprite = Sprite::create(_emptyBall);
    _yellowBallSprite = Sprite::create(_yellowBall);
    _ballSize = _emptyBallSprite->getContentSize();
    _gap = _ballSize.width + _ballSize.width / 4;

    //yellow balls
    for(int i = 0; i < _currentLevel; ++i)
    {
        Sprite *clonedBall = Sprite::createWithTexture(_yellowBallSprite->getTexture());
        //startPosition.x - позиция первого
        //_gap - расстояние между центрами шаров
        //_gap * i расстояние от центра первого шара до центра текущего шара
        clonedBall->setPosition(Vec2(_gap * i, 0));
        this->addChild(clonedBall);
    }
    //empty balls
    for(int i = _currentLevel; i < _maxLevel; ++i)
    {
        Sprite *clonedBall = Sprite::createWithTexture(_emptyBallSprite->getTexture());
        clonedBall->setPosition(Vec2(_gap * i, 0));
        this->addChild(clonedBall);
    }
    return true;
}

bool ProgressStackBar::set_new_progress_bar(int newLevel)
{
    removeAllChildren();

    return init(newLevel, _maxLevel);
}

