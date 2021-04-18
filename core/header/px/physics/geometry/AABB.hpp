#ifndef PXPHYSICS_AABB_HPP
#define PXPHYSICS_AABB_HPP

#include "px/physics/geometry/Pos2D.hpp"

namespace px::physics
{
/**
 * Represent an AABB
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class AABB
{
public:

    /**
     * Constructor
     *
     * \param w The width
     * \param h The height
     */
    AABB(int w, int h);

    /**
     * Constructor
     *
     * \param x The top-left corner X position
     * \param y The top-left corner Y position
     * \param w The width
     * \param h The height
     */
    AABB(int x, int y, int w, int h);

    /**
     * Get the top-left corner position
     *
     * \return The top-left corner position
     */
    [[nodiscard]] Pos2D &getPos();

    /**
     * Get the width
     *
     * \return The width
     */
    [[nodiscard]] int getW() const;

    /**
     * Get the height
     *
     * \return The height
     */
    [[nodiscard]] int getH() const;

    /**
     * Set the width
     *
     * \param w The new width
     *
     * \return this
     */
    AABB &setW(int w);

    /**
     * Set the height
     *
     * \param h The new height
     *
     * \return this
     */
    AABB &setH(int h);

private:

    /** \var The top-left corner position */
    Pos2D _pos;

    /** \var The width */
    int _w;

    /** \var The height */
    int _h;
};
}

#endif //PXPHYSICS_AABB_HPP
