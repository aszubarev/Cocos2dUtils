#include "SpriteUtils.h"
#include "../PhysicsBodyUtils/PhysicsBodyUtils.h"
#include <iostream>

std::string SpriteUtils::prefix_err_create_sprite = "ERROR: Can not create sprite from ";

SpriteUtils::SpriteUtils()
{}

SpriteUtils::~SpriteUtils()
{}

Sprite *SpriteUtils::createWithBoxPB(const std::string &filename, int bitmask,
                                     bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                     const PhysicsMaterial &material,
                                     const Vec2 &offset)
{
    Sprite *sprite = Sprite::create(filename);
    if (sprite == nullptr)
    {
        throw std::invalid_argument(prefix_err_create_sprite + filename);
    }

    PhysicsBody *pb = PhysicsBodyUtils::createBox(sprite->getContentSize(), bitmask,
                                                  id_dynamic, gravity_enable, rotation_enable, material, offset);

    sprite->addComponent(pb);

    return sprite;
}

Sprite *SpriteUtils::createWithBoxPB(const std::string &filename, const Size &size, int bitmask,
                                     bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                     const PhysicsMaterial &material,
                                     const Vec2 &offset)
{
    Sprite *sprite = Sprite::create(filename);
    if (sprite == nullptr)
    {
        throw std::invalid_argument(prefix_err_create_sprite + filename);
    }

    PhysicsBody *pb = PhysicsBodyUtils::createBox(size, bitmask,
                                                  id_dynamic, gravity_enable, rotation_enable, material, offset);

    sprite->addComponent(pb);

    return sprite;
}

Sprite *SpriteUtils::createWithStaticBoxPB(const std::string &filename, const Size &size,
                                           int bitmask, const PhysicsMaterial &material,
                                           const Vec2 &offset)
{
    return createWithBoxPB(filename, size, bitmask, false, false, false, material, offset);
}

Sprite *SpriteUtils::createWithStaticBoxPB(const std::string &filename, int bitmask,
                                           const PhysicsMaterial &material,
                                           const Vec2 &offset)
{
    return createWithBoxPB(filename, bitmask, false, false, false, material, offset);
}

Sprite *SpriteUtils::createWithDynamicBoxPB(const std::string &filename, int bitmask,
                                            const PhysicsMaterial &material,
                                            const Vec2 &offset)
{
    return createWithBoxPB(filename, bitmask, true, true, true, material, offset);
}

Sprite *SpriteUtils::createWithDynamicBoxPB(const std::string &filename, const Size &size,
                                            int bitmask, const PhysicsMaterial &material,
                                            const Vec2 &offset)
{
    return createWithBoxPB(filename, size, bitmask, true, true, true, material, offset);
}

Sprite *SpriteUtils::createWithDynamicBoxPBnoRotation(const std::string &filename, int bitmask,
                                                      const PhysicsMaterial &material,
                                                      const Vec2 &offset)
{
    return createWithBoxPB(filename, bitmask, true, true, false, material, offset);
}

Sprite *SpriteUtils::createWithDynamicBoxPBnoRotation(const std::string &filename, const Size &size,
                                                      int bitmask, const PhysicsMaterial &material,
                                                      const Vec2 &offset)
{
    return createWithBoxPB(filename, size, bitmask, true, true, false, material, offset);
}

Sprite *SpriteUtils::createWithCirclePB(const std::string &filename, int bitmask, bool id_dynamic, bool gravity_enable,
                                        bool rotation_enable, const PhysicsMaterial &material,
                                        const Vec2 &offset)
{
    Sprite *sprite = Sprite::create(filename);
    if (sprite == nullptr)
    {
        throw std::invalid_argument(prefix_err_create_sprite + filename);
    }

    Size size = sprite->getContentSize();
    float radius = (size.width > size.height)? size.height * 0.5f : size.width * 0.5f;
    PhysicsBody *pb = PhysicsBodyUtils::createCircle(radius, bitmask,
                                                     id_dynamic, gravity_enable, rotation_enable,
                                                     material, offset);

    sprite->addComponent(pb);

    return sprite;
}

Sprite *SpriteUtils::createWithCirclePB(const std::string &filename, float radius, int bitmask, bool id_dynamic,
                                        bool gravity_enable, bool rotation_enable, const PhysicsMaterial &material,
                                        const Vec2 &offset)
{
    Sprite *sprite = Sprite::create(filename);
    if (sprite == nullptr)
    {
        throw std::invalid_argument(prefix_err_create_sprite + filename);
    }

    PhysicsBody *pb = PhysicsBodyUtils::createCircle(radius, bitmask,
                                                     id_dynamic, gravity_enable, rotation_enable,
                                                     material, offset);

    sprite->addComponent(pb);

    return sprite;
}

Sprite *SpriteUtils::createWithStaticCirclePB(const std::string &filename, int bitmask,
                                              const PhysicsMaterial &material,
                                              const Vec2 &offset)
{
    return createWithCirclePB(filename, bitmask, false, false, false, material, offset);
}

Sprite *SpriteUtils::createWithStaticCirclePB(const std::string &filename, float radius, int bitmask,
                                              const PhysicsMaterial &material, const Vec2 &offset)
{
    return createWithCirclePB(filename, radius, bitmask, false, false, false, material, offset);
}

Sprite * SpriteUtils::createWithDynamicCirclePB(const std::string &filename, int bitmask,
                                                const PhysicsMaterial &material,
                                                const Vec2 &offset)
{
    return createWithCirclePB(filename, bitmask, true, true, true, material, offset);
}

Sprite *SpriteUtils::createWithDynamicCirclePB(const std::string &filename, float radius, int bitmask,
                                               const PhysicsMaterial &material, const Vec2 &offset)
{
    return createWithCirclePB(filename, radius, bitmask, true, true, true, material, offset);
}

Sprite *SpriteUtils::createWithDynamicCirclePBnoRotation(const std::string &filename, int bitmask,
                                                         const PhysicsMaterial &material, const Vec2 &offset)
{
    return createWithCirclePB(filename, bitmask, true, true, false, material, offset);
}

Sprite *SpriteUtils::createWithDynamicCirclePBnoRotation(const std::string &filename, float radius, int bitmask,
                                                         const PhysicsMaterial &material, const Vec2 &offset)
{
    return createWithCirclePB(filename, radius, bitmask, true, true, false, material, offset);
}
