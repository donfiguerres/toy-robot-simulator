# Toy Robot Simulator

![actions workflow](https://github.com/donfiguerres/toy-robot-simulator/actions/workflows/cmake.yml/badge.svg)

This is a simulation of a robot toy moving on a square table top with a size of
5 units x 5 units.

## Prerequisites

### CMake

CMake is used to allow the project to cross-platform compatible. Follow the
instructions in the CMake installation guide for your environment
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
