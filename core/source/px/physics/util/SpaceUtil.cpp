#include <cmath>

#include "px/physics/util/SpaceUtil.hpp"

namespace px::physics
{
float SpaceUtil::getDist(const Pos2D &a, const Pos2D &b)
{
    return static_cast<float>(std::sqrt(std::pow(a.getX() - b.getX(), 2) + std::pow(a.getY() - b.getY(), 2)));
}
}