#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

#include <Position.h>
#include <Robot.h>

/**
 * \brief Abstract base class for commands.
 *
 * This class represents a generic command that a Robot object can execute.
 */
class Command
{
public:
    /**
     * \brief Virtual destructor for the Command base class.
     */
    virtual ~Command() = default;

    /**
     * \brief Pure virtual function to execute a command.
     *
     * \param robot A shared pointer to the Robot object that will execute the command.
     */
    virtual void execute(std::shared_ptr<Robot> robot) = 0;
};

/**
 * \brief A Command that places a Robot at a specified position.
 */
class PlaceCommand : public Command
{
public:
    /**
     * \brief Construct a new Place Command object.
     *
     * \param position The Position where the Robot should be placed.
     */
    PlaceCommand(Position position);

    /**
     * \brief Execute the PlaceCommand, placing the Robot at a specific
     * position.
     *
     * \param robot A shared pointer to the Robot object that will be placed.
     */
    virtual void execute(std::shared_ptr<Robot> robot);

private:
    Position position;
};

/**
 * \brief A Command that moves a Robot.
 */
class MoveCommand : public Command
{
public:
    /**
     * \brief Execute the MoveCommand, moving the Robot.
     *
     * \param robot A shared pointer to the Robot object that will be moved.
     */
    virtual void execute(std::shared_ptr<Robot> robot);
};

/**
 * \brief A Command that turns a Robot to the left.
 */
class LeftCommand : public Command
{
public:
    /**
     * \brief Execute the LeftCommand, turning the Robot to the left.
     *
     * \param robot A shared pointer to the Robot object that will be turned.
     */
    virtual void execute(std::shared_ptr<Robot> robot);
};

/**
 * \brief A Command that turns a Robot to the right.
 */
class RightCommand : public Command
{
public:
    /**
     * \brief Execute the RightCommand, turning the Robot to the right.
     *
     * \param robot A shared pointer to the Robot object that will be turned.
     */
    virtual void execute(std::shared_ptr<Robot> robot);
};

/**
 * \brief A Command that reports the state of a Robot.
 */
class ReportCommand : public Command
{
public:
    /**
     * \brief Execute the ReportCommand, reporting the state of the Robot.
     *
     * \param robot A shared pointer to the Robot object whose state will be reported.
     */
    virtual void execute(std::shared_ptr<Robot> robot);
};

#endif