#include "SpriteUtils.h"
#include "../PhysicsBodyUtils/PhysicsBodyUtils.h"
#include <iostream>

std::string SpriteUtils::prefix_err_create_sprite = "ERROR: Can not create sprite from ";

SpriteUtils::SpriteUtils()
{}

SpriteUtils::~SpriteUtils()
{}

Sprite *SpriteUtils::createSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                          bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                                          const PhysicsMaterial &material)
{
    Sprite *sprite = Sprite::create(filename);
    if (sprite == nullptr)
    {
        throw std::invalid_argument(prefix_err_create_sprite + filename);
    }

    PhysicsBody *pb = PhysicsBodyUtils::createBox(sprite->getContentSize(), bitmask,
                                                  id_dynamic, gravity_enable, rotation_enable, material);

    sprite->addComponent(pb);

    return sprite;
}

Sprite *SpriteUtils::createSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size, int bitmask,
                                                          bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                                          const PhysicsMaterial &material)
{
    Sprite *sprite = Sprite::create(filename);
    if (sprite == nullptr)
    {
        throw std::invalid_argument(prefix_err_create_sprite + filename);
    }

    PhysicsBody *pb = PhysicsBodyUtils::createBox(size, bitmask,
                                                  id_dynamic, gravity_enable, rotation_enable, material);

    sprite->addComponent(pb);

    return sprite;
}

Sprite *SpriteUtils::createStaticSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size,
                                                                int bitmask, const PhysicsMaterial &material)
{
    return createSpriteWithRectanglePhysicsBody(filename, size, bitmask, false, false, false, material);
}

Sprite *SpriteUtils::createStaticSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                                const PhysicsMaterial &material)
{
    return createSpriteWithRectanglePhysicsBody(filename, bitmask, false, false, false, material);
}

Sprite *SpriteUtils::createDynamicSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                                 const PhysicsMaterial &material)
{
    return createSpriteWithRectanglePhysicsBody(filename, bitmask, true, true, true, material);
}

Sprite *SpriteUtils::createDynamicSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size,
                                                                int bitmask, const PhysicsMaterial &material)
{
    return createSpriteWithRectanglePhysicsBody(filename, size, bitmask, true, true, true, material);
}

Sprite *SpriteUtils::createDynamicNoRotationSpriteWithRectanglePhysicsBody(const std::string &filename, int bitmask,
                                                                           const PhysicsMaterial &material)
{
    return createSpriteWithRectanglePhysicsBody(filename, bitmask, true, true, false, material);
}

Sprite *SpriteUtils::createDynamicNoRotationSpriteWithRectanglePhysicsBody(const std::string &filename, const Size &size,
                                                                           int bitmask, const PhysicsMaterial &material)
{
    return createSpriteWithRectanglePhysicsBody(filename, size, bitmask, true, true, false, material);
}
