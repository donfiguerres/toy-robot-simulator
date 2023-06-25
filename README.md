# Toy Robot Simulator

![actions workflow](https://github.com/donfiguerres/toy-robot-simulator/actions/workflows/cmake.yml/badge.svg)

This is a simulation of a robot toy moving on a square table top with a size of
5 units x 5 units. It reads the instructions from the standard input and will
perform the necessary actions based on the input.

For example:

```bash
PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT
```

PLACE will put the toy robot on the table in position X,Y and facing NORTH,
SOUTH, EAST or WEST. The origin (0,0) can be considered to be the SOUTH WEST
most corner.

MOVE will move the toy robot one unit forward in the direction it is currently
facing.

LEFT and RIGHT will rotate the robot 90 degrees in the specified direction
without changing the position of the robot.

REPORT will announce the X,Y and F of the robot to the standard output.

## Constraints

1. It is required that the first command to the robot is a PLACE command, after
that, any sequence of commands may be issued, in any order, including another
PLACE command. The application should discard all commands in the sequence
until a valid PLACE command has been executed.

2. The toy robot must not fall off the table during movement. This also
includes the initial placement of the toy robot. Any move that would cause the
robot to fall must be ignored.

## Design Considerations

### Entities

The problem domain has the following entities.

- Robot: The robot toy itself. It performs the received instructions.
- Table: The environment where the robot is placed and performs the
instructions.
- Position: The current position of the robot in the Table.
- Instructions: The commands given by the user.

### Design Pattern

The Command Design Pattern is used to encapsulate each operation as an object.
This provides a flexible and extensible structure where new commands can be
easily added, and existing commands can be modified with minimal impact on
other parts of the code.

Using a design pattern can also improve the readability of the code because a
person familiar with the design pattern can easily understand the design intent
and structure of the project.

| Class              | Entity       | Description                                                                     |
| ------------------ | -----------  | ------------------------------------------------------------------------------- |
| Robot              | Robot        | Implements the `Robot` entity including its actions                             |
| SimulationMap      | Table        | Contains the properties of the `Table`                                          |
| Position           | Position     | Contains data about a position in the table                                     |
| Parser             | -            | Converts the user input into `CommandInstruction`                               |
| CommandInstruction | Instructions | Data structure containing the user in a format understood by the `Invoker` |
| Invoker            | -            | Calls the appropriate `Command` based on the received `CommandInstruction`           |
| Command            | -            | Executes the corresponding `Robot` method.                                                |

### Cross-Platform Compatibility

The project uses CMake as a build system to ensure that it can be easily built
and run on various platforms.

### Unit Testing

The Catch2 framework is used as it is a lightweight flexible unit testing
framework. There is no need to install the Catch2 framework separately as it is
already included in CMake `FetchContent` requirements.

### Continuous Integration

GitHub Actions is Continuous Integration (CI) tooling chosen as it is freely
available on GitHub. Using a CI tooling in this project will ensure that all
the code pushed into the repository is properly tested and all breakages
are promptly reported and visible in the project's README page.

## Prerequisites

### CMake

Follow the instructions in the CMake installation guide for your environment
[here](https://cmake.org/install/).

## Building the Application

Once you have cloned the project to your working environment, go to the
project directory and run the following commands.

```bash
cmake .
make
```

## Running the Tests

To run the tests, simply run the test target of the generated makefile.

```bash
make test
```

## Running the Command Line Application

After building the project, the executable should be available in src/robot.
To run the application, execute the generated robot binary.

```bash
./src/robot
```

The application will wait for commands via the standard input. Type your command
in the terminal then press enter.

### Examples

#### Example 1

```bash
PLACE 0,0,NORTH
MOVE
REPORT
```

stdout:

```bash
0,1,NORTH
```

#### Example 2

```bash
PLACE 0,0,NORTH
LEFT
REPORT
```

stdout:

```bash
0,0,WEST
```

#### Example 3

```bash
PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT
```

stdout:

```bash
3,3,NORTH
```
