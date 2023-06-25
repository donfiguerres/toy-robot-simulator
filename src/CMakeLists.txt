include_directories(.)

add_executable(
  robot
  main.cpp
)

add_library(
  robot_core
  Command.cpp
  CommandInstruction.cpp
  Controller.cpp
  Robot.cpp
  Parser.cpp
  Position.cpp
)

target_link_libraries(
    robot
    robot_core
)

target_include_directories(
    robot PUBLIC
    src
)
