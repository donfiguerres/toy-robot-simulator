#include <iostream>
#include <map>

#include <SimulationMap.h>
#include <Robot.h>

Robot::Robot()
{
    this->position = nullptr;
}

std::unique_ptr<Position> Robot::getPosition()
{
    if (this->position == nullptr)
        return nullptr;
    return std::make_unique<Position>(*this->position);
}

void Robot::place(Position position)
{
    if (isValidPosition(position))
        this->position = std::make_unique<Position>(position);
}

void Robot::move()
{
    if (this->position == nullptr)
        return;
    Position newPosition = calculateNewPosition(*this->position);
    if (isValidPosition(newPosition))
        this->position = std::make_unique<Position>(newPosition);
}

void Robot::rotateLeft()
{
    if (this->position == nullptr)
        return;
    std::map<Position::Direction, Position::Direction> directionMap = {
        {Position::NORTH, Position::WEST},
        {Position::EAST, Position::NORTH},
        {Position::SOUTH, Position::EAST},
        {Position::WEST, Position::SOUTH},
    };
    this->position->direction = directionMap[this->position->direction];
}

void Robot::rotateRight()
{
    if (this->position == nullptr)
        return;
    std::map<Position::Direction, Position::Direction> directionMap = {
        {Position::NORTH, Position::EAST},
        {Position::EAST, Position::SOUTH},
        {Position::SOUTH, Position::WEST},
        {Position::WEST, Position::NORTH},
    };
    this->position->direction = directionMap[this->position->direction];
}

void Robot::display()
{
    if (this->position == nullptr)
        return;
    // This method can be offloaded later on to a Display class
    // for more flexibility on displaying the report.
    std::map<Position::Direction, std::string> directionMap = {
        {Position::NORTH, "NORTH"},
        {Position::SOUTH, "SOUTH"},
        {Position::EAST, "EAST"},
        {Position::WEST, "WEST"},
    };
    std::string direction = directionMap[position->direction];

    std::cout
        << position->x << "," << position->y << "," << direction << std::endl;
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
