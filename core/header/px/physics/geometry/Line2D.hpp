#ifndef PXPHYSICS_LINE2D_HPP
#define PXPHYSICS_LINE2D_HPP

#include "px/physics/geometry/Pos2D.hpp"

namespace px::physics
{
/**
 * Represent a 2D line
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Line2D
{
public:

    /**
     * Constructor
     *
     * \param ax The A X position
     * \param ay The A Y position
     * \param bx The B X position
     * \param by The B Y position
     */
    Line2D(float ax, float ay, float bx, float by);

    /**
     * Get the A position
     *
     * \return The A position
     */
    [[nodiscard]] Pos2D &getA();

    /**
     * Get the B position
     *
     * \return The B position
     */
    [[nodiscard]] Pos2D &getB();

    /**
     * Get the length
     *
     * \return The length
     */
    [[nodiscard]] double getLength() const;

private:

    /** \var The A position */
    Pos2D _a;

    /** \var The B position */
    Pos2D _b;
};
}

#endif //PXPHYSICS_LINE2D_HPP
