#include "px/physics/geometry/Pos2D.hpp"

namespace px::physics
{
Pos2D::Pos2D()
    : _x {0}, _y {0}
{
}

Pos2D::Pos2D(int x, int y)
    : _x {x}, _y {y}
{
}

int Pos2D::getX() const
{
    return _x;
}

int Pos2D::getY() const
{
    return _y;
}

Pos2D &Pos2D::setX(int x)
{
    _x = x;

    return *this;
}

Pos2D &Pos2D::setY(int y)
{
    _y = y;

    return *this;
}

Pos2D &Pos2D::setXY(int x, int y)
{
    _x = x;
    _y = y;

    return *this;
}

Pos2D &Pos2D::setRelativeX(int value)
{
    _x += value;

    return *this;
}

Pos2D &Pos2D::setRelativeY(int value)
{
    _y += value;

    return *this;
}

Pos2D &Pos2D::setRelativeXY(int x, int y)
{
    _x += x;
    _y += y;

    return *this;
}
}