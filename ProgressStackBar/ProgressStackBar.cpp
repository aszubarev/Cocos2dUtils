#include "ProgressStackBar.h"
#include "../ImageUtils/ImageUtils.h"

ProgressStackBar::ProgressStackBar(std::string &emptyCellFileName, std::string &filledCellFileName,
                                   int currentLevel, int maxLevel):
                    _emptyCellFileName(emptyCellFileName), _filledCellFileName(filledCellFileName),
                                _currentLevel(currentLevel), _maxLevel(maxLevel)
{
    prefix_err_create_sprite = "ERROR: Can not open ";
    try
    {
        _cellSize = ImageUtils::getSize(_emptyCellFileName);
    }
    catch(std::invalid_argument &a)
    {
        CCLOG("Error in PROGRESSSTACKBAR constructor");
    }

    _gap = _cellSize.width / 4;
    _step = _gap + _cellSize.width;

    if(!init(_currentLevel, maxLevel))
    {
        CCLOG("Error in PROGRESSSTACKBAR INIT");
    }
}

ProgressStackBar::~ProgressStackBar()
{}

ProgressStackBar *ProgressStackBar::create(std::string &emptyCellFileName, std::string &filledCellFileName,
            int currentLevel, int maxLevel)
{
    ProgressStackBar *progressStackBar = new (std::nothrow) ProgressStackBar(emptyCellFileName, filledCellFileName, currentLevel, maxLevel);
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
        Sprite *cell = Sprite::create(_filledCellFileName);
        if(cell == nullptr)
        {
            throw std::invalid_argument(prefix_err_create_sprite + _filledCellFileName);
        }
        cell->setPosition(Vec2(_step * i, 0));
        this->addChild(cell);
    }
    //empty balls
    for(int i = _currentLevel; i < _maxLevel; ++i)
    {
        Sprite *cell = Sprite::create(_emptyCellFileName);
        if(cell == nullptr)
        {
            throw std::invalid_argument(prefix_err_create_sprite + _filledCellFileName);
        }
        cell->setPosition(Vec2(_step * i, 0));
        this->addChild(cell);
    }
    return true;
}

bool ProgressStackBar::update_current_level(int currentLevel)
{
    removeAllChildren();

    return init(currentLevel, _maxLevel);
}

bool ProgressStackBar::increment()
{
    removeAllChildren();

    return init(++_currentLevel, _maxLevel);
}

bool ProgressStackBar::decrement()
{
    removeAllChildren();

    return init(--_currentLevel, _maxLevel);
}

bool ProgressStackBar::update_structure(int currentLevel, int maxLevel)
{
    removeAllChildren();

    return init(currentLevel, maxLevel);
}
