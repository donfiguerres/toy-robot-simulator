#ifndef ROBOT_DRIVER
#define ROBOT_DRIVER

#include <Robot.h>
#include <Parser.h>

/**
 * \brief Drives the execution of the robot's commands
 *
 * The RobotDriver class uses a Parser to fetch commands and passes them to a
 * Robot to execute. The driver can run until all commands are exhausted.
 */
class RobotDriver
{
public:
    /**
     * \brief Construct a new RobotDriver object
     *
     * Constructs a new RobotDriver that will drive the given robot using
     * commands parsed by the given parser.
     *
     * \param robot The robot to be driven
     * \param parser The parser to fetch commands from
     */
    RobotDriver(Robot &robot, Parser &parser);

    /**
     * \brief Run the robot driver
     *
     * Runs the robot driver until all commands are exhausted. For each
     * command, the robot driver makes the robot perform the command.
     */
    void run();

private:
    Robot robot;   ///< The robot that this driver is driving
    Parser parser; ///< The parser to fetch commands from
};

#endif
