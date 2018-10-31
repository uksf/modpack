#pragma once

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include <map>

typedef std::pmr::map<std::string, std::string> ROUTE;

class router : public Poco::Net::HTTPRequestHandlerFactory {
public:
    router();

    void addRoute(const std::string &, const std::string &);
    Poco::Net::HTTPRequestHandler * createRequestHandler(const Poco::Net::HTTPServerRequest & request) override;

private:
    void init();
    ROUTE routingTable;
    Poco::Net::HTTPRequestHandler * getResource(const std::string &);
};
