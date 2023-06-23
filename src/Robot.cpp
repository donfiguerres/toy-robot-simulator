#include <iostream>

#include <Robot.h>

Robot::Robot()
{
    this->position = Position();
}

void Robot::perform(Command cmd)
{
    switch (cmd.commandType)
    {
    case Command::PLACE:
        position = cmd.position;
        break;
    case Command::MOVE:
        move();
        break;
    case Command::LEFT:
        rotateLeft();
        break;
    case Command::RIGHT:
        rotateRight();
        break;
    case Command::REPORT:
        display();
        break;
    }
}

Position Robot::getPosition()
{
    return this->position;
}

void Robot::move()
{
    Position newPosition = calcNewPositionAfterMove(this->position);
    if (isValidPosition(newPosition))
        this->position = newPosition;
}

void Robot::rotateLeft()
{
    switch (this->position.direction)
    {
    case Position::NORTH:
        this->position.direction = Position::WEST;
        break;
    case Position::SOUTH:
        this->position.direction = Position::EAST;
        break;
    case Position::EAST:
        this->position.direction = Position::NORTH;
        break;
    case Position::WEST:
        this->position.direction = Position::SOUTH;
        break;
    }
}

void Robot::rotateRight()
{
    switch (this->position.direction)
    {
    case Position::NORTH:
        this->position.direction = Position::EAST;
        break;
    case Position::SOUTH:
        this->position.direction = Position::WEST;
        break;
    case Position::EAST:
        this->position.direction = Position::SOUTH;
        break;
    case Position::WEST:
        this->position.direction = Position::NORTH;
        break;
    }
}

void Robot::display()
{
    // This method can be offloaded later on to a Display class
    // for more flexibility on displaying the report.
    std::string direction = "";

    switch (position.direction)
    {
    case Position::NORTH:
        direction = "NORTH";
        break;
    case Position::SOUTH:
        direction = "SOUTH";
        break;
    case Position::EAST:
        direction = "EAST";
        break;
    case Position::WEST:
        direction = "WEST";
        break;
    }

    std::cout << position.x << "," << position.y << "," << direction << std::endl;
}

bool Robot::isValidPosition(Position position)
{
    if (position.x > 5 || position.x < 0 || position.y > 5 || position.y < 0)
        return false;
    return true;
}

Position Robot::calcNewPositionAfterMove(Position position)
{
    Position newPosition = position;
    switch (position.direction)
    {
    case Position::NORTH:
        newPosition.y++;
        break;
    case Position::SOUTH:
        newPosition.y--;
        break;
    case Position::EAST:
        newPosition.x++;
        break;
    case Position::WEST:
        newPosition.x--;
        break;
    }
    return newPosition;
}
