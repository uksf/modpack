#pragma once
#include <Poco/Net/HTTPRequestHandler.h>

class IFactory {
public:
    virtual Poco::Net::HTTPRequestHandler * createResource() = 0;
};
