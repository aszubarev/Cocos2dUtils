#include "SettingsUtils.h"
#include <iostream>


SettingsUtils* SettingsUtils::getInstance()
{
    SettingsUtils *instance = new (std::nothrow) SettingsUtils();
    instance->autorelease();

    return instance;
}

SettingsUtils::SettingsUtils():
        _table_name("AppSettings"), _pk("pk"), _volumeEffect("volumeEffect"),
        _volumeSound("volumeSound"), _languages("languages"), _vibroEnable("vibroEnable")
{
    _dbUtils = DataBaseUtils::getInstance();
//    _dbUtils->retain();
    createTable();
}

SettingsUtils::~SettingsUtils()
{
//    CC_SAFE_RELEASE_NULL(_dbUtils);
}

void SettingsUtils::createTable()
{
    if (_dbUtils->open())
    {
        sqlite3_stmt* stmt;
        std::string sql = "CREATE TABLE IF NOT EXISTS " + _table_name + "(" +
                          _pk + " INTEGER PRIMARY KEY, " + _volumeEffect + " INTEGER, " +
                          _volumeSound + " INTEGER, " + _languages + " INTEGER, " +
                          _vibroEnable + " INTEGER);";

        if (sqlite3_prepare_v2(_dbUtils->db(), sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
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
    std::string query = "INSERT INTO " + _table_name + " VALUES(1, ?, ?, ?, ?);";
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

void SettingsUtils::deleteLine()
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "delete from " + _table_name +  " where " + _pk + "=1";

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

void SettingsUtils::setOneAtribute(std::string &atribute, int newAmount)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "UPDATE " + _table_name + " set " + atribute + "=? where " + _pk + "=1;";

    if (sqlite3_prepare_v2(_dbUtils->db(), query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, newAmount);
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in UPDATE 1, %s", sqlite3_errmsg(_dbUtils->db()));
        }
    }
    else
    {
        CCLOG("Error in UPDATE 2, %s", sqlite3_errmsg(_dbUtils->db()));
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dbUtils->close();
}

void SettingsUtils::setVolumeEffect(int volumeEffect)
{
    if(volumeEffect < 0)
    {
        setOneAtribute(_volumeEffect, 0);
    }
    else if(volumeEffect > 100)
    {
        setOneAtribute(_volumeEffect, MAX_VOLUMEEFFECT);
    }
    else
    {
        setOneAtribute(_volumeEffect, volumeEffect);
    }
}

void SettingsUtils::setVolumeSound(int volumeSound)
{
    if(volumeSound < 0)
    {
        setOneAtribute(_volumeSound, 0);
    }
    else if(volumeSound > 100)
    {
        setOneAtribute(_volumeSound, MAX_VOLUMESOUND);
    }
    else
    {
        setOneAtribute(_volumeSound, volumeSound);
    }
}

void SettingsUtils::setLanguages(int languages)
{
    if(languages < 0)
    {
        setOneAtribute(_languages, 0);
    }
    else if(languages > 100)
    {
        setOneAtribute(_languages, MAX_LANGUAGES);
    }
    else
    {
        setOneAtribute(_languages, languages);
    }
}

void SettingsUtils::setVibroEnable(int vibroEnable)
{
    if(vibroEnable < 0)
    {
        setOneAtribute(_vibroEnable, 0);
    }
    else if(vibroEnable > 100)
    {
        setOneAtribute(_vibroEnable, MAX_VIBROENABLE);
    }
    else
    {
        setOneAtribute(_vibroEnable, vibroEnable);
    }
}

void SettingsUtils::setAllAtributes(int volumeEffect, int volumeSound, int languages, int vibroEnable)
{
    setVolumeEffect(volumeEffect);
    setVolumeSound(volumeSound);
    setLanguages(languages);
    setVibroEnable(vibroEnable);
}

std::string SettingsUtils::getOneAtribute(std::string &atribute)
{
    _dbUtils->open();
    sqlite3_stmt* stmt;
    std::string result;
    std::string query = "SELECT " + atribute + " from " + _table_name + " where " + _pk + "=1;";

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

std::string SettingsUtils::getVolumeEffect()
{
    return getOneAtribute(_volumeEffect);
}
std::string SettingsUtils::getVolumeSound()
{
    return getOneAtribute(_volumeSound);
}
std::string SettingsUtils::getLanguages()
{
    return getOneAtribute(_languages);
}

std::string SettingsUtils::getVibroEnable()
{
    return getOneAtribute(_vibroEnable);
}
