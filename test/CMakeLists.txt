Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)
FetchContent_MakeAvailable(Catch2)

include_directories(../src)

add_executable(RobotTest RobotTest.cpp)

target_link_libraries(
    RobotTest
    PRIVATE Catch2::Catch2WithMain
    robot_core
)

add_executable(ParserTest ParserTest.cpp)

target_link_libraries(
    ParserTest
    PRIVATE Catch2::Catch2WithMain
    robot_core
)

include(CTest)
include(Catch)
catch_discover_tests(RobotTest)
catch_discover_tests(ParserTest)
