#ifndef ROBOT
#define ROBOT

#include <Command.h>


class Robot
{
public:
    Robot();
    void perform(Command cmd);
    Position getPosition();

private:
    void move();
    void rotateLeft();
    void rotateRight();
    void display();

    Position position;

    // Pure functions
    static bool isValidPosition(Position position);
    static Position calcNewPositionAfterMove(Position position);
};

#endif