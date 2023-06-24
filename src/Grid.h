#ifndef GRID_H
#define GRID_H

/**
 * \brief Represents the size of the grid on which the robot can move.
 *
 * This enum provides constants for the maximum values of X and Y coordinates
 * on the grid. The grid extends from (0,0) to (MAX_X, MAX_Y).
 */
enum Grid
{
    MIN_X = 0,
    MIN_Y = 0,
    MAX_X = 5,
    MAX_Y = 5
};

#endif