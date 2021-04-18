#ifndef PXPHYSICS_SPACEUTIL_HPP
#define PXPHYSICS_SPACEUTIL_HPP

#include "px/physics/geometry/Pos2D.hpp"

namespace px::physics
{
/**
 * Utilitary class to manage space calculations
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class SpaceUtil
{
public:

    /**
     * Get distance between 2 points
     *
     * \param a The A point
     * \param b The B point
     *
     * \return The distance
     */
    static float getDist(const Pos2D &a, const Pos2D &b);
};
}

#endif //PXPHYSICS_SPACEUTIL_HPP
