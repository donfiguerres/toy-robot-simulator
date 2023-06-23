#include <Command.h>

Command::Command(CommandType commandType)
{
    this->commandType = commandType;

    // Set position to default. Caller should be the one responsible to
    // set the position.
    Position position;
    this->position = position;
}
