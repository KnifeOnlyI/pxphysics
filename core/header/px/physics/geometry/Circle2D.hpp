#ifndef PXPHYSICS_CIRCLE2D_HPP
#define PXPHYSICS_CIRCLE2D_HPP

#include "Pos2D.hpp"

namespace px::physics
{
/**
 * Represent a 2D circle
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Circle2D
{
public:

    /**
     * Constructor
     *
     * \param radius The radius
     */
    explicit Circle2D(float radius);

    /**
     * Constructor
     *
     * \param x The X position
     * \param y The Y position
     * \param radius The radius
     */
    Circle2D(float x, float y, float radius);

    /**
     * Get the position
     *
     * \return The position
     */
    [[nodiscard]] Pos2D &getPos();

    /**
     * Get the radius
     *
     * \return The radius
     */
    [[nodiscard]] float getRadius() const;

    /**
     * Set the radius
     *
     * \param radius The new radius
     *
     * \return this
     */
    Circle2D &setRadius(float radius);

private:

    /** \var The position */
    Pos2D _pos;

    /** \var The radius */
    float _radius;
};
}

#endif //PXPHYSICS_CIRCLE2D_HPP
