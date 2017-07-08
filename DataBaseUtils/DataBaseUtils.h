#ifndef COCOS2DUTILS_DATABASEUTILS_H
#define COCOS2DUTILS_DATABASEUTILS_H

#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
USING_NS_CC;

class DataBaseUtils {
public:
    static DataBaseUtils* getInstance(sqlite3 *&db);
    DataBaseUtils(sqlite3 *&db);

    bool open();
    void close();
private:
    ~DataBaseUtils();
    static DataBaseUtils* instance;
    sqlite3 *_db;
};

#endif //COCOS2DUTILS_DATABASEUTILS_H
