#pragma once

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include <map>

class router : public Poco::Net::HTTPRequestHandlerFactory {
public:
    router();

    void addRoute(const std::string &, const std::string &);
    Poco::Net::HTTPRequestHandler * createRequestHandler(const Poco::Net::HTTPServerRequest & request);

private:
    void init();
    std::map<std::string, std::string> routingTable;
    Poco::Net::HTTPRequestHandler * getResource(const std::string &);
};
