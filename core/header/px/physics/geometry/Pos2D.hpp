#ifndef PXPHYSICS_POS2D_HPP
#define PXPHYSICS_POS2D_HPP

namespace px::physics
{
/**
 * Represent a 2D position
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Pos2D
{
public:

    /**
     * Constructor
     */
    Pos2D();

    /**
     * Constructor
     *
     * \param x The X position
     * \param y The Y position
     */
    Pos2D(float x, float y);

    /**
     * Get the X position
     *
     * \return The X position
     */
    [[nodiscard]] float getX() const;

    /**
     * Get the Y position
     *
     * \return The Y position
     */
    [[nodiscard]] float getY() const;

    /**
     * Set the X position
     *
     * \param x The new X position
     *
     * \return this
     */
    Pos2D &setX(float x);

    /**
     * Set the X position
     *
     * \param x The new X position
     *
     * \return this
     */
    Pos2D &setY(float y);

    /**
     * Set the X and Y position
     *
     * \param x The new X position
     * \param y The new Y position
     *
     * \return this
     */
    Pos2D &setXY(float x, float y);

    /**
     * Set the X relative position
     *
     * \param value The value of relative position
     *
     * \return this
     */
    Pos2D &setRelativeX(float value);

    /**
     * Set the Y relative position
     *
     * \param value The value of relative position
     *
     * \return this
     */
    Pos2D &setRelativeY(float value);

    /**
     *  Set the X and Y relative position
     *
     * \param x The X value of relative position
     * \param y The Y value of relative position
     *
     * \return this
     */
    Pos2D &setRelativeXY(float x, float y);

private:

    /** \var The X position */
    float _x;

    /** \var The X position */
    float _y;
};
}

#endif //PXPHYSICS_POS2D_HPP
