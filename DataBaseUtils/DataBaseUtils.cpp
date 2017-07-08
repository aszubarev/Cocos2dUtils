#include "DataBaseUtils.h"
#include <iostream>

DataBaseUtils* DataBaseUtils::_instance = nullptr;

DataBaseUtils *DataBaseUtils::getInstance()
{
    if (_instance != nullptr) { return _instance; }
    _instance = new (std::nothrow) DataBaseUtils();
    _instance->autorelease();

    return _instance;
}

DataBaseUtils::DataBaseUtils():
        _db_name("AppDataBase"),
        _db_path(FileUtils::getInstance()->getWritablePath() + _db_name),
        _status_code(SQLITE_OK)
{
    if (!this->open())
    {
        CCLOG("Error in OPENING DATABASE, %s", sqlite3_errmsg(_db));
    }
    else { this->close(); }
    return;
}

DataBaseUtils::~DataBaseUtils()
{}

DataBaseUtils::DataBaseUtils(const DataBaseUtils &obj)
{
    _db_name = obj._db_name;
    _db_path = obj._db_path;
    _status_code = obj._status_code;
    _db = obj._db;
}

DataBaseUtils &DataBaseUtils::operator=(const DataBaseUtils &obj)
{
    _db_name = obj._db_name;
    _db_path = obj._db_path;
    _status_code = obj._status_code;
    _db = obj._db;

    return *this;
}

bool DataBaseUtils::open()
{
    _status_code = sqlite3_open(_db_path.c_str(), &_db);
    if (_status_code != SQLITE_OK) { return false; }
    return true;
}

bool DataBaseUtils::close()
{
    _status_code = sqlite3_close(_db);
    if (_status_code != SQLITE_OK) { return false; }
    return true;
}
