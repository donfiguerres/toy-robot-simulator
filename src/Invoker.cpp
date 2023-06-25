#include <functional>
#include <map>

#include <Invoker.h>

void Invoker::executeCommand(std::shared_ptr<Robot> robot,
                             CommandInstruction instruction)
{
    auto command = createCommand(instruction);
    command->execute(robot);
}

std::unique_ptr<Command> Invoker::createCommand(CommandInstruction instruction)
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
