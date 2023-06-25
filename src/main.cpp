#include <iostream>

#include <Robot.h>
#include <Parser.h>

int main(int argc, char **argv)
{
    std::unique_ptr<Robot> robot = std::make_unique<Robot>();
    std::unique_ptr<Parser> parser = std::make_unique<Parser>();

    CommandInstruction cmd = parser->nextCommand();
    while (cmd.commandType != CommandInstruction::CommandType::END)
    {
        // Ignore erroneous parsing output.
        if (cmd.commandType == CommandInstruction::CommandType::ERROR)
            continue;

        robot->perform(cmd);
        cmd = parser->nextCommand();
    }

    return 0;
}
