#include "px/physics/geometry/Pos2D.hpp"

namespace px::physics
{
Pos2D::Pos2D()
    : _x {0}, _y {0}
{
}

Pos2D::Pos2D(float x, float y)
    : _x {x}, _y {y}
{
}

float Pos2D::getX() const
{
    return _x;
}

float Pos2D::getY() const
{
    return _y;
}

Pos2D &Pos2D::setX(float x)
{
    _x = x;

    return *this;
}

Pos2D &Pos2D::setY(float y)
{
    _y = y;

    return *this;
}

Pos2D &Pos2D::setXY(float x, float y)
{
    _x = x;
    _y = y;

    return *this;
}

Pos2D &Pos2D::setRelativeX(float value)
{
    _x += value;

    return *this;
}

Pos2D &Pos2D::setRelativeY(float value)
{
    _y += value;

    return *this;
}

Pos2D &Pos2D::setRelativeXY(float x, float y)
{
    _x += x;
    _y += y;

    return *this;
}
}