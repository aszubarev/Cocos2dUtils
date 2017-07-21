#include "ProgressStackBar.h"
#include "../ImageUtils/ImageUtils.h"

ProgressStackBar::ProgressStackBar(const std::string &emptyCellFile, const std::string &filledCellFile,
                                   int currentLevel, int maxLevel):
                    _emptyCellFile(emptyCellFile), _filledCellFile(filledCellFile),
                    _currentLevel(currentLevel), _maxLevel(maxLevel)
{
    prefix_err_create_sprite = "Can't create from ";

    _cellSize = ImageUtils::getSize(_emptyCellFile);

    _gap = _cellSize.width / 4;
    _step = _gap + _cellSize.width;
    init(_currentLevel, _maxLevel);
}

ProgressStackBar::~ProgressStackBar()
{}

ProgressStackBar *ProgressStackBar::create(const std::string &emptyCellFile, const std::string &filledCellFile,
                                           int currentLevel, int maxLevel)
{
    ProgressStackBar *progressStackBar = new (std::nothrow) ProgressStackBar(emptyCellFile, filledCellFile,
                                                                             currentLevel, maxLevel);
    progressStackBar->autorelease();
    return progressStackBar;
}

void ProgressStackBar::init(int currentLevel, int maxLevel)
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
}

void ProgressStackBar::updateCurrentLevel(int currentLevel)
{
    if(currentLevel < 0 || currentLevel > _maxLevel)
    {
        std::string err = StringUtils::format("Can't call updateCurrentLevel(int param):\n"
                                                      "param = %d\nmaxParam = %d\n", currentLevel, _maxLevel);
        throw std::invalid_argument(err);
    }
    removeAllChildren();
    init(currentLevel, _maxLevel);
}

bool ProgressStackBar::increment()
{
    if(_currentLevel >= _maxLevel) { return false; }
    removeAllChildren();
    init(++_currentLevel, _maxLevel);
    return true;
}

bool ProgressStackBar::decrement()
{
    if(_currentLevel <= 0) { return false; }
    removeAllChildren();
    init(--_currentLevel, _maxLevel);
    return true;
}

bool ProgressStackBar::updateStructure(int currentLevel, int maxLevel)
{
    removeAllChildren();
    init(currentLevel, maxLevel);
}

int ProgressStackBar::getCurrentLevel()
{
    return _currentLevel;
}

int ProgressStackBar::getMaxLevel()
{
    return _maxLevel;
}

