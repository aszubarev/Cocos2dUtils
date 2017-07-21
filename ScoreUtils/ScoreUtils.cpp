#include "ScoreUtils.h"

ScoreUtils* ScoreUtils::getInstance()
{
    ScoreUtils *instance = new (std::nothrow) ScoreUtils();
    instance->autorelease();

    return instance;
}

ScoreUtils::ScoreUtils():
        _tableName("AppCoins"), _atrPk("pk"), _atrCoins("coins"), _atrDiamonds("diamonds")
{
    _dbUtils = DataBaseUtils::getInstance();
    _dbUtils->retain();
    createTable();
}

ScoreUtils::~ScoreUtils()
{
    CC_SAFE_RELEASE_NULL(_dbUtils);
}

void ScoreUtils::createTable()
{
    if (_dbUtils->open())
    {
        sqlite3_stmt* stmt;
        std::string query = "CREATE TABLE IF NOT EXISTS " + _tableName + "(" +
                            _atrPk + " INTEGER PRIMARY KEY, " + _atrCoins + " INTEGER, " +
                            _atrDiamonds + " INTEGER);";

        if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
        {
            if (sqlite3_step(stmt) != SQLITE_DONE)
            {
                CCLOG("Error in SCOREuTILS CREATE TABLE");
            }

            insert(DEFAULT_COINS, DEFAULT_DIAMONDS);

        }

        sqlite3_reset(stmt);
        sqlite3_finalize(stmt);
        _dbUtils->close();
    }
}

void ScoreUtils::insert(int coins, int diamonds)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "INSERT INTO " + _tableName + " VALUES(1, ?, ?);";
    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, coins);
        sqlite3_bind_int(stmt, 2, diamonds);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in SCOREuTILS INSERT 1, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }
    else
    {
        CCLOG("Error in SCOREuTILS INSERT 2, %s", sqlite3_errmsg(_dbUtils->db()));
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
}

void ScoreUtils::deleteLine(int pk)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "delete from " + _tableName +  " where " + _atrPk + "=" + cocos2d::StringUtils::toString(pk);

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in SCOREuTILS Delete, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
}

bool ScoreUtils::setOneAtribute(std::string &atribute, int newAmount)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "UPDATE " + _tableName + " set " + atribute + "=? where " + _atrPk + "=1;";

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, newAmount);
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in SCOREuTILS UPDATE 1, %s", sqlite3_errmsg(_dbUtils->db()));
            return false;
        }
    }
    else
    {
        CCLOG("Error in SCOREuTILS UPDATE 2, %s", sqlite3_errmsg(_dbUtils->db()));
        return false;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
    return true;
}

bool ScoreUtils::setCoins(int coins)
{
    if(coins < 0)
    {
        return false;
    }
    else
    {
        return setOneAtribute(_atrCoins, coins);
    }
}

bool ScoreUtils::setDiamonds(int diamonds)
{
    if(diamonds < 0)
    {
        return false;
    }
    else
    {
        return setOneAtribute(_atrDiamonds, diamonds);
    }
}

bool ScoreUtils::setAllAtributes(int coins, int diamonds)
{
    bool flag = true;
    bool result = true;

    flag = setCoins(coins);
    if(flag == false)
    {
        result = false;
    }
    flag = setDiamonds(diamonds);
    if(flag == false)
    {
        result = false;
    }
    return result;
}

std::string ScoreUtils::getOneAtribute(std::string &atribute)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string result;
    std::string query = "SELECT " + atribute + " from " + _tableName + " where " + _atrPk + "=1;";

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

int ScoreUtils::getCoins()
{
    return stoi(getOneAtribute(_atrCoins));
}

int ScoreUtils::getDiamonds()
{
    return stoi(getOneAtribute(_atrDiamonds));
}
