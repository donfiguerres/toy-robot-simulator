#ifndef POSITION_H
#define POSITION_H

/**
 * \brief Represents the position of the toy robot
 *
 * The Position class is used to store the position and direction of the toy
 * robot on the grid.
 */
class Position
{
public:
    /**
     * \brief Possible directions that the toy robot can face
     */
    enum Direction
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    /**
     * \brief Construct a new Position object
     *
     * Constructs a new Position with default values. The position will be
     * (0,0) and the direction will be NORTH.
     */
    Position();

    /**
     * \brief Construct a new Position object
     *
     * Constructs a new Position with the given values.
     *
     * \param x The x-coordinate of the position
     * \param y The y-coordinate of the position
     * \param direction The direction that the robot is facing
     */
    Position(int x, int y, Direction direction);

    int x;               ///< The x-coordinate of the position
    int y;               ///< The y-coordinate of the position
    Direction direction; ///< The direction that the robot is facing
};

#endif