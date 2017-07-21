#ifndef COCOS2DUTILS_SCOREUTILS_H
#define COCOS2DUTILS_SCOREUTILS_H
#include "cocos2d.h"
#include "../DataBaseUtils/DataBaseUtils.h"
USING_NS_CC;
#define DEFAULT_COINS 0
#define DEFAULT_DIAMONDS 0

class ScoreUtils : public Ref
{
public:
    static ScoreUtils* getInstance();

    bool setAllAtributes(int coins, int diamonds);
    bool setCoins(int coins);
    bool setDiamonds(int diamonds);

    int getCoins();
    int getDiamonds();

    CC_CONSTRUCTOR_ACCESS:
    ScoreUtils();
    ScoreUtils(const ScoreUtils &obj) = delete;
    ScoreUtils &operator =(const ScoreUtils &obj) = delete;
    ~ScoreUtils();

private:
    DataBaseUtils *_dbUtils;
    std::string _tableName;
    std::string _atrPk;
    std::string _atrCoins;
    std::string _atrDiamonds;

    bool setOneAtribute(std::string &atribute, int newAmount);
    std::string getOneAtribute(std::string &atribute);
    void createTable();
    void insert(int coins, int diamonds);
    void deleteLine(int pk);
};

#endif //COCOS2DUTILS_SCOREUTILS_H
