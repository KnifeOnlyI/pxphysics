#include <cmath>

#include "px/physics/geometry/Line2D.hpp"

namespace px::physics
{
Line2D::Line2D(float ax, float ay, float bx, float by)
    : _a {ax, ay}, _b {bx, by}
{
}

Pos2D &Line2D::getA()
{
    return _a;
}

Pos2D &Line2D::getB()
{
    return _b;
}

double Line2D::getLength() const
{
    return std::sqrt(
        std::pow(_a.getX() - _b.getX(), 2) +
        std::pow(_a.getY() - _b.getY(), 2)
    );
}
}