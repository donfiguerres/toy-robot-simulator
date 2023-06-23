#include <catch2/catch_test_macros.hpp>

#include <Parser.h>

TEST_CASE("end of input", "[Parser]")
{
    Parser parser("");
    REQUIRE(parser.nextCommand().commandType == Command::END);
}

TEST_CASE("move", "[Parser]")
{
    Parser parser("MOVE");
    REQUIRE(parser.nextCommand().commandType == Command::MOVE);
}

TEST_CASE("left", "[Parser]")
{
    Parser parser("LEFT");
    REQUIRE(parser.nextCommand().commandType == Command::LEFT);
}

TEST_CASE("right", "[Parser]")
{
    Parser parser("RIGHT");
    REQUIRE(parser.nextCommand().commandType == Command::RIGHT);
}

TEST_CASE("report", "[Parser]")
{
    Parser parser("REPORT");
    REQUIRE(parser.nextCommand().commandType == Command::REPORT);
}

TEST_CASE("report lowercase", "[Parser]")
{
    Parser parser("report");
    REQUIRE(parser.nextCommand().commandType == Command::REPORT);
}

TEST_CASE("report space", "[Parser]")
{
    Parser parser("   REPORT    ");
    REQUIRE(parser.nextCommand().commandType == Command::REPORT);
}

TEST_CASE("place", "[Parser]")
{
    Parser parser("PLACE 1,2,NORTH");
    Command nextCommand = parser.nextCommand();
    REQUIRE(nextCommand.commandType == Command::PLACE);
    REQUIRE(nextCommand.position.x == 1);
    REQUIRE(nextCommand.position.y == 2);
    REQUIRE(nextCommand.position.direction == Position::Direction::NORTH);
}

TEST_CASE("place space", "[Parser]")
{
    Parser parser("  PLACE 1, 2, NORTH    ");
    Command nextCommand = parser.nextCommand();
    REQUIRE(nextCommand.commandType == Command::PLACE);
    REQUIRE(nextCommand.position.x == 1);
    REQUIRE(nextCommand.position.y == 2);
    REQUIRE(nextCommand.position.direction == Position::Direction::NORTH);
}
