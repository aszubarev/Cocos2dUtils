#ifndef COCOS2DUTILS_SETTINGSUTILS_H
#define COCOS2DUTILS_SETTINGSUTILS_H
#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
#include "../DataBaseUtils/DataBaseUtils.h"

class SettingsUtils {
public:
    SettingsUtils();
    static SettingsUtils* create();
    void insert(int volumeEffect, int volumeSound, int languages, int vibroEnable);
    void updateOneAtribute(std::string &atribute, int newAmount);
    void updateAllAtributes(int volumeEffect, int volumeSound, int languages, int vibroEnable);
    std::string select(std::string &atribute);
    void deleteLine();
private:
    void createTable();
    DataBaseUtils *_dataBaseUtils;
    sqlite3 *_db;
};


#endif //COCOS2DUTILS_SETTINGSUTILS_H
