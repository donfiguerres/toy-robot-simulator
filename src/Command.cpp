#include <Command.h>

PlaceCommand::PlaceCommand(Position position)
{
    this->position = position;
}

void PlaceCommand::execute(std::shared_ptr<Robot> robot)
{
    robot->place(this->position);
}

void MoveCommand::execute(std::shared_ptr<Robot> robot)
{
    robot->move();
}

void LeftCommand::execute(std::shared_ptr<Robot> robot)
{
    robot->rotateLeft();
}

void RightCommand::execute(std::shared_ptr<Robot> robot)
{
    robot->rotateRight();
}

void ReportCommand::execute(std::shared_ptr<Robot> robot)
{
    robot->display();
}
