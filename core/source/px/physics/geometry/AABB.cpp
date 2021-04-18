#include "px/physics/exception/InvalidWidthException.hpp"
#include "px/physics/geometry/AABB.hpp"

namespace px::physics
{
AABB::AABB(int w, int h)
    : _pos {0, 0}, _w {w}, _h {h}
{
}

AABB::AABB(int x, int y, int w, int h)
    : _pos {x, y}, _w {w}, _h {h}
{
}

Pos2D &AABB::getPos()
{
    return _pos;
}

int AABB::getW() const
{
    return _w;
}

int AABB::getH() const
{
    return _h;
}

AABB &AABB::setW(int w)
{
    if (w <= 0)
    {
        throw InvalidWidthException("The width MUST be greater than 0");
    }

    _w = w;

    return *this;
}

AABB &AABB::setH(int h)
{
    if (h <= 0)
    {
        throw InvalidWidthException("The height MUST be greater than 0");
    }

    _h = h;

    return *this;
}
}