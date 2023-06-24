include_directories(.)

add_executable(
  robot
  main.cpp
)

add_library(
  robot_core
  Robot.cpp
  Parser.cpp
  Position.cpp
  Command.cpp
)

target_link_libraries(
    robot
    robot_core
)

target_include_directories(
    robot PUBLIC
    src
)
