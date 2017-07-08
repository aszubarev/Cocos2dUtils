#include "SettingsUtils.h"
#include <iostream>
SettingsUtils::SettingsUtils()
{
    _dataBaseUtils = DataBaseUtils::getInstance(_db);//Указатель на базу + объект
    this->createTable();

//    this->insert(100500, 100501, 100502, 100503, 100504);

//    this->updateOneAtribute("volumeEffect", 18);
//    this->updateOneAtribute("volumeSound", 19);
//    this->updateOneAtribute("languages", 20);
//    this->updateOneAtribute("vibroEnable", 121);

//    this->updateAllAtributes(-20, -1, -2, -3);//NOT WORKING

    std::string atribute = "vibroEnable";
    std::cout << atribute << ": " << this->select(atribute);

    this->deleteLine();
}

SettingsUtils* SettingsUtils:: create()
{
    return new SettingsUtils();
}

void SettingsUtils::insert(int volumeEffect, int volumeSound, int languages, int vibroEnable)
{
    _dataBaseUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "INSERT INTO settingsTable(pk, volumeEffect, volumeSound, languages, vibroEnable) VALUES(1, ?, ?, ?, ?);";

    if (sqlite3_prepare_v2(_db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, volumeEffect);
        sqlite3_bind_int(stmt, 2, volumeSound);
        sqlite3_bind_int(stmt, 3, languages);
        sqlite3_bind_int(stmt, 4, vibroEnable);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in INSERT 1, %s", sqlite3_errmsg(_db));
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dataBaseUtils->close();
}

void SettingsUtils::updateOneAtribute(std::string &atribute, int newAmount)
{
    _dataBaseUtils->open();
    sqlite3_stmt* stmt;

    char* query = new char[100];
    sprintf(query, "UPDATE settingsTable set %s=%d where pk=1;", atribute.c_str(), newAmount);

    if (sqlite3_prepare_v2(_db, query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in UPDATE 1, %s", sqlite3_errmsg(_db));
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    delete[] query;
    _dataBaseUtils->close();
}

std::string SettingsUtils::select(std::string &atribute)
{
    _dataBaseUtils->open();
    sqlite3_stmt* stmt;
    std::string result;

    char* query = new char[100];
    sprintf(query, "SELECT %s from settingsTable where pk=1;", atribute.c_str());

    if (sqlite3_prepare_v2(_db, query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            const unsigned char* val = sqlite3_column_text(stmt, 0);
            result = std::string((char*)val);
        }
        else
        {
            CCLOG("Error in SELECT1, %s", sqlite3_errmsg(_db));
        }
    }
    else
    {

        CCLOG("Error in SELECT2, %s", sqlite3_errmsg(_db));
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    delete[] query;
    _dataBaseUtils->close();
    return result;
}

void SettingsUtils::createTable()
{
    if (_dataBaseUtils->open())
    {
        sqlite3_stmt* stmt;
        std::string sql = "CREATE TABLE IF NOT EXISTS settingsTable(pk INTEGER PRIMARY KEY,"
                "volumeEffect INTEGER, volumeSound INTEGER, languages INTEGER, vibroEnable INTEGER);";

        if (sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
        {
            if (sqlite3_step(stmt) != SQLITE_DONE)
            {
                CCLOG("Error in CREATE TABLE");
            }
        }

        sqlite3_reset(stmt);
        sqlite3_finalize(stmt);
        _dataBaseUtils->close();
    }
}

void SettingsUtils::deleteLine()
{
    _dataBaseUtils->open();
    sqlite3_stmt* stmt;
    std::string query = "delete from settingsTable where pk=1";

    if (sqlite3_prepare_v2(_db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in Delete, %s", sqlite3_errmsg(_db));
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    _dataBaseUtils->close();
}

void SettingsUtils::updateAllAtributes(int volumeEffect, int volumeSound, int languages, int vibroEnable)
{
    _dataBaseUtils->open();
    sqlite3_stmt* stmt;

    char* query = new char[400];
//    sprintf(query, "UPDATE settingsTable set volumeSound=-21 where pk=1;'\n'"
//     "UPDATE settingsTable set volumeSound=-22 where pk=2;'\n'"
//     "UPDATE settingsTable set languages=-23 where pk=3;'\n'"
//     "UPDATE settingsTable set vibroEnable=-24 where pk=4;\0");

//    std::string query = "UPDATE settingsTable set volumeEffect=17 where pk=1;";
    if (sqlite3_prepare_v2(_db, query, -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            CCLOG("Error in UPDATEALLATRIBUTES 1, %s",
                  sqlite3_errmsg(_db));
        }
    }

    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    delete[] query;
    _dataBaseUtils->close();
}