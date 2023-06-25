#include <iostream>

#include <SimulationMap.h>
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
    Position newPosition = calculateNewPosition(*this->position);
    if (isValidPosition(newPosition))
        this->position = std::make_unique<Position>(newPosition);
}

void Robot::rotateLeft()
{
    if (this->position->direction == Position::Direction::NORTH)
    {
        this->position->direction = Position::Direction::WEST;
        return;
    }

    this->position->direction = static_cast<Position::Direction>(
        this->position->direction - 1);
}

void Robot::rotateRight()
{
    if (this->position->direction == Position::Direction::WEST)
    {
        this->position->direction = Position::Direction::NORTH;
        return;
    }

    this->position->direction = static_cast<Position::Direction>(
        this->position->direction + 1);
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
    if (position.x > SimulationMap::MAX_X || position.x < SimulationMap::MIN_X || position.y > SimulationMap::MAX_Y || position.y < SimulationMap::MIN_Y)
        return false;
    return true;
}

Position Robot::calculateNewPosition(Position position)
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
