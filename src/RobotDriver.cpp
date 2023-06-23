#include <RobotDriver.h>

RobotDriver::RobotDriver(Robot &robot, Parser &parser)
{
    this->robot = robot;
    this->parser = parser;
}

void RobotDriver::run()
{
    Command cmd = parser.nextCommand();

    // The first command should be a PLACE command as per specs.
    if (cmd.commandType != Command::CommandType::PLACE)
        return;

    while (cmd.commandType != Command::CommandType::END)
    {
        // Ignore erroneous parsing output.
        if (cmd.commandType == Command::CommandType::ERROR)
            continue;

        robot.perform(cmd);
        cmd = parser.nextCommand();
    }
}
