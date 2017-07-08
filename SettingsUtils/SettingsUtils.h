#ifndef COCOS2DUTILS_SETTINGSUTILS_H
#define COCOS2DUTILS_SETTINGSUTILS_H
#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
#include "../DataBaseUtils/DataBaseUtils.h"

USING_NS_CC;

class SettingsUtils: Ref
{
public:
    static SettingsUtils* getInstance();
    void insert(int volumeEffect, int volumeSound, int languages, int vibroEnable);
    void updateOneAtribute(std::string &atribute, int newAmount);
    void updateAllAtributes(int volumeEffect, int volumeSound, int languages, int vibroEnable);
    std::string select(std::string &atribute);
    void deleteLine();

CC_CONSTRUCTOR_ACCESS:
    SettingsUtils();
    SettingsUtils(const SettingsUtils &obj);
    SettingsUtils &operator =(const SettingsUtils &obj);
    ~SettingsUtils();

private:
    DataBaseUtils *_dbUtils;
    std::string _table_name;

    static SettingsUtils *_instance;

    void createTable();
};


#endif //COCOS2DUTILS_SETTINGSUTILS_H
