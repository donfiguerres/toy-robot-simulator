#include <functional>
#include <map>

#include <Controller.h>

std::unique_ptr<Command> Controller::createCommand(CommandInstruction instruction)
{
    std::map<CommandInstruction::CommandType, std::function<std::unique_ptr<Command>(void)>> commands = {
        {CommandInstruction::PLACE, [&]()
         { return std::make_unique<PlaceCommand>(instruction.position); }},
        {CommandInstruction::MOVE, []()
         { return std::make_unique<MoveCommand>(); }},
        {CommandInstruction::LEFT, []()
         { return std::make_unique<LeftCommand>(); }},
        {CommandInstruction::RIGHT, []()
         { return std::make_unique<RightCommand>(); }},
        {CommandInstruction::REPORT, []()
         { return std::make_unique<ReportCommand>(); }},
    };
    return commands[instruction.commandType]();
}