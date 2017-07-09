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

class SettingsUtils : public Ref
{
public:
    static SettingsUtils* getInstance();

    bool setAllAtributes(int volumeEffect, int volumeSound, int languages, int vibroEnable);
    bool setVolumeEffect(int volumeEffect);
    bool setVolumeSound(int volumeSound);
    bool setLanguages(int languages);
    bool setVibroEnable(int vibroEnable);

    int getVolumeEffect();
    int getVolumeSound();
    int getLanguages();
    int getVibroEnable();

    void deleteLine();

CC_CONSTRUCTOR_ACCESS:
    SettingsUtils();
    SettingsUtils(const SettingsUtils &obj) = delete;
    SettingsUtils &operator =(const SettingsUtils &obj) = delete;
    ~SettingsUtils();

private:
    DataBaseUtils *_dbUtils;
    std::string _atrTableName;
    std::string _atrPk;
    std::string _atrVolumeEffect;
    std::string _atrVolumeSound;
    std::string _atrLanguages;
    std::string _atrVibroEnable;

    bool setOneAtribute(std::string &atribute, int newAmount);
    std::string getOneAtribute(std::string &atribute);
    void createTable();
    void insert(int volumeEffect, int volumeSound, int languages, int vibroEnable);

};


#endif //COCOS2DUTILS_SETTINGSUTILS_H
