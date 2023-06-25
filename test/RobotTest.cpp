#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <vector>
#include <tuple>

#include <SimulationMap.h>
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
    auto params = GENERATE(
        std::make_tuple(0, int(SimulationMap::MAX_Y), Position::Direction::NORTH),
        std::make_tuple(int(SimulationMap::MAX_X), 0, Position::Direction::EAST),
        std::make_tuple(int(SimulationMap::MIN_X), 0, Position::Direction::WEST),
        std::make_tuple(0, int(SimulationMap::MIN_Y), Position::Direction::SOUTH));
    int x = std::get<0>(params);
    int y = std::get<1>(params);
    Position::Direction direction = std::get<2>(params);

    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(x, y, direction);
    robot.perform(cmd1);

    Command cmd2(Command::MOVE);
    robot.perform(cmd2);

    // The robot should not move
    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == x);
    REQUIRE(newPosition->y == y);
    REQUIRE(newPosition->direction == direction);
}

TEST_CASE("rotate right", "[Robot]")
{
    Robot robot;
    auto params = GENERATE(
        std::make_tuple(Position::Direction::NORTH, Position::Direction::EAST),
        std::make_tuple(Position::Direction::EAST, Position::Direction::SOUTH),
        std::make_tuple(Position::Direction::SOUTH, Position::Direction::WEST),
        std::make_tuple(Position::Direction::WEST, Position::Direction::NORTH));
    Position::Direction initialDirection = std::get<0>(params);
    Position::Direction expectedDirection = std::get<1>(params);

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 0, initialDirection);
    robot.perform(cmd1);

    Command cmd2(Command::RIGHT);
    robot.perform(cmd2);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 0);
    REQUIRE(newPosition->direction == expectedDirection);
}

TEST_CASE("rotate left", "[Robot]")
{
    Robot robot;
    auto params = GENERATE(
        std::make_tuple(Position::Direction::NORTH, Position::Direction::WEST),
        std::make_tuple(Position::Direction::WEST, Position::Direction::SOUTH),
        std::make_tuple(Position::Direction::SOUTH, Position::Direction::EAST),
        std::make_tuple(Position::Direction::EAST, Position::Direction::NORTH));
    Position::Direction initialDirection = std::get<0>(params);
    Position::Direction expectedDirection = std::get<1>(params);

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 0, initialDirection);
    robot.perform(cmd1);

    Command cmd2(Command::LEFT);
    robot.perform(cmd2);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 0);
    REQUIRE(newPosition->direction == expectedDirection);
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
