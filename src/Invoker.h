#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include <Command.h>
#include <CommandInstruction.h>
#include <Robot.h>

class Invoker
{
public:
    void executeCommand(std::shared_ptr<Robot> robot, CommandInstruction instruction);

private:
    std::unique_ptr<Command> createCommand(CommandInstruction instruction);
};

#endif