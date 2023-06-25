#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <vector>
#include <tuple>

#include <Parser.h>

TEST_CASE("end of input", "[Parser]")
{
    Parser parser("");
    REQUIRE(parser.nextCommandInstruction().commandType == CommandInstruction::END);
}

TEST_CASE("move", "[Parser]")
{
    Parser parser("MOVE");
    REQUIRE(parser.nextCommandInstruction().commandType == CommandInstruction::MOVE);
}

TEST_CASE("left", "[Parser]")
{
    Parser parser("LEFT");
    REQUIRE(parser.nextCommandInstruction().commandType == CommandInstruction::LEFT);
}

TEST_CASE("right", "[Parser]")
{
    Parser parser("RIGHT");
    REQUIRE(parser.nextCommandInstruction().commandType == CommandInstruction::RIGHT);
}

TEST_CASE("report", "[Parser]")
{
    Parser parser("REPORT");
    REQUIRE(parser.nextCommandInstruction().commandType == CommandInstruction::REPORT);
}

TEST_CASE("report lowercase", "[Parser]")
{
    Parser parser("report");
    REQUIRE(parser.nextCommandInstruction().commandType == CommandInstruction::REPORT);
}

TEST_CASE("report space", "[Parser]")
{
    Parser parser("   REPORT    ");
    REQUIRE(parser.nextCommandInstruction().commandType == CommandInstruction::REPORT);
}

TEST_CASE("place", "[Parser]")
{
    Parser parser("PLACE 1,2,NORTH");
    CommandInstruction nextCommand = parser.nextCommandInstruction();
    REQUIRE(nextCommand.commandType == CommandInstruction::PLACE);
    REQUIRE(nextCommand.position.x == 1);
    REQUIRE(nextCommand.position.y == 2);
    REQUIRE(nextCommand.position.direction == Position::Direction::NORTH);
}

TEST_CASE("place space", "[Parser]")
{
    Parser parser("  PLACE 1, 2, NORTH    ");
    CommandInstruction nextCommand = parser.nextCommandInstruction();
    REQUIRE(nextCommand.commandType == CommandInstruction::PLACE);
    REQUIRE(nextCommand.position.x == 1);
    REQUIRE(nextCommand.position.y == 2);
    REQUIRE(nextCommand.position.direction == Position::Direction::NORTH);
}

TEST_CASE("invalid input", "[Parser]")
{
    auto input = GENERATE(
        " fasdl;kasf as",
        "rubbish",
        "move north move");
    Parser parser(input);
    CommandInstruction nextCommand = parser.nextCommandInstruction();
    REQUIRE(nextCommand.commandType == CommandInstruction::ERROR);
}
