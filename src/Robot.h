#ifndef ROBOT
#define ROBOT

#include <memory>

#include <CommandInstruction.h>

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
     * \brief Get the current position of the robot
     *
     * This function returns a unique pointer to a copy of the current position
     * of the robot.
     * Ownership of the new Position object is transferred to the caller.
     *
     * \return A std::unique_ptr to a new Position object representing the current position of the robot.
     * \warning The returned unique_ptr may be nullptr if the robot has not been placed.
     */
    std::unique_ptr<Position> getPosition();

    /// \brief Place the robot on the grid at the given position.
    void place(Position position);

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

private:
    std::unique_ptr<Position> position; ///< Current position of the robot

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
    static Position calculateNewPosition(Position position);
};

#endif
