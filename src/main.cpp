#include <iostream>

// #include <RobotDriver.h>
#include <Robot.h>
#include <Parser.h>

int main(int argc, char **argv)
{
    std::unique_ptr<Robot> robot = std::make_unique<Robot>();
    std::unique_ptr<Parser> parser = std::make_unique<Parser>();

    Command cmd = parser->nextCommand();
    while (cmd.commandType != Command::CommandType::END)
    {
        // Ignore erroneous parsing output.
        if (cmd.commandType == Command::CommandType::ERROR)
            continue;

        robot->perform(cmd);
        cmd = parser->nextCommand();
    }

    return 0;
}
