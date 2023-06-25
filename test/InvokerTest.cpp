#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <tuple>

#include <Invoker.h>

TEST_CASE("move", "[Invoker]")
{
    auto robot = std::make_shared<Robot>();
    Invoker invoker;

    auto position = Position(0, 0, Position::Direction::NORTH);
    CommandInstruction place(CommandInstruction::PLACE);
    place.position = position;
    invoker.executeCommand(robot, place);
    invoker.executeCommand(robot, CommandInstruction::MOVE);

    std::unique_ptr<Position> newPosition = robot->getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 1);
    REQUIRE(newPosition->direction == Position::Direction::NORTH);
}

TEST_CASE("rotate", "[Invoker]")
{
    auto params = GENERATE(
        std::make_tuple(CommandInstruction::LEFT, Position::Direction::WEST),
        std::make_tuple(CommandInstruction::RIGHT, Position::Direction::EAST));
    auto instruction = std::get<0>(params);
    auto expectedDirection = std::get<1>(params);

    auto robot = std::make_shared<Robot>();
    Invoker invoker;

    auto position = Position(0, 0, Position::Direction::NORTH);
    CommandInstruction place(CommandInstruction::PLACE);
    place.position = position;
    invoker.executeCommand(robot, place);

    auto command = CommandInstruction(instruction);
    invoker.executeCommand(robot, command);

    std::unique_ptr<Position> newPosition = robot->getPosition();
    REQUIRE(newPosition->x == 0);
    REQUIRE(newPosition->y == 0);
    REQUIRE(newPosition->direction == expectedDirection);
}
