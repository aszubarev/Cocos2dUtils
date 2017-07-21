#include "ProgressStackBar.h"
#include "../ImageUtils/ImageUtils.h"

ProgressStackBar::ProgressStackBar(std::string &emptyCellFile, std::string &filledCellFile,
                                   int currentLevel, int maxLevel):
                    _emptyCellFile(emptyCellFile), _filledCellFile(filledCellFile),
                                _currentLevel(currentLevel), _maxLevel(maxLevel)
{
    prefix_err_create_sprite = "ERROR: Can not open ";
    prefix_err_bad_argument = "ERROR: bad argument";

    _cellSize = ImageUtils::getSize(_emptyCellFile);

    _gap = _cellSize.width / 4;
    _step = _gap + _cellSize.width;

    if(!init(_currentLevel, maxLevel))
    {
        CCLOG("Error in PROGRESSSTACKBAR INIT");
    }
}

ProgressStackBar::~ProgressStackBar()
{}

ProgressStackBar *ProgressStackBar::create(std::string &emptyCellFile, std::string &filledCellFile,
                                           int currentLevel, int maxLevel)
{
    ProgressStackBar *progressStackBar = new (std::nothrow) ProgressStackBar(emptyCellFile, filledCellFile, currentLevel, maxLevel);
    progressStackBar->autorelease();
    return progressStackBar;
}

bool ProgressStackBar::init(int currentLevel, int maxLevel)
{
    _currentLevel = currentLevel;
    _maxLevel = maxLevel;

    //yellow balls
    for(int i = 0; i < _currentLevel; ++i)
    {
        Sprite *cell = Sprite::create(_filledCellFile);
        if(cell == nullptr)
        {
            throw std::invalid_argument(prefix_err_create_sprite + _filledCellFile);
        }
        cell->setPosition(Vec2(_step * i, 0));
        this->addChild(cell);
    }
    //empty balls
    for(int i = _currentLevel; i < _maxLevel; ++i)
    {
        Sprite *cell = Sprite::create(_emptyCellFile);
        if(cell == nullptr)
        {
            throw std::invalid_argument(prefix_err_create_sprite + _filledCellFile);
        }
        cell->setPosition(Vec2(_step * i, 0));
        this->addChild(cell);
    }
    return true;
}

bool ProgressStackBar::updateCurrentLevel(int currentLevel)
{
    if(currentLevel < 0 || currentLevel > _maxLevel)
    {
        throw std::invalid_argument(prefix_err_bad_argument);
    }
    removeAllChildren();
    return init(currentLevel, _maxLevel);
}

bool ProgressStackBar::increment()
{
    if(_currentLevel >= _maxLevel)
    {
        throw std::invalid_argument(prefix_err_create_sprite);
    }
    removeAllChildren();
    return init(++_currentLevel, _maxLevel);
}

bool ProgressStackBar::decrement()
{
    if(_currentLevel <= 0)
    {
        throw std::invalid_argument(prefix_err_bad_argument);
    }
    removeAllChildren();
    return init(--_currentLevel, _maxLevel);
}

bool ProgressStackBar::updateStructure(int currentLevel, int maxLevel)
{
    if(currentLevel < 0 || currentLevel > _maxLevel)
    {
        throw std::invalid_argument(prefix_err_bad_argument);
    }
    removeAllChildren();
    return init(currentLevel, maxLevel);
}

int ProgressStackBar::getCurrentLevel()
{
    return _currentLevel;
}

int ProgressStackBar::getMaxLevel()
{
    return _maxLevel;
}

