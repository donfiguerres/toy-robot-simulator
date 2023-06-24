#include <iostream>

#include <Grid.h>
#include <Robot.h>

Robot::Robot()
{
    this->position = nullptr;
}

void Robot::perform(Command cmd)
{
    // Ignore all commands except PLACE when the robot is not placed. The
    // position is mean to stay as nullptr until a PLACE command is issued.
    if (this->position == nullptr && cmd.commandType != Command::PLACE)
        return;

    switch (cmd.commandType)
    {
    case Command::PLACE:
        position = std::make_unique<Position>(cmd.position);
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

std::unique_ptr<Position> Robot::getPosition()
{
    if (this->position == nullptr)
        return nullptr;
    return std::make_unique<Position>(*this->position);
}

void Robot::move()
{
    // It is expected that the position is not nullptr because we only execute
    // the MOVE command when the robot is placed.
    Position newPosition = calcNewPositionAfterMove(*this->position);
    if (isValidPosition(newPosition))
        this->position = std::make_unique<Position>(newPosition);
}

void Robot::rotateLeft()
{
    switch (this->position->direction)
    {
    case Position::NORTH:
        this->position->direction = Position::WEST;
        break;
    case Position::SOUTH:
        this->position->direction = Position::EAST;
        break;
    case Position::EAST:
        this->position->direction = Position::NORTH;
        break;
    case Position::WEST:
        this->position->direction = Position::SOUTH;
        break;
    }
}

void Robot::rotateRight()
{
    switch (this->position->direction)
    {
    case Position::NORTH:
        this->position->direction = Position::EAST;
        break;
    case Position::SOUTH:
        this->position->direction = Position::WEST;
        break;
    case Position::EAST:
        this->position->direction = Position::SOUTH;
        break;
    case Position::WEST:
        this->position->direction = Position::NORTH;
        break;
    }
}

void Robot::display()
{
    // This method can be offloaded later on to a Display class
    // for more flexibility on displaying the report.
    std::string direction = "";

    switch (position->direction)
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

    std::cout << position->x << "," << position->y << "," << direction
              << std::endl;
}

bool Robot::isValidPosition(Position position)
{
    if (position.x > Grid::MAX_X || position.x < Grid::MIN_X || position.y > Grid::MAX_Y || position.y < Grid::MIN_Y)
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
