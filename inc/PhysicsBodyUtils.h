#ifndef COCOS2DUTILS_PHYSICSBODYUTILS_H
#define COCOS2DUTILS_PHYSICSBODYUTILS_H

#include "cocos2d.h"
USING_NS_CC;

class PhysicsBodyUtils
{
public:
    PhysicsBodyUtils();
    ~PhysicsBodyUtils();

    static PhysicsBody *createBox(const Size &size, int bitmask,
                                  bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                  const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

private:
    static std::string err_create_pb;

};


#endif //COCOS2DUTILS_PHYSICSBODYUTILS_H
