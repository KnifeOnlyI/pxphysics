#include "px/physics/geometry/Line2D.hpp"
#include "px/physics/util/SpaceUtil.hpp"

namespace px::physics
{
Line2D::Line2D(int ax, int ay, int bx, int by)
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

float Line2D::getLength() const
{
    return SpaceUtil::getDist(_a, _b);
}
}