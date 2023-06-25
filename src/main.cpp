#include <iostream>

#include <Command.h>
#include <Controller.h>
#include <Robot.h>
#include <Parser.h>

int main(int argc, char **argv)
{
    auto robot = std::make_shared<Robot>();
    auto parser = std::make_shared<Parser>();
    auto controller = std::make_shared<Controller>();

    for (CommandInstruction instruction = parser->nextCommandInstruction();
         instruction.commandType != CommandInstruction::CommandType::END;
         instruction = parser->nextCommandInstruction())
    {
        // Ignore erroneous input.
        if (instruction.commandType == CommandInstruction::CommandType::ERROR)
            continue;

        auto command = controller->createCommand(instruction);
        command->execute(robot);
    }

    return 0;
}
