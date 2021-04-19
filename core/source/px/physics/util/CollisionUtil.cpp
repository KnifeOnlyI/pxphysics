#include <cmath>

#include "px/physics/util/CollisionUtil.hpp"
#include "px/physics/util/SpaceUtil.hpp"

namespace px::physics
{
bool CollisionUtil::check(const physics::Pos2D &a, const physics::Pos2D &b)
{
    return a.getX() == b.getX() && a.getY() == b.getY();
}

bool CollisionUtil::check(const physics::Pos2D &a, physics::Line2D &b)
{
    return check(a, b, 0.1);
}

bool CollisionUtil::check(const physics::Pos2D &a, physics::Line2D &b, float buffer)
{
    const float d1 {SpaceUtil::getDist(a, b.getA())};
    const float d2 {SpaceUtil::getDist(a, b.getB())};
    const float lineLength {b.getLength()};

    return (d1 + d2 >= lineLength - buffer) && (d1 + d2 <= lineLength + buffer);
}

bool CollisionUtil::check(const physics::Pos2D &a, physics::Circle2D &b)
{
    return SpaceUtil::getDist(a, b.getPos()) <= b.getRadius();
}

bool CollisionUtil::check(const physics::Pos2D &a, physics::AABB &b)
{
    return a.getX() >= b.getPos().getX() &&
           a.getX() <= b.getPos().getX() + b.getW() &&
           a.getY() >= b.getPos().getY() &&
           a.getY() <= b.getPos().getY() + b.getH();
}

bool CollisionUtil::check(physics::Line2D &a, physics::Line2D &b)
{
    // FIXME: Pas de collision si les mêmes angles (orientations)

    const float uA {static_cast<float>((b.getB().getX() - b.getA().getX()) * (a.getA().getY() - b.getA().getY()) -
                                       (b.getB().getY() - b.getA().getY()) * (a.getA().getX() - b.getA().getX())) /
                    static_cast<float>((b.getB().getY() - b.getA().getY()) * (a.getB().getX() - a.getA().getX()) -
                                       (b.getB().getX() - b.getA().getX()) * (a.getB().getY() - a.getA().getY()))};
    const float uB {static_cast<float>((a.getB().getX() - a.getA().getX()) * (a.getA().getY() - b.getA().getY()) -
                                       (a.getB().getY() - a.getA().getY()) * (a.getA().getX() - b.getA().getX())) /
                    static_cast<float>((b.getB().getY() - b.getA().getY()) * (a.getB().getX() - a.getA().getX()) -
                                       (b.getB().getX() - b.getA().getX()) * (a.getB().getY() - a.getA().getY()))};

    return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1);
}

bool CollisionUtil::check(physics::Line2D &a, physics::Circle2D &b)
{
    bool results {true};

    if (!check(a.getA(), b) && !check(a.getB(), b))
    {
        const float dot {
            static_cast<float>(((b.getPos().getX() - a.getA().getX()) * (a.getB().getX() - a.getA().getX())) +
                               ((b.getPos().getY() - a.getA().getY()) * (a.getB().getY() - a.getA().getY()))) /
            static_cast<float>(std::pow(a.getLength(), 2))
        };

        const Pos2D closestPoint {
            static_cast<int>(a.getA().getX() + static_cast<int>(
                dot * static_cast<float>(a.getB().getX() - a.getA().getX())
            )),
            static_cast<int>(a.getA().getY() + static_cast<int>(
                dot * static_cast<float>(a.getB().getY() - a.getA().getY())
            ))
        };

        results = check(closestPoint, a) && SpaceUtil::getDist(closestPoint, b.getPos()) <= b.getRadius();
    }

    return results;
}

bool CollisionUtil::check(physics::Line2D &a, physics::AABB &b)
{
    bool results {true};

    if (!check(a.getA(), b) || !check(a.getB(), b))
    {
        Line2D left {b.getPos().getX(), b.getPos().getY(), b.getPos().getX(), b.getPos().getY() + b.getH()};
        Line2D right {b.getPos().getX() + b.getW(), b.getPos().getY(), b.getPos().getX() + b.getW(),
                      b.getPos().getY() + b.getH()};
        Line2D top {b.getPos().getX(), b.getPos().getY(), b.getPos().getX() + b.getW(), b.getPos().getY()};
        Line2D bottom {b.getPos().getX(), b.getPos().getY() + b.getH(), b.getPos().getX() + b.getW(),
                       b.getPos().getY() + b.getH()};

        results = check(a, left) || check(a, right) || check(a, top) || check(a, bottom);
    }

    return results;
}

bool CollisionUtil::check(physics::Circle2D &a, physics::Circle2D &b)
{
    return SpaceUtil::getDist(a.getPos(), b.getPos()) <= (a.getRadius() + b.getRadius());
}

bool CollisionUtil::check(physics::Circle2D &a, physics::AABB &b)
{
    int testX {a.getPos().getX()};
    int testY {a.getPos().getY()};

    if (a.getPos().getX() < b.getPos().getX())
    {
        testX = b.getPos().getX();
    }
    else if (a.getPos().getX() > b.getPos().getX() + b.getW())
    {
        testX = b.getPos().getX() + b.getW();
    }

    if (a.getPos().getY() < b.getPos().getY())
    {
        testY = b.getPos().getY();
    }
    else if (a.getPos().getY() > b.getPos().getY() + b.getH())
    {
        testY = b.getPos().getY() + b.getH();
    }

    return SpaceUtil::getDist(a.getPos(), Pos2D {testX, testY}) <= a.getRadius();
}

bool CollisionUtil::check(physics::AABB &a, physics::AABB &b)
{
    return (a.getPos().getX() + a.getW() >= b.getPos().getX() &&
            a.getPos().getX() <= b.getPos().getX() + b.getW() &&
            a.getPos().getY() + a.getH() >= b.getPos().getY() &&
            a.getPos().getY() <= b.getPos().getY() + b.getH());
}
}