#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

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

#endif