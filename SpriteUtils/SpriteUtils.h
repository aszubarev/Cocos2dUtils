#ifndef COCOS2DUTILS_SPRITEUTILS_H
#define COCOS2DUTILS_SPRITEUTILS_H

#include "cocos2d.h"
USING_NS_CC;

class SpriteUtils
{
public:
    SpriteUtils();
    ~SpriteUtils();

    // Sprite with Rectangle PhysicsBody
    static Sprite *createSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                        bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                                        const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    static Sprite *createSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size, int bitmask,
                                                        bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                                        const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

    static Sprite *createStaticSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                              const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    static Sprite *createStaticSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size, int bitmask,
                                                              const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

    static Sprite *createDynamicSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                               const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    static Sprite *createDynamicSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size, int bitmask,
                                                               const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

    static Sprite *createDynamicNoRotationSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                                         const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    static Sprite *createDynamicNoRotationSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size, int bitmask,
                                                                         const PhysicsMaterial &material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    // =================================================================================================================




private:

    static std::string prefix_err_create_sprite;

};


#endif //COCOS2DUTILS_SPRITEUTILS_H
