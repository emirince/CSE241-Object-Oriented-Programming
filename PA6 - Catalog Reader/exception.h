#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

namespace PA6{

class Exception{
public: 
    std::string errorMessage() const { return "base exception class"; }
};

class DuplicateEntry{
public:
    std::string errorMessage() const { return "duplicate entry"; }
};

class MissingField{
public:
    std::string errorMessage() const { return "missing field"; }
};

class CommandWrong{
public:
    std::string errorMessage() const { return "command is wrong"; }
};

class WrongVariable{
public: 
    std::string errorMessage() const { return "can't call that variable"; }
};
}
#endif