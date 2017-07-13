#include "DataBaseUtils.h"



DataBaseUtils *DataBaseUtils::getInstance()
{
    DataBaseUtils* instance = new (std::nothrow) DataBaseUtils();
    instance->autorelease();

    return instance;
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
