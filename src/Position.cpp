#include <Position.h>

Position::Position()
{
    // Arbitrary default values
    x = 0;
    y = 0;
    direction = Direction::NORTH;
}

Position::Position(int x, int y, Direction direction)
{
    this->x = x;
    this->y = y;
    this->direction = direction;
}
