#ifndef SIMULATION_MAP_H
#define SIMULATION_MAP_H

/**
 * \brief Represents the size of the map on which the robot can move.
 *
 * This enum provides constants for the maximum values of X and Y coordinates
 * on the map. The map extends from (0,0) to (MAX_X, MAX_Y).
 */
enum SimulationMap
{
    MIN_X = 0,
    MIN_Y = 0,
    MAX_X = 5,
    MAX_Y = 5
};

#endif