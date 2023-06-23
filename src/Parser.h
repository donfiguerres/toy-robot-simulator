#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

#include <Command.h>


class Parser
{
public:
    // Input reading can be abstracted to a separate class later.
    // For now, I've included it here for simplicity.
    Parser();
    Parser(std::string input);
    Command nextCommand();

private:
    std::string nextLineStdin();
    std::string nextLineString();

    bool isStdin;
    std::string input;
    int currentPosition;

    // Pure functions
    static std::vector<std::string> tokenize(std::string input, std::string delimiter, int limit = 0);
    static Position::Direction direction(std::string input);
    static std::string trim(std::string input);
    static std::string rtrim(std::string input);
    static std::string ltrim(std::string input);
};

#endif