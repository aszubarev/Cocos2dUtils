#include "DataBaseUtils.h"
#include <iostream>
DataBaseUtils* DataBaseUtils::instance = nullptr;

DataBaseUtils::~DataBaseUtils()
{}

DataBaseUtils::DataBaseUtils()
{
    if(this->open()) {

    }
    else{
        CCLOG("Error in OPENING DATABASE, %s", sqlite3_errmsg(_db));
    }
    return;
}

void DataBaseUtils::create_tables()
{
    if (this->open()) {
        sqlite3_stmt* stmt;
        // create table
        std::string sql = "CREATE TABLE IF NOT EXISTS data(key TEXT PRIMARY KEY,value TEXT);";
        if (sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
            if (sqlite3_step(stmt)!=SQLITE_DONE) {
                CCLOG("Error in CREATE TABLE");
            }
        }
        sqlite3_reset(stmt);
        sqlite3_finalize(stmt);
        this->close();
    }
}

DataBaseUtils* DataBaseUtils::getInstance() {
    if (instance==nullptr) {
        instance = new DataBaseUtils();
    }
    return instance;
}

//Add the method that opens and closes the database
bool DataBaseUtils::open()
{
    std::string path = FileUtils::getInstance()->getWritablePath()+"StrikeTowerDB";
    std::cout << path;
    return sqlite3_open(path.c_str(), &_db)==SQLITE_OK;
}

void DataBaseUtils::close()
{
    sqlite3_close(_db);
}

//Add themethod that inserts data to the database
void DataBaseUtils::insert(std::string key, std::string value)
{
    this->open();
    // insert data
    sqlite3_stmt* stmt;
    std::string sql = "INSERT INTO data (key, value)VALUES(?, ?)";
    if (sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt,
                           nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, key.c_str(), -1,
                          SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, value.c_str(), -1,
                          SQLITE_TRANSIENT);        if (sqlite3_step(stmt)!=SQLITE_DONE) {
            CCLOG("Error in INSERT 1, %s",
                  sqlite3_errmsg(_db));
        }
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    this->close();
}

//Add the method that selects data from the database:
std::string DataBaseUtils::select(std::string key)
{
    this->open();
    // select data
    std::string value;
    sqlite3_stmt* stmt;
    std::string sql = "SELECT VALUE from data where key=?";
    if (sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt,
                           NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, key.c_str(), -1,
                          SQLITE_TRANSIENT);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* val =
                    sqlite3_column_text(stmt, 0);
            value = std::string((char*)val);
            CCLOG("key=%s, value=%s", key.c_str(), val);
        } else {
            CCLOG("Error in SELECT, %s",
                  sqlite3_errmsg(_db));
        }
    } else {
        CCLOG("Error in SELECT, %s", sqlite3_errmsg(_db));
    }
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
    this->close();
    return value;
}

//---------Second variant of insert----------------
//    char *err_msg;
//    int rc = sqlite3_exec(_db, query.c_str(), 0, 0, &err_msg);
//    if (rc != SQLITE_OK)
//    {
//        fprintf(stderr, "SQL error: %s\n", err_msg);
//        sqlite3_free(err_msg);
//    }
