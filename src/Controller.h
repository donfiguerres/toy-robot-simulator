#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include <Command.h>
#include <CommandInstruction.h>
#include <Robot.h>

class Controller
{
public:
    std::unique_ptr<Command> createCommand(CommandInstruction instruction);
};

#endif