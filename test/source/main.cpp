#include <iostream>

#include "px/physics/geometry/Line2D.hpp"
#include "px/physics/geometry/Circle2D.hpp"
#include "px/physics/geometry/AABB.hpp"

int main()
{
    px::physics::Pos2D pos1 {};
    px::physics::Pos2D pos2 {50, 50};
    px::physics::Line2D line1 {50, 50, 30, 124};
    px::physics::Circle2D circle1 {30};
    px::physics::Circle2D circle2 {50, 30, 124};
    px::physics::AABB aabb1 {30, 124};
    px::physics::AABB aabb2 {50, 50, 30, 124};

    return 0;
}
