#ifndef ROBOT
#define ROBOT

#include <Command.h>

/**
 * \brief Represents a toy robot
 *
 * The Robot class provides functionality for moving a robot on a grid and
 * changing its direction.
 */
class Robot
{
public:
    /**
     * \brief Construct a new Robot object
     *
     * When a Robot object is created, it's not yet placed on the grid.
     */
    Robot();

    /**
     * \brief Perform a command
     *
     * Depending on the command type, the robot will either move, rotate left,
     * rotate right, or display its current position. The command is ignored if
     * it would cause the robot to move off the grid.
     *
     * \param cmd The command to be performed
     */
    void perform(Command cmd);

    /**
     * \brief Get the current position of the robot
     *
     * \return The current position of the robot
     */
    Position getPosition();

private:
    /// \brief Move the robot one unit forward in its current direction.
    void move();

    // \brief Rotate the robot 90 degrees to the left.
    void rotateLeft();

    /// \brief Rotate the robot 90 degrees to the right.
    void rotateRight();

    /**
     * \brief Print the robot's current position and direction to standard
     * output.
     *
     * If the robot hasn't been placed on the grid yet, this method does
     * nothing.
     */
    void display();

    Position position; ///< Current position of the robot

    /**
     * \brief Check if a position is valid
     *
     * A position is valid if it is on the grid.
     *
     * \param position The position to check
     * \return true if the position is valid, false otherwise
     */
    static bool isValidPosition(Position position);

    /**
     * \brief Calculate the new position after a move
     *
     * This does not change the robot's current position. It just calculates
     * what the position would be after a move.
     *
     * \param position The current position
     * \return The new position after the move
     */
    static Position calcNewPositionAfterMove(Position position);
};

#endif
