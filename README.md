# Cocos2dUtils


[![Travis](https://img.shields.io/badge/cocos2d-v3.14.1-blue.svg?style=flat&maxAge=2592000)]()
[![Cocos2d](https://img.shields.io/travis/rust-lang/rust.svg?style=flat)]()
[![Issue Count](https://codeclimate.com/github/ZubAnt/Cocos2dUtils/badges/issue_count.svg)](https://codeclimate.com/github/ZubAnt/Cocos2dUtils)

### install:

Add submodule to your project in root folder:

    git submodule add -b master https://github.com/ZubAnt/Cocos2dUtils.git
    
Update submodule by command:

    git submodule update --init --force --remote --recursive

Add to your CmakeList.txt variable "COCOS2d_UTILS_ROOT":
    
    set(COCOS2d_UTILS_ROOT ${CMAKE_SOURCE_DIR}/Cocos2dUtils)
    
Copy next headers paths into set(GAME_HEADERS path1 path2 ...):
    
    ${COCOS2d_UTILS_ROOT}/ImageUtils/ImageUtils.h
    ${COCOS2d_UTILS_ROOT}/PhysicsBodyUtils/PhysicsBodyUtils.h
    ${COCOS2d_UTILS_ROOT}/SpriteUtils/SpriteUtils.h
    ${COCOS2d_UTILS_ROOT}/AnimateUtils/AnimateUtils.h
    
Copy next sources paths into set(GAME_SRC path1 path2 ...):

    ${COCOS2d_UTILS_ROOT}/ImageUtils/ImageUtils.cpp
    ${COCOS2d_UTILS_ROOT}/PhysicsBodyUtils/PhysicsBodyUtils.cpp
    ${COCOS2d_UTILS_ROOT}/SpriteUtils/SpriteUtils.cpp
    ${COCOS2d_UTILS_ROOT}/AnimateUtils/AnimateUtils.cpp
    
Add to your CmakeList.txt:
  
    include_directories(${COCOS2d_UTILS_ROOT})

Copy next sources paths into set(GAME_SRC path1 path2 ...):
${COCOS2d_UTILS_ROOT}/SettingsUtils/SettingsUtils.cpp
${COCOS2d_UTILS_ROOT}/DataBaseUtils/DataBaseUtils.cpp
  
Copy next headers paths into set(GAME_HEADERS path1 path2 ...):
${COCOS2d_UTILS_ROOT}/SettingsUtils/SettingsUtils.h
${COCOS2d_UTILS_ROOT}/DataBaseUtils/DataBaseUtils.h

Copy target_link_libraries:
target_link_libraries(${APP_NAME} cocos2d sqlite3)


    
    
  


