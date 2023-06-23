#ifndef ROBOT_DRIVER
#define ROBOT_DRIVER

#include <Robot.h>
#include <Parser.h>


class RobotDriver
{
public:
    RobotDriver(Robot &robot, Parser &parser);
    void run();

private:
    Robot robot;
    Parser parser;
};

#endif