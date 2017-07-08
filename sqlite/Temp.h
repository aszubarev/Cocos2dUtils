#ifndef COCOS2DUTILS_DATABASEUTILS_H
#define COCOS2DUTILS_DATABASEUTILS_H

#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
USING_NS_CC;

class DataBaseUtils {
public:
    static DataBaseUtils* getInstance();
    void insert(std::string key, std::string value);
    std::string select(std::string key);
private:
    static DataBaseUtils* instance;
    sqlite3 *_db;
    bool open();
    void close();
    void create_tables();
};

#endif //COCOS2DUTILS_DATABASEUTILS_H
