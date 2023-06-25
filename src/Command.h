#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

#include <Position.h>
#include <Robot.h>

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute(std::shared_ptr<Robot> robot) = 0;
};

class PlaceCommand : public Command
{
public:
    PlaceCommand(Position position);
    virtual void execute(std::shared_ptr<Robot> robot);

private:
    Position position;
};

class MoveCommand : public Command
{
public:
    virtual void execute(std::shared_ptr<Robot> robot);
};

class LeftCommand : public Command
{
public:
    virtual void execute(std::shared_ptr<Robot> robot);
};

class RightCommand : public Command
{
public:
    virtual void execute(std::shared_ptr<Robot> robot);
};

class ReportCommand : public Command
{
public:
    virtual void execute(std::shared_ptr<Robot> robot);
};

#endif