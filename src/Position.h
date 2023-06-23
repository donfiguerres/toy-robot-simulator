#ifndef POSITION
#define POSITION

class Position {
public:
    enum Direction {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    Position();
    Position(int x, int y, Direction direction);

    int x;
    int y;
    Direction direction;
};

#endif