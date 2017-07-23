#include "SettingsUtils.h"
#include <iostream>


SettingsUtils* SettingsUtils::getInstance()
{
    SettingsUtils *instance = new (std::nothrow) SettingsUtils();
    instance->autorelease();

    return instance;
}

SettingsUtils::SettingsUtils():
        _tableName("AppSettings"), _atrPk("pk"), _atrVolumeEffect("volumeEffect"),
        _atrVolumeSound("volumeSound"), _atrLanguages("languages"), _atrVibroEnable("vibroEnable")
{
    _dbUtils = DataBaseUtils::getInstance();
    _dbUtils->retain();
    createTable();
}

SettingsUtils::~SettingsUtils()
{
    CC_SAFE_RELEASE_NULL(_dbUtils);
}

void SettingsUtils::createTable()
{
    if (_dbUtils->open())
    {
        sqlite3_stmt* stmt;
        std::string query = "CREATE TABLE IF NOT EXISTS " + _tableName + "(" +
                _atrPk + " INTEGER PRIMARY KEY, " + _atrVolumeEffect + " INTEGER, " +
                _atrVolumeSound + " INTEGER, " + _atrLanguages + " INTEGER, " +
                _atrVibroEnable + " INTEGER);";

        if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
        {
            if (sqlite3_step(stmt) != SQLITE_DONE)
            {
                CCLOG("Error in CREATE TABLE");
            }

            insert(DEFAULT_VOLUMEEFFECT, DEFAULT_VOLUMESOUND, DEFAULT_LANGUAGES, DEFAULT_VIBROENABLE);

        }

        sqlite3_reset(stmt);
        sqlite3_finalize(stmt);
        _dbUtils->close();
    }
}

void SettingsUtils::insert(int volumeEffect, int volumeSound, int languages, int vibroEnable)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "INSERT INTO " + _tableName + " VALUES(1, ?, ?, ?, ?);";
    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, volumeEffect);
        sqlite3_bind_int(stmt, 2, volumeSound);
        sqlite3_bind_int(stmt, 3, languages);
        sqlite3_bind_int(stmt, 4, vibroEnable);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in INSERT 1, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }
    else
    {
        CCLOG("Error in INSERT 2, %s", sqlite3_errmsg(_dbUtils->db()));
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
}

void SettingsUtils::deleteLine(int pk)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "delete from " + _tableName +  " where " + _atrPk + "=" + cocos2d::StringUtils::toString(pk);

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in Delete, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
}

bool SettingsUtils::setOneAtribute(std::string &atribute, int newAmount)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "UPDATE " + _tableName + " set " + atribute + "=? where " + _atrPk + "=1;";

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, newAmount);
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in UPDATE 1, %s", sqlite3_errmsg(_dbUtils->db()));
            return false;
        }
    }
    else
    {
        CCLOG("Error in UPDATE 2, %s", sqlite3_errmsg(_dbUtils->db()));
        return false;
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
    return true;
}

bool SettingsUtils::setVolumeEffect(int volumeEffect)
{
    if(volumeEffect < 0)
    {
        return setOneAtribute(_atrVolumeEffect, 0);
    }
    else if(volumeEffect > 100)
    {
        return setOneAtribute(_atrVolumeEffect, MAX_VOLUMEEFFECT);
    }
    else
    {
        return setOneAtribute(_atrVolumeEffect, volumeEffect);
    }
}

bool SettingsUtils::setVolumeSound(int volumeSound)
{
    if(volumeSound < 0)
    {
        return setOneAtribute(_atrVolumeSound, 0);
    }
    else if(volumeSound > 100)
    {
        return setOneAtribute(_atrVolumeSound, MAX_VOLUMESOUND);
    }
    else
    {
        return setOneAtribute(_atrVolumeSound, volumeSound);
    }
}

bool SettingsUtils::setLanguages(int languages)
{
    if(languages < 0)
    {
        return setOneAtribute(_atrLanguages, 0);
    }
    else if(languages > 100)
    {
        return setOneAtribute(_atrLanguages, MAX_LANGUAGES);
    }
    else
    {
        return setOneAtribute(_atrLanguages, languages);
    }
}

bool SettingsUtils::setVibroEnable(int vibroEnable)
{
    if(vibroEnable < 0)
    {
        return setOneAtribute(_atrVibroEnable, 0);
    }
    else if(vibroEnable > 100)
    {
        return setOneAtribute(_atrVibroEnable, MAX_VIBROENABLE);
    }
    else
    {
        return setOneAtribute(_atrVibroEnable, vibroEnable);
    }
}

bool SettingsUtils::setAllAtributes(int volumeEffect, int volumeSound, int languages, int vibroEnable)
{
    bool flag = true;
    bool result = true;

    flag = setVolumeEffect(volumeEffect);
    if(flag == false)
    {
        result = false;
    }
    flag = setVolumeSound(volumeSound);
    if(flag == false)
    {
        result = false;
    }
    flag = setLanguages(languages);
    if(flag == false)
    {
        result = false;
    }
    flag = setVibroEnable(vibroEnable);
    if(flag == false)
    {
        result = false;
    }
    return result;
}

std::string SettingsUtils::getOneAtribute(std::string &atribute)
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

int SettingsUtils::getVolumeEffect()
{
    return Value(getOneAtribute(_atrVolumeEffect)).asInt();
}
int SettingsUtils::getVolumeSound()
{
    return Value(getOneAtribute(_atrVolumeSound)).asInt();
}
int SettingsUtils::getLanguages()
{
    return Value(getOneAtribute(_atrLanguages)).asInt();
}

int SettingsUtils::getVibroEnable()
{
    return Value(getOneAtribute(_atrVibroEnable)).asInt();
}
