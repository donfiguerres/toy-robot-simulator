#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <tuple>

#include <SimulationMap.h>
#include <Robot.h>

TEST_CASE("move north", "[Robot]")
{
    Robot robot;

    auto position = Position(0, 0, Position::Direction::NORTH);
    robot.place(position);

    robot.move();

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

    auto position = Position(x, y, direction);
    robot.place(position);

    robot.move();

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

    auto position = Position(0, 0, initialDirection);
    robot.place(position);

    robot.rotateRight();

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

    auto position = Position(0, 0, initialDirection);
    robot.place(position);

    CommandInstruction cmd2(CommandInstruction::LEFT);
    robot.perform(cmd2);

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 0);
    REQUIRE(newPosition->direction == expectedDirection);
}

TEST_CASE("complex", "[Robot]")
{
    Robot robot;

    auto position = Position(1, 2, Position::Direction::EAST);
    robot.place(position);

    CommandInstruction moveCmd(CommandInstruction::MOVE);
    CommandInstruction leftCmd(CommandInstruction::LEFT);

    robot.move();
    robot.move();
    robot.rotateLeft();
    robot.move();

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 3);
    REQUIRE(newPosition->y == 3);
    REQUIRE(newPosition->direction == Position::Direction::NORTH);
}

TEST_CASE("ignore commands before place", "[Robot]")
{
    CommandInstruction moveCmd(CommandInstruction::MOVE);
    CommandInstruction leftCmd(CommandInstruction::LEFT);

    Robot robot;

    // This should be ignored
    robot.move();

    auto position = Position(1, 2, Position::Direction::EAST);
    robot.place(position);

    robot.move();
    robot.move();
    robot.rotateLeft();
    robot.move();

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition->x == 3);
    REQUIRE(newPosition->y == 3);
    REQUIRE(newPosition->direction == Position::Direction::NORTH);
}

TEST_CASE("robot not placed", "[Robot]")
{
    CommandInstruction moveCmd(CommandInstruction::MOVE);

    Robot robot;
    robot.move();
    robot.rotateLeft();
    robot.rotateRight();
    robot.display();

    std::unique_ptr<Position> newPosition = robot.getPosition();
    REQUIRE(newPosition == nullptr);
}
