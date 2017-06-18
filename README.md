# Cocos2dUtils

### install:

Add submodule to your project in root folder:

    git submodule add -b master https://github.com/ZubAnt/Cocos2dUtils.git
    
Update submodule by command:

    git submodule update --init --force --remote --recursive

Add  to {PROJECT_ROOT}/CmakeList.txt variable "COCOS2d_UTILS_ROOT":
    
    set(COCOS2d_UTILS_ROOT ${CMAKE_SOURCE_DIR}/Cocos2dUtils)
    
Copy next headers paths into set(GAME_HEADERS path1 path2 ...):
    
    {COCOS2d_UTILS_ROOT}/ImageUtils/ImageUtils.h
    {COCOS2d_UTILS_ROOT}/PhysicsBodyUtils/PhysicsBodyUtils.h
    {COCOS2d_UTILS_ROOT}/SpriteUtils/SpriteUtils.h
    
Copy next sources paths into set(GAME_SRC path1 path2 ...):

    {COCOS2d_UTILS_ROOT}/ImageUtils/ImageUtils.cpp
    {COCOS2d_UTILS_ROOT}/PhysicsBodyUtils/PhysicsBodyUtils.cpp
    {COCOS2d_UTILS_ROOT}/SpriteUtils/SpriteUtils.cpp
    
Add to {PROJECT_ROOT}/CmakeList.txt in "include_directoriese" path:
  
    include_directories({COCOS2d_UTILS_ROOT})
    
    
  


