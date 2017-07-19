#include "SkillsUtils.h"
#include <iostream>

SkillsUtils* SkillsUtils::getInstance()
{
    SkillsUtils *instance = new (std::nothrow) SkillsUtils();
    instance->autorelease();

    return instance;
}

SkillsUtils::SkillsUtils():
        _atrTableName("AppSkills"), _atrPlayerId("playerId"), _atrFlyingSkill("flyingSkill"),
        _atrMagneticSkill("magneticSkill"), _atrArmorSkill("armorSkill"), _atrDamageSkill("damageSkill"),
        _atrLuckMoneySkill("luckMoneySkill")
{

    _numberOfPlayers = 7;

    _dbUtils = DataBaseUtils::getInstance();
    _dbUtils->retain();
    createTable();
}

SkillsUtils::~SkillsUtils()
{
    CC_SAFE_RELEASE_NULL(_dbUtils);
}

void SkillsUtils::createTable()
{
    if (_dbUtils->open())
    {
        sqlite3_stmt* stmt;
        std::string sql = "CREATE TABLE IF NOT EXISTS " + _atrTableName + "(" +
                _atrPlayerId + " INTEGER PRIMARY KEY, " + _atrFlyingSkill + " INTEGER, " +
                _atrMagneticSkill + " INTEGER, " + _atrArmorSkill + " INTEGER, " +
                _atrDamageSkill + " INTEGER, " + _atrLuckMoneySkill + " INTEGER);";

        if (sqlite3_prepare_v2(_dbUtils->db(), sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
        {
            if (sqlite3_step(stmt) != SQLITE_DONE)
            {
                CCLOG("Error in CREATE TABLE skillsUtils");
            }
            for(int i = 0; i < _numberOfPlayers; ++i)
            {
                insert(i, DEFAULT_FLYINGSKILL, DEFAULT_MAGNETICSKILL, DEFAULT_ARMORSKILL,
                       DEFAULT_DAMAGESKILL, DEFAULT_LUCKMONEYSKILL);
            }

        }

        sqlite3_reset(stmt);
        sqlite3_finalize(stmt);
        _dbUtils->close();
    }
}

void SkillsUtils::insert(int playerId, int flyingSkill, int magneticSkill, int armorSkill, int damageSkill, int luckMoneySkill)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string playerIdStr = StringUtils::toString(playerId);
    std::string query = "INSERT INTO " + _atrTableName + " VALUES(" +
            playerIdStr + ", ?, ?, ?, ?, ?);";
    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, flyingSkill);
        sqlite3_bind_int(stmt, 2, magneticSkill);
        sqlite3_bind_int(stmt, 3, armorSkill);
        sqlite3_bind_int(stmt, 4, damageSkill);
        sqlite3_bind_int(stmt, 5, luckMoneySkill);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in INSERT skillsUtils 1, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }
    else
    {
        CCLOG("Error in INSERT skillsUtils 2, %s", sqlite3_errmsg(_dbUtils->db()));
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
}

void SkillsUtils::deleteLine(int playerId)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string playerIdStr = StringUtils::toString(playerId);
    std::string query = "delete from " + _atrTableName +  " where " + _atrPlayerId + "=" + playerIdStr;

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in Delete skillsUtils, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
}

bool SkillsUtils::setOneAtribute(int playerId, std::string &atribute, int newAmount)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string playerIdStr = StringUtils::toString(playerId);
    std::string query = "UPDATE " + _atrTableName + " set " + atribute + "=? where " + _atrPlayerId +
                         "=" + playerIdStr + ";";

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, newAmount);
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in UPDATE skillsUtils 1, %s", sqlite3_errmsg(_dbUtils->db()));
            return false;
        }
    }
    else
    {
        CCLOG("Error in UPDATE skillsUtils 2, %s", sqlite3_errmsg(_dbUtils->db()));
        return false;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
    return true;
}

bool SkillsUtils::setFlyingSkill(int playerId, int flyingSkill)
{
    if(flyingSkill < 0)
    {
        return false;
    }
    else if(flyingSkill > 10)
    {
        return false;
    }
    else
    {
        return setOneAtribute(playerId, _atrFlyingSkill, flyingSkill);
    }
}

bool SkillsUtils::setMagneticSkill(int playerId, int magneticSkill)
{
    if(magneticSkill < 0)
    {
        return false;
    }
    else if(magneticSkill > 10)
    {
        return false;
    }
    else
    {
        return setOneAtribute(playerId, _atrMagneticSkill, magneticSkill);
    }
}

bool SkillsUtils::setArmorSkill(int playerId, int armorSkill)
{
    if(armorSkill < 0)
    {
        return false;
    }
    else if(armorSkill > 10)
    {
        return false;
    }
    else
    {
        return setOneAtribute(playerId, _atrArmorSkill, armorSkill);
    }
}

bool SkillsUtils::setDamageSkill(int playerId, int damageSkill)
{
    if(damageSkill < 0)
    {
        return false;
    }
    else if(damageSkill > 10)
    {
        return false;
    }
    else
    {
        return setOneAtribute(playerId, _atrDamageSkill, damageSkill);
    }
}

bool SkillsUtils::setLuckMoneySkill(int playerId, int luckMoneySkill)
{
    if(luckMoneySkill < 0)
    {
        return false;
    }
    else if(luckMoneySkill > 10)
    {
        return false;
    }
    else
    {
        return setOneAtribute(playerId, _atrLuckMoneySkill, luckMoneySkill);
    }
}

bool SkillsUtils::setAllAtributes(int playerId, int flyingSkill, int magneticSkill, int armorSkill, int damageSkill, int luckMoneySkill)
{
    bool flag = true;
    bool result = true;

    flag = setFlyingSkill(playerId, flyingSkill);
    if(flag == false)
    {
        result = false;
    }
    flag = setMagneticSkill(playerId, magneticSkill);
    if(flag == false)
    {
        result = false;
    }
    flag = setArmorSkill(playerId, armorSkill);
    if(flag == false)
    {
        result = false;
    }
    flag = setDamageSkill(playerId, damageSkill);
    if(flag == false)
    {
        result = false;
    }
    flag = setLuckMoneySkill(playerId, luckMoneySkill);
    if(flag == false)
    {
        result = false;
    }
    return result;
}

std::string SkillsUtils::getOneAtribute(int playerId, std::string &atribute)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string result;
    std::string playerIdStr = StringUtils::toString(playerId);
    std::string query = "SELECT " + atribute + " from " + _atrTableName + " where " + _atrPlayerId +
            "=" + playerIdStr + ";";

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            const unsigned char* val = sqlite3_column_text(stmt, 0);
            result = std::string((char*)val);
        }
        else
        {
            CCLOG("Error in SELECT1, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }
    else
    {

        CCLOG("Error in SELECT2, %s", sqlite3_errmsg(_dbUtils->db()));
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
    return result;
}

int SkillsUtils::getFlyingSkill(int playerId)
{
    return stoi(getOneAtribute(playerId, _atrFlyingSkill));
}

int SkillsUtils::getMagneticSkill(int playerId)
{
    return stoi(getOneAtribute(playerId, _atrMagneticSkill));
}

int SkillsUtils::getArmorSkill(int playerId)
{
    return stoi(getOneAtribute(playerId, _atrArmorSkill));
}

int SkillsUtils::getDamageSkill(int playerId)
{
    return stoi(getOneAtribute(playerId, _atrDamageSkill));
}

int SkillsUtils::getLuckMoneySkill(int playerId)
{
    return stoi(getOneAtribute(playerId, _atrLuckMoneySkill));
}
