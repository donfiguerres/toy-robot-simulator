#include <iostream>
#include <functional>
#include <cctype>
#include <algorithm>

#include <Parser.h>

/**
 * \brief Custom exception for parsing errors.
 */
class ParsingException : public std::exception
{
public:
    ParsingException(const std::string &message) : message_(message) {}

    virtual const char *what() const noexcept override
    {
        return message_.c_str();
    }

private:
    std::string message_;
};

Parser::Parser()
{
    this->isStdin = true;
}

Parser::Parser(std::string input)
{
    this->input = input;
    this->currentPosition = 0;
    this->isStdin = false;
}

CommandInstruction Parser::nextCommandInstruction()
{
    std::string line = this->isStdin ? nextLineStdin() : nextLineString();

    try
    {
        // Keep all input in uppercase so that string comparisons are easier from
        // this point forward.
        std::transform(line.begin(), line.end(), line.begin(), ::toupper);
        line = trim(line);

        if (line.size() == 0)
            return CommandInstruction(CommandInstruction::END);

        if (line == "MOVE")
            return CommandInstruction(CommandInstruction::MOVE);

        if (line == "LEFT")
            return CommandInstruction(CommandInstruction::LEFT);

        if (line == "RIGHT")
            return CommandInstruction(CommandInstruction::RIGHT);

        if (line == "REPORT")
            return CommandInstruction(CommandInstruction::REPORT);

        // Check the first token
        std::vector<std::string> tokens = tokenize(line, " ", 2);
        if (tokens.front() == "PLACE")
        {
            std::vector<std::string> params = tokenize(tokens[1], ",");
            CommandInstruction result(CommandInstruction::PLACE);
            auto dir = direction(params[2]);
            Position position(std::stoi(params[0]),
                              std::stoi(params[1]),
                              dir);
            result.position = position;
            return result;
        }
        return CommandInstruction(CommandInstruction::ERROR);
    }
    catch (const ParsingException &e)
    {
        return CommandInstruction(CommandInstruction::ERROR);
    }
}

std::string Parser::nextLineStdin()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

std::string Parser::nextLineString()
{
    int start = this->currentPosition;
    int end = input.find("\n", start);

    if (end = -1)
    {
        if (start < input.length())
            end = input.length();
        else
            return std::string("");
    }

    if (end + 1 < input.size())
        this->currentPosition = end + 1;
    else
        this->currentPosition = end;

    std::string result = input.substr(start, end - start);

    return result;
}

std::vector<std::string> Parser::tokenize(std::string input,
                                          std::string delimiter,
                                          int limit)
{
    std::vector<std::string> result;
    int start = 0;
    int end = input.find(delimiter, start);

    while (end != -1)
    {
        if (limit != 0 && ((result.size() + 1) == limit))
        {
            end = input.size();
            break;
        }
        std::string sub = input.substr(start, end - start);
        sub = trim(sub);
        result.push_back(sub);
        start = end + 1;
        end = input.find(delimiter, start);
    }

    // append last token
    std::string sub = input.substr(start, end - start);
    sub = trim(sub);
    result.push_back(sub);

    return result;
}

Position::Direction Parser::direction(std::string input)
{
    if (input == "NORTH")
        return Position::Direction::NORTH;
    if (input == "SOUTH")
        return Position::Direction::SOUTH;
    if (input == "EAST")
        return Position::Direction::EAST;
    if (input == "WEST")
        return Position::Direction::WEST;
    throw ParsingException("Invalid direction: " + input);
}

std::string Parser::trim(std::string input)
{
    return rtrim(ltrim(input));
}

static const std::string WHITESPACE = " \n\r\t\f\v";

std::string Parser::ltrim(std::string input)
{
    size_t start = input.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : input.substr(start);
}

std::string Parser::rtrim(std::string input)
{
    size_t end = input.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : input.substr(0, end + 1);
}
