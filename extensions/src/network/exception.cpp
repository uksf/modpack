#include "exception.hpp"
#include <utility>

exception::exception(std::string type, std::string message, const int statusCode)
    : _statusCode(statusCode),
      _type(std::move(type)),
      _message(std::move(message)) {}

int exception::code() const {
    return _statusCode;
}

std::string exception::type() const {
    return _type;
}

std::string exception::message() const {
    return _message;
}
