#ifndef COMMAND
#define COMMAND

#include <Position.h>

class Command
{
public:
    enum CommandType {
        PLACE,
        MOVE,
        LEFT,
        RIGHT,
        REPORT,
        ERROR, // Failed to parse
        END // end of input
    };

    Command(CommandType commandType);
    CommandType commandType;
    Position position;
};

#endif