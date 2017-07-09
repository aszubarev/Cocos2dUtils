#ifndef COCOS2DUTILS_SETTINGSUTILS_H
#define COCOS2DUTILS_SETTINGSUTILS_H
#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
#include "../DataBaseUtils/DataBaseUtils.h"

USING_NS_CC;
#define DEFAULT_VOLUMEEFFECT 50
#define DEFAULT_VOLUMESOUND 50
#define DEFAULT_LANGUAGES 1
#define DEFAULT_VIBROENABLE 1
#define MAX_VOLUMEEFFECT 100
#define MAX_VOLUMESOUND 100
#define MAX_LANGUAGES 1
#define MAX_VIBROENABLE 1

class SettingsUtils: Ref
{
public:
    static SettingsUtils* getInstance();

    void setAllAtributes(int volumeEffect, int volumeSound, int languages, int vibroEnable);
    void setVolumeEffect(int volumeEffect);
    void setVolumeSound(int volumeSound);
    void setLanguages(int languages);
    void setVibroEnable(int vibroEnable);

    std::string getVolumeEffect();
    std::string getVolumeSound();
    std::string getLanguages();
    std::string getVibroEnable();

    void deleteLine();

CC_CONSTRUCTOR_ACCESS:
    SettingsUtils();
    SettingsUtils(const SettingsUtils &obj) = delete;
    SettingsUtils &operator =(const SettingsUtils &obj) = delete;
    ~SettingsUtils();

private:
    DataBaseUtils *_dbUtils;
    std::string _table_name;
    std::string _pk;
    std::string _volumeEffect;
    std::string _volumeSound;
    std::string _languages;
    std::string _vibroEnable;

    void setOneAtribute(std::string &atribute, int newAmount);
    std::string getOneAtribute(std::string &atribute);
    void createTable();
    void insert(int volumeEffect, int volumeSound, int languages, int vibroEnable);

};


#endif //COCOS2DUTILS_SETTINGSUTILS_H
