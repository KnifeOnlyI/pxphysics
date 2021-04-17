#include "px/physics/exception/InvalidRadiusException.hpp"
#include "px/physics/geometry/Circle2D.hpp"

namespace px::physics
{
Circle2D::Circle2D(float radius)
    : _pos {0, 0}, _radius {radius}
{
}

Circle2D::Circle2D(float x, float y, float radius)
    : _pos {x, y}, _radius {radius}
{
}

Pos2D &Circle2D::getPos()
{
    return _pos;
}

float Circle2D::getRadius() const
{
    return _radius;
}

Circle2D &Circle2D::setRadius(float radius)
{
    if (radius <= 0)
    {
        throw InvalidRadiusException("Radius MUST be greater than 0");
    }

    _radius = radius;

    return *this;
}
}