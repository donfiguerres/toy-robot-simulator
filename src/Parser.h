#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

#include <CommandInstruction.h>

/**
 * \brief Parser for command input
 *
 * The Parser class is used to parse command input and convert it into Command
 * objects. It supports reading from standard input or from a provided string.
 *
 * TODO: Abstract the input source into a separate class.
 */
class Parser
{
public:
    /**
     * \brief Construct a new Parser object for reading from standard input.
     */
    Parser();

    /**
     * \brief Construct a new Parser object for reading from a string.
     *
     * \param input The string to parse commands from.
     */
    Parser(std::string input);

    /**
     * \brief Retrieve the next Command from the input.
     *
     * \return The next Command.
     */
    CommandInstruction nextCommandInstruction();

private:
    /**
     * \brief Retrieve the next line from standard input.
     *
     * \return The next line.
     */
    std::string nextLineStdin();

    /**
     * \brief Retrieve the next line from the input string.
     *
     * \return The next line.
     */
    std::string nextLineString();

    bool isStdin;        ///< Determines whether the input is standard input.
    std::string input;   ///< The string to parse commands from, if not standard input.
    int currentPosition; ///< The current position in the input string.

    /**
     * \brief Tokenizes the given input string.
     *
     * \param input The string to tokenize.
     * \param delimiter The delimiter to tokenize by.
     * \param limit The maximum number of tokens. Default is 0, which means no limit.
     * \return The tokens.
     */
    static std::vector<std::string> tokenize(
        std::string input, std::string delimiter, int limit = 0);

    /**
     * \brief Converts the given string to a Direction.
     *
     * \param input The string to convert.
     * \return The Direction.
     */
    static Position::Direction direction(std::string input);

    /**
     * \brief Trims both leading and trailing whitespace from the given string.
     *
     * \param input The string to trim.
     * \return The trimmed string.
     */
    static std::string trim(std::string input);

    /**
     * \brief Trims trailing whitespace from the given string.
     *
     * \param input The string to trim.
     * \return The trimmed string.
     */
    static std::string rtrim(std::string input);

    /**
     * \brief Trims leading whitespace from the given string.
     *
     * \param input The string to trim.
     * \return The trimmed string.
     */
    static std::string ltrim(std::string input);
};

#endif
