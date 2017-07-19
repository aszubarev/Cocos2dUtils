#ifndef COCOS2DUTILS_SKILLSUTILS_H
#define COCOS2DUTILS_SKILLSUTILS_H
#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
#include "../DataBaseUtils/DataBaseUtils.h"

USING_NS_CC;

class SkillsUtils : public Ref
{
public:
    static SkillsUtils* getInstance();

    bool setAllAtributes(int playerId, int flyingSkill, int magneticSkill, int armorSkill, int damageSkill, int luckMoneySkill);
    bool setFlyingSkill(int playerId, int flyingSkill);
    bool setMagneticSkill(int playerId, int magneticSkill);
    bool setArmorSkill(int playerId, int armorSkill);
    bool setDamageSkill(int playerId, int damageSkill);
    bool setLuckMoneySkill(int playerId, int luckMoneySkill);

    int getFlyingSkill(int playerId);
    int getMagneticSkill(int playerId);
    int getArmorSkill(int playerId);
    int getDamageSkill(int playerId);
    int getLuckMoneySkill(int playerId);

    void deleteLine(int playerId);

    CC_CONSTRUCTOR_ACCESS:
    SkillsUtils();
    SkillsUtils(const SkillsUtils &obj) = delete;
    SkillsUtils &operator =(const SkillsUtils &obj) = delete;
    ~SkillsUtils();
    void insert(int playerId, int flyingSkill, int magneticSkill, int armorSkill, int damageSkill, int luckMoneySkill);

private:
    DataBaseUtils *_dbUtils;
    std::string _atrTableName;
    std::string _atrPlayerId;
    std::string _atrFlyingSkill;
    std::string _atrMagneticSkill;
    std::string _atrArmorSkill;
    std::string _atrDamageSkill;

    std::string _atrLuckMoneySkill;

    int _numberOfPlayers;
    bool setOneAtribute(int playerId, std::string &atribute, int newAmount);
    std::string getOneAtribute(int playerId, std::string &atribute);
    void createTable();

};


#endif //COCOS2DUTILS_SKILLSUTILS_H
