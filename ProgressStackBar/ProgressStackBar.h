#ifndef COCOS2DUTILS_PROGRESSSTACKBAR_H
#define COCOS2DUTILS_PROGRESSSTACKBAR_H
#include "cocos2d.h"
#include <stdexcept>
USING_NS_CC;

class ProgressStackBar : public Sprite
{
public:
    ProgressStackBar(std::string &emptyBall, std::string &yellowBall,
                     int currentLevel, int maxLevel);
    ~ProgressStackBar();

    static ProgressStackBar *create(std::string &emptyBall, std::string &yellowBall,
                    int currentLevel, int maxLevel);

    bool increment();
    bool decrement();
    bool update_structure(int newCurrentLevel, int newMaxLevel);
private:
    std::string _emptyCellFileName;
    std::string _filledCellFileName;
    int _currentLevel;
    int _maxLevel;

    Size _cellSize;
    float _gap;
    float _step;

    bool init(int currentLevel, int maxLevel);
    bool update_current_level(int currentLevel);

    std::string prefix_err_create_sprite;
};


#endif //COCOS2DUTILS_PROGRESSSTACKBAR_H
