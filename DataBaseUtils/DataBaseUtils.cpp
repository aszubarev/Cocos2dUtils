#include "DataBaseUtils.h"
#include <iostream>

DataBaseUtils* DataBaseUtils::instance = nullptr;

DataBaseUtils::~DataBaseUtils()
{}

DataBaseUtils::DataBaseUtils(sqlite3 *&db)
{
    if(!this->open())
    {
        CCLOG("Error in OPENING DATABASE, %s", sqlite3_errmsg(_db));
    }
    else
    {
        db = _db;
        this->close();
    }
    return;
}
DataBaseUtils* DataBaseUtils::getInstance(sqlite3 *&db)
{
    if (instance == nullptr)
    {
        instance = new DataBaseUtils(db);
    }
    return instance;
}

bool DataBaseUtils::open()
{
    std::string path = FileUtils::getInstance()->getWritablePath()+"StrikeTowerDB";
    return sqlite3_open(path.c_str(), &_db)==SQLITE_OK;
}

void DataBaseUtils::close()
{
    sqlite3_close(_db);

}
