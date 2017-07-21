#ifndef COCOS2DUTILS_PROGRESSSTACKBAR_H
#define COCOS2DUTILS_PROGRESSSTACKBAR_H
#include "cocos2d.h"
#include <stdexcept>
USING_NS_CC;

class ProgressStackBar : public Sprite
{
public:
    ProgressStackBar(const std::string &emptyCellFile, const std::string &filledCellFile,
                     int currentLevel, int maxLevel);
    ~ProgressStackBar();

    static ProgressStackBar *create(const std::string &emptyCellFile, const std::string &filledCellFile,
                                    int currentLevel, int maxLevel);

    bool increment();
    bool decrement();
    bool updateStructure(int currentLevel, int maxLevel);
    void updateCurrentLevel(int currentLevel);

    int getCurrentLevel();
    int getMaxLevel();
private:
    std::string _emptyCellFile;
    std::string _filledCellFile;
    int _currentLevel;
    int _maxLevel;

    Size _cellSize;
    float _gap;
    float _step;

    void init(int currentLevel, int maxLevel);

    std::string prefix_err_create_sprite;
    std::string prefix_err_bad_argument;
};


#endif //COCOS2DUTILS_PROGRESSSTACKBAR_H
