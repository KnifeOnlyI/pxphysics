#ifndef PXPHYSICS_COLLISIONUTIL_HPP
#define PXPHYSICS_COLLISIONUTIL_HPP

#include "px/physics/geometry/Pos2D.hpp"
#include "px/physics/geometry/Line2D.hpp"
#include "px/physics/geometry/Circle2D.hpp"
#include "px/physics/geometry/AABB.hpp"

namespace px::physics
{
/**
 * Utilitary class to manage the collisions between geometry
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class CollisionUtil
{
public:

    /**
     * Check util between A pos and B pos
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(const Pos2D &a, const Pos2D &b);

    /**
     * Check util between A pos and B line (With default buffer to 0.1)
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(const Pos2D &a, Line2D &b);

    /**
     * Check util between A pos and B line
     *
     * \param a The A
     * \param b The B
     * \param buffer The buffer accurate (due to floating number operations)
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(const Pos2D &a, Line2D &b, float buffer);

    /**
     * Check util between A pos and B circle
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(const Pos2D &a, Circle2D &b);

    /**
     * Check util between A pos and B AABB
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(const Pos2D &a, AABB &b);

    /**
     * Check util between A line and B line
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(Line2D &a, Line2D &b);

    /**
     * Check util between A line and B circle
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(Line2D &a, Circle2D &b);

    /**
     * Check util between A line and B AABB
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(Line2D &a, AABB &b);

    /**
     * Check util between A circle and B circle
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(Circle2D &a, Circle2D &b);

    /**
     * Check util between A circle and B AABB
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(Circle2D &a, AABB &b);

    /**
     * Check util between A AABB and B AABB
     *
     * \param a The A
     * \param b The B
     *
     * \return TRUE if collides, FALSE otherwise
     */
    static bool check(AABB &a, AABB &b);
};
}

#endif //PXPHYSICS_COLLISIONUTIL_HPP
