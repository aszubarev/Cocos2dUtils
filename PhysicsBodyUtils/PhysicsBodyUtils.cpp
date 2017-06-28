#include "PhysicsBodyUtils.h"

std::string PhysicsBodyUtils::err_create_pb = "ERROR: Can not create PhysicsBody";

PhysicsBodyUtils::PhysicsBodyUtils()
{}

PhysicsBodyUtils::~PhysicsBodyUtils()
{}

PhysicsBody *PhysicsBodyUtils::createBox(const Size &size, int bitmask,
                                         bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                         const PhysicsMaterial &material,
                                         const Vec2 &offset)
{
    PhysicsBody *pb = PhysicsBody::createBox(size, material, offset);
    if (pb == nullptr)
    {
        throw std::runtime_error(err_create_pb);
    }

    pb->setDynamic(id_dynamic);
    pb->setGravityEnable(gravity_enable);
    pb->setRotationEnable(rotation_enable);
    pb->setContactTestBitmask(true);
    pb->setCollisionBitmask(bitmask);

    return pb;
}

PhysicsBody *PhysicsBodyUtils::createCircle(float radius, int bitmask,
                                            bool id_dynamic, bool gravity_enable, bool rotation_enable,
                                            const PhysicsMaterial &material,
                                            const Vec2 &offset)
{
    PhysicsBody *pb = PhysicsBody::createCircle(radius, material, offset);
    if (pb == nullptr)
    {
        throw std::runtime_error(err_create_pb);
    }

    pb->setDynamic(id_dynamic);
    pb->setGravityEnable(gravity_enable);
    pb->setRotationEnable(rotation_enable);
    pb->setContactTestBitmask(true);
    pb->setCollisionBitmask(bitmask);

    return pb;
}
