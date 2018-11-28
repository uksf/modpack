#pragma once
#include <string>

class exception : public std::exception {
public:
    exception(std::string type, std::string message, int statusCode);

    int code() const;
    std::string type() const;
    std::string message() const;

private:
    int _statusCode;
    std::string _type;
    std::string _message;
};
