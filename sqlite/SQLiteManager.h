#ifndef MYGAME_SQLITEMANAGER_H
#define MYGAME_SQLITEMANAGER_H

#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
USING_NS_CC;

class SQLiteManager {
private:
    SQLiteManager();
    static SQLiteManager* instance;
    sqlite3 *_db;
    bool open();
    void close();
public:
    virtual ~SQLiteManager();
    static SQLiteManager* getInstance();
    void insert(std::string key, std::string value);
    std::string select(std::string key);
};

#endif //MYGAME_SQLITEMANAGER_H
