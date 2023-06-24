#include <catch2/catch_test_macros.hpp>

#include <Robot.h>

TEST_CASE("move north", "[Robot]")
{
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 0, Position::Direction::NORTH);
    robot.perform(cmd1);

    Command cmd2(Command::MOVE);
    robot.perform(cmd2);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 1);
    REQUIRE(newPosition->direction == Position::Direction::NORTH);
}

TEST_CASE("avoid falling", "[Robot]")
{
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 5, Position::Direction::NORTH);
    robot.perform(cmd1);

    Command cmd2(Command::MOVE);
    robot.perform(cmd2);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 5);
    REQUIRE(newPosition->direction == Position::Direction::NORTH);
}

TEST_CASE("rotate", "[Robot]")
{
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 0, Position::Direction::NORTH);
    robot.perform(cmd1);

    Command cmd2(Command::RIGHT);
    robot.perform(cmd2);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 0);
    REQUIRE(newPosition->direction == Position::Direction::EAST);
}

TEST_CASE("complex", "[Robot]")
{
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(1, 2, Position::Direction::EAST);
    robot.perform(cmd1);

    Command moveCmd(Command::MOVE);
    Command leftCmd(Command::LEFT);

    robot.perform(moveCmd);
    robot.perform(moveCmd);
    robot.perform(leftCmd);
    robot.perform(moveCmd);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 3);
    REQUIRE(newPosition->y == 3);
    REQUIRE(newPosition->direction == Position::Direction::NORTH);
}

TEST_CASE("ignore commands before place", "[Robot]")
{
    Command moveCmd(Command::MOVE);
    Command leftCmd(Command::LEFT);

    Robot robot;

    // This should be ignored
    robot.perform(moveCmd);

    Command cmd1(Command::PLACE);
    cmd1.position = Position(1, 2, Position::Direction::EAST);
    robot.perform(cmd1);

    robot.perform(moveCmd);
    robot.perform(moveCmd);
    robot.perform(leftCmd);
    robot.perform(moveCmd);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 3);
    REQUIRE(newPosition->y == 3);
    REQUIRE(newPosition->direction == Position::Direction::NORTH);
}

TEST_CASE("robot not placed", "[Robot]")
{
    Command moveCmd(Command::MOVE);

    Robot robot;
    robot.perform(moveCmd);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition == nullptr);
}
