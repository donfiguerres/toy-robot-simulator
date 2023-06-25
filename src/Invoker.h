#ifndef INVOKER_H
#define INVOKER_H

#include <memory>

#include <Command.h>
#include <CommandInstruction.h>
#include <Robot.h>

/**
 * \brief A class responsible for receiving the instructions and executing the
 * right command for those instructions.
 */
class Invoker
{
public:
    /**
     * \brief Execute a command for a given robot based on a command
     * instruction.
     *
     * This function creates a command based on the provided instruction and
     * executes this command for the specified robot.
     *
     * \param robot A shared pointer to a Robot that the command will be executed for.
     * \param instruction A CommandInstruction that specifies the type of command to be created and executed.
     */
    void executeCommand(std::shared_ptr<Robot> robot, CommandInstruction instruction);

private:
    /**
     * \brief Create a Command object based on a command instruction.
     *
     * This function creates a unique pointer to a Command object based on the
     * provided command instruction. The created command can then be executed
     * for a robot.
     *
     * \param instruction A CommandInstruction that specifies the type of command to be created.
     * \return A unique pointer to a Command object.
     */
    std::unique_ptr<Command> createCommand(CommandInstruction instruction);
};

#endif