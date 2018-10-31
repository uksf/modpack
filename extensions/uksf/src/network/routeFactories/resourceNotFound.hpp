#pragma once
#include <Poco/Net/HTTPRequestHandler.h>

class resourceNotFound : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);
};
