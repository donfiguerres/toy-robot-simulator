#ifndef COMMAND
#define COMMAND

#include <Position.h>

/**
 * \brief Encapsulates a command for the toy robot
 *
 * The Command class is used to represent a command for the toy robot.
 * It includes the type of the command and, for PLACE commands, the position.
 */
class Command
{
public:
    /**
     * \brief Types of commands that the toy robot can execute
     */
    enum CommandType
    {
        PLACE,  ///< Place the robot at a position on the grid
        MOVE,   ///< Move the robot one unit forward in its current direction
        LEFT,   ///< Rotate the robot 90 degrees to the left
        RIGHT,  ///< Rotate the robot 90 degrees to the right
        REPORT, ///< Print the robot's current position and direction
        ERROR,  ///< Failed to parse the command
        END     ///< End of input
    };

    /**
     * \brief Construct a new Command object
     *
     * Constructs a new Command of the given type. If the command type is PLACE,
     * the position should be set separately.
     *
     * \param commandType The type of the command
     */
    Command(CommandType commandType);

    CommandType commandType; ///< The type of the command
    Position position;       ///< The position for PLACE commands. Ignored for other command types.
};

#endif
